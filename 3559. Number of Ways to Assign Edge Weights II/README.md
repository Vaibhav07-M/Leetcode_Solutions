# 3559. Number of Ways to Assign Edge Weights II

**Difficulty:** `Hard`  
**Tags:** `Tree`, `Lowest Common Ancestor`, `Math`

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

[LeetCode — 3559. Number of Ways to Assign Edge Weights II](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/)

---

## Problem Summary

You are given a tree rooted at node `1`. Each edge must be assigned weight `1` or `2`.

For each query `[u, v]`, consider only the edges on the path between `u` and `v`. Count how many assignments make the total path cost odd. Return the answer for every query modulo `10^9 + 7`.

If `u == v`, the path has no edges, so the answer is `0`.

---

## Examples

### Example 1
**Input:** `edges = [[1,2]], queries = [[1,1],[1,2]]`  
**Output:** `[0,1]`

### Example 2
**Input:** `edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]`  
**Output:** `[2,1,4]`

---

## Intuition

Only the length of the path matters.

Every edge contributes either an odd value (`1`) or an even value (`2`). A path of length `d` has `2^d` total assignments. Exactly half of them produce an odd sum when `d > 0`, because odd parity is achieved when the number of `1`s on the path is odd.

So for any non-empty path, the number of valid assignments is:

$$2^{d-1}$$

The main task is to compute the path length for each query efficiently.

---

## Approach

1. Build the tree with adjacency lists.
2. Precompute binary-lifting parents and depths using DFS.
3. For each query `[u, v]`, compute the lowest common ancestor `p`.
4. The path length is `depth[u] + depth[v] - 2 * depth[p]`.
5. If the length is `0`, return `0`; otherwise return `2^(length - 1) mod 10^9 + 7`.

Why this works:
- The path contains exactly `length` edges.
- Each edge has 2 choices.
- Half of those assignments yield odd parity when `length > 0`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Preprocessing Time** | `O(n log n)` |
| **Per Query** | `O(log n)` |
| **Space** | `O(n log n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17 + 1;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void dfs(int node, int parent) {
        up[node][0] = parent;
        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 1));
        depth.assign(n + 1, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];
            int p = lca(u, v);

            long long len = depth[u] + depth[v] - 2LL * depth[p];
            if (len == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, len - 1));
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The odd/even counting becomes simple once you reduce the problem to path length.
- Lowest common ancestor is the key tool for answering arbitrary path queries in a tree.
- Binary lifting gives an efficient `O(log n)` query solution.
