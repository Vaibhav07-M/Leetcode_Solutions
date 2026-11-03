# 3736. Minimum Moves to Equal Array Elements III

**Difficulty:** `Easy`  
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

[LeetCode — 3736. Minimum Moves to Equal Array Elements III](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/)

---

## Problem Summary

The problem requires finding the minimum number of moves to make all elements in an integer array equal. Each move allows increasing the value of a single element by 1. The goal is to determine the total number of such moves needed to achieve equality across the entire array.

---

## Examples

_No examples provided._

---

## Intuition

The most efficient strategy is to identify the maximum value in the array and increase all other elements to match it. This minimizes the total number of moves required, as any other target value would necessitate more operations to reach equality.

---

## Approach

1. Identify the maximum element in the array using the `max_element` function.
2. Initialize a counter for the total number of moves.
3. Iterate through the array, calculating the difference between the maximum value and each current element.
4. Accumulate these differences to determine the total number of moves required to equalize the array.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single pass through the array to calculate the sum of differences, which is linear in the number of elements. |
| **Space** | `O(1)` — The solution uses only a constant amount of extra space for variables, regardless of the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Find the maximum element
        int maximum = *max_element(nums.begin(), nums.end());

        int moves = 0;

        // Calculate the required moves
        for (int i = 0; i < nums.size(); i++) {
            moves += maximum - nums[i];
        }

        return moves;
    }
};
```

---

## Key Takeaways

- The optimal solution for equalizing an array is to target the maximum value.
- The problem can be solved efficiently with a single linear scan of the data.
