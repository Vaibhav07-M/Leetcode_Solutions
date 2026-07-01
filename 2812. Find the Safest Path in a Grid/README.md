# 2812. Find the Safest Path in a Grid

**Difficulty:** `Medium`  
**Tags:** `Graph`, `Breadth-First Search`, `Binary Search`, `Matrix`

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

[LeetCode — 2812. Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)

---

## Problem Summary

You are given an `n × n` grid where:

- `1` represents a thief.
- `0` represents an empty cell.

You start at the top-left cell `(0, 0)` and want to reach the bottom-right cell `(n - 1, n - 1)`.

The **safeness factor** of a path is defined as the minimum Manhattan distance from any cell on the path to the nearest thief.

Return the **maximum possible safeness factor** among all valid paths. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
grid = [[1,0,0],[0,0,0],[0,0,1]]
```

**Output:**

```cpp
0
```

**Explanation:**

Every path passes through a cell containing a thief, so the maximum safeness factor is `0`.

---

### Example 2

**Input:**

```cpp
grid = [[0,0,1],[0,0,0],[0,0,0]]
```

**Output:**

```cpp
2
```

---

### Example 3

**Input:**

```cpp
grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
```

**Output:**

```cpp
2
```

---

## Intuition

The solution consists of two main steps.

First, compute for every cell its distance to the nearest thief using a **multi-source BFS**. This gives the maximum possible safeness value available at every position.

Then, instead of searching directly for the optimal path, perform a **binary search** on the answer.

For a candidate safeness value:

- Check whether a path exists from `(0,0)` to `(n-1,n-1)` using only cells whose distance is at least that value.
- If such a path exists, try a larger safeness factor.
- Otherwise, reduce the search space.

---

## Approach

### 1. Multi-Source BFS

Push every thief cell into the BFS queue.

Compute:

```cpp
dist[i][j]
```

which stores the minimum Manhattan distance from each cell to the nearest thief.

---

### 2. Binary Search the Answer

The safeness factor lies between:

```cpp
0
```

and

```cpp
2 * n
```

Binary search this range.

---

### 3. Check Feasibility

For every candidate value:

- Ensure both the start and destination satisfy the required safeness.
- Perform a BFS using only cells where:

```cpp
dist >= safe
```

If the destination is reachable, the candidate is feasible.

---

### 4. Return the Maximum Value

Binary search returns the largest safeness factor for which a valid path exists.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n² log n)` |
| **Space** | `O(n²)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from thieves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n &&
                   dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto canReach = [&](int safe) {
            if(dist[0][0] < safe || dist[n-1][n-1] < safe)
                return false;

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int,int>> bfs;
            bfs.push({0, 0});
            vis[0][0] = true;

            while(!bfs.empty()) {
                auto [x, y] = bfs.front();
                bfs.pop();

                if(x == n - 1 && y == n - 1)
                    return true;

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n &&
                       !vis[nx][ny] && dist[nx][ny] >= safe) {
                        vis[nx][ny] = true;
                        bfs.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int low = 0, high = 2 * n, ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Use **multi-source BFS** to compute the distance from every cell to its nearest thief.
- The distance grid transforms the problem into checking whether a path satisfies a minimum safeness threshold.
- Apply **binary search** on the answer instead of searching for the optimal path directly.
- Use a second **BFS** to verify whether a path exists for a chosen safeness value.
- The overall solution runs in `O(n² log n)` time with `O(n²)` extra space.