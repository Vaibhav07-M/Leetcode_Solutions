# 2089. Find Target Indices After Sorting Array

**Difficulty:** `Easy`  
**Tags:** `Array`, `Binary Search`, `Sorting`

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

[LeetCode — 2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)

---

## Problem Summary

The problem requires finding all indices in a given integer array where the value equals a specified target, after the array has been sorted in non-decreasing order. The output should be a list of these target indices, sorted in increasing order, or an empty list if no such indices exist.

---

## Examples

### Example 1
**Input:** `nums = [1,2,5,2,3], target = 2`  
**Output:** `[1,2]`  
**Explanation:**
- After sorting, nums is [1,2,2,3,5].
- The indices where nums[i] == 2 are 1 and 2.

### Example 2
**Input:** `nums = [1,2,5,2,3], target = 3`  
**Output:** `[3]`  
**Explanation:**
- After sorting, nums is [1,2,2,3,5].
- The index where nums[i] == 3 is 3.

### Example 3
**Input:** `nums = [1,2,5,2,3], target = 5`  
**Output:** `[4]`  
**Explanation:**
- After sorting, nums is [1,2,2,3,5].
- The index where nums[i] == 5 is 4.

---

## Intuition

Since the target indices are defined as the positions of the target value in the sorted array, the most straightforward approach is to first sort the input array. Then, iterate through the sorted array to identify all elements that match the target, recording their indices. This ensures the returned indices correspond to the sorted state of the data.

---

## Approach

1. Sort the input array 'nums' in non-decreasing order using the standard library sort function.
2. Initialize an empty vector 'ans' to store the target indices.
3. Iterate through the sorted array from index 0 to the end.
4. For each element, check if it is equal to the target. If it is, add the current index to the 'ans' vector.
5. Return the 'ans' vector, which now contains all target indices in increasing order.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant operation is sorting the array, which has a time complexity of O(n log n). The subsequent linear scan to find target indices is O(n), but the sorting step determines the overall bound. |
| **Space** | `O(1)` — The space complexity is constant relative to the input size. The output vector 'ans' stores indices, which are integers, and its size is bounded by the number of occurrences of the target, which is typically much smaller than the input array size. The sorting is performed in-place, so no significant extra space is used. |

---

## Code (C++)

```cpp

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Sorting is a fundamental step when dealing with index-based queries on unordered data.
- A linear scan is efficient for finding specific values in a sorted list.
- The problem demonstrates how to map a value-based query to a specific index output.
