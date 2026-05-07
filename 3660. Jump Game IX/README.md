# 3660. Jump Game IX

**Difficulty:** `Medium`  
**Tags:** `Array`, `Monotonic Stack`, `Dynamic Programming`

---

## Table of Contents
- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode — 3660. Jump Game IX](https://leetcode.com/problems/jump-game-ix/)

---

## Problem Summary

Given an integer array `nums`, you may jump from index `i` to index `j` under rules:
- If `j > i` then the jump is allowed only when `nums[j] < nums[i]`.
- If `j < i` then the jump is allowed only when `nums[j] > nums[i]`.

For each `i`, compute the maximum value in `nums` reachable by following any valid sequence of jumps starting at `i`. Return the array `ans` where `ans[i]` is that maximum value.

---

## Examples

### Example 1
**Input:** `nums = [2,1,3]`  
**Output:** `[2,2,3]`

### Example 2
**Input:** `nums = [2,3,1]`  
**Output:** `[3,3,3]`

---

## Intuition

Valid jumps depend on relative comparisons and direction. We can view possible moves as directed edges defined by next-smaller (to the right) and previous-greater (to the left) relationships. Those edges form a DAG on indices which we can traverse to propagate the maximum reachable value.

Monotonic stacks give us next/previous greater/smaller indices efficiently. With those edges, DP on the DAG (topological via index order or memoized DFS) yields the answer.

---

## Approach

1. Compute next-smaller-to-the-right and previous-greater-to-the-left indices using monotonic stacks.
2. Build directed edges for valid jumps (from i to next-smaller-right indices, and from i to previous-greater-left indices). Multiple outgoing edges per node are possible.
3. Use memoized DFS (or DP) to compute the maximum value reachable from each index:
   - If a node has no outgoing edges, its reachable maximum is `nums[i]`.
   - Otherwise, `ans[i] = max(nums[i], max(ans[child] for child in edges[i]))`.
4. Return the `ans` array.

This runs in linear time for stack computation and linear-time DFS across edges (O(n)).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — monotonic stacks + DFS over edges |
| **Space** | `O(n)` — stacks, edge lists, and memoization |

---

## Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSmaller(n, -1), prevGreater(n, -1);
        // next smaller to the right
        {
            vector<int> st;
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && nums[i] < nums[st.back()]) {
                    nextSmaller[st.back()] = i; st.pop_back();
                }
                st.push_back(i);
            }
        }
        // previous greater to the left
        {
            vector<int> st;
            for (int i = n-1; i >= 0; --i) {
                while (!st.empty() && nums[i] > nums[st.back()]) {
                    prevGreater[st.back()] = i; st.pop_back();
                }
                st.push_back(i);
            }
        }
        // build edges
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            if (nextSmaller[i] != -1) edges[i].push_back(nextSmaller[i]);
            if (prevGreater[i] != -1) edges[i].push_back(prevGreater[i]);
        }
        vector<int> memo(n, INT_MIN);
        function<int(int)> dfs = [&](int u) -> int {
            if (memo[u] != INT_MIN) return memo[u];
            int best = nums[u];
            for (int v: edges[u]) best = max(best, dfs(v));
            return memo[u] = best;
        };
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = dfs(i);
        return ans;
    }
};
```

---

## Key Takeaways

- Translate directional comparison rules into next/previous relations.
- Monotonic stacks efficiently compute required indices.
- Treat the problem as DP on a DAG defined by valid jumps.
