# 3970. Shortest Path With At Most K Consecutive Identical Characters

**Difficulty:** `Medium`  
**Tags:** `String`, `Graph Theory`, `Heap (Priority Queue)`, `Shortest Path`

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

[LeetCode — 3970. Shortest Path With At Most K Consecutive Identical Characters](https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/)

---

## Problem Summary

The problem requires finding the shortest path in a directed graph from node 0 to node n-1, with the constraint that the sequence of labels along the path must not contain more than k consecutive identical characters. The solution uses a priority queue to perform a modified Dijkstra's search, tracking both the total cost and the current count of consecutive identical labels.

---

## Examples

_No examples provided._

---

## Intuition

The key insight is to treat the 'consecutive character count' as a state variable. By storing the minimum cost to reach each node with a specific count of consecutive characters (dist[node][count]), we can efficiently determine if a new edge violates the k-constraint. The priority queue ensures we always explore the lowest-cost path first, while the 2D dist array prevents us from re-exploring states that are already known to be suboptimal.

---

## Approach

1. Initialize a 2D distance array dist where dist[node][count] represents the minimum cost to reach node 'node' with 'count' consecutive identical characters. Set all values to infinity, except dist[0][1] = 0 (starting state).
2. Create a priority queue to store tuples of (cost, node, count). Push the starting state (0, 0, 1) into the queue.
3. While the queue is not empty, pop the top element (lowest cost). If this node is the destination (n-1), return the cost.
4. For each neighbor of the current node, calculate the new consecutive character count. If the labels are the same, increment the count; otherwise, reset to 1. If the new count exceeds k, skip this edge.
5. Calculate the new total cost. If this new cost is lower than the current minimum for this node and count (dist[next][newCount]), update the distance array and push the new state into the priority queue.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(E * log(V * (k+1)))` — The algorithm performs a search similar to Dijkstra's, where the number of states is proportional to the number of nodes (V) and the range of the count variable (k+1). The priority queue operations dominate the time complexity, resulting in O(E * log(V * (k+1))) for a graph with E edges. |
| **Space** | `O(V * (k+1))` — The primary space usage is the 2D array dist, which has dimensions V (nodes) by k+1 (counts). The priority queue also stores up to O(V * (k+1)) elements at its peak, leading to a total space complexity of O(V * (k+1)). |

---

## Code (C++)

```cpp
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        // Build the adjacency list
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][count] = minimum cost to reach this state
        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive character count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, count] = pq.top();
            pq.pop();

            // Skip outdated states
            if (cost != dist[node][count]) {
                continue;
            }

            // Destination reached
            if (node == n - 1) {
                return (int)cost;
            }

            // Explore neighboring nodes
            for (auto [next, weight] : adj[node]) {
                int newCount;

                if (labels[next] == labels[node]) {
                    newCount = count + 1;
                } else {
                    newCount = 1;
                }

                // Reject paths exceeding k consecutive characters
                if (newCount > k) {
                    continue;
                }

                long long newCost = cost + weight;

                if (newCost < dist[next][newCount]) {
                    dist[next][newCount] = newCost;
                    pq.push({newCost, next, newCount});
                }
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- This problem demonstrates how to extend Dijkstra's algorithm to handle constraints on the path's properties (in this case, label repetition) by introducing an additional state variable.
- The use of a priority queue ensures that the search is efficient and finds the optimal solution, while the 2D array prevents redundant calculations of already visited states.
