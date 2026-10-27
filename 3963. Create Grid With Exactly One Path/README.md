# 3963. Create Grid With Exactly One Path

**Difficulty:** `Easy`  
**Tags:** 

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

[LeetCode — 3963. Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/)

---

## Problem Summary

The problem requires constructing an m x n grid with exactly one valid path from the top-left to the bottom-right cell. The path must consist of free cells ('.') and can only move right or down. The solution creates a grid where the first row and the last column are free, while all other cells are obstacles ('#'), ensuring a unique path exists.

---

## Examples

_No examples provided._

---

## Intuition

By setting the first row and last column to free cells, we force the path to start at the top-left, move horizontally to the right, and then vertically down to the bottom-right. Since all other cells are obstacles, there is no alternative route, guaranteeing a single valid path.

---

## Approach

1. Initialize a grid of size m x n with all cells set to obstacles ('#').
2. Set the entire first row (index 0) to free cells ('.') to allow the path to begin and move horizontally.
3. Set the entire last column (index n-1) to free cells ('.') to allow the path to move vertically to the end.
4. Return the constructed grid, which contains exactly one valid path.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The algorithm iterates over the entire grid to initialize it and then updates specific rows and columns. The total number of operations is proportional to the size of the grid (m * n). |
| **Space** | `O(m * n)` — The solution stores the entire grid as a 2D vector of strings. The space required is directly dependent on the dimensions of the grid (m * n). |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // Make the first row free
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Make the last column free
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};
```

---

## Key Takeaways

- A unique path can be created by restricting movement to specific boundaries (e.g., first row and last column).
- The use of obstacles ('#') effectively blocks all other potential paths, ensuring the solution is robust.
