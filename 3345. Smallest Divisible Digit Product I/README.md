# 3345. Smallest Divisible Digit Product I

**Difficulty:** `Easy`  
**Tags:** `Math`, `Simulation`

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

[LeetCode — 3345. Smallest Divisible Digit Product I](https://leetcode.com/problems/smallest-divisible-digit-product-i/)

---

## Problem Summary

You are given two integers `n` and `t`. Return the **smallest number greater than or equal to `n`** such that the **product of its digits** is divisible by `t`.

---

## Examples

### Example 1
**Input:** `n = 10, t = 2`  
**Output:** `10`  
**Explanation:**  
The digit product of 10 is `1 × 0 = 0`, which is divisible by 2.

### Example 2
**Input:** `n = 15, t = 3`  
**Output:** `16`  
**Explanation:**  
The digit product of 16 is `1 × 6 = 6`, which is divisible by 3.

---

## Intuition

Since the constraints are small (`n ≤ 100`, `t ≤ 10`), we can simply check each number starting from `n` until we find one whose digit product is divisible by `t`. The digit product of any number containing `0` is `0`, which is divisible by any positive `t`.

---

## Approach

1. Start from `n` and check each subsequent number.
2. For each number, compute the product of its digits.
3. If the product is divisible by `t`, return that number.
4. Otherwise, increment and repeat.

This brute-force simulation works efficiently given the small constraints.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(k × d)` where `k` is the number of iterations (at most ~100) and `d` is the number of digits (at most 3) |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int product = 1;

            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};
```

---

## Key Takeaways

- Small constraints often allow simple brute-force solutions.
- Digit product becomes `0` if any digit is `0`, making it divisible by any `t > 0`.
- Simulation with early exit is clean and effective for such problems.