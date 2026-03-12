# 3600. Maximize Spanning Tree Stability with Upgrades

**Difficulty:** `Hard`  
**Tags:** `Graph`, `Union Find`, `Binary Search`, `Greedy`

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

[LeetCode - 3600. Maximize Spanning Tree Stability with Upgrades](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)

---

## Problem Summary

You are given an undirected graph with `n` nodes and edges described as:
- `u`, `v`: endpoints
- `s`: strength
- `must`: `1` means this edge is mandatory and must be included in the spanning tree

You may perform at most `k` upgrades. Each upgrade can be applied only to an optional edge (`must == 0`) and doubles its strength.

The stability of a spanning tree is the minimum edge strength inside that tree.

Return the maximum possible stability among all valid spanning trees, or `-1` if no valid spanning tree exists.

---

## Examples

### Example 1
**Input:** `n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1`  
**Output:** `2`  
**Explanation:**
- Edge `[0,1]` is mandatory, so it must be used with strength `2`.
- Edge `[1,2]` can be upgraded from `3` to `6`.
- Spanning tree strengths are `{2, 6}`, so stability is `2`.

### Example 2
**Input:** `n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2`  
**Output:** `6`  
**Explanation:**
- Upgrade `[0,1]` to `8` and `[1,2]` to `6`.
- Use those two edges as the spanning tree.
- Minimum edge strength is `6`.

### Example 3
**Input:** `n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0`  
**Output:** `-1`  
**Explanation:**
- All edges are mandatory and they form a cycle.
- A spanning tree cannot contain a cycle, so it is impossible.

---

## Intuition

We want to maximize a minimum value (the weakest edge in the chosen spanning tree), which strongly suggests **binary search on the answer**.

Suppose we guess a target stability `T`. Can we build a valid spanning tree where every selected edge has effective strength at least `T`?

For a fixed `T`:
1. Mandatory edges must be taken.
- If any mandatory edge has `s < T`, this `T` is impossible.
- If mandatory edges create a cycle, impossible.
2. Optional edges fall into three groups:
- `s >= T`: usable without upgrade
- `s < T <= 2*s`: usable with one upgrade
- `2*s < T`: unusable
3. We connect remaining components with DSU:
- Prefer free usable edges first
- Then use upgrade-usable edges while upgrades used `<= k`

If we can connect all `n` nodes using exactly `n-1` edges under these rules, then `T` is feasible.

---

## Approach

1. Binary search `T` in range `[1, 200000]` because `s <= 100000` and upgraded strength can be `2 * 100000`.
2. For each midpoint `T`, run feasibility check `can(T)`:
- Initialize DSU and counters `usedEdges`, `usedUpgrades`.
- Add mandatory edges first:
  - reject if `s < T`
  - reject if they form cycle
- Process optional edges:
  - if `s >= T`, use edge if it connects different components
  - else if `2*s >= T` and upgrades left, use upgraded edge
- Feasible if total used edges becomes `n - 1`.
3. If feasible, move binary search right; otherwise left.
4. Return the best feasible `T`, else `-1`.

---

## Complexity

Let `m = edges.size()` and `S = 200000`.

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log S * (m log m + m * alpha(n)))` for the submitted style (sorting optional edges inside each feasibility check) |
| **Space** | `O(n + m)` |

---

## Code (C++)

### Solution 1 - Binary Search + DSU (Submitted)

```cpp
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;

        if (rank[pa] < rank[pb])
            swap(pa, pb);

        parent[pb] = pa;

        if (rank[pa] == rank[pb])
            rank[pa]++;

        return true;
    }
};

class Solution {
public:
    bool can(int n, vector<vector<int>>& edges, int k, int target) {
        DSU dsu(n);
        int used = 0;
        int upgrades = 0;

        vector<vector<int>> optional;

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 1) {
                if (s < target) return false;

                if (!dsu.unite(u, v))
                    return false;

                used++;
            } else {
                optional.push_back(e);
            }
        }

        sort(optional.begin(), optional.end(),
             [](auto& a, auto& b) {
                 return a[2] > b[2];
             });

        for (auto& e : optional) {
            int u = e[0], v = e[1], s = e[2];

            if (dsu.find(u) == dsu.find(v))
                continue;

            if (s >= target) {
                dsu.unite(u, v);
                used++;
            } else if (2 * s >= target && upgrades < k) {
                dsu.unite(u, v);
                upgrades++;
                used++;
            }

            if (used == n - 1)
                return true;
        }

        return used == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 1;
        int hi = 200000;
        int ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (can(n, edges, k, mid)) {
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

### Solution 2 - Pre-Sort Optional Edges Once

Same idea, but sort optional edges once outside the feasibility function.

```cpp
class DSU {
public:
    vector<int> parent, rnk;

    DSU(int n) : parent(n), rnk(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<array<int, 3>> mustEdges;
        vector<array<int, 3>> optional;

        for (auto& e : edges) {
            if (e[3] == 1) mustEdges.push_back({e[0], e[1], e[2]});
            else optional.push_back({e[0], e[1], e[2]});
        }

        sort(optional.begin(), optional.end(), [](const auto& a, const auto& b) {
            return a[2] > b[2];
        });

        auto can = [&](int target) -> bool {
            DSU dsu(n);
            int used = 0;
            int upgrades = 0;

            for (auto& e : mustEdges) {
                int u = e[0], v = e[1], s = e[2];
                if (s < target) return false;
                if (!dsu.unite(u, v)) return false;
                used++;
            }

            for (auto& e : optional) {
                if (used == n - 1) break;

                int u = e[0], v = e[1], s = e[2];
                if (dsu.find(u) == dsu.find(v)) continue;

                if (s >= target) {
                    dsu.unite(u, v);
                    used++;
                } else if (2 * s >= target && upgrades < k) {
                    dsu.unite(u, v);
                    upgrades++;
                    used++;
                }
            }

            return used == n - 1;
        };

        int lo = 1, hi = 200000, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
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

### Solution 3 - Two-Pass Feasibility (No Sorting Inside Check)

For a fixed target:
- First consume optional edges that already satisfy target (`s >= target`)
- Then consume upgrade-eligible edges (`2*s >= target`) while upgrades remain

```cpp
class DSU {
public:
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        while (x != p[x]) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<array<int, 3>> mustEdges;
        vector<array<int, 3>> optional;

        for (auto& e : edges) {
            if (e[3] == 1) mustEdges.push_back({e[0], e[1], e[2]});
            else optional.push_back({e[0], e[1], e[2]});
        }

        auto can = [&](int target) -> bool {
            DSU dsu(n);
            int used = 0;
            int upgrades = 0;

            for (auto& e : mustEdges) {
                int u = e[0], v = e[1], s = e[2];
                if (s < target) return false;
                if (!dsu.unite(u, v)) return false;
                used++;
            }

            for (auto& e : optional) {
                int u = e[0], v = e[1], s = e[2];
                if (s >= target && dsu.unite(u, v)) {
                    used++;
                }
            }

            for (auto& e : optional) {
                if (used == n - 1) break;
                if (upgrades == k) break;

                int u = e[0], v = e[1], s = e[2];
                if (s < target && 2 * s >= target && dsu.unite(u, v)) {
                    used++;
                    upgrades++;
                }
            }

            return used == n - 1;
        };

        int lo = 1, hi = 200000, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
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

- Maximizing a minimum value is often solved with binary search on the answer.
- DSU handles connectivity and cycle constraints efficiently in each feasibility check.
- Mandatory edges must be validated first because they are non-negotiable.
- For a fixed threshold, optional edges are naturally split into free-usable, upgrade-usable, and unusable sets.
- If mandatory edges already contain a cycle, the answer is immediately `-1`.
