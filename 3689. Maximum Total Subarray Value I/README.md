# 3689. Maximum Total Subarray Value I

**Difficulty:** `Medium`  
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

[LeetCode — 3689. Maximum Total Subarray Value I](https://leetcode.com/problems/maximum-total-subarray-value-i/)

---

## Problem Summary

Given an integer array `nums` and an integer `k`, choose exactly `k` non-empty subarrays (they may overlap and may repeat). The value of a subarray is `max(subarray) - min(subarray)`. Return the maximum possible total value by choosing `k` subarrays.

---

## Examples

### Example 1
**Input:** `nums = [1,3,2], k = 2`  
**Output:** `4`

### Example 2
**Input:** `nums = [4,2,5,1], k = 3`  
**Output:** `12`

---

## Intuition

The best single subarray value is obtained by taking a subarray that contains the global maximum and global minimum of `nums` (their difference). Since subarrays can repeat and overlap, choosing that best subarray `k` times yields `k * (global_max - global_min)`.

---

## Approach

1. Scan `nums` once to find `mx = max(nums)` and `mn = min(nums)`.
2. The optimal strategy is to pick the subarray covering `mn` and `mx` repeatedly `k` times.
3. Return `1LL * k * (mx - mn)`.

This is linear time and constant extra space.

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
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = *max_element(nums.begin(), nums.end());
        long long mn = *min_element(nums.begin(), nums.end());
        return 1LL * k * (mx - mn);
    }
};
```

---

## Key Takeaways

- When repetition is allowed, repeating the globally best subarray is optimal.
- Linear scan to find min/max suffices; complexity is `O(n)`.
