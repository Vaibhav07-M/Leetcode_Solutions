# 3620. Network Recovery Pathways

**Difficulty:** `Hard`  
**Tags:** `Graph`, `Dynamic Programming`, `Binary Search`, `Topological Sort`

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

[LeetCode — 3620. Network Recovery Pathways](https://leetcode.com/problems/network-recovery-pathways/)

---

## Problem Summary

You are given:

- A Directed Acyclic Graph (DAG) with `n` nodes.
- An array `edges`, where each edge is represented as:

```cpp
[u, v, cost]
```

- A boolean array `online`, where offline nodes cannot be used as intermediate nodes.
- An integer `k` representing the maximum total recovery cost.

A valid path from node `0` to node `n - 1` must satisfy:

- Every intermediate node is online.
- The total edge cost does not exceed `k`.

The **score** of a path is the **minimum edge cost** along that path.

Return the **maximum possible path score** among all valid paths. If no valid path exists, return `-1`.

---

## Examples

### Example 1

**Input:**

```cpp
edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]]
online = [true,true,true,true]
k = 10
```

**Output:**

```cpp
3
```

**Explanation:**

The path:

```text
0 → 2 → 3
```

has total cost:

```text
3 + 4 = 7
```

which is within the budget.

Its score is:

```text
min(3,4) = 3
```

---

### Example 2

**Input:**

```cpp
edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]]
online = [true,true,true,false,true]
k = 12
```

**Output:**

```cpp
6
```

**Explanation:**

Since node `3` is offline, every path passing through it is invalid.

The path:

```text
0 → 2 → 4
```

has:

```text
total cost = 12
score = 6
```

which is optimal.

---

## Intuition

The answer is the largest possible minimum edge cost.

Instead of directly maximizing it, binary search on the minimum allowed edge cost.

For every candidate value:

- Ignore every edge whose cost is smaller.
- Ignore paths passing through offline intermediate nodes.
- Check whether the destination can still be reached within budget `k`.

Since the graph is a DAG, shortest paths can be computed efficiently using a topological ordering instead of Dijkstra's algorithm.

---

## Approach

### 1. Build the Graph

Construct the adjacency list and compute the indegree of every node.

---

### 2. Compute Topological Order

Since the graph is acyclic, generate a topological ordering using Kahn's Algorithm.

This order allows shortest-path relaxation in linear time.

---

### 3. Binary Search the Answer

Search over:

```cpp
0 ... maximum edge cost
```

For every candidate minimum edge cost:

- Ignore all edges whose cost is smaller.
- Skip offline intermediate nodes.
- Compute the minimum path cost using DP over the topological order.

If the destination can be reached with total cost:

```cpp
<= k
```

then the candidate score is feasible.

---

### 4. Return the Largest Valid Score

Binary search returns the maximum feasible minimum edge cost.

If no feasible path exists, return `-1`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((V + E) × log C)` |
| **Space** | `O(V + E)` |

Where:

- `V` = number of nodes
- `E` = number of edges
- `C` = maximum edge cost

---

## Code (C++)

```cpp
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            maxCost = max(maxCost, e[2]);
        }

        // Topological order
        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {
            const long long INF = 4e18;

            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : adj[u]) {

                    if (w < limit) continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0;
        int hi = maxCost;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The graph is a DAG, allowing shortest-path computation using a topological order.
- Binary search is performed on the answer (minimum edge cost).
- For each candidate score, ignore edges with smaller costs.
- Dynamic programming over the topological order computes the minimum recovery cost.
- Offline intermediate nodes are skipped during path computation.
- The overall complexity is `O((V + E) × log C)`.