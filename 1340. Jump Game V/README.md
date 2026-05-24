# 1340. Jump Game V

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `DFS`

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

[LeetCode — 1340. Jump Game V](https://leetcode.com/problems/jump-game-v/)

---

## Problem Summary

Given an array of integers `arr` and an integer `d`. From index `i` you can jump to `i + x` or `i - x` where `0 < x <= d`, but only if `arr[i] > arr[j]` for all indices between `i` and `j`. You may start at any index; return the maximum number of indices you can visit.

---

## Examples

### Example 1
**Input:** `arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2`  
**Output:** `4`

### Example 2
**Input:** `arr = [3,3,3,3,3], d = 3`  
**Output:** `1`

### Example 3
**Input:** `arr = [7,6,5,4,3,2,1], d = 1`  
**Output:** `7`

---

## Intuition

We want the longest path of valid jumps starting from any index. Because jumps can only go to strictly smaller elements and are constrained by distance `d`, the structure is a DAG when edges go from larger to smaller elements. We can compute the longest reachable path with memoized DFS or dynamic programming over indices.

---

## Approach

1. Use DFS with memoization: `dp[i]` = max reachable count starting at `i`.
2. For each index, try jumping left and right up to distance `d`, stopping when encountering a value >= `arr[i]`.
3. For each valid next index `j` (with `arr[j] < arr[i]` and reachable), `dp[i] = max(dp[i], 1 + dfs(j))`.
4. Answer is `max(dp[i])` across all `i`.

This yields `O(n * d)` time where `d` is the jump limit, with memoization avoiding repeated work.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * d)` worst-case | 
| **Space** | `O(n)` for recursion + `dp` |

---

## Code (C++)

```cpp
class Solution {
public:
    int n, D;
    vector<int> dp;
    vector<int> arr;

    int dfs(int i) {
        if (dp[i]) return dp[i];
        int best = 1;
        for (int k = 1; k <= D; ++k) {
            int j = i + k;
            if (j >= n || arr[j] >= arr[i]) break;
            best = max(best, 1 + dfs(j));
        }
        for (int k = 1; k <= D; ++k) {
            int j = i - k;
            if (j < 0 || arr[j] >= arr[i]) break;
            best = max(best, 1 + dfs(j));
        }
        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr_, int d) {
        arr = arr_; n = arr.size(); D = d;
        dp.assign(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, dfs(i));
        return ans;
    }
};
```

---

## Key Takeaways

- Model allowed jumps as directed edges from higher to lower values; the graph is acyclic in jump direction.
- Memoized DFS (top-down DP) efficiently computes longest reachable path per index.
- Time depends linearly on `d` per index — keep `d` small when possible.
