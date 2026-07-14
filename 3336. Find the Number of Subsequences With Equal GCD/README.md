# 3336. Find the Number of Subsequences With Equal GCD

**Difficulty:** `Hard`  
**Tags:** `Dynamic Programming`, `Math`, `GCD`

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

[LeetCode — 3336. Find the Number of Subsequences With Equal GCD](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/)

---

## Problem Summary

You are given an integer array `nums`.

Your task is to count the number of pairs of **non-empty, disjoint subsequences** `(seq1, seq2)` such that:

- Both subsequences are non-empty.
- They do not share any indices.
- The GCD of `seq1` is equal to the GCD of `seq2`.

Return the total number of such pairs modulo `10^9 + 7`. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:** `nums = [1,2,3,4]`  
**Output:** `10`

---

### Example 2

**Input:** `nums = [10,20,30]`  
**Output:** `2`

---

### Example 3

**Input:** `nums = [1,1,1,1]`  
**Output:** `50`

---

## Intuition

Each element has three possible choices:

- Ignore it.
- Add it to the first subsequence.
- Add it to the second subsequence.

Instead of storing the actual subsequences, we only need to keep track of their current GCDs. Since the maximum value in `nums` is at most `200`, the number of possible GCD states is small enough for dynamic programming.

---

## Approach

1. Find the maximum value in `nums`.
2. Create a DP table where:
   - `dp[g1][g2]` represents the number of ways to obtain:
     - GCD of first subsequence = `g1`
     - GCD of second subsequence = `g2`
3. Initially, both subsequences are empty:
   - `dp[0][0] = 1`
4. For every number:
   - Skip it.
   - Add it to the first subsequence.
   - Add it to the second subsequence.
5. Update GCD values using the `gcd()` function.
6. After processing all numbers, sum all states where:
   - `g1 == g2`
   - `g1 > 0`

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n × M² × log M)` |
| **Space** | `O(M²)` |

Where:

- `n` = size of `nums`
- `M` = maximum value in `nums` (≤ 200)

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(maxVal + 1, vector<int>(maxVal + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp = dp;

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    // Put x into first subsequence
                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;

                    // Put x into second subsequence
                    int ng2 = (g2 == 0 ? x : gcd(g2, x));
                    ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= maxVal; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};
```

---

## Key Takeaways

- DP states are defined by the GCDs of the two subsequences rather than their contents.
- Every element has exactly three choices: skip, add to the first subsequence, or add to the second subsequence.
- The small constraint on element values (`≤ 200`) makes a GCD-state DP feasible.
- Using the GCD operation compresses many subsequences into a manageable number of states.
```