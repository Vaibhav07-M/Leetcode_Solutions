# 1563. Stone Game V

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Dynamic Programming`, `Game Theory`

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

[LeetCode — 1563. Stone Game V](https://leetcode.com/problems/stone-game-v/)

---

## Problem Summary

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.  
In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

---

## Examples

### Example 1
**Input:** `stoneValue = [6,2,3,4,5,5]`  
**Output:** `18`  
**Explanation:**
- In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
- In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
- The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

### Example 2
**Input:** `stoneValue = [7,7,7,7,7,7,7]`  
**Output:** `28`  

### Example 3
**Input:** `stoneValue = [4]`  
**Output:** `0`  

---

## Intuition

The problem revolves around array, math, dynamic programming, game theory. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    int leftSum = prefix[k + 1] - prefix[l];
                    int rightSum = prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Math, Dynamic Programming, Game Theory patterns often reduce an apparently complex problem to a few simple rules.
