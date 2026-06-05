# 3753. Total Waviness of Numbers in Range II

**Difficulty:** `Hard`  
**Tags:** `Math`, `Digit DP`, `Dynamic Programming`

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

[LeetCode — 3753. Total Waviness of Numbers in Range II](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/)

---

## Problem Summary

Given integers `num1` and `num2` defining an inclusive range `[num1, num2]`, the waviness of a number is the count of peaks and valleys among its digits (a peak is a digit strictly greater than both neighbors; a valley is strictly less than both neighbors). The first and last digits cannot be peaks/valleys. Numbers with fewer than 3 digits have waviness `0`.

Return the total waviness summed over all numbers in the range `[num1, num2]`.

Constraints: `1 <= num1 <= num2 <= 1e15`.

---

## Examples

### Example 1
**Input:** `num1 = 120, num2 = 130`  
**Output:** `3`

### Example 2
**Input:** `num1 = 198, num2 = 202`  
**Output:** `3`

### Example 3
**Input:** `num1 = 4848, num2 = 4848`  
**Output:** `2`

---

## Intuition

Brute-force enumeration is too slow when the range can be as large as 1e15. Use digit DP to count how many numbers up to `x` have each waviness contribution and sum these values; then compute answer as `count(num2) - count(num1-1)`.

The DP keeps track of position, previous two digits, whether we've seen any non-zero digit (leading zeros), and the tight constraint. At each transition we update both the number of ways and the total waviness contributed by placing a new digit.

---

## Approach

Use a memoized DP over digits:
1. Convert the bound `x` to its digit vector (most significant to least).
2. Define `dp(i, prev, prev2, zero, tight)` returning a pair `(count, wavinessSum)` for suffix starting at position `i` given previous digits `prev` and `prev2` (-1 for none), `zero` indicating all leading zeros so far, and `tight` indicating whether prefix equals the bound.
3. For each possible next digit `d` (0..limit), compute new `count` and `wavinessSum` by recursing; if `prev2 != -1` and `!zero` and `prev2, prev, d` form a peak/valley, add the number of new numbers to the waviness sum.
4. Memoize results keyed by `(i, prev, prev2, zero, tight)`.
5. Answer is `count(num2) - count(num1-1)` where `count(x)` returns total waviness sum for all numbers in `[0,x]`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(len * 10 * states)` — effectively bounded by digits (≤16) and small state space |
| **Space** | `O(len * states)` — memo table size |

---

## Code (C++)

```cpp
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        auto count = [&](long long x) {
            if (x < 0) return 0LL;
            string s = to_string(x);
            int n = s.size();
            unordered_map<long long, pair<long long,long long>> memo;

            function<pair<long long,long long>(int,int,int,bool,bool)> dp =
            [&](int i, int prev, int prev2, bool zero, bool tight) -> pair<long long,long long> {
                if (i == n) return {1, 0};
                long long key = i;
                key = key * 11 + (prev + 1);
                key = key * 11 + (prev2 + 1);
                key = key * 2 + (zero ? 1 : 0);
                key = key * 2 + (tight ? 1 : 0);
                if (!tight && memo.count(key)) return memo[key];

                int limit = tight ? (s[i]-'0') : 9;
                long long ways = 0, wav = 0;
                for (int d = 0; d <= limit; ++d) {
                    bool nz = zero && d == 0;
                    auto res = dp(i+1, nz ? -1 : d, prev, nz, tight && d==limit);
                    long long cnt = res.first;
                    long long wsum = res.second;
                    if (!nz && prev != -1 && prev2 != -1) {
                        if ((prev2 < prev && prev > d) || (prev2 > prev && prev < d)) {
                            wav += cnt; // each of these numbers gains +1 waviness at this position
                        }
                    }
                    ways += cnt;
                    wav += wsum;
                }
                if (!tight) memo[key] = {ways, wav};
                return {ways, wav};
            };

            return dp(0, -1, -1, true, true).second;
        };
        return count(num2) - count(num1 - 1);
    }
};
```

---

## Key Takeaways

- For huge ranges, digit DP lets you count properties across all numbers up to a bound efficiently.
- Track both counts and cumulative contributions (waviness) in the DP state.
- Careful handling of leading zeros and memoization (skip tight states) improves performance.
