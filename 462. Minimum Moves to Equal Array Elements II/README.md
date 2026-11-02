# 462. Minimum Moves to Equal Array Elements II

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Sorting`

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

[LeetCode — 462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

---

## Problem Summary

The problem requires minimizing the total number of moves needed to make all elements in an integer array equal. Each move allows for incrementing or decrementing an element by 1. The goal is to find the optimal value to which all elements should be adjusted to minimize the sum of absolute differences.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3]`  
**Output:** `2`  
**Explanation:**
- Only two moves are needed (remember each move increments or decrements one element):
- [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

### Example 2
**Input:** `nums = [1,10,2,9]`  
**Output:** `16`  

---

## Intuition

The optimal strategy is to set all elements to the median of the sorted array. This minimizes the total absolute deviation because the median is the point where the sum of distances to the left is equal to the sum of distances to the right, effectively balancing the 'cost' of moving elements up or down.

---

## Approach

1. Sort the input array to easily identify the median.
2. Calculate the median value (the middle element of the sorted array).
3. Iterate through the sorted array, accumulating the absolute difference between each element and the median.
4. Return the total sum of these differences, which represents the minimum number of moves required.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant operation is sorting the array, which has a time complexity of O(n log n). The subsequent iteration to calculate the sum of differences is linear, O(n), but the sorting step determines the overall bound. |
| **Space** | `O(1)` — The algorithm uses a constant amount of extra space for variables (like the median and moves counter). The sorting is performed in-place, and no additional data structures are created that scale with the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());

        // Find the median
        int median = nums[nums.size() / 2];

        int moves = 0;

        // Calculate total moves
        for (int i = 0; i < nums.size(); i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};
```

---

## Key Takeaways

- The median is the optimal target value for minimizing the sum of absolute deviations in a set of numbers.
- Sorting is a necessary first step to efficiently locate the median and calculate the total deviation.
- This problem demonstrates a classic application of the median in optimization, particularly in the context of minimizing transportation or adjustment costs.
