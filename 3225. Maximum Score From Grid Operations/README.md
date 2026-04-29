# 3225. Maximum Score From Grid Operations

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Matrix`, `Prefix Sum`

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

[LeetCode — 3225. Maximum Score From Grid Operations](https://leetcode.com/problems/maximum-score-from-grid-operations/)

---

## Problem Summary

You are given an n x n grid of non-negative integers. Initially all cells are white. In one operation you may choose a cell (i, j) and color black every cell in column j from row 0 down to row i (inclusive). The grid score is the sum of grid[i][j] over all white cells (i, j) that have a horizontally adjacent black cell (that is, either (i, j-1) or (i, j+1) is black).

Return the maximum score achievable after any sequence of operations.

---

## Examples

### Example 1
Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]

Output: 11

### Example 2
Input: grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]

Output: 94

---

## Intuition

Operations affect entire prefixes of columns. The adjacency that contributes to the score depends on which rows in neighboring columns are painted. The problem reduces to choosing, for each column, how far down to paint (a prefix length) to maximize collected values from neighboring columns' unpainted cells that become adjacent to painted cells.

---

## Approach

1. For each column, consider all possible prefix heights (0..n-1) you might paint.
2. For each cell that remains white, determine if it has a black neighbor based on the chosen prefixes for adjacent columns.
3. This can be optimized by precomputing column prefix sums and evaluating contributions efficiently for combinations of neighboring prefix heights — often solvable with greedy choices or dynamic programming across columns depending on constraints.

Note: Implementation details vary; carefully optimize to O(n^2) or O(n^2 log n) to fit within n <= 100.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | O(n^3) naive, can be optimized to O(n^2 log n) or O(n^2) with careful preprocessing |
| **Space** | O(n^2) |

---

## Code (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;

    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};
```

---

## Key Takeaways
- Think in terms of column prefix choices and how they affect neighbors.
- Precompute prefix sums per column to evaluate contributions quickly.
- Optimize by noticing local interactions between adjacent columns.
