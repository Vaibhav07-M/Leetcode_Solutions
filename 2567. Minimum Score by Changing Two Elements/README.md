# 2567. Minimum Score by Changing Two Elements

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`

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

[LeetCode — 2567. Minimum Score by Changing Two Elements](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)

---

## Problem Summary

The problem requires minimizing the sum of the maximum and minimum absolute differences in an integer array by changing two elements. The goal is to reduce the 'high score' (max difference) while keeping the 'low score' (min difference) as small as possible, ideally zero.

---

## Examples

_No examples provided._

---

## Intuition

To minimize the score, we aim to make the array as uniform as possible. Since we can change two elements, the strategy is to adjust them to reduce the spread of the data. The solution considers three scenarios: removing the two largest elements, removing the two smallest elements, and removing one large and one small element. The optimal choice is the one that results in the smallest maximum difference among the remaining elements.

---

## Approach

1. Sort the array in ascending order to easily identify the smallest and largest elements.
2. Calculate the maximum absolute difference for three specific configurations: removing the last two elements (nums[n-3] - nums[0]), removing the first two elements (nums[n-1] - nums[2]), and removing the first and last elements (nums[n-2] - nums[1]).
3. Return the minimum value from these three calculations, which represents the lowest possible score after the two changes.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant operation is sorting the array, which has a time complexity of O(n log n). The subsequent calculations are linear and do not change the overall bound. |
| **Space** | `O(1)` — The algorithm uses a constant amount of extra space for variables and does not require additional data structures proportional to the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        //sort
        sort(begin(nums), end(nums));

        // low score = 0, bas high ko minimize karna hai
        return min({
            nums[n-3] - nums[0], // do sabse bade hatao
            nums[n-1] - nums[2], // do sabse chhote hatao
            nums[n-2] - nums[1]  // ek bada + ek chhota hatao
        });
    }
};
```

---

## Key Takeaways

- Sorting is a crucial first step to visualize the distribution of the data and identify outliers.
- The problem can be solved by evaluating a few specific cases rather than trying to optimize every possible pair of changes.
- The optimal solution often involves reducing the variance by bringing the extremes closer to the center of the data range.
