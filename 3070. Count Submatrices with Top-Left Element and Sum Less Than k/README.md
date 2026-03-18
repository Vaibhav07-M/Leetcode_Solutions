# 3070. Count Submatrices with Top-Left Element and Sum Less Than k

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

[LeetCode - 3070. Count Submatrices with Top-Left Element and Sum Less Than k](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)

---

## Problem Summary

You are given an `m x n` integer matrix `grid` and an integer `k`.

Count how many submatrices:
- contain the top-left element `grid[0][0]`, and
- have sum less than or equal to `k`.

---

## Examples

### Example 1
**Input:** `grid = [[7,6,3],[6,6,1]], k = 18`  
**Output:** `4`  
**Explanation:**
The valid submatrices are exactly those ending at bottom-right corners `(0,0)`, `(0,1)`, `(0,2)`, and `(1,0)`.

### Example 2
**Input:** `grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20`  
**Output:** `6`

---

## Intuition

Any submatrix that must include `grid[0][0]` is uniquely defined by its bottom-right corner `(i, j)`.
So the required sum is simply the `2D prefix sum` up to `(i, j)`.

That means the problem reduces to:
1. compute prefix sum for every cell,
2. count how many prefix sums are `<= k`.

---

## Approach

1. Traverse the matrix row by row.
2. Convert `grid[i][j]` into an in-place 2D prefix sum:
   - add prefix from top (`i-1, j`) if it exists,
   - add prefix from left (`i, j-1`) if it exists,
   - subtract overlap (`i-1, j-1`) if both exist.
3. After computing each prefix value, if it is `<= k`, increment answer.
4. Return answer.

Because we write prefix sums back into `grid`, no extra matrix is needed.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` |
| **Space** | `O(1)` extra space (in-place) |

---

## Code (C++)

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) ans++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Submatrices that must include top-left can be represented by bottom-right corners.
- 2D prefix sums turn each candidate sum query into `O(1)`.
- In-place prefix updates keep memory usage minimal.
