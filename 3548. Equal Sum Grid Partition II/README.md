# 3548. Equal Sum Grid Partition II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Matrix`, `Prefix Sum`

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

[LeetCode - 3548. Equal Sum Grid Partition II](https://leetcode.com/problems/equal-sum-grid-partition-ii/)

---

## Problem Summary

You are given an `m x n` grid of positive integers. You need to check whether a single horizontal cut or a single vertical cut can split the grid into two non-empty parts such that:

- Both parts have equal sum, or can be made equal by discounting at most one cell in total.
- If a cell is discounted, the remaining cells in that part must stay connected.

Return `true` if such a cut exists, otherwise return `false`.

---

## Examples

### Example 1
**Input:** `grid = [[1,4],[2,3]]`  
**Output:** `true`  
**Explanation:** A horizontal cut gives sums `5` and `5`.

### Example 2
**Input:** `grid = [[1,2],[3,4]]`  
**Output:** `true`  
**Explanation:** A vertical cut gives sums `4` and `6`; discounting `2` balances them.

### Example 3
**Input:** `grid = [[1,2,4],[2,3,5]]`  
**Output:** `false`

---

## Intuition

A direct brute-force check of every cut and every removable cell would be too slow.  
The key idea is to process cut lines incrementally and maintain running sums of one side versus the other.

For each cut:
- If sums are equal, we are done.
- Otherwise, we need to know whether removing exactly one allowed cell with value `abs(diff)` can balance both sides while preserving connectivity constraints.

The provided solution handles horizontal cuts, then reuses the same logic for vertical cuts through transposition.

---

## Approach

1. Compute total grid sum.
2. Scan all possible horizontal cuts (`0 ... m-2`) while building the top-part sum incrementally.
3. For each cut:
- Let `diff = top - bottom`.
- If `diff == 0`, return `true`.
- Otherwise, check whether a valid removable cell of value `diff` exists under the constraints.
4. Reverse rows and run the same horizontal check again to cover symmetric edge cases.
5. Transpose the grid and repeat steps above to simulate vertical cuts.
6. If no valid cut is found, return `false`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` |
| **Space** | `O(m * n)` (transpose + hash set across checks) |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for(int i = 0; i <= m-2; i++) {

            for(int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = top - bottom;

            if (diff == 0) return true;

            if (diff == (ll)grid[0][0])   return true;
            if (diff == (ll)grid[0][n-1]) return true;
            if (diff == (ll)grid[i][0]) return true;

            if(i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if(checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));

        if(checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));

        vector<vector<int>> transposeGrid(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorCuts(transposeGrid)) {
            return true;
        }

        reverse(begin(transposeGrid), end(transposeGrid));

        if(checkHorCuts(transposeGrid)) {
            return true;
        }

        return false;
    }
};
```

---

## Key Takeaways

- Prefix-like running sums allow cut evaluation in linear scan order.
- Transposition is a clean way to reuse horizontal-cut logic for vertical cuts.
- Hash-based lookups help validate whether balancing by one discounted cell is possible.
