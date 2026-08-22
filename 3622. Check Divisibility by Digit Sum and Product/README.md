# 3622. Check Divisibility by Digit Sum and Product

**Difficulty:** `Easy`  
**Tags:** `Math`

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

[LeetCode — 3622. Check Divisibility by Digit Sum and Product](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/)

---

## Problem Summary

The goal is to determine whether a given positive integer n is divisible by the sum of its digit sum and digit product.  
The problem requires calculating the sum and product of the digits of n and checking if n is divisible by their sum.

---

## Examples

_No examples provided._

---

## Intuition

The solution relies on the mathematical property that the remainder of an integer division operation can be used to check for divisibility.  
By calculating the sum and product of the digits of n and checking if n is divisible by their sum using the modulo operator, we can determine the divisibility of n.

---

## Approach

1. Extract each digit of the input number n by taking the remainder of n divided by 10.
2. Calculate the sum of the digits by adding each extracted digit to a running total.
3. Calculate the product of the digits by multiplying each extracted digit with a running product.
4. Remove the last extracted digit from n by performing integer division of n by 10.
5. Repeat steps 1-4 until all digits have been extracted from n.
6. Check if n is divisible by the sum of the digit sum and digit product using the modulo operator.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` — The number of digits in n is proportional to the logarithm of n, and we perform a constant amount of work for each digit. |
| **Space** | `O(1)` — We use a constant amount of space to store the sum, product, and temporary variables. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int product = 1;

        while (temp > 0) {
            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};
```

---

## Key Takeaways

- The modulo operator can be used to check for divisibility.
- Extracting digits from a number can be done using the remainder of integer division by 10.
- Calculating the sum and product of digits can be done using a simple iterative approach.
