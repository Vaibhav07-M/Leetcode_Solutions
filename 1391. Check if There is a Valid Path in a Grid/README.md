# 1391. Check if There is a Valid Path in a Grid

**Difficulty:** `Medium`  
**Tags:** `Graph`, `BFS`, `DFS`, `Matrix`

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

[LeetCode — 1391. Check if There is a Valid Path in a Grid](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/)

---

## Problem Summary

You are given an m x n grid. Each cell of `grid` represents a street. The street of `grid[i][j]` can be:

- `1` which means a street connecting the left cell and the right cell.
- `2` which means a street connecting the upper cell and the lower cell.
- `3` which means a street connecting the left cell and the lower cell.
- `4` which means a street connecting the right cell and the lower cell.
- `5` which means a street connecting the left cell and the upper cell.
- `6` which means a street connecting the right cell and the upper cell.

You start at the upper-left cell `(0, 0)` and want to reach the bottom-right cell `(m - 1, n - 1)` following the streets. You cannot change any street. Return `true` if there is a valid path, otherwise `false`.

---

## Examples

### Example 1
**Input:** `grid = [[2,4,3],[6,5,2]]`  
**Output:** `true`  
**Explanation:** A valid path exists from `(0,0)` to `(1,2)` following streets.

### Example 2
**Input:** `grid = [[1,2,1],[1,2,1]]`  
**Output:** `false`  
**Explanation:** The street at `(0,0)` cannot connect to any neighbour to progress.

### Example 3
**Input:** `grid = [[1,1,2]]`  
**Output:** `false`

---

## Intuition

Each street type encodes which directions you can leave a cell. A path is valid only if, for every move from a cell to a neighbour, the neighbour also has a street that connects back (the opposite direction). We can therefore perform a BFS/DFS from `(0,0)` and only traverse edges that are mutually connected.

---

## Approach

1. Build a mapping from street type to allowed directions (up/down/left/right).
2. BFS from `(0,0)` using a queue and a `visited` matrix.
3. For each allowed direction from the current cell, check the neighbour is inside bounds and that its street type allows the opposite direction. If so and it's not visited, enqueue it.
4. If we reach `(m-1, n-1)`, return `true`. If BFS completes without reaching it, return `false`.

This guarantees we only follow valid mutual connections.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — each cell visited at most once |
| **Space** | `O(m * n)` — queue and visited matrix |

---

## Code (C++)

```cpp
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: up, right, down, left
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        // For each street type, which directions are allowed (0=up,1=right,2=down,3=left)
        vector<vector<int>> allow(7);
        allow[1] = {3,1};      // left, right
        allow[2] = {0,2};      // up, down
        allow[3] = {3,2};      // left, down
        allow[4] = {1,2};      // right, down
        allow[5] = {3,0};      // left, up
        allow[6] = {1,0};      // right, up

        vector<vector<char>> vis(m, vector<char>(n, 0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        auto opposite = [&](int d){ return (d + 2) % 4; };

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            if (r == m-1 && c == n-1) return true;
            int t = grid[r][c];
            for(int d : allow[t]){
                int nr = r + dirs[d].first;
                int nc = c + dirs[d].second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (vis[nr][nc]) continue;
                int nt = grid[nr][nc];
                // neighbour must allow opposite direction
                int od = opposite(d);
                bool ok = false;
                for (int nd : allow[nt]) if (nd == od) { ok = true; break; }
                if (!ok) continue;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }

        return false;
    }
};
```

---

## Key Takeaways

- Model each street type as a set of outgoing directions and require the neighbour to accept the opposite direction.
- BFS/DFS that enforces mutual connectivity ensures correctness.
- Time and space scale linearly with grid size.
