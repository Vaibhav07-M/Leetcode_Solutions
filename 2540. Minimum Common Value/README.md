# 2540. Minimum Common Value

**Difficulty:** `Easy`  
**Tags:** `Array`, `Two Pointers`

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

[LeetCode — 2540. Minimum Common Value](https://leetcode.com/problems/minimum-common-value/)

---

## Problem Summary

You are given two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order.

Return the **minimum integer that appears in both arrays**. If there is no common value, return `-1`.

---

## Examples

### Example 1
**Input:** `nums1 = [1,2,3], nums2 = [2,4]`  
**Output:** `2`  
**Explanation:** The smallest value present in both arrays is `2`.

### Example 2
**Input:** `nums1 = [1,2,3,6], nums2 = [2,3,4,5]`  
**Output:** `2`  
**Explanation:** Common values are `2` and `3`; the smallest is `2`.

---

## Intuition

Because both arrays are already sorted, we can scan them similarly to the merge step of merge sort.

- If `nums1[i]` is smaller, it can’t match any earlier element in `nums2`, so we advance `i`.
- If `nums2[j]` is smaller, we advance `j`.
- When they are equal, we found the smallest common value (since we’re moving left-to-right).

---

## Approach

Use two pointers:

1. Initialize `i = 0`, `j = 0`.
2. While `i < nums1.size()` and `j < nums2.size()`:
   - If `nums1[i] == nums2[j]`, return that value.
   - If `nums1[i] < nums2[j]`, increment `i`.
   - Otherwise, increment `j`.
3. If the loop ends, return `-1` (no common value exists).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` — each pointer moves forward at most once per element |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j]) {
                return nums1[i];
            }

            else if(nums1[i] < nums2[j]) {
                i++;
            }

            else {
                j++;
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- Sorted arrays enable a linear two-pointer scan.
- Advancing the pointer at the smaller value never skips a possible smaller common answer.
- This achieves optimal time (`O(n+m)`) with constant extra space.
