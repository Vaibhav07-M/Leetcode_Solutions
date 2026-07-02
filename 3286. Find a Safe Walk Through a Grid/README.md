# 3286. Find a Safe Walk Through a Grid

**Difficulty:** `Medium`  
**Tags:** `Graph`, `Shortest Path`, `Matrix`

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

[LeetCode — 3286. Find a Safe Walk Through a Grid](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/)

---

## Problem Summary

You are given:

- A binary matrix `grid`.
- An integer `health`.

You start at the top-left cell `(0, 0)` and want to reach the bottom-right cell `(m - 1, n - 1)`.

- Entering a cell with value `1` decreases your health by `1`.
- You may move up, down, left, or right.
- Your health must remain **positive** throughout the journey.

Return `true` if you can reach the destination with at least `1` health remaining; otherwise, return `false`. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
health = 1
```

**Output:**

```cpp
true
```

---

### Example 2

**Input:**

```cpp
grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]]
health = 3
```

**Output:**

```cpp
false
```

---

### Example 3

**Input:**

```cpp
grid = [[1,1,1],[1,0,1],[1,1,1]]
health = 5
```

**Output:**

```cpp
true
```

---

## Intuition

Each unsafe cell contributes a cost of `1`, while safe cells contribute `0`.

Instead of maximizing remaining health directly, we minimize the total health lost while traveling from the start to the destination.

Since every move has a non-negative cost (`0` or `1`), **Dijkstra's Algorithm** efficiently finds the minimum health required to complete the journey.

If the minimum health loss is strictly less than the available `health`, the walk is possible.

---

## Approach

### 1. Initialize Distance Array

Maintain:

```cpp
dist[i][j]
```

which stores the minimum health lost to reach each cell.

Initialize every value to `INT_MAX` except the starting cell.

---

### 2. Apply Dijkstra's Algorithm

Use a min-priority queue storing:

```cpp
(totalCost, row, column)
```

Always process the cell with the smallest accumulated health loss.

---

### 3. Relax Neighboring Cells

For each adjacent cell:

```cpp
newCost = currentCost + grid[nx][ny]
```

If this produces a better path, update the distance and push the new state into the priority queue.

---

### 4. Check the Destination

As soon as the destination is removed from the priority queue:

```cpp
cost < health
```

means at least one health point remains.

Return the corresponding boolean result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m × n log(m × n))` |
| **Space** | `O(m × n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if (cost > dist[x][y]) continue;

            if (x == m - 1 && y == n - 1)
                return cost < health;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost + grid[nx][ny];

                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
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

- Treat unsafe cells as having a traversal cost of `1`.
- Minimize the total health lost instead of maximizing the remaining health.
- Dijkstra's Algorithm efficiently computes the minimum health cost path.
- A priority queue ensures the smallest-cost path is always explored first.
- The path is valid only if the minimum health loss is strictly less than the available health.