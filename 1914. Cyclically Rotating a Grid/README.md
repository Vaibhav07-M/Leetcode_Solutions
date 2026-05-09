# 1914. Cyclically Rotating a Grid

**Difficulty:** `Medium`  
**Tags:** `Matrix`, `Simulation`

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

[LeetCode — 1914. Cyclically Rotating a Grid](https://leetcode.com/problems/cyclically-rotating-a-grid/)

---

## Problem Summary

You are given an even-sized matrix `grid` and an integer `k`.
The matrix is formed by several concentric layers.

A single cyclic rotation moves every element in a layer one step in the counter-clockwise direction.
Your task is to apply `k` such rotations to every layer and return the final grid.

---

## Examples

### Example 1
**Input:** `grid = [[40,10],[30,20]], k = 1`  
**Output:** `[[10,20],[40,30]]`

### Example 2
**Input:** `grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2`  
**Output:** `[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]`

---

## Intuition

Each layer is a closed loop. Instead of rotating the matrix one step at a time, it is simpler to:

- extract the elements of one layer in traversal order,
- rotate that linear list by `k % len` positions,
- write the values back into the same layer.

Because layers do not overlap, we can process them independently.

---

## Approach

1. Identify each layer by its `top`, `bottom`, `left`, and `right` boundaries.
2. Traverse the layer in a fixed order and store all values in a temporary array.
   - top row left to right
   - right column top+1 to bottom-1
   - bottom row right to left
   - left column bottom-1 to top+1
3. Rotate the temporary array by `k % layerSize` positions.
4. Write the rotated values back into the same cells using the same traversal order.
5. Repeat for every layer.

This directly simulates the cyclic movement while staying easy to reason about.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — every cell is visited a constant number of times |
| **Space** | `O(m + n)` — temporary storage for one layer |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            int top = layer, left = layer;
            int bottom = m - 1 - layer, right = n - 1 - layer;

            vector<int> vals;

            for (int j = left; j <= right; ++j) vals.push_back(grid[top][j]);
            for (int i = top + 1; i <= bottom - 1; ++i) vals.push_back(grid[i][right]);
            for (int j = right; j >= left; --j) vals.push_back(grid[bottom][j]);
            for (int i = bottom - 1; i >= top + 1; --i) vals.push_back(grid[i][left]);

            int len = vals.size();
            int shift = k % len;
            vector<int> rotated(len);
            for (int i = 0; i < len; ++i) {
                rotated[i] = vals[(i + shift) % len];
            }

            int idx = 0;
            for (int j = left; j <= right; ++j) grid[top][j] = rotated[idx++];
            for (int i = top + 1; i <= bottom - 1; ++i) grid[i][right] = rotated[idx++];
            for (int j = right; j >= left; --j) grid[bottom][j] = rotated[idx++];
            for (int i = bottom - 1; i >= top + 1; --i) grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};
```

---

## Key Takeaways

- Treat each layer as an independent cycle.
- Linearizing a cycle makes rotation straightforward.
- Reusing the same traversal order for extraction and restoration keeps the solution clean.
