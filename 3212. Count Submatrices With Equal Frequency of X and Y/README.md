# 3212. Count Submatrices With Equal Frequency of X and Y

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

[LeetCode - 3212. Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/)

---

## Problem Summary

You are given an `m x n` character matrix `grid`, where each cell is one of:
- `'X'`
- `'Y'`
- `'.'`

Return the number of submatrices that:
- contain `grid[0][0]`,
- have equal frequency of `'X'` and `'Y'`, and
- contain at least one `'X'`.

---

## Examples

### Example 1
**Input:** `grid = [["X","Y","."],["Y",".","."]]`  
**Output:** `3`

### Example 2
**Input:** `grid = [["X","X"],["X","Y"]]`  
**Output:** `0`

### Example 3
**Input:** `grid = [[".","."],[".","."]]`  
**Output:** `0`

---

## Intuition

Any submatrix that contains `grid[0][0]` must have top-left corner fixed at `(0, 0)`.
So each valid submatrix is uniquely identified by its bottom-right corner `(i, j)`.

For each rectangle `(0,0) -> (i,j)`, we need to verify two conditions:
1. number of `'X'` equals number of `'Y'`
2. number of `'X'` is at least `1`

We can check both in `O(1)` per cell using 2D prefix sums.

---

## Approach

1. Build two 2D prefix matrices while scanning the grid:
   - `sum[i][j]`: balance `(#X - #Y)` in rectangle `(0,0) -> (i,j)`
   - `countX[i][j]`: number of `'X'` in rectangle `(0,0) -> (i,j)`
2. Cell contribution for `sum`:
   - `'X'` contributes `+1`
   - `'Y'` contributes `-1`
   - `'.'` contributes `0`
3. Use normal 2D prefix relation with inclusion-exclusion.
4. For every `(i, j)`, if:
   - `sum[i][j] == 0` (equal `'X'` and `'Y'`), and
   - `countX[i][j] > 0` (at least one `'X'`),
   increment the answer.

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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> sum(m, vector<int>(n, 0));
        vector<vector<int>> countX(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                sum[i][j] = val;
                countX[i][j] = (grid[i][j] == 'X');

                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j-1];
                    countX[i][j] += countX[i][j-1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }

                if(sum[i][j] == 0 && countX[i][j] > 0)
                    ans++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Because `grid[0][0]` must be included, every candidate is a prefix rectangle.
- Tracking both balance `(#X - #Y)` and `countX` lets us verify both constraints in constant time.
- 2D prefix sums turn the whole solution into a single `O(m * n)` pass.
