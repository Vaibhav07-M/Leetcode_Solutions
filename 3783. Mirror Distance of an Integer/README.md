# 3783. Mirror Distance of an Integer

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

[LeetCode - 3783. Mirror Distance of an Integer](https://leetcode.com/problems/mirror-distance-of-an-integer/)

---

## Problem Summary

Given an integer `n`, define mirror distance as:

`abs(n - reverse(n))`

where `reverse(n)` is formed by reversing the decimal digits of `n` (leading zeros are dropped).  
Return this mirror distance.

---

## Examples

### Example 1
**Input:** `n = 25`  
**Output:** `27`  
**Explanation:** `reverse(25) = 52`, so `abs(25 - 52) = 27`.

### Example 2
**Input:** `n = 10`  
**Output:** `9`  
**Explanation:** `reverse(10) = 1`, so `abs(10 - 1) = 9`.

### Example 3
**Input:** `n = 7`  
**Output:** `0`

---

## Intuition

Build the reversed number digit by digit using modulo and division.  
Once reversed, return absolute difference from the original number.

---

## Approach

1. Store original value `n` in `orignal`.
2. Repeatedly take last digit `digit = n % 10` and append to `reverse`.
3. Divide `n` by `10` to continue.
4. Return `abs(reverse - orignal)`.

The provided implementation also includes overflow guards before appending digits.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(d)` where `d` is number of digits in `n` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int orignal = n;
        while(n!=0) {
            int digit = n%10;
            if(reverse>INT_MAX/10|| (reverse == INT_MAX/10 && digit>7)) return 0;
            if (reverse < INT_MIN/10 || (reverse == INT_MIN/10 && digit < -8)) return 0;
            reverse = (reverse * 10) + digit;
            n /= 10;
        }
        return abs(reverse-orignal);
    }
};
```

---

## Key Takeaways

- Digit reversal is a classic `% 10` and `/ 10` pattern.
- Mirror distance is directly computed once reverse is known.
- This can be solved in constant extra space.