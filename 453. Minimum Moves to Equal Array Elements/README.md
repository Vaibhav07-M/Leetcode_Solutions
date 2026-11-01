# 453. Minimum Moves to Equal Array Elements

**Difficulty:** `Medium`  
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

[LeetCode — 453. Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)

---

## Problem Summary

The problem requires minimizing the number of moves to equalize all elements in an integer array. Each move allows incrementing n-1 elements by 1. The goal is to determine the fewest moves needed to reach a uniform state.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3]`  
**Output:** `3`  
**Explanation:**
- Only three moves are needed (remember each move increments two elements):
- [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

### Example 2
**Input:** `nums = [1,1,1]`  
**Output:** `0`  

---

## Intuition

Since incrementing n-1 elements is equivalent to decrementing one element, the optimal strategy is to reduce the maximum elements to the minimum value. The total number of moves corresponds to the sum of the differences between each element and the minimum value, representing the total 'deficit' that needs to be eliminated.

---

## Approach

1. Identify the minimum element in the array using the `min_element` function.
2. Iterate through the array, calculating the difference between each element and the minimum value.
3. Sum these differences to determine the total number of moves required to equalize the array.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The solution involves a single pass through the array to calculate the sum of differences, which is a linear operation. |
| **Space** | `O(1)` — The algorithm uses only a few integer variables for tracking the minimum and the sum, requiring constant space regardless of the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Find the minimum element
        int minimum = *min_element(nums.begin(), nums.end());

        int moves = 0;

        // Calculate total difference
        for (int i = 0; i < nums.size(); i++) {
            moves += nums[i] - minimum;
        }

        return moves;
    }
};
```

---

## Key Takeaways

- The problem can be reframed as a minimization problem where the goal is to reduce the 'height' of the taller elements to the baseline.
- The total moves are directly proportional to the sum of the deviations from the minimum value, providing a simple mathematical formula for the solution.
