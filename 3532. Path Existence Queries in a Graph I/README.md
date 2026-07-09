# 3532. Path Existence Queries in a Graph I

**Difficulty:** `Medium`  
**Tags:** `Union Find`, `Graph`

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

[LeetCode — 3532. Path Existence Queries in a Graph I](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/)

---

## Problem Summary

You are given:

- An integer `n` representing the number of nodes.
- A sorted array `nums`.
- An integer `maxDiff`.
- A list of connectivity queries.

An undirected edge exists between two nodes if the absolute difference between their values is at most `maxDiff`.

For each query `[u, v]`, determine whether there exists a path between the two nodes. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```cpp
n = 2
nums = [1,3]
maxDiff = 1
queries = [[0,0],[0,1]]
```

**Output**

```cpp
[true,false]
```

---

### Example 2

**Input**

```cpp
n = 4
nums = [2,5,6,8]
maxDiff = 2
queries = [[0,1],[0,2],[1,3],[2,3]]
```

**Output**

```cpp
[false,false,true,true]
```

---

## Intuition

Since `nums` is already sorted, if two adjacent numbers differ by more than `maxDiff`, they can never belong to the same connected component.

Therefore, it is sufficient to connect only adjacent indices whose difference is within `maxDiff`. All nodes connected through consecutive valid differences belong to the same component.

Once the connected components are built, each query reduces to checking whether both nodes belong to the same component.

---

## Approach

### 1. Initialize Disjoint Set Union (DSU)

Create a parent array and rank array for Union-Find.

---

### 2. Build Connected Components

Traverse the sorted array.

If

```cpp
nums[i] - nums[i - 1] <= maxDiff
```

merge the two indices into the same component.

---

### 3. Answer Queries

For every query:

- Find the representative of both nodes.
- If both representatives are equal, a path exists.
- Otherwise, no path exists.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + q) · α(n))` |
| **Space** | `O(n)` |

Where:

- `n` = number of nodes
- `q` = number of queries
- `α(n)` = inverse Ackermann function (nearly constant)

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                unite(i, i - 1);
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The sorted property of `nums` allows connecting only adjacent elements.
- Union-Find efficiently maintains connected components.
- Each query becomes a constant-time connectivity check after preprocessing.
- Path compression and union by rank make DSU operations nearly constant time.
```