# 1260. Shift 2D Grid

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

[LeetCode — 1260. Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)

---

## Problem Summary

Given an `m × n` grid and an integer `k`, shift the grid to the right `k` times.

In one shift:

- `grid[i][j]` moves to `grid[i][j + 1]`.
- The last element of a row moves to the first position of the next row.
- The bottom-right element moves to the top-left corner.

Return the grid after all shifts. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
grid = [[1,2,3],
        [4,5,6],
        [7,8,9]]
k = 1
```

**Output**

```text
[[9,1,2],
 [3,4,5],
 [6,7,8]]
```

---

### Example 2

**Input**

```text
grid = [[3,8,1,9],
        [19,7,2,5],
        [4,6,11,10],
        [12,0,21,13]]
k = 4
```

**Output**

```text
[[12,0,21,13],
 [3,8,1,9],
 [19,7,2,5],
 [4,6,11,10]]
```

---

## Intuition

Treat the 2D grid as a single one-dimensional array.

Each cell has an index:

```text
index = row × n + column
```

After shifting by `k`, every element simply moves to:

```text
(index + k) % (m × n)
```

Finally, convert the new one-dimensional index back into row and column positions.

---

## Approach

1. Compute the total number of elements.
2. Reduce `k` using modulo since shifting by `m × n` leaves the grid unchanged.
3. Traverse every cell in the original grid.
4. Convert each cell into its 1D index.
5. Compute its shifted position.
6. Convert the shifted index back to 2D coordinates and place the element there.
7. Return the new grid.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(m × n)` |
| **Space** | `O(m × n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                int newIdx = (idx + k) % total;
                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- View the matrix as a flattened one-dimensional array.
- Convert between 2D coordinates and a 1D index using simple arithmetic.
- Use modulo to avoid unnecessary full-grid rotations.
- Each element is processed exactly once, resulting in **O(m × n)** time complexity.
- The implementation is simple, efficient, and avoids performing `k` individual shifts.