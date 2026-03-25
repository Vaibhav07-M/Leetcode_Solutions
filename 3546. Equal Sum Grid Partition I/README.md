# 3546. Equal Sum Grid Partition I

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

[LeetCode - 3546. Equal Sum Grid Partition I](https://leetcode.com/problems/equal-sum-grid-partition-i/)

---

## Problem Summary

You are given an `m x n` matrix `grid` of positive integers.

You need to determine whether it is possible to make exactly one cut:
- horizontally between two rows, or
- vertically between two columns,

such that:
- both resulting parts are non-empty, and
- the sum of both parts is equal.

Return `true` if such a cut exists, otherwise return `false`.

---

## Examples

### Example 1
**Input:** `grid = [[1,4],[2,3]]`  
**Output:** `true`  
**Explanation:** A horizontal cut between row `0` and row `1` gives sums `5` and `5`.

### Example 2
**Input:** `grid = [[1,3],[2,4]]`  
**Output:** `false`  
**Explanation:** No horizontal or vertical cut produces equal sums.

---

## Intuition

If the total sum of the grid is odd, equal partition is impossible.
If it is even, each side must have sum `total / 2`.

A valid cut means that while scanning rows (for horizontal cuts) or columns (for vertical cuts), a running sum reaches exactly that target before the last row/column (to keep both parts non-empty).

---

## Approach

1. Compute `total` sum of all cells.
2. If `total` is odd, return `false`.
3. Set `target = total / 2`.
4. Check horizontal cuts:
   - accumulate row sums from top to bottom,
   - stop at `m - 2` (cut after row `i`, so both parts stay non-empty),
   - if running sum equals `target`, return `true`.
5. Check vertical cuts similarly by accumulating column sums up to `n - 2`.
6. If no cut matches, return `false`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // Total sum
        for (auto &row : grid) {
            for (auto &val : row) {
                total += val;
            }
        }

        // If odd, equal split is impossible
        if (total % 2 != 0) return false;

        long long target = total / 2;

        // Check horizontal cuts
        long long sum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        // Check vertical cuts
        sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        return false;
    }
};
```

---

## Key Takeaways

- Equal partition requires an even total sum.
- Valid cuts are found using linear scans over row/column prefix sums.
- Enforcing non-empty sections means excluding the final row/column as a cut boundary.
