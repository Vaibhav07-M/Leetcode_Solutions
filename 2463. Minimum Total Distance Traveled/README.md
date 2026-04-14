# 2463. Minimum Total Distance Traveled

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Sorting`

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

[LeetCode - 2463. Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/)

---

## Problem Summary

You are given:
- an array `robot`, where `robot[i]` is the position of robot `i`
- an array `factory`, where `factory[j] = [positionj, limitj]`

Each robot must be repaired by some factory, and each factory can repair at most its `limit` robots.
Robots move on the X-axis, and moving from `x` to `y` costs `|x - y|`.

Return the minimum possible total distance so that all robots are repaired.

---

## Examples

### Example 1
**Input:** `robot = [0,4,6]`, `factory = [[2,2],[6,2]]`  
**Output:** `4`

**Explanation:**
- Assign robots at `0` and `4` to factory `2`.
- Assign robot at `6` to factory `6`.
- Total = `|2-0| + |2-4| + |6-6| = 4`.

### Example 2
**Input:** `robot = [1,-1]`, `factory = [[-2,1],[2,1]]`  
**Output:** `2`

**Explanation:**
- Robot `-1` -> factory `-2` (cost `1`)
- Robot `1` -> factory `2` (cost `1`)
- Total = `2`.

---

## Intuition

After sorting robots and factories by position, optimal assignments become order-preserving.
That means we can process factories from left to right and decide how many of the first `i` robots are repaired using the first `j` factories.

This naturally leads to DP:
- `dp[i][j]` = minimum cost to repair first `i` robots using first `j` factories.

At factory `j`, either:
- we skip it, or
- we assign `k` robots to it (up to its limit), and add their total distance cost.

---

## Approach

1. Sort `robot` and `factory` by position.
2. Let `n = robot.size()`, `m = factory.size()`.
3. Use 2D DP table initialized to `INF`:
   - `dp[0][j] = 0` for all `j` (no robots costs 0).
4. For each factory `j`:
   - carry over `dp[i][j-1]` (skip current factory)
   - try assigning `k = 1..min(i, limit)` robots ending at `i` to this factory
   - update `dp[i][j] = min(dp[i][j], dp[i-k][j-1] + assignmentCost)`
5. Return `dp[n][m]`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * limit)` in worst case (bounded by roughly `O(10^6)` for constraints) |
| **Space** | `O(n * m)` |

---

## Code (C++)

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        const long long INF = 1e18;

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, INF));

        // base case
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int j = 1; j <= m; j++) {
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];

            for(int i = 0; i <= n; i++) {
                // skip this factory
                dp[i][j] = dp[i][j-1];

                long long cost = 0;

                // assign k robots
                for(int k = 1; k <= min(i, limit); k++) {
                    cost += abs(robot[i-k] - pos);
                    dp[i][j] = min(dp[i][j],
                                   dp[i-k][j-1] + cost);
                }
            }
        }

        return dp[n][m];
    }
};
```

---

## Key Takeaways

- Sorting enables an order-preserving assignment DP.
- `dp[i][j]` with a "take `k` robots" transition handles factory capacity cleanly.
- Incremental `cost` accumulation inside the `k` loop keeps transitions efficient.