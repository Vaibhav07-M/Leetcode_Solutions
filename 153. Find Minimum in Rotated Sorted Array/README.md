# 153. Find Minimum in Rotated Sorted Array

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

[LeetCode — 153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

---

## Problem Summary

Given a sorted array of unique integers that has been rotated between 1 and n times, return the minimum element. The algorithm must run in $O(\log n)$ time.

---

## Examples

### Example 1
**Input:** `nums = [3,4,5,1,2]`  
**Output:** `1`

### Example 2
**Input:** `nums = [4,5,6,7,0,1,2]`  
**Output:** `0`

### Example 3
**Input:** `nums = [11,13,15,17]`  
**Output:** `11`

---

## Intuition

The array is two sorted subarrays: one from rotation point to end, and the other from start to rotation point. The minimum is the rotation pivot. Binary search can locate the pivot using comparisons to the rightmost or leftmost element.

---

## Approach

Use modified binary search:
1. Maintain `lo=0`, `hi=n-1`.
2. If `nums[lo] <= nums[hi]`, array is already sorted — return `nums[lo]`.
3. While `lo < hi`:
   - mid = lo + (hi-lo)/2
   - If `nums[mid] > nums[hi]`, minimum is in right half → `lo = mid + 1`
   - Else, minimum is in left half including mid → `hi = mid`
4. Return `nums[lo]`.

This guarantees $O(\log n)$ time.

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
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] < nums[hi]) return nums[lo];
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
```

---

## Key Takeaways

- Rotated sorted arrays can be searched in $O(\log n)$ by comparing mid to endpoints.
- Check for already-sorted subarray as a fast path.
- Handle edge cases with single-element arrays.
