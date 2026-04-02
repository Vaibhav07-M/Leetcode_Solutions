# 3418. Maximum Amount of Money Robot Can Earn

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

[LeetCode - 3418. Maximum Amount of Money Robot Can Earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)

---

## Problem Summary

A robot starts at the top-left of an `m x n` grid and must reach the bottom-right, moving only right or down.

Each cell contains:
- non-negative value: robot gains coins
- negative value: robber steals coins

The robot can neutralize robbers in at most **2** cells on its path, so those negative cells contribute `0` instead of a loss.

Return the maximum total coins the robot can collect. The total can be negative.

---

## Examples

### Example 1
**Input:** `coins = [[0,1,-1],[1,-2,3],[2,-3,4]]`  
**Output:** `8`

### Example 2
**Input:** `coins = [[10,10,10],[10,10,10]]`  
**Output:** `40`

---

## Intuition

At every cell, the decision depends on:
1. current position `(i, j)`
2. how many neutralizations are still available (`0..2`)

So this is a 3D DP state.

If current cell is non-negative, we always take it.
If current cell is negative and we still have neutralizations, we choose the better of:
- taking the loss
- neutralizing this robber and taking `0` from this cell

Because each state repeats through many paths, memoization is required.

---

## Approach

Use top-down DP with memoization:

- `solve(i, j, neu)` = maximum coins from `(i, j)` to destination with `neu` neutralizations left.
- Base cases:
  - out of bounds -> very small value (`INT_MIN`)
  - destination cell -> either take value, or `0` if negative and `neu > 0`
- Transition:
  - `take = coins[i][j] + max(solve(i+1, j, neu), solve(i, j+1, neu))`
  - if `coins[i][j] < 0 && neu > 0`, also try:
    - `skip = max(solve(i+1, j, neu-1), solve(i, j+1, neu-1))`
  - answer is `max(take, skip)`

Memoize results in `t[i][j][neu]` initialized with `INT_MIN`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * 3)` |
| **Space** | `O(m * n * 3)` for DP table + recursion stack |

---

## Code (C++)

```cpp
class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0; // neutralize robber at destination
            }

            return coins[i][j];
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        // Take current cell value
        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        // Neutralize current robber if possible
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};
```

---

## Key Takeaways

- Track limited-use abilities (like neutralizations) as an extra DP dimension.
- For negative cells, compare both actions: accept loss vs consume ability.
- Memoization is essential to avoid exponential recomputation.
- Always model invalid paths safely using a very small sentinel value.
