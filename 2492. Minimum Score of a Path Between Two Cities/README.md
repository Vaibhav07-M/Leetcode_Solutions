# 2492. Minimum Score of a Path Between Two Cities

**Difficulty:** `Medium`  
**Tags:** `Graph`, `Breadth-First Search`

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

[LeetCode — 2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)

---

## Problem Summary

You are given:

- An integer `n` representing `n` cities.
- A list of bidirectional roads, where:

```cpp
roads[i] = [ai, bi, distancei]
```

denotes a road between cities `ai` and `bi` with distance `distancei`.

The **score** of a path is defined as the **minimum road distance** among all roads used in that path.

Return the **minimum possible score** of any path from city `1` to city `n`.

A path may revisit cities and roads multiple times.

---

## Examples

### Example 1

**Input:**

```cpp
n = 4
roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
```

**Output:**

```cpp
5
```

**Explanation:**

One optimal path is:

```text
1 → 2 → 4
```

The score is:

```text
min(9,5) = 5
```

---

### Example 2

**Input:**

```cpp
n = 4
roads = [[1,2,2],[1,3,4],[3,4,7]]
```

**Output:**

```cpp
2
```

**Explanation:**

A valid path is:

```text
1 → 2 → 1 → 3 → 4
```

Its score is:

```text
min(2,2,4,7) = 2
```

---

## Intuition

Since roads and cities may be revisited, we are free to traverse **any edge** inside the connected component containing city `1`.

Therefore, the answer is simply the **smallest road distance** among all roads reachable from city `1`.

A Breadth-First Search (BFS) allows us to visit every city in this connected component while tracking the minimum edge weight encountered.

---

## Approach

### 1. Build the Graph

Create an adjacency list for the undirected graph.

---

### 2. Perform BFS

Start from city `1`.

For every visited city:

- Traverse all adjacent roads.
- Update the answer using:

```cpp
ans = min(ans, distance)
```

- Visit every unvisited neighboring city.

---

### 3. Return the Minimum Edge

After exploring the entire connected component containing city `1`, the recorded minimum edge weight is the minimum possible path score.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` |
| **Space** | `O(n + m)` |

Where:

- `n` = number of cities
- `m` = number of roads

---

## Code (C++)

```cpp
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, d] : adj[u]) {
                ans = min(ans, d);

                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Since revisiting roads is allowed, any edge in the connected component of city `1` can be included in the path.
- The answer is the smallest edge weight in that connected component.
- Build the graph using an adjacency list.
- Use BFS to traverse the component while maintaining the minimum edge weight.
- The solution runs in linear time, `O(n + m)`.