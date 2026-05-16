# 154. Find Minimum in Rotated Sorted Array II

**Difficulty:** `Hard`  
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

[LeetCode - 154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

---

## Problem Summary

You are given a sorted array that was rotated between `1` and `n` times.
Unlike problem 153, this array may contain duplicates.
Return the minimum element.

---

## Examples

### Example 1
**Input:** `nums = [1,3,5]`  
**Output:** `1`

### Example 2
**Input:** `nums = [2,2,2,0,1]`  
**Output:** `0`

---

## Intuition

With no duplicates, binary search cleanly decides which half to keep.
With duplicates, equal boundary values can hide the pivot and make the decision ambiguous.
So when boundaries are equal, we safely shrink the search range.

---

## Approach

Use modified binary search with duplicate handling:

1. Initialize `l = 0`, `r = n - 1`.
2. While `l < r`:
   - Compute `mid = l + (r - l) / 2`.
   - If `nums[mid] < nums[r]`, minimum is in left half (including `mid`) -> `r = mid`.
   - If `nums[mid] > nums[r]`, minimum is in right half -> `l = mid + 1`.
   - Else (`nums[mid] == nums[r]`), decrease `r` by one to remove ambiguity.
3. Return `nums[l]`.

This keeps correctness while handling duplicate-heavy inputs.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` average, `O(n)` worst case (many duplicates) |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r--;
            }
        }

        return nums[l];
    }
};
```

---

## Key Takeaways

- Duplicate values can break the strict half-selection of normal binary search.
- Shrinking one boundary on equality keeps the algorithm correct.
- Worst-case runtime degrades to `O(n)` when duplicates dominate.
