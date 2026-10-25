# 1254. Number of Closed Islands

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

[LeetCode — 1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)

---

## Problem Summary

The problem requires counting the number of 'closed islands' in a 2D grid. A closed island is a region of land (0s) that is completely surrounded by water (1s), meaning it has no connection to the grid's boundary. The solution uses a depth-first search (DFS) approach to identify and eliminate islands that are connected to the edges, leaving only the truly closed islands to be counted.

---

## Examples

### Example 1
**Input:** `grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]`  
**Output:** `2`  
**Explanation:**
- Islands in gray are closed because they are completely surrounded by water (group of 1s).

### Example 2
**Input:** `grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]`  
**Output:** `1`  

### Example 3
**Input:** `grid = [[1,1,1,1,1,1,1], [1,0,0,0,0,0,1], [1,0,1,1,1,0,1], [1,0,1,0,1,0,1], [1,0,1,1,1,0,1], [1,0,0,0,0,0,1], [1,1,1,1,1,1,1]]`  
**Output:** `2`  

---

## Intuition

To distinguish between closed and open islands, the algorithm first removes all land that is connected to the grid's boundary. This is done by performing DFS from the four edges of the grid, effectively 'flooding' any open islands. After this initial sweep, the remaining disconnected regions of land are the closed islands, which are then counted.

---

## Approach

1. Initialize the grid dimensions (rows and cols) from the input data.
2. Perform a DFS from each cell on the top and bottom edges (rows 0 and rows-1) to mark all connected land as water (1).
3. Perform a DFS from each cell on the left and right edges (cols 0 and cols-1) to mark all connected land as water (1).
4. Iterate through the entire grid. For each cell containing land (0), increment the island count and perform a DFS to mark that island as visited, ensuring each island is counted only once.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The algorithm performs a single pass over the grid to remove boundary-connected islands and a second pass to count the remaining closed islands. Since the DFS operations are linear relative to the number of cells, the total time complexity is proportional to the size of the grid. |
| **Space** | `O(m * n)` — The space complexity is determined by the recursion stack depth of the DFS. In the worst case, where the entire grid is a single island, the stack could grow to the size of the grid. Additionally, the input grid is modified in-place, so no significant extra space is used for data storage beyond the call stack. |

---

## Code (C++)

```cpp
class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            grid[r][c] == 1) {
            return;
        }

        grid[r][c] = 1;

        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Step 1: Remove all land connected to the boundary
        for (int r = 0; r < rows; r++) {
            dfs(grid, r, 0);
            dfs(grid, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(grid, 0, c);
            dfs(grid, rows - 1, c);
        }

        // Step 2: Count the remaining islands
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};
```

---

## Key Takeaways

- This solution demonstrates a 'flood-fill' strategy to distinguish between internal and external features in a grid.
- By processing the boundary first, the algorithm efficiently isolates the closed islands without needing to check every cell against the boundary multiple times.
- The use of DFS is appropriate here because it allows for the efficient traversal and marking of connected components.
