# 3650. Minimum Cost Path with Edge Reversals

**Difficulty:** `Medium`  
**Tags:** `Graph`, `Shortest Path`, `Heap (Priority Queue)`, `Dynamic Programming`

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

[LeetCode — 3650. Minimum Cost Path with Edge Reversals](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/)

---

## Problem Summary

You are given a directed, weighted graph with `n` nodes labeled from `0` to `n - 1`, and an array `edges` where `edges[i] = [ui, vi, wi]` represents a directed edge from node `ui` to node `vi` with cost `wi`.

Each node `ui` has a **switch** that can be used **at most once**: when you arrive at `ui` and have not yet used its switch, you may activate it on one of its **incoming edges** `vi → ui`, reverse that edge to `ui → vi`, and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs `2 * wi`.

Return the **minimum total cost** to travel from node `0` to node `n - 1`. If it is not possible, return `-1`.

---

## Examples

### Example 1
**Input:** `n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]`  
**Output:** `5`  
**Explanation:**
- Use the path 0 → 1 (cost 3)
- At node 1, reverse the edge 3 → 1 into 1 → 3 and traverse it at cost 2 × 1 = 2
- Total cost is 3 + 2 = 5

### Example 2
**Input:** `n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]`  
**Output:** `3`  
**Explanation:**
- No reversal needed
- Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1)
- Total cost is 1 + 1 + 1 = 3

---

## Intuition

This is a **shortest path problem with state-dependent transitions**. The twist is that at each node, we can use its switch **once** to reverse an incoming edge and traverse it.

The key insight is that we need to track:
1. Which node we're at
2. Which switches we've already used

Since each node's switch can be used at most once, we can use a **bitmask** or a **set** to track used switches in our state space.

This leads to a **modified Dijkstra's algorithm** where:
- **State:** `(node, used_switches)`
- **Transitions:** From each state, we can:
  1. Take any normal outgoing edge (no switch needed)
  2. If we haven't used the current node's switch, reverse any incoming edge and traverse it (costs `2 * weight`)

---

## Approach

### Algorithm Steps:
1. **Build two graphs:**
   - `forward[u]` = list of `(v, w)` representing outgoing edges `u → v` with weight `w`
   - `backward[u]` = list of `(v, w)` representing incoming edges `v → u` with weight `w`

2. **Use Dijkstra with state tracking:**
   - State: `(cost, node, used_switches_bitmask)`
   - Priority queue (min-heap) to explore states in order of increasing cost
   - Distance map: `dist[node][used_switches]` = minimum cost to reach this state

3. **For each state `(node, used_switches)` popped from the heap:**
   - **Normal transitions:** For each outgoing edge `node → v`, add state `(v, used_switches)` with cost + weight
   - **Reversal transitions:** If switch at `node` hasn't been used, for each incoming edge `u → node`, add state `(u, used_switches | (1 << node))` with cost + 2 × weight

4. **Return the minimum cost** to reach node `n-1` with any switch configuration, or `-1` if unreachable.

### Optimization:
For large `n`, using a bitmask becomes impractical. Instead, represent `used_switches` as a **hash set** or use a different state encoding like `(node, last_switch_used)`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((V + E) × 2^V × log(V × 2^V))` — Dijkstra with state space of `V × 2^V`. For practical cases with large `n`, use optimized state representation |
| **Space** | `O(V × 2^V)` — storing distances for all states |

**Note:** For large `n` (up to 50,000), the bitmask approach is infeasible. A more practical solution uses `(node, switches_used_count)` or tracks individual switch usage differently, reducing space to `O(V × V)` or better.

---

## Code (C++)

### Solution 1: Dijkstra with State Tracking (Optimized for Large N)

```cpp
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Build forward and backward adjacency lists
        vector<vector<pair<int,int>>> forward(n), backward(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            forward[u].push_back({v, w});
            backward[v].push_back({u, w});
        }
        
        // State: (cost, node, used_switches as set)
        // Use map to track: dist[node][switches_set] = min_cost
        map<pair<int, set<int>>, int> dist;
        priority_queue<tuple<int, int, set<int>>, 
                       vector<tuple<int, int, set<int>>>, 
                       greater<>> pq;
        
        set<int> initial;
        pq.push({0, 0, initial});
        dist[{0, initial}] = 0;
        
        while (!pq.empty()) {
            auto [cost, node, used] = pq.top();
            pq.pop();
            
            if (node == n - 1) return cost;
            
            auto state = make_pair(node, used);
            if (dist.count(state) && dist[state] < cost) continue;
            
            // Normal outgoing edges
            for (auto [v, w] : forward[node]) {
                int new_cost = cost + w;
                auto new_state = make_pair(v, used);
                if (!dist.count(new_state) || dist[new_state] > new_cost) {
                    dist[new_state] = new_cost;
                    pq.push({new_cost, v, used});
                }
            }
            
            // Reverse incoming edges (if switch not used)
            if (used.find(node) == used.end()) {
                set<int> new_used = used;
                new_used.insert(node);
                for (auto [u, w] : backward[node]) {
                    int new_cost = cost + 2 * w;
                    auto new_state = make_pair(u, new_used);
                    if (!dist.count(new_state) || dist[new_state] > new_cost) {
                        dist[new_state] = new_cost;
                        pq.push({new_cost, u, new_used});
                    }
                }
            }
        }
        
        return -1;
    }
};
```

### Solution 2: Simplified Dijkstra (Tracking Last Reversed Node)

```cpp
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n), rev(n);
        
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        
        // dist[node][last_reversed] = min cost
        vector<map<int, int>> dist(n);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        
        pq.push({0, 0, -1}); // cost, node, last_reversed (-1 = none)
        dist[0][-1] = 0;
        
        while (!pq.empty()) {
            auto [cost, u, last_rev] = pq.top();
            pq.pop();
            
            if (u == n - 1) return cost;
            if (dist[u].count(last_rev) && dist[u][last_rev] < cost) continue;
            
            // Normal edges
            for (auto [v, w] : graph[u]) {
                int nc = cost + w;
                if (!dist[v].count(last_rev) || dist[v][last_rev] > nc) {
                    dist[v][last_rev] = nc;
                    pq.push({nc, v, last_rev});
                }
            }
            
            // Reverse edge (if not used at this node yet)
            if (last_rev != u) {
                for (auto [v, w] : rev[u]) {
                    int nc = cost + 2 * w;
                    if (!dist[v].count(u) || dist[v][u] > nc) {
                        dist[v][u] = nc;
                        pq.push({nc, v, u});
                    }
                }
            }
        }
        
        return -1;
    }
};
```

---

## Key Takeaways

1. **State-space search:** When constraints involve "use at most once per node," track which resources have been used as part of your state.

2. **Modified Dijkstra:** The shortest path problem with additional constraints can often be solved by expanding the state space in Dijkstra's algorithm.

3. **Graph representation:** Maintain both forward and backward adjacency lists when edge direction can be altered.

4. **Edge reversal cost:** Reversing an edge costs `2×` the original weight — this prevents infinite loops and ensures the problem remains a shortest path variant.

5. **State compression:** For large `n`, full bitmask representation (`2^n` states) is infeasible. Use alternative encodings like sets, maps, or track only relevant constraints.

6. **Pruning:** Always check if a state has been reached with lower cost before processing to avoid redundant work.

7. **BFS vs Dijkstra:** Since edge weights vary, BFS won't work — must use priority queue (Dijkstra) to explore in cost order.

8. **Complexity trade-offs:** The theoretical state space is exponential, but in practice, many states are unreachable or pruned early, making the solution feasible for constraint limits.

---
