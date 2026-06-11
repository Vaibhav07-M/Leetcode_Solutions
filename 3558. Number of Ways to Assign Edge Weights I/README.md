# 3558. Number of Ways to Assign Edge Weights I

**Difficulty:** `Medium`  
**Tags:** `Tree`, `BFS`, `Math`

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

[LeetCode — 3558. Number of Ways to Assign Edge Weights I](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/)

---

## Problem Summary

You are given a rooted tree with node `1` as the root. Every edge initially has weight `0`, and each edge must be assigned either weight `1` or `2`.

For any path, the cost is the sum of its edge weights. Pick any node at the maximum depth, and count how many ways there are to assign weights along the path from the root to that node so that the total cost is odd.

Only the edges on that root-to-deepest-node path matter.

---

## Examples

### Example 1
**Input:** `edges = [[1,2]]`  
**Output:** `1`

### Example 2
**Input:** `edges = [[1,2],[1,3],[3,4],[3,5]]`  
**Output:** `2`

---

## Intuition

The answer depends only on the depth of any deepest node.

Every edge on the chosen path can be assigned `1` or `2`. Since `2` is even and `1` is odd, the total path sum is odd exactly when the number of `1` weights on the path is odd. For a path of length `d`, the number of odd-sum assignments is the number of ways to choose an odd number of edges to carry weight `1`, which equals $2^{d-1}$.

So the task becomes:
1. find the maximum depth in the tree,
2. compute $2^{\text{depth}-1}$ modulo $10^9 + 7$.

---

## Approach

1. Build an adjacency list for the tree.
2. Run BFS from node `1` to compute the maximum depth.
3. If the deepest node is at depth `d`, return `2^(d-1) mod (1e9 + 7)`.

Why this works:
- Each edge contributes either an odd value (`1`) or an even value (`2`).
- A sum of `d` such values is odd iff the number of odd contributions is odd.
- Exactly half of the `2^d` assignments have odd parity, so the count is `2^(d-1)`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        q.push({1, 0});

        vector<int> vis(n + 1, 0);
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nxt : adj[node]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push({nxt, depth + 1});
                }
            }
        }

        return (int)modPow(2, maxDepth - 1);
    }
};
```

---

## Key Takeaways

- Once the parity condition is isolated, the counting collapses to a simple power of two.
- BFS is enough to determine the deepest level in an unweighted tree.
- Modulo exponentiation is the right tool when the answer grows exponentially.
