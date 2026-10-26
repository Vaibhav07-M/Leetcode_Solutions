# 3619. Count Islands With Total Value Divisible by K

**Difficulty:** `Medium`  
**Tags:** `Array`, `Depth-First Search`, `Breadth-First Search`, `Union-Find`, `Matrix`

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

[LeetCode — 3619. Count Islands With Total Value Divisible by K](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)

---

## Problem Summary

The problem requires counting the number of islands in a 2D grid where the total value of each island is divisible by a given integer k. An island is defined as a connected component of positive integer cells, and the total value is the sum of these cell values.

---

## Examples

_No examples provided._

---

## Intuition

The solution uses a depth-first search (DFS) approach to traverse the grid. For each cell that is part of an island, the DFS function recursively visits all connected cells, accumulating their values into a total sum. After traversing an entire island, the sum is checked to see if it is divisible by k, and a counter is incremented if the condition is met.

---

## Approach

1. Iterate through the 2D grid to find cells with positive values, which indicate the start of an island.
2. For each such cell, call the dfs function to recursively explore the island and calculate its total value.
3. In the dfs function, mark the current cell as visited (set to 0) to prevent cycles and accumulate the cell's value.
4. Recursively call dfs for the four neighboring cells (up, down, left, right) to gather the total value of the connected component.
5. After returning from the DFS, check if the accumulated sum is divisible by k. If it is, increase the island count.
6. Continue scanning the grid until all islands have been processed.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The algorithm iterates over every cell in the grid once. For each cell, it performs a DFS that visits all connected cells, but since no cell is visited more than once (it is set to 0), the total number of operations is proportional to the number of cells in the grid. |
| **Space** | `O(m * n)` — The space complexity is determined by the recursion depth of the DFS. In the worst case, where the entire grid is a single island, the recursion stack could go as deep as the number of cells. Additionally, the grid itself is modified, but the extra space used for the call stack is the dominant factor. |

---

## Code (C++)

```cpp
class Solution {
public:
    int m, n;

    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];
        grid[r][c] = 0;

        sum += dfs(grid, r + 1, c); // Down
        sum += dfs(grid, r - 1, c); // Up
        sum += dfs(grid, r, c + 1); // Right
        sum += dfs(grid, r, c - 1); // Left

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
```

---

## Key Takeaways

- This problem demonstrates the use of DFS for region analysis in a 2D grid, specifically for calculating the total value of a connected component.
- The solution efficiently checks for divisibility by k, which is a common constraint in problems involving modular arithmetic and grid traversal.
- The approach of marking cells as visited (setting them to 0) is a standard technique to avoid infinite loops and ensure each cell is processed only once.
