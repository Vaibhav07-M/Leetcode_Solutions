# 1345. Jump Game IV

**Difficulty:** `Hard`  
**Tags:** `Array`, `BFS`, `Graph`, `Hash Table`

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

[LeetCode — 1345. Jump Game IV](https://leetcode.com/problems/jump-game-iv/)

---

## Problem Summary

You are given an integer array `arr` and start at index `0`. From index `i`, you may jump to:

- `i + 1` (if within bounds)
- `i - 1` (if within bounds)
- any index `j` where `arr[i] == arr[j]` and `i != j`

Return the **minimum number of steps** needed to reach index `n - 1`.

---

## Examples

### Example 1
**Input:** `arr = [100,-23,-23,404,100,23,23,23,3,404]`  
**Output:** `3`  
**Explanation:** One optimal sequence is `0 -> 4 -> 3 -> 9`.

### Example 2
**Input:** `arr = [7]`  
**Output:** `0`  
**Explanation:** You are already at the last index.

### Example 3
**Input:** `arr = [7,6,9,6,9,6,9,7]`  
**Output:** `1`  
**Explanation:** Jump directly from index `0` to index `7` (same value).

---

## Intuition

This is a shortest-path problem on an implicit graph:

- Each index is a node.
- Edges connect `i` to `i-1`, `i+1`, and all indices with the same value.

Since all edges have equal cost (one step), **BFS** from index `0` guarantees the first time we reach `n - 1` is the minimum number of steps.

The only tricky part is jumping to “same value” indices efficiently; if we repeatedly scan all equal-value indices, we can blow up to `O(n^2)`.

---

## Approach

1. Build a map `value -> list of indices` so we can jump to all equal-value positions quickly.
2. Run BFS starting from index `0`:
   - Pop `(index, steps)`.
   - If `index == n - 1`, return `steps`.
   - Push valid neighbors:
     - `index - 1`, `index + 1`
     - every index in the list for `arr[index]`
3. To keep BFS efficient, after processing the same-value list for a value `v`, **erase it from the map**. This ensures every list is expanded at most once.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` amortized — each index is visited once and each value-group list is processed once |
| **Space** | `O(n)` — map + visited + BFS queue |

---

## Code (C++)

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idx;
        int n = arr.size();
        for (int i = 0; i < n; ++i) idx[arr[i]].push_back(i);
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        unordered_set<int> vis;
        vis.insert(0);
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            int i = e.first, step = e.second;
            if (i == n - 1) return step;
            int v = arr[i];
            ++step;
            if (idx.count(v)) {
                for (int j : idx[v]) {
                    if (!vis.count(j)) {
                        vis.insert(j);
                        q.emplace(j, step);
                    }
                }
                idx.erase(v);
            }
            if (i + 1 < n && !vis.count(i + 1)) {
                vis.insert(i + 1);
                q.emplace(i + 1, step);
            }
            if (i - 1 >= 0 && !vis.count(i - 1)) {
                vis.insert(i - 1);
                q.emplace(i - 1, step);
            }
        }
        return -1;
    }
};
```

---

## Key Takeaways

- Model the array as an implicit graph; use BFS for minimum steps.
- Precompute `value -> indices` to get same-value jumps in `O(1)` access.
- Erasing a value’s index list after expanding it is the key optimization that prevents `O(n^2)` behavior.
