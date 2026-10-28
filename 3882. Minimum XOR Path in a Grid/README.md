# 3882. Minimum XOR Path in a Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`, `Bit Manipulation`, `Matrix`

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

[LeetCode — 3882. Minimum XOR Path in a Grid](https://leetcode.com/problems/minimum-xor-path-in-a-grid/)

---

## Problem Summary

The problem requires finding the minimum XOR value of a path from the top-left to the bottom-right cell in a 2D grid. The path cost is defined as the bitwise XOR of all cell values along the route. The solution employs a dynamic programming approach to track possible XOR values at each cell, ultimately determining the minimum achievable value at the destination.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is that the XOR operation is associative and commutative, allowing us to build the total path cost incrementally. By maintaining a boolean array 'possible' that indicates whether a specific XOR value can be reached at each cell, we can efficiently update the state as we move through the grid. This allows us to identify the smallest valid XOR value at the final destination without needing to enumerate every possible path.

---

## Approach

1. Initialize a 3D boolean array 'possible' where 'possible[i][j][x]' indicates if an XOR value of 'x' is achievable at cell (i, j).
2. Set the initial state: 'possible[0][0][grid[0][0]] = true', as the starting cell's XOR is simply its own value.
3. Iterate through the grid. For each cell (i, j), check the states of the cells directly above and to the left.
4. If a path exists to a neighboring cell with XOR value 'x', update the current cell's state to include the new XOR value 'x ^ grid[i][j]'.
5. After processing all cells, check the 'possible' array at the bottom-right corner (m-1, n-1) to find the smallest index 'x' where 'possible[m-1][n-1][x] = true'. This represents the minimum XOR cost.
6. Return the identified minimum XOR value.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * 2^k)` — The algorithm iterates over each cell in the m x n grid. For each cell, it potentially updates a state for every possible XOR value (up to 2^k, where k is the number of bits in the integer representation). This results in a time complexity of O(m * n * 2^k). |
| **Space** | `O(m * n * 2^k)` — The space complexity is dominated by the 3D boolean array 'possible', which stores a state for every cell and every possible XOR value. Since there are m*n cells and approximately 2^k possible XOR values, the total space required is O(m * n * 2^k). |

---

## Code (C++)

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // possible[i][j][x] indicates whether XOR value x
        // can be obtained on a path ending at cell (i, j).
        vector<vector<vector<bool>>> possible(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        possible[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int value = grid[i][j];

                // Paths coming from above
                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (possible[i - 1][j][x]) {
                            possible[i][j][x ^ value] = true;
                        }
                    }
                }

                // Paths coming from the left
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (possible[i][j - 1][x]) {
                            possible[i][j][x ^ value] = true;
                        }
                    }
                }
            }
        }

        // Find the smallest XOR value at the destination
        for (int x = 0; x < 1024; x++) {
            if (possible[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- The solution effectively uses a 3D dynamic programming table to track the feasibility of specific XOR values, rather than storing the actual paths.
- The associative property of XOR allows for efficient state updates by combining the current cell value with the incoming path's XOR value.
- The approach successfully reduces the problem of finding the minimum path cost to a search for the smallest index in a boolean array at the destination.
