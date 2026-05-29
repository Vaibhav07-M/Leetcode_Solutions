# 3300. Minimum Element After Replacement With Digit Sum

**Difficulty:** `Easy`  
**Tags:** `Array`, `Math`

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

[LeetCode — 3300. Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)

---

## Problem Summary

Given an integer array `nums`, replace each element with the sum of its digits (once). Return the minimum element in the array after performing this replacement for every element.

---

## Examples

### Example 1
**Input:** nums = [10,12,13,14]  
**Output:** 1

### Example 2
**Input:** nums = [1,2,3,4]  
**Output:** 1

### Example 3
**Input:** nums = [999,19,199]  
**Output:** 10

---

## Intuition

Summing digits of a number is independent per element. After replacing each number with its digit-sum, the answer is simply the minimum among those sums.

---

## Approach

1. Iterate through `nums`.
2. For each number, compute its digit sum by repeatedly extracting digits and summing them.
3. Track the minimum digit-sum seen and return it.

This runs in O(n * d) where d is average number of digits (bounded by a small constant).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * d)` — `d` is digits per number (<= 5 for constraints) |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int x : nums) {
            int s = 0;
            int y = x;
            while (y > 0) { s += y % 10; y /= 10; }
            ans = min(ans, s);
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Digit-sum is a local transformation per element; compute and take the minimum.
- Complexity is linear in number of elements with a small per-number cost.
