# 3348. Smallest Divisible Digit Product II

**Difficulty:** `Hard`  
**Tags:** `Math`, `Greedy`, `Number Theory`, `String`

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

[LeetCode — 3348. Smallest Divisible Digit Product II](https://leetcode.com/problems/smallest-divisible-digit-product-ii/)

---

## Problem Summary

You are given a string `num` representing a positive integer, and an integer `t`.

A number is called **zero-free** if none of its digits are `0`.

Return a string representing the **smallest zero-free number greater than or equal to `num`** such that the **product of its digits is divisible by `t`**. If no such number exists, return `"-1"`.

---

## Examples

### Example 1
**Input:** `num = "1234", t = 256`  
**Output:** `"1488"`  
**Explanation:**  
The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

### Example 2
**Input:** `num = "12355", t = 50`  
**Output:** `"12355"`  
**Explanation:**  
12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

### Example 3
**Input:** `num = "11111", t = 26`  
**Output:** `"-1"`  
**Explanation:**  
No number greater than 11111 has the product of its digits divisible by 26.

---

## Intuition

The key observation is that the product of digits can only contain prime factors `2, 3, 5, 7` (since digits are 1–9). If `t` contains any other prime factor, the answer is immediately `"-1"`.

We need the smallest number ≥ `num` that is zero-free and satisfies the divisibility condition. A greedy approach works: try to keep the prefix of `num` as long as possible, and when we must increase a digit, fill the remaining positions with the smallest possible digits that satisfy the remaining factor requirement.

---

## Approach

1. **Prime Factor Check**: Factorize `t`. If any prime factor > 7 remains, return `"-1"`.

2. **Prefix Feasibility Tracking**: Compute `remainingFactor[i]` = the factor of `t` still needed after using the first `i` digits of `num` (assuming they are non-zero). Stop if a `0` is encountered since zero-free numbers cannot have `0`.

3. **Check Exact Match**: If `remainingFactor[n] == 1`, then `num` itself satisfies the condition — return it.

4. **Backtrack from Right to Left**: Starting from the rightmost position (or the first `0`), try incrementing the digit at position `i` (from `num[i]+1` to `9`). For each candidate digit, compute the new required factor and check if the remaining positions can be filled with valid digits (1–9) to satisfy it.

5. **Fill Remaining Slots**: Use a helper `freeSlotsFiller(required, length)` that greedily uses the largest possible digits (9 down to 2) to cover the required prime factors, then pads with `1`s. This yields the lexicographically smallest completion for the suffix.

6. **Fallback**: If no valid number of the same length exists, construct the smallest valid number of length `n+1` using `freeSlotsFiller(t, n+1)`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n × log t)` — single pass for prefix factors, backtracking checks at most 9 digits per position |
| **Space** | `O(n)` — for the `remainingFactor` array |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;

    string freeSlotsFiller(ll required, int length) {
        string str;

        for(int digit = 9; digit >= 2; digit--) {
            while(required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        while(str.length() < length) {
            str.push_back('1');
        }

        reverse(begin(str), end(str));

        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t;
        for(int primeFact : {2, 3, 5, 7}) {
            while(temp % primeFact == 0) {
                temp /= primeFact;
            }
        }

        if(temp != 1) {
            return "-1";
        }

        // Precompute remainingFactor[i] = factor remaining after using first i digits
        vector<ll> remainingFactor(n+1, t);
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if(digit == 0) {
                break;
            }

            remainingFactor[i+1] = remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        if(remainingFactor[n] == 1) { // the input itself is sufficient for t
            return num;
        }

        int zeroPos = num.find('0');
        int zeroIdx = n-1;
        if(zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        for(int i = zeroIdx; i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for(int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll furtherRequired = required / gcd(required, digit);
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots);

                if(requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) + char(digit + '0') + requiredNumber;
                }
            }
        }

        return freeSlotsFiller(t, n+1); // fallback: e.g., num = "11", t = 2^15
    }
};
```

---

## Key Takeaways

- **Prime factor constraint**: Digit products can only yield primes 2, 3, 5, 7 — any other prime in `t` makes it impossible.
- **Greedy suffix construction**: To minimize the number, fill remaining positions with the largest possible digits first (9→2), then pad with 1s.
- **Prefix preservation + backtracking**: Keep as much of the original prefix as possible; only increase when necessary, then optimally complete the suffix.
- **GCD-based factor reduction**: Track how much of `t` remains uncovered after each digit using `remainingFactor[i] = remainingFactor[i-1] / gcd(remainingFactor[i-1], digit)`.