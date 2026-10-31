# 3665. Twisted Mirror Path Count

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`, `Matrix`

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

[LeetCode — 3665. Twisted Mirror Path Count](https://leetcode.com/problems/twisted-mirror-path-count/)

---

## Problem Summary

The problem involves a robot navigating a binary grid with mirrors. The robot can move right or down, but if it encounters a mirror, it is reflected (moving down if it was going right, and right if it was going down). The goal is to count the number of unique valid paths from the top-left corner to the bottom-right corner, where a path is valid if the robot does not move outside the grid boundaries. The result is returned modulo 10^9 + 7.

---

## Examples

_No examples provided._

---

## Intuition

The solution uses dynamic programming to track the number of ways to reach each cell. A key insight is that the robot's movement is deterministic when it hits a mirror — it must reflect in a specific direction. Therefore, we can pre-compute the 'final destination' of a reflection starting from any cell using a recursive function (`solve`). The main DP table (`dp`) then accumulates the number of paths that lead to each cell, considering both direct moves and reflected paths from previous cells.

---

## Approach

1. Initialize a 2D DP table (`dp`) to store the number of ways to reach each cell, starting with 1 at the top-left corner.
2. For each cell, if it is a mirror, skip it (mirrors are not stopping points).
3. If the cell is empty, calculate the number of ways to reach it by summing the paths from the cell above and the cell to the left.
4. Additionally, for each empty cell, use the `solve` function to determine where the robot would end up if it tried to move right or down into a mirror. If the reflection leads to a valid cell within the grid, add the current cell's path count to that destination cell's count.
5. Repeat this process for all cells to build up the path counts, and finally return the value at the bottom-right corner.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The algorithm iterates over each cell in the grid once to update the DP table. The `solve` function is memoized, so each reflection path is calculated only once, making the overall time complexity linear with respect to the number of cells. |
| **Space** | `O(m * n)` — The space complexity is dominated by the 2D DP table and the 3D memoization array used for the `solve` function. Both require O(m * n) space to store the path counts and reflection destinations for every cell. |

---

## Code (C++)

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;

    vector<vector<int>> grid;

    // memo[i][j][dir] stores the final cell
    vector<vector<vector<int>>> memo;

    // dir = 0 means moving right
    // dir = 1 means moving down

    int solve(int i, int j, int dir) {

        // Outside the grid
        if (i >= m || j >= n) {
            return -1;
        }

        // Already calculated
        if (memo[i][j][dir] != -2) {
            return memo[i][j][dir];
        }

        // Empty cell: stop here
        if (grid[i][j] == 0) {
            return memo[i][j][dir] = i * n + j;
        }

        // Mirror: change direction
        if (dir == 0) {
            return memo[i][j][dir] =
                solve(i + 1, j, 1);
        }
        else {
            return memo[i][j][dir] =
                solve(i, j + 1, 0);
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {

        this->grid = grid;

        m = grid.size();
        n = grid[0].size();

        memo.assign(
            m,
            vector<vector<int>>(
                n, vector<int>(2, -2)
            )
        );

        vector<vector<int>> dp(
            m, vector<int>(n, 0)
        );

        // Start from top-left
        dp[0][0] = 1;

        // Process cells row by row
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Mirror cells are not stopping points
                if (grid[i][j] == 1) {
                    continue;
                }

                int ways = dp[i][j];

                if (ways == 0) {
                    continue;
                }

                // Try moving right
                int right = solve(i, j + 1, 0);

                if (right != -1) {

                    int x = right / n;
                    int y = right % n;

                    dp[x][y] =
                        (dp[x][y] + ways) % MOD;
                }

                // Try moving down
                int down = solve(i + 1, j, 1);

                if (down != -1) {

                    int x = down / n;
                    int y = down % n;

                    dp[x][y] =
                        (dp[x][y] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

---

## Key Takeaways

- This problem demonstrates the use of dynamic programming to solve a path-finding problem with non-standard movement rules (reflection).
- The `solve` function effectively 'unrolls' the reflection logic, allowing the main DP loop to treat reflected paths as simple transitions between cells.
- The memoization of the reflection destinations is crucial for efficiency, preventing redundant calculations of where the robot would end up after multiple reflections.
