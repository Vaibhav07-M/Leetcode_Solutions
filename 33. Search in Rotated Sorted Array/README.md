# 33. Search in Rotated Sorted Array

**Difficulty:** `Medium`  
**Tags:** `Array`, `Binary Search`

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

[LeetCode — 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

---

## Problem Summary

You are given an integer array `nums` sorted in ascending order with distinct values, which may have been rotated at an unknown pivot. Given a `target`, return its index in `nums` if present, otherwise return `-1`.

You must implement an algorithm with `O(log n)` runtime.

---

## Examples

### Example 1
**Input:** `nums = [4,5,6,7,0,1,2], target = 0`  
**Output:** `4`

### Example 2
**Input:** `nums = [4,5,6,7,0,1,2], target = 3`  
**Output:** `-1`

### Example 3
**Input:** `nums = [1], target = 0`  
**Output:** `-1`

---

## Intuition

Use binary search while detecting which half of the current interval is sorted. If the left half is sorted and the target lies within it, search left; otherwise search right. If the right half is sorted and the target lies within it, search right; otherwise search left.

---

## Approach

1. Initialize `l = 0`, `r = n - 1`.
2. While `l <= r`: compute `mid = (l + r) / 2`.
3. If `nums[mid] == target`, return `mid`.
4. Determine which half is sorted:
   - If `nums[l] <= nums[mid]`, left half is sorted. If `nums[l] <= target < nums[mid]` then `r = mid - 1`; else `l = mid + 1`.
   - Otherwise, right half is sorted. If `nums[mid] < target <= nums[r]` then `l = mid + 1`; else `r = mid - 1`.
5. Return `-1` if not found.

This uses standard rotated-array binary search.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};
```

---

## Key Takeaways

- Rotated array search can be done in `O(log n)` by checking which half is sorted.
- Handle edge cases for single-element arrays and when pivot equals ends.
