# 1895. Largest Magic Square

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Prefix Sum`

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

[LeetCode — 1895. Largest Magic Square](https://leetcode.com/problems/largest-magic-square/)

---

## Problem Summary

A `k x k` magic square is a grid where:
- Every row sum is equal
- Every column sum is equal
- Both diagonal sums are equal
- All these sums must be the same value

Given an `m x n` grid of integers, find the **size** (side length `k`) of the largest magic square that can be found within this grid.

---

## Examples

### Example 1
**Input:**  
```
grid = [[7,1,4,5,6],
        [2,5,1,6,4],
        [1,5,4,3,2],
        [1,2,7,3,4]]
```  
**Output:** `3`  
**Explanation:**  
The largest magic square has size 3:
```
[5,1,6]
[5,4,3]
[2,7,3]
```
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

### Example 2
**Input:**  
```
grid = [[5,1,3,1],
        [9,3,3,1],
        [1,3,3,8]]
```  
**Output:** `2`

---

## Intuition

A brute force solution checks every possible square subgrid starting from the largest size down to 1x1.  
For each square, we verify if all rows, columns, and diagonals have the same sum.

To optimize sum calculations, we can use **prefix sums** for rows and columns.  
This allows us to compute any subarray sum in constant time, making validation faster.

---

## Approach

1. **Precompute prefix sums:**
   - `rowSum[i][j]` = sum of row `i` from column `0` to `j`
   - `colSum[i][j]` = sum of column `j` from row `0` to `i`

2. **Iterate over all possible square sizes** `k` from `min(m, n)` down to `1`:
   - For each top-left corner `(r, c)`, check if a `k x k` square starting there is magic.

3. **Check if square is magic:**
   - Compute the expected sum from the first row.
   - Verify all rows have this sum.
   - Verify all columns have this sum.
   - Verify both diagonals have this sum.

4. Return the first (largest) `k` where a magic square is found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * min(m, n)²)` — worst case checking all squares and validating sums |
| **Space** | `O(m * n)` — for prefix sum arrays |

With prefix sums, validation of a `k x k` square is `O(k)`, making this approach feasible for the given constraints.

---

## Code (C++)

```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Prefix sums
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        vector<vector<int>> colSum(m + 1, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }
        
        // Check from largest to smallest square
        for (int k = min(m, n); k >= 1; k--) {
            for (int r = 0; r <= m - k; r++) {
                for (int c = 0; c <= n - k; c++) {
                    if (isMagic(grid, rowSum, colSum, r, c, k)) {
                        return k;
                    }
                }
            }
        }
        
        return 1;
    }
    
    bool isMagic(vector<vector<int>>& grid, vector<vector<int>>& rowSum,
                 vector<vector<int>>& colSum, int r, int c, int k) {
        // Expected sum from first row
        int expectedSum = rowSum[r][c + k] - rowSum[r][c];
        
        // Check all rows
        for (int i = r; i < r + k; i++) {
            if (rowSum[i][c + k] - rowSum[i][c] != expectedSum) {
                return false;
            }
        }
        
        // Check all columns
        for (int j = c; j < c + k; j++) {
            if (colSum[r + k][j] - colSum[r][j] != expectedSum) {
                return false;
            }
        }
        
        // Check main diagonal (top-left to bottom-right)
        int diag1 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[r + i][c + i];
        }
        if (diag1 != expectedSum) {
            return false;
        }
        
        // Check anti-diagonal (top-right to bottom-left)
        int diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag2 += grid[r + i][c + k - 1 - i];
        }
        if (diag2 != expectedSum) {
            return false;
        }
        
        return true;
    }
};
```

---

## Key Takeaways

1. **Prefix sums optimize range sum queries** — essential for checking multiple subgrids efficiently
2. **Check largest squares first** — early exit when a valid magic square is found
3. **Magic square verification** requires checking rows, columns, and both diagonals
4. **Diagonal computation** needs manual iteration as no prefix sum helps here
5. **Constraints matter** — with `m, n ≤ 50`, even O(n³) solutions are acceptable
6. **1x1 squares are trivially magic** — guarantees at least size 1 as answer
7. **Careful indexing** is critical when using prefix sums to avoid off-by-one errors

---
