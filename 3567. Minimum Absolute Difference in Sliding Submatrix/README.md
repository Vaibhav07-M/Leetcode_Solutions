# 3567. Minimum Absolute Difference in Sliding Submatrix

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Sliding Window`, `Sorting`

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

[LeetCode - 3567. Minimum Absolute Difference in Sliding Submatrix](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/)

---

## Problem Summary

You are given an `m x n` integer matrix `grid` and an integer `k`.

For every contiguous `k x k` submatrix, compute the minimum absolute difference between any two distinct values inside that submatrix.

Return a matrix `ans` of size `(m - k + 1) x (n - k + 1)` where `ans[i][j]` corresponds to the submatrix with top-left corner `(i, j)`.

If all values in a submatrix are equal, the answer for that window is `0`.

---

## Examples

### Example 1
**Input:** `grid = [[1,8],[3,-2]], k = 2`  
**Output:** `[[2]]`

### Example 2
**Input:** `grid = [[3,-1]], k = 1`  
**Output:** `[[0,0]]`

### Example 3
**Input:** `grid = [[1,-2,3],[2,3,5]], k = 2`  
**Output:** `[[1,2]]`

---

## Intuition

For one fixed `k x k` window:
- We only care about **distinct values**.
- The minimum absolute difference among numbers is achieved by two adjacent values in sorted order.

So for each window:
1. collect values in a sorted structure with deduplication,
2. scan adjacent values,
3. keep the minimum difference.

Since `m, n <= 30`, a direct per-window approach is fast enough.

---

## Approach

1. Create answer matrix `result` with size `(m-k+1) x (n-k+1)` initialized to `0`.
2. For each window top-left `(i, j)`:
   - Insert all `k x k` elements into a `set<int>` (`set` keeps distinct values in sorted order).
3. If set size is `1`, all values are identical, so answer remains `0`.
4. Otherwise, iterate adjacent elements in the set and compute:
   - `minDiff = min(minDiff, current - previous)`
5. Store `minDiff` in `result[i][j]`.
6. Return `result`.

---

## Complexity

Let `W = (m-k+1) * (n-k+1)` be the number of windows.

| Metric | Complexity |
|--------|------------|
| **Time** | `O(W * k^2 * log(k^2))` |
| **Space** | `O(k^2)` per window for the set |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));

        for (int i = 0; i <= m-k; i++) {
            for (int j = 0; j <= n-k; j++) {

                // Set for distinct + sorted
                set<int> vals;

                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }

                // If all elements were same, set has only 1 element
                if (vals.size() == 1) {
                    continue;
                }

                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);

                while (curr != vals.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                result[i][j] = minAbsDiff;
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- For minimum pair difference, sorting (or ordered set) is the key observation.
- Adjacent sorted values give the minimum absolute difference.
- Given small constraints, rebuilding per window is simple and sufficient.
