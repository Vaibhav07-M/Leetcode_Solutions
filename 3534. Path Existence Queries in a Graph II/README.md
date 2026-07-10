# 3534. Path Existence Queries in a Graph II

**Difficulty:** `Hard`  
**Tags:** `Graph`, `Binary Lifting`, `Sorting`

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

[LeetCode — 3534. Path Existence Queries in a Graph II](https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/)

---

## Problem Summary

You are given:

- An integer `n` representing the number of nodes.
- An array `nums`.
- An integer `maxDiff`.
- A list of queries.

An undirected edge exists between two nodes if the absolute difference between their values is at most `maxDiff`.

For every query `[u, v]`, return the **minimum number of edges** required to travel between the two nodes. If no path exists, return `-1`. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```text
n = 5
nums = [1,8,3,4,2]
maxDiff = 3
queries = [[0,3],[2,4]]
```

**Output:**

```text
[1,1]
```

---

### Example 2

**Input:**

```text
n = 5
nums = [5,3,1,9,10]
maxDiff = 2
queries = [[0,1],[0,2],[2,3],[4,3]]
```

**Output:**

```text
[1,2,-1,1]
```

---

## Intuition

Instead of explicitly constructing every edge, sort the nodes by their values.

For each node, determine the **furthest node reachable in one step** while keeping the value difference within `maxDiff`.

Once these direct jumps are known, Binary Lifting allows us to repeatedly make the largest possible jumps toward the destination, reducing each query to logarithmic time.

---

## Approach

1. Pair every value with its original index and sort by value.
2. Using a two-pointer technique, compute the furthest reachable node for every position.
3. Build a Binary Lifting table where `f[i][k]` stores the node reached after `2^k` jumps.
4. For each query:
   - Handle trivial cases.
   - Use Binary Lifting to make the largest valid jumps.
   - If the destination is still unreachable, return `-1`.
   - Otherwise, return the minimum number of jumps.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + q) log n)` |
| **Space** | `O(n log n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.emplace_back(nums[i], i);
        }
        sort(pairs.begin(), pairs.end());

        int m = 20;
        vector<vector<int>> f(n, vector<int>(m));
        int r = n - 1;
        for (int l = n - 1; l >= 0; l--) {
            while (pairs[r].first - pairs[l].first > maxDiff) {
                r--;
            }
            int i = pairs[l].second, j = pairs[r].second;
            f[i][0] = j;
            for (int k = 1; k < m; k++) {
                f[i][k] = f[f[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            if (nums[i] > nums[j]) {
                swap(i, j);
            }
            if (i == j) {
                ans.push_back(0);
                continue;
            }
            if (nums[i] == nums[j]) {
                ans.push_back(1);
                continue;
            }
            int d = 0;
            for (int k = m - 1; k >= 0; k--) {
                if (nums[f[i][k]] < nums[j]) {
                    d |= 1 << k;
                    i = f[i][k];
                }
            }
            if (nums[f[i][0]] < nums[j]) {
                ans.push_back(-1);
            } else {
                ans.push_back(d + 1);
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Sorting converts value constraints into ordered intervals.
- Two pointers efficiently compute the maximum reachable node in one move.
- Binary Lifting answers shortest-jump queries in logarithmic time.
- Preprocessing enables handling up to `10^5` queries efficiently.