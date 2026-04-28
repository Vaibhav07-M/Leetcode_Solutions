# 2033. Minimum Operations to Make a Uni-Value Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Math`, `Sorting`

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

[LeetCode — 2033. Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)

---

## Problem Summary

You are given a 2D integer grid of size `m x n` and an integer `x`. In one operation you can add `x` to or subtract `x` from any element in the grid. A uni-value grid is a grid where all the elements are equal. Return the minimum number of operations to make the grid uni-value, or `-1` if impossible.

---

## Examples

### Example 1
**Input:** `grid = [[2,4],[6,8]], x = 2`  
**Output:** `4`  
**Explanation:** Make all elements equal to `4` using 4 operations.

### Example 2
**Input:** `grid = [[1,5],[2,3]], x = 1`  
**Output:** `5`  
**Explanation:** Make all elements equal to `3`.

### Example 3
**Input:** `grid = [[1,2],[3,4]], x = 2`  
**Output:** `-1`  
**Explanation:** Impossible because elements are not congruent modulo `x`.

---

## Intuition

If it's possible to make all cells equal, all cell values must be congruent modulo `x`. After confirming that, the minimum number of add/subtract operations to make all values equal is achieved by choosing a target equal to the median of the flattened values (in steps of `x`). Converting values to their relative coordinates (value / x) reduces the problem to bringing all integers to the same value using unit increments.

---

## Approach

1. Flatten the grid to a single array `vals` and check that all `vals[i] % x` are equal. If not, return `-1`.
2. Transform each value to `vals[i] / x` (integer division) to count how many unit moves are needed.
3. Choose the median `m` of transformed values; sum absolute differences to `m` — that sum is the minimal number of unit moves. Multiply by `1` (already in units) to get operations.

This works because moving to the median minimizes sum of absolute deviations.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m*n log(m*n))` — sorting the flattened array |
| **Space** | `O(m*n)` — flattened array |

---

## Code (C++)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vals;
        vals.reserve(m * n);
        for (auto &row : grid) for (int v : row) vals.push_back(v);

        int r = vals[0] % x;
        for (int v : vals) if (v % x != r) return -1;

        vector<int> t(vals.size());
        for (size_t i = 0; i < vals.size(); ++i) t[i] = vals[i] / x;

        sort(t.begin(), t.end());
        int mid = t[t.size() / 2];
        long long ops = 0;
        for (int v : t) ops += llabs((long long)v - mid);
        return ops;
    }
};
```

---

## Key Takeaways

- Feasibility requires all values congruent modulo `x`.
- After normalizing by `x`, target the median to minimize moves.
- Flattening + sorting is straightforward and sufficient within constraints.
