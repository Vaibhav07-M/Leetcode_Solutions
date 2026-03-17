# 1727. Largest Submatrix With Rearrangements

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Sorting`

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

[LeetCode - 1727. Largest Submatrix With Rearrangements](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

---

## Problem Summary

You are given a binary matrix `matrix` of size `m x n`.

You may reorder columns in any way (the same reordering applies within a chosen row view), and you need the maximum area of a submatrix consisting only of `1`s.

Return that largest possible area.

---

## Examples

### Example 1
**Input:** `matrix = [[0,0,1],[1,1,1],[1,0,1]]`  
**Output:** `4`

### Example 2
**Input:** `matrix = [[1,0,1,0,1]]`  
**Output:** `3`

### Example 3
**Input:** `matrix = [[1,1,0],[1,0,1]]`  
**Output:** `2`

---

## Intuition

For each row, treat `matrix[i][j]` as a histogram height of consecutive `1`s ending at row `i`.

If columns can be rearranged freely, then for a fixed row we should sort heights in descending order.  
After sorting, if `row[j]` is the `j`-th height (0-indexed), we can form width `j + 1` with minimum height `row[j]`, so area is:

`row[j] * (j + 1)`

Take the maximum over all rows and positions.

---

## Approach

1. Build cumulative heights in-place:
- For row `i > 0`, if `matrix[i][j] == 1`, add `matrix[i-1][j]`.
2. For each row:
- Copy row into a temp vector.
- Sort descending.
- Compute max `row[j] * (j + 1)`.
3. Return global maximum area.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n log n)` (sorting each row) |
| **Space** | `O(n)` extra for copied row |

---

## Code (C++)

### Solution 1 - Histogram Heights + Per-Row Sort (Submitted)

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Build height histogram
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            vector<int> row = matrix[i];
            
            sort(row.begin(), row.end(), greater<int>());

            for(int j = 0; j < n; j++){
                ans = max(ans, row[j] * (j + 1));
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Convert binary rows into consecutive-height histograms.
- Column rearrangement means each row can be greedily sorted by height.
- Evaluate area by fixing width after sorting and using the corresponding minimum height.
