# 1559. Detect Cycles in 2D Grid

**Difficulty:** `Medium`  
**Tags:** `DFS`, `Matrix`

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

[LeetCode — 1559. Detect Cycles in 2D Grid](https://leetcode.com/problems/detect-cycles-in-2d-grid/)

---

## Problem Summary

Given a character grid, determine whether there exists a cycle made of the same character.

A valid cycle must:
- have length at least 4,
- move only in four directions (up, down, left, right),
- stay on cells with the same character,
- and cannot immediately go back to the previous cell.

Return `true` if such a cycle exists, else `false`.

---

## Examples

### Example 1
**Input:** `grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]`  
**Output:** `true`

### Example 2
**Input:** `grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]`  
**Output:** `true`

### Example 3
**Input:** `grid = [["a","b","b"],["b","z","b"],["b","b","a"]]`  
**Output:** `false`

---

## Intuition

This is a graph cycle detection problem on a grid:
- each cell is a node,
- edges exist between adjacent cells with the same character.

While doing DFS, if we reach an already visited cell that is not the immediate parent, then we found a cycle.

---

## Approach

1. Maintain a `visited` matrix.
2. For every unvisited cell, run DFS with parameters `(x, y, parentX, parentY)`.
3. In DFS, explore 4-directional neighbors only if:
   - inside bounds,
   - same character,
   - not the parent cell.
4. If such a neighbor is already visited, return `true` (cycle found).
5. If any DFS call finds a cycle, return `true`; otherwise return `false`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` |
| **Space** | `O(m * n)` for visited + recursion stack |

---

## Code (C++)

```cpp
class Solution {
public:
    int m, n;
    
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[x][y] = true;
        
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(grid[nx][ny] != grid[x][y]) continue;
            
            // skip parent
            if(nx == px && ny == py) continue;
            
            if(vis[nx][ny]) return true; // cycle found
            
            if(dfs(nx, ny, x, y, grid, vis)) return true;
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
```

---

## Key Takeaways

- Treating grid traversal as graph traversal makes cycle logic straightforward.
- Parent tracking prevents false cycle detection from immediate backtracking.
- A single DFS over all components detects cycles in linear time.
