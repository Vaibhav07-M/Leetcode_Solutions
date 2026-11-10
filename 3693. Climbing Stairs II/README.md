# 3693. Climbing Stairs II

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`

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

[LeetCode — 3693. Climbing Stairs II](https://leetcode.com/problems/climbing-stairs-ii/)

---

## Problem Summary

You are climbing a staircase with n + 1 steps, numbered from 0 to n.  
You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, dynamic programming. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — each element/state processed once |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);

        // Starting step has zero cost
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            // Jump from i - 1
            if (i >= 1) {
                dp[i] = min(dp[i],
                    dp[i - 1] + costs[i - 1] + 1);
            }

            // Jump from i - 2
            if (i >= 2) {
                dp[i] = min(dp[i],
                    dp[i - 2] + costs[i - 1] + 4);
            }

            // Jump from i - 3
            if (i >= 3) {
                dp[i] = min(dp[i],
                    dp[i - 3] + costs[i - 1] + 9);
            }
        }

        return dp[n];
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Dynamic Programming patterns often reduce an apparently complex problem to a few simple rules.
