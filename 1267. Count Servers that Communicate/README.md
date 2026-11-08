# 1267. Count Servers that Communicate

**Difficulty:** `Medium`  
**Tags:** `Array`, `Depth-First Search`, `Breadth-First Search`, `Union-Find`, `Matrix`, `Counting`

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

[LeetCode — 1267. Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)

---

## Problem Summary

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.  
Return the number of servers that communicate with any other server.

---

## Examples

### Example 1
**Input:** `grid = [[1,0],[0,1]]`  
**Output:** `0`  
**Explanation:**
- No servers can communicate with others.

### Example 2
**Input:** `grid = [[1,0],[1,1]]`  
**Output:** `3`  
**Explanation:**
- All three servers can communicate with at least one other server.

### Example 3
**Input:** `grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]`  
**Output:** `4`  
**Explanation:**
- The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

---

## Intuition

The problem revolves around array, depth-first search, breadth-first search, union-find, matrix, counting. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // Step 1: Count servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // Step 2: Count servers that can communicate
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 &&
                    (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix, Counting patterns often reduce an apparently complex problem to a few simple rules.
