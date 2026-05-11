# 2553. Separate the Digits in an Array

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

[LeetCode — 2553. Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array/)

---

## Problem Summary

Given an array of positive integers `nums`, return an array containing all digits of each number in the same order they appear.

For each `nums[i]`, split it into its digits from left to right, and append them to the answer.

---

## Examples

### Example 1
**Input:** `nums = [13,25,83,77]`  
**Output:** `[1,3,2,5,8,3,7,7]`

### Example 2
**Input:** `nums = [7,1,3,9]`  
**Output:** `[7,1,3,9]`

---

## Intuition

If we repeatedly take `% 10` from a number, digits come out in reverse order. So for each number, we can collect digits into a temporary list and then reverse it before appending to the final answer.

---

## Approach

1. Initialize an empty result array `ans`.
2. For each number `x` in `nums`:
   - Extract digits using `% 10` and `/= 10`, store them in a temporary vector.
   - Reverse the temporary vector to restore left-to-right order.
   - Append all temporary digits to `ans`.
3. Return `ans`.

This preserves the order of numbers and the order of digits inside each number.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(d)` where `d` is the total number of digits across all numbers |
| **Space** | `O(d)` for output (and temporary digit storage per number) |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            vector<int> tmp;
            while (x > 0) {
                tmp.push_back(x % 10);
                x /= 10;
            }

            reverse(tmp.begin(), tmp.end());
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }

        return ans;
    }
};
```

---

## Key Takeaways

- `% 10` and `/ 10` are natural tools for digit extraction.
- Reverse per-number digits to keep original left-to-right order.
- Appending in traversal order keeps the final array correctly ordered.
