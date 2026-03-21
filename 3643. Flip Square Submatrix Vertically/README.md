# 3643. Flip Square Submatrix Vertically

**Difficulty:** `Easy`  
**Tags:** `Array`, `Matrix`, `Simulation`

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

[LeetCode - 3643. Flip Square Submatrix Vertically](https://leetcode.com/problems/flip-square-submatrix-vertically/)

---

## Problem Summary

You are given an integer matrix `grid` and three integers `x`, `y`, and `k`.

- `(x, y)` is the top-left corner of a `k x k` square submatrix.
- You need to flip this square vertically, meaning reverse the order of its rows.

Return the updated matrix after applying this operation.

---

## Examples

### Example 1
**Input:** `grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3`  
**Output:** `[[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]`

### Example 2
**Input:** `grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2`  
**Output:** `[[3,4,4,2],[2,3,2,3]]`

---

## Intuition

A vertical flip swaps:
- top row of the chosen square with bottom row,
- second row with second-last row,
- and so on.

Only cells inside the selected `k x k` region are modified.

---

## Approach

1. Iterate over only the first half of rows in the chosen square (`i` from `0` to `k/2 - 1`).
2. For each row pair, iterate all `k` columns in the square.
3. Swap corresponding elements:
   - `grid[x + i][y + j]`
   - `grid[x + k - 1 - i][y + j]`
4. Return the modified matrix.

This performs the vertical reversal in-place.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(k^2)` |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        for(int i = 0; i < k / 2; i++) {
            for(int j = 0; j < k; j++) {
                // Swap vertically
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        
        return grid;
    }
};
```

---

## Key Takeaways

- Vertical flip of a square is row-pair swapping.
- Only half the rows need processing.
- In-place swapping gives constant extra space.
