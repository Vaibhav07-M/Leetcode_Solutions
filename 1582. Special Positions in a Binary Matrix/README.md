# 1582. Special Positions in a Binary Matrix

**Difficulty:** `Easy`  
**Tags:** `Array`, `Matrix`

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

[LeetCode — 1582. Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)

---

## Problem Summary

Given an `m x n` binary matrix `mat`, return the number of **special positions**.

A position `(i, j)` is **special** if:
- `mat[i][j] == 1`
- All other elements in row `i` are `0`
- All other elements in column `j` are `0`

---

## Examples

### Example 1
**Input:** `mat = [[1,0,0],[0,0,1],[1,0,0]]`  
**Output:** `1`  
**Explanation:**
- `(1, 2)` is special: `mat[1][2] == 1`, all other elements in row 1 and column 2 are `0`.
- `(0, 0)` is **not** special: column 0 also has a `1` at row 2.

### Example 2
**Input:** `mat = [[1,0,0],[0,1,0],[0,0,1]]`  
**Output:** `3`  
**Explanation:**
- `(0, 0)`, `(1, 1)`, and `(2, 2)` are all special — each row and column contains exactly one `1`.

---

## Constraints
- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `mat[i][j]` is either `0` or `1`

---

## Intuition

A position is special if its row sum and column sum are both exactly `1` (and the cell itself is `1`).

Pre-computing row and column sums lets us check every `1` cell in O(1) instead of re-scanning rows and columns every time.

---

## Approach

1. Pre-compute `row[i]` = sum of row `i`, and `col[j]` = sum of column `j`.
2. Iterate over all cells; for each cell where `mat[i][j] == 1`, check if `row[i] == 1 && col[j] == 1`.
3. Count and return all such qualifying cells.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m × n)` — two passes over the matrix |
| **Space** | `O(m + n)` — for the row and column sum arrays |

---

## Code (C++)

### Solution 1: Pre-compute Row and Column Sums (Submitted)
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
```

### Solution 2: Single Pass with Row Sum Check
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> col(n, 0);

        // Accumulate column sums
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                col[j] += mat[i][j];

        int ans = 0;
        for (int i = 0; i < m; i++) {
            // Find the single 1 in row i (if exactly one)
            int rowSum = 0, pos = -1;
            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
                if (mat[i][j] == 1) pos = j;
            }
            if (rowSum == 1 && col[pos] == 1) ans++;
        }

        return ans;
    }
};
```

### Solution 3: Brute Force (No Extra Space)
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 1) continue;

                bool special = true;
                // Check row
                for (int k = 0; k < n && special; k++)
                    if (k != j && mat[i][k] == 1) special = false;
                // Check column
                for (int k = 0; k < m && special; k++)
                    if (k != i && mat[k][j] == 1) special = false;

                if (special) ans++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Pre-computing sums is the cleanest approach — reduces the problem to a single comparison per cell.
- A position is special if and only if `row[i] == 1 && col[j] == 1 && mat[i][j] == 1`.
- The brute-force scan works for the given constraints (`m, n ≤ 100`) but is `O(m × n × (m + n))`.
- The optimised solution avoids rescanning rows/columns per cell, bringing it to `O(m × n)`.
