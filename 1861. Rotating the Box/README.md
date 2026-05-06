# 1861. Rotating the Box

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

[LeetCode — 1861. Rotating the Box](https://leetcode.com/problems/rotating-the-box/)

---

## Problem Summary

You are given an `m x n` matrix `boxGrid` representing a side view of a box.
Each cell contains one of the following:
- `#` for a stone
- `*` for a stationary obstacle
- `.` for empty space

The box is rotated 90 degrees clockwise.
After rotation, stones fall due to gravity until they land on an obstacle, another stone, or the bottom of the box.

Return the final `n x m` grid after rotation and gravity are applied.

---

## Examples

### Example 1
**Input:** `boxGrid = [["#",".","#"]]`  
**Output:** `[["."],["#"],["#"]]`

### Example 2
**Input:** `boxGrid = [["#",".","*","."],["#","#","*","."]]`  
**Output:** `[["#","."],["#","#"],["*","*"],[".","."]]`

### Example 3
**Input:** `boxGrid = [["#","#","*",".","*","."],["#","#","#","*",".","."],["#","#","#",".","#","."]]`  
**Output:** `[[".","#","#"],[".","#","#"],["#","#","*"],["#","*","."],["#",".","*"],["#",".","."]]`

---

## Intuition

Rotating first and then trying to simulate gravity is awkward.
A cleaner approach is to handle gravity in the original orientation, where stones fall to the right.

Within each row, obstacles split the row into independent segments.
In each segment, stones can be compacted as far right as possible, while obstacles stay fixed.
After that, rotating the grid clockwise becomes a simple index remapping step.

---

## Approach

1. **Simulate gravity row by row.**
   - Traverse each row from right to left.
   - Keep a pointer to the next position where a stone can fall.
   - When you see an obstacle, reset that pointer to the cell just left of it.
   - When you see a stone, swap it into the current available position.
2. **Rotate the grid clockwise.**
   - Create an `n x m` result matrix.
   - Map `boxGrid[i][j]` to `ans[j][m - 1 - i]`.

This keeps the logic simple and runs in linear time over the grid.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(mn)` — each cell is processed a constant number of times |
| **Space** | `O(mn)` — for the rotated result matrix |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: simulate gravity (stones fall right)
        for (int i = 0; i < m; i++) {
            int empty = n - 1;

            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: rotate clockwise
        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Simulating gravity before rotation keeps the implementation straightforward.
- Obstacles divide each row into independent segments.
- A simple index transform handles the clockwise rotation cleanly.
