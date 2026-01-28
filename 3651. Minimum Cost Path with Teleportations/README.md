# 3651. Minimum Cost Path with Teleportations

**Difficulty:** `Hard`  
**Tags:** `Array`, `Matrix`, `Graph`, `Shortest Path`, `Heap (Priority Queue)`, `Dynamic Programming`

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

[LeetCode — 3651. Minimum Cost Path with Teleportations](https://leetcode.com/problems/minimum-cost-path-with-teleportations/)

---

## Problem Summary

You are given a `m x n` 2D integer array `grid` and an integer `k`. You start at the top-left cell `(0, 0)` and your goal is to reach the bottom-right cell `(m - 1, n - 1)`.

There are **two types of moves** available:

1. **Normal move**: Move right or down from current cell `(i, j)` to `(i, j + 1)` or `(i + 1, j)`. The cost is the **value of the destination cell**.

2. **Teleportation**: Teleport from any cell `(i, j)` to any cell `(x, y)` where `grid[x][y] <= grid[i][j]`. The cost is **0**, and you may teleport **at most k times**.

Return the **minimum total cost** to reach cell `(m - 1, n - 1)` from `(0, 0)`.

---

## Examples

### Example 1
**Input:** `grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2`  
**Output:** `7`  
**Explanation:**

| Current Position | Move | New Position | Total Cost |
|-----------------|------|--------------|------------|
| (0, 0) | Move Down | (1, 0) | 0 + 2 = 2 |
| (1, 0) | Move Right | (1, 1) | 2 + 5 = 7 |
| (1, 1) | Teleport to (2, 2) | (2, 2) | 7 + 0 = 7 |

The minimum cost to reach bottom-right cell is **7**.

### Example 2
**Input:** `grid = [[1,2],[2,3],[3,4]], k = 1`  
**Output:** `9`  
**Explanation:**

| Current Position | Move | New Position | Total Cost |
|-----------------|------|--------------|------------|
| (0, 0) | Move Down | (1, 0) | 0 + 2 = 2 |
| (1, 0) | Move Right | (1, 1) | 2 + 3 = 5 |
| (1, 1) | Move Down | (2, 1) | 5 + 4 = 9 |

The minimum cost to reach bottom-right cell is **9**.

---

## Intuition

This problem is a **shortest path problem with state-dependent transitions**. The key challenge is handling teleportations efficiently.

### Key Observations:
1. **State representation**: We need to track `(position, teleports_used)` because the number of teleportations remaining affects our available moves.

2. **Normal moves**: Moving right or down always costs the value of the destination cell — this is standard grid pathfinding.

3. **Teleportation constraint**: We can teleport to any cell with value ≤ current cell's value, but only up to `k` times total.

4. **Zero-cost teleportation**: Teleporting is free, which means if we're at a high-value cell, we might want to teleport to multiple lower-value cells to explore cheaper paths.

5. **Modified Dijkstra**: Since costs vary and we need minimum cost paths, we use **Dijkstra's algorithm** with priority queue, where states are `(cost, row, col, teleports_used)`.

### Strategy:
- Use **Dijkstra's algorithm** with state `(row, col, teleports_remaining)` 
- For each state, consider:
  - Normal moves (right/down) with cost = destination cell value
  - If teleports remain, consider all cells with value ≤ current cell value (cost = 0)
- Pre-process grid to group cells by value for efficient teleportation lookup
- Track minimum cost to reach each state

---

## Approach

### Algorithm Steps:

1. **Initialize Data Structures**:
   - Priority queue (min-heap): stores `(cost, row, col, teleports_used)`
   - Distance map: `dist[row][col][teleports_used]` = minimum cost to reach this state
   - Pre-compute cells by value for efficient teleportation lookup

2. **Pre-process Grid**:
   - Create a map: `value -> list of (row, col)` positions with that value
   - Sort values for efficient range queries when finding teleportation targets

3. **Dijkstra's Algorithm**:
   - Start from `(0, 0)` with cost = 0 and teleports_used = 0
   - For each state popped from the priority queue:
     - **Normal moves**: Try moving right and down (if in bounds)
       - New cost = current cost + grid[new_row][new_col]
     - **Teleportation moves** (if teleports_used < k):
       - Find all cells with value ≤ grid[current_row][current_col]
       - For each such cell, add state with same cost but teleports_used + 1

4. **Optimization**:
   - Use visited set to avoid reprocessing states
   - Early termination when target is reached
   - Pre-sorted cells by value enable binary search for valid teleport targets

5. **Return Result**:
   - Return minimum cost among all states that reach `(m-1, n-1)` with any number of teleports used

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m*n*k * log(m*n*k) + m*n²*k)` — Dijkstra with state space of `O(m*n*k)`. For each state, we may check `O(m*n)` teleport targets |
| **Space** | `O(m*n*k)` — storing distances for all states plus priority queue |

**Note**: With optimization (pre-grouping cells by value), teleportation checks can be done more efficiently.

---

## Code (C++)

### Solution 1: Dijkstra with Full State Tracking

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const long long INF = 1e18;
        
        // dist[teleports][cell_id] = minimum cost
        auto id = [&](int r, int c) {
            return r * n + c;
        };
        
        vector<vector<long long>> dist(k + 1, vector<long long>(m * n, INF));
        
        // Priority queue: {cost, teleports_used, row, col}
        priority_queue<tuple<long long, int, int, int>,
                       vector<tuple<long long, int, int, int>>,
                       greater<>> pq;
        
        pq.push({0, 0, 0, 0});
        dist[0][id(0, 0)] = 0;
        
        int target = id(m - 1, n - 1);
        
        while (!pq.empty()) {
            auto [cost, t, r, c] = pq.top();
            pq.pop();
            
            if (id(r, c) == target) {
                return cost;
            }
            
            if (cost > dist[t][id(r, c)]) continue;
            
            // Normal moves: right and down
            int dr[] = {0, 1};
            int dc[] = {1, 0};
            
            for (int i = 0; i < 2; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < m && nc < n) {
                    long long new_cost = cost + grid[nr][nc];
                    if (new_cost < dist[t][id(nr, nc)]) {
                        dist[t][id(nr, nc)] = new_cost;
                        pq.push({new_cost, t, nr, nc});
                    }
                }
            }
            
            // Teleportation moves
            if (t < k) {
                int curr_val = grid[r][c];
                for (int tr = 0; tr < m; tr++) {
                    for (int tc = 0; tc < n; tc++) {
                        if (grid[tr][tc] <= curr_val) {
                            if (cost < dist[t + 1][id(tr, tc)]) {
                                dist[t + 1][id(tr, tc)] = cost;
                                pq.push({cost, t + 1, tr, tc});
                            }
                        }
                    }
                }
            }
        }
        
        // Find minimum cost across all teleport counts
        long long ans = INF;
        for (int t = 0; t <= k; t++) {
            ans = min(ans, dist[t][target]);
        }
        
        return ans == INF ? -1 : (int)ans;
    }
};
```

### Solution 2: Optimized with Pre-grouped Cells

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Group cells by value for efficient teleportation
        map<int, vector<pair<int, int>>> cells_by_value;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells_by_value[grid[i][j]].push_back({i, j});
            }
        }
        
        // dist[row][col][teleports_used]
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       greater<>> pq;
        
        pq.push({0, 0, 0, 0}); // cost, row, col, teleports_used
        dist[0][0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, r, c, tp] = pq.top();
            pq.pop();
            
            if (r == m - 1 && c == n - 1) {
                return cost;
            }
            
            if (cost > dist[r][c][tp]) continue;
            
            // Normal moves
            vector<pair<int, int>> moves = {{r, c + 1}, {r + 1, c}};
            for (auto [nr, nc] : moves) {
                if (nr < m && nc < n) {
                    int new_cost = cost + grid[nr][nc];
                    if (new_cost < dist[nr][nc][tp]) {
                        dist[nr][nc][tp] = new_cost;
                        pq.push({new_cost, nr, nc, tp});
                    }
                }
            }
            
            // Teleportation
            if (tp < k) {
                int curr_val = grid[r][c];
                for (auto& [val, positions] : cells_by_value) {
                    if (val > curr_val) break; // All higher values won't work
                    for (auto [tr, tc] : positions) {
                        if (cost < dist[tr][tc][tp + 1]) {
                            dist[tr][tc][tp + 1] = cost;
                            pq.push({cost, tr, tc, tp + 1});
                        }
                    }
                }
            }
        }
        
        return -1; // Unreachable
    }
};
```

---

## Key Takeaways

1. **State-space pathfinding**: When constraints involve limited resources (k teleportations), include the resource count in your state representation.

2. **Dijkstra for variable costs**: Since movement costs vary (normal moves cost cell value, teleports cost 0), use Dijkstra's algorithm with priority queue, not simple BFS.

3. **Zero-cost edges**: Teleportation being free creates zero-cost edges in the graph, which can lead to multiple paths to the same cell with different costs — careful state management is crucial.

4. **Pre-processing optimization**: Grouping cells by value allows efficient lookup of valid teleportation targets, avoiding O(m*n) scan for each teleport attempt.

5. **3D state space**: Track `dist[row][col][teleports_used]` rather than just `dist[row][col]` because the same cell reached with different teleport counts represents different states.

6. **Early termination**: Once we pop the target cell from the priority queue, we've found the optimal cost due to Dijkstra's guarantee.

7. **Constraint exploitation**: With k ≤ 10, the state space is manageable. For larger k, different optimization strategies would be needed.

8. **Value-based teleportation**: The constraint `grid[x][y] <= grid[i][j]` for teleportation creates a partial ordering that can be exploited for pruning and optimization.

---
