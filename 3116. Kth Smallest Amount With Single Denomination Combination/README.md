# 3116. Kth Smallest Amount With Single Denomination Combination

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Binary Search`, `Bit Manipulation`, `Combinatorics`, `Number Theory`

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

[LeetCode — 3116. Kth Smallest Amount With Single Denomination Combination](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/)

---

## Problem Summary

You are given an integer array coins representing coins of different denominations and an integer k.  
You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, math, binary search, bit manipulation, combinatorics, number theory. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

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
    typedef long long ll;

    ll countSmaller(ll mid, vector<int>& coins) { 
        ll correctedCount = 0;
        int n = coins.size();

        //2^n * n * log(maxCoin)
        for(int expressions = 1; expressions <= (1 << n)-1; expressions++) { //2^n-1 expressions
            ll lcm = 0;
            ll order = 0; //even or odd order of expressions

            for(int i = 0; i < n; i++) {
                if(expressions & (1 << i)) {
                    order++; //we have taken ith coin

                    if(lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order % 2 == 0) { //even then subtract
                correctedCount -= mid/lcm;
            } else {
                correctedCount += mid/lcm;
            }
        }

        return correctedCount;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;

        ll l = 1;
        ll r = (ll)(*max_element(begin(coins), end(coins))) * k;

        //log(maxCoin * k) * 2^n * n * log(maxCoin)
        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(countSmaller(mid, coins) >= k) { //left side me we can find kth smallest element
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Math, Binary Search, Bit Manipulation, Combinatorics, Number Theory patterns often reduce an apparently complex problem to a few simple rules.
