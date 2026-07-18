# 1979. Find Greatest Common Divisor of Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `Math`, `Number Theory`, `GCD`

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

[LeetCode — 1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)

---

## Problem Summary

Given an integer array `nums`, return the greatest common divisor (GCD) of the **smallest** and **largest** elements in the array.

The GCD of two numbers is the largest positive integer that divides both numbers.

---

## Examples

### Example 1

**Input:** `nums = [2,5,6,9,10]`

**Output:** `2`

**Explanation:**

- Smallest element = `2`
- Largest element = `10`
- `gcd(2,10) = 2`

---

### Example 2

**Input:** `nums = [7,5,6,8,3]`

**Output:** `1`

**Explanation:**

- Smallest element = `3`
- Largest element = `8`
- `gcd(3,8) = 1`

---

### Example 3

**Input:** `nums = [3,3]`

**Output:** `3`

---

## Intuition

The problem only asks for the GCD of the smallest and largest numbers in the array. Therefore, there is no need to compute the GCD of every element.

Simply find:

- the minimum element,
- the maximum element,

and compute their GCD.

---

## Approach

1. Find the minimum element in the array.
2. Find the maximum element in the array.
3. Compute `gcd(minimum, maximum)`.
4. Return the result.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};
```

---

## Key Takeaways

- Only the smallest and largest elements affect the answer.
- Use `min_element()` and `max_element()` from the STL for concise code.
- The built-in `gcd()` function efficiently computes the greatest common divisor.
- The solution requires a single traversal of the array, giving **O(n)** time complexity.