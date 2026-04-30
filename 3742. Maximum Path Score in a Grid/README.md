# 3742. Maximum Path Score in a Grid

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

[LeetCode — 3742. Maximum Path Score in a Grid](https://leetcode.com/problems/maximum-path-score-in-a-grid/)

---

## Problem Summary

You are given an m x n grid where each cell is 0, 1, or 2, and an integer k. Starting at (0, 0), move only right or down to reach (m - 1, n - 1).

Each cell adds to the score and cost based on its value:
- 0: score +0, cost +0
- 1: score +1, cost +1
- 2: score +2, cost +1

Return the maximum score achievable with total cost <= k, or -1 if no valid path exists.

---

## Examples

### Example 1
Input: grid = [[0,1],[2,0]], k = 1

Output: 2

Explanation:
- Path: (0,0) -> (1,0) -> (1,1)
- Score: 0 + 2 + 0 = 2
- Cost: 0 + 1 + 0 = 1

### Example 2
Input: grid = [[0,1],[1,2]], k = 1

Output: -1

Explanation:
All paths exceed total cost 1.

---

## Intuition

We need the best score while respecting a cost budget. This is a classic grid DP with an extra dimension for cost. At each cell, we can arrive from top or left with some cost used so far. We keep the maximum score for each (cell, cost) state.

---

## Approach

1. Convert each cell to its (score, cost) contribution.
2. Use dynamic programming where `dp[i][j][c]` stores the maximum score reaching (i, j) with total cost c.
3. Transition from top or left by adding the current cell's score if the cost budget allows.
4. Optimize memory with rolling rows: keep `prevRow` and `currRow` for all columns and costs.
5. The answer is the maximum value in the last cell over all costs <= k.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | O(m * n * k) |
| **Space** | O(n * k) |

---

## Code (C++)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prevRow(n, vector<int>(k + 1, -1));
        vector<vector<int>> currRow(n, vector<int>(k + 1, -1));

        auto cellScore = [](int v) { return v; };
        auto cellCost = [](int v) { return v == 0 ? 0 : 1; };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(currRow[j].begin(), currRow[j].end(), -1);

                int score = cellScore(grid[i][j]);
                int cost = cellCost(grid[i][j]);

                if (i == 0 && j == 0) {
                    if (cost <= k) {
                        currRow[j][cost] = score;
                    }
                    continue;
                }

                for (int c = cost; c <= k; c++) {
                    int best = -1;
                    int prevCost = c - cost;

                    if (i > 0 && prevRow[j][prevCost] != -1) {
                        best = max(best, prevRow[j][prevCost] + score);
                    }
                    if (j > 0 && currRow[j - 1][prevCost] != -1) {
                        best = max(best, currRow[j - 1][prevCost] + score);
                    }

                    currRow[j][c] = best;
                }
            }
            swap(prevRow, currRow);
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, prevRow[n - 1][c]);
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Add a cost dimension when you need to maximize score under budget.
- Rolling arrays reduce memory from O(m * n * k) to O(n * k).
- Always check the final cell over all feasible costs.
