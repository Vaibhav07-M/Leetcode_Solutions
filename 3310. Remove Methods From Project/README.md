# 3310. Remove Methods From Project

**Difficulty:** `Medium`  
**Tags:** `Graph`, `BFS`, `DFS`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Why This Works](#why-this-works)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

https://leetcode.com/problems/remove-methods-from-project/

---

## Problem Summary

A project contains `n` methods connected through invocation relationships.

- Method `k` contains a bug.
- Every method reachable from `k` is also considered **suspicious**.
- We may remove all suspicious methods **only if no non-suspicious method invokes any suspicious method**.

Return the remaining methods after removal. If removal is impossible, return all methods. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
n = 4
k = 1
invocations = [[1,2],[0,1],[3,2]]
```

**Output**

```text
[0,1,2,3]
```

---

### Example 2

**Input**

```text
n = 5
k = 0
invocations = [[1,2],[0,2],[0,1],[3,4]]
```

**Output**

```text
[3,4]
```

---

### Example 3

**Input**

```text
n = 3
k = 2
invocations = [[1,2],[0,1],[2,0]]
```

**Output**

```text
[]
```

---

## Intuition

Starting from the buggy method `k`, every method reachable through invocation is also suspicious.

After finding all suspicious methods, verify whether some safe method still invokes one of them.

- If yes, removing them would break the project, so return every method.
- Otherwise, remove every suspicious method.

---

## Approach

### Step 1

Construct the directed graph.

```text
u → v
```

means method `u` invokes method `v`.

---

### Step 2

Perform a BFS starting from `k`.

Mark every reachable method as suspicious.

---

### Step 3

Traverse every invocation again.

If there exists an edge

```text
safe → suspicious
```

then removal is impossible.

Return

```text
0...n-1
```

---

### Step 4

Otherwise, collect every method that is **not suspicious**.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n + m)` |
| **Space** | `O(n + m)` |

where `m` is the number of invocations.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        // Find all suspicious methods
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Check if any outside method calls a suspicious method
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};
```

---

## Why This Works

Consider

```text
0 → 1 → 2
3 → 2
```

and

```text
k = 1
```

BFS marks

```text
1, 2
```

as suspicious.

Now inspect every edge.

```
3 → 2
```

goes from a safe method to a suspicious method.

Therefore removing `{1,2}` would leave method `3` calling a deleted method.

Hence removal is invalid and we return every method.

If no such edge exists, deleting all suspicious methods is safe.

---

## Key Takeaways

- Model the methods as a directed graph.
- BFS/DFS finds every suspicious method reachable from `k`.
- A single edge from a safe method to a suspicious method prevents removal.
- Otherwise, simply keep all non-suspicious methods.
- Time Complexity is **O(n + m)**.
- Space Complexity is **O(n + m)**.