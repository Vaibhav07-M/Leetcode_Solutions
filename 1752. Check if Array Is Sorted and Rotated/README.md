# 1752. Check if Array Is Sorted and Rotated

**Difficulty:** `Easy`  
**Tags:** `Array`

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

[LeetCode — 1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

---

## Problem Summary

Given an integer array `nums`, return `true` if the array was originally sorted in non-decreasing order and then rotated some number of positions (including zero). Otherwise, return `false`. Duplicates are allowed.

---

## Examples

### Example 1
**Input:** `nums = [3,4,5,1,2]`  
**Output:** `true`

### Example 2
**Input:** `nums = [2,1,3,4]`  
**Output:** `false`

### Example 3
**Input:** `nums = [1,2,3]`  
**Output:** `true`

---

## Intuition

A sorted (non-decreasing) array rotated will have at most one place where a value decreases (a drop). If there are more than one drop, it cannot be a rotated sorted array.

---

## Approach

1. Count the number of indices `i` where `nums[i] > nums[(i+1) % n]`.
2. If the count is `0` or `1`, the array is sorted and rotated; otherwise it's not.

This handles duplicates correctly because equal elements don't count as drops.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i+1) % n]) ++drops;
            if (drops > 1) return false;
        }
        return true;
    }
};
```

---

## Key Takeaways

- A rotated sorted array has at most one decrease point.
- Counting drops and allowing wrap-around comparison covers the rotation.
