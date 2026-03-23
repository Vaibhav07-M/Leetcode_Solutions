# 1594. Maximum Non Negative Product in a Matrix

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`, `Matrix`

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

[LeetCode - 1594. Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)

---

## Problem Summary

You are given an `m x n` integer matrix `grid`.
Starting at the top-left cell `(0, 0)`, you can move only **right** or **down** until you reach the bottom-right cell `(m - 1, n - 1)`.

The product of a path is the multiplication of all visited values.
Return the **maximum non-negative path product modulo `10^9 + 7`**.
If every possible path product is negative, return `-1`.

---

## Examples

### Example 1
**Input:** `grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]`  
**Output:** `-1`

### Example 2
**Input:** `grid = [[1,-2,1],[1,-2,1],[3,-4,1]]`  
**Output:** `8`  
**Explanation:** One optimal path gives `1 * 1 * -2 * -4 * 1 = 8`.

### Example 3
**Input:** `grid = [[1,3],[0,-4]]`  
**Output:** `0`

---

## Intuition

Because of negative numbers, a very small (negative) product can become a very large positive product after multiplying by another negative number.
So at each cell, we must track:

- the **maximum product** reaching that cell
- the **minimum product** reaching that cell

Both are necessary to correctly handle sign flips.

---

## Approach

1. Use two DP tables:
   - `maxProd[i][j]`: maximum product reaching `(i, j)`
   - `minProd[i][j]`: minimum product reaching `(i, j)`
2. Initialize `(0, 0)` with `grid[0][0]` in both tables.
3. Fill first row and first column directly (only one incoming direction).
4. For every other cell `(i, j)`, compute four candidates:
   - from top using previous `maxProd` and `minProd`
   - from left using previous `maxProd` and `minProd`
   each multiplied by `grid[i][j]`
5. Store the maximum of candidates in `maxProd[i][j]` and minimum in `minProd[i][j]`.
6. Final answer is `maxProd[m-1][n-1]`:
   - if negative -> return `-1`
   - else return `maxProd[m-1][n-1] % (10^9 + 7)`

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` |
| **Space** | `O(m * n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxProd(m, vector<long long>(n));
        vector<vector<long long>> minProd(m, vector<long long>(n));

        maxProd[0][0] = minProd[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            maxProd[0][j] = minProd[0][j] = maxProd[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            maxProd[i][0] = minProd[i][0] = maxProd[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long a = maxProd[i - 1][j] * grid[i][j];
                long long b = minProd[i - 1][j] * grid[i][j];
                long long c = maxProd[i][j - 1] * grid[i][j];
                long long d = minProd[i][j - 1] * grid[i][j];

                maxProd[i][j] = max({a, b, c, d});
                minProd[i][j] = min({a, b, c, d});
            }
        }

        long long result = maxProd[m - 1][n - 1];
        const int mod = 1e9 + 7;

        if (result < 0) return -1;
        return static_cast<int>(result % mod);
    }
};
```

---

## Key Takeaways

- With negative values, tracking only maximum is not enough; minimum is equally important.
- Dual-state DP (`max` + `min`) is a standard pattern for product/sign path problems.
- Apply modulo only to the final non-negative answer, as required by the problem.
