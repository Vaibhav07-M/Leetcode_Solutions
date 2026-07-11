# 2685. Count the Number of Complete Components

**Difficulty:** `Medium`  
**Tags:** `Graph`, `Breadth-First Search (BFS)`

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

[LeetCode — 2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/)

---

## Problem Summary

Given an undirected graph with `n` vertices and a list of edges, count how many connected components are **complete**.

A connected component is complete if every pair of vertices within that component is directly connected by an edge. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
n = 6
edges = [[0,1],[0,2],[1,2],[3,4]]
```

**Output**

```text
3
```

---

### Example 2

**Input**

```text
n = 6
edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
```

**Output**

```text
1
```

---

## Intuition

Traverse each connected component independently.

For every component:

- Find all its vertices using BFS.
- Let its size be `k`.
- In a complete graph, every vertex must have exactly `k - 1` neighbors.
- If every vertex satisfies this condition, the component is complete.

---

## Approach

1. Build an adjacency list for the graph.
2. Traverse every unvisited node using BFS.
3. Collect all vertices belonging to the current connected component.
4. Let the component size be `k`.
5. Verify that every vertex has degree `k - 1`.
6. Count the component if all vertices satisfy the condition.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n + m)` |
| **Space** | `O(n + m)` |

where `m` is the number of edges.

---

## Code (C++)

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            vector<int> comp;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            int sz = comp.size();
            bool complete = true;

            for (int node : comp) {
                if (adj[node].size() != sz - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete) ans++;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- BFS efficiently discovers each connected component.
- A connected component with `k` vertices is complete if every vertex has degree `k - 1`.
- Degree verification is simpler than checking every possible pair of vertices.
- The solution runs in linear time relative to the size of the graph.
```