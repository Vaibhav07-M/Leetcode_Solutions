# 1658. Minimum Operations to Reduce X to Zero

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Binary Search`, `Sliding Window`, `Prefix Sum`

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

[LeetCode — 1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

---

## Problem Summary

The problem requires finding the minimum number of operations to reduce a given integer x to zero by removing elements from the left or right of an array. Each removal operation subtracts the element's value from x. The goal is to determine the shortest sequence of removals that results in x being zero, or to identify if such a sequence is impossible.

---

## Examples

### Example 1
**Input:** `nums = [1,1,4,2,3], x = 5`  
**Output:** `2`  
**Explanation:**
- The optimal solution is to remove the last two elements to reduce x to zero.

### Example 2
**Input:** `nums = [5,6,7,8,9], x = 4`  
**Output:** `-1`  

### Example 3
**Input:** `nums = [3,2,20,1,1,3], x = 10`  
**Output:** `5`  
**Explanation:**
- The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

---

## Intuition

The solution employs a sliding window approach to identify a subarray whose sum equals the target value (total - x). By finding the longest such subarray, we can determine the maximum number of elements that can remain in the center, allowing us to calculate the minimum number of elements that must be removed from the ends to reach zero.

---

## Approach

1. Calculate the total sum of the array and determine the target value (total - x). If the target is negative, the operation is impossible.
2. Use a sliding window to iterate through the array, maintaining a sum of the current window.
3. When the window sum exceeds the target, shrink the window from the left until the sum is less than or equal to the target.
4. If the window sum equals the target, update the maximum length of a valid subarray.
5. Return the total number of elements minus the maximum length of the valid subarray, which represents the minimum number of operations required.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the array once with a sliding window, performing constant-time operations for each element. The while loop for shrinking the window is bounded by the total number of elements, resulting in a linear time complexity. |
| **Space** | `O(1)` — The solution uses only a few integer variables (total, target, left, sum, maxLength) to store state, requiring no additional data structures or dynamic memory allocation proportional to the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target is negative,
        // it is impossible.
        if (target < 0)
            return -1;

        // If target is 0,
        // we have to remove the whole array.
        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Window sum is too large
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a valid subarray
            if (sum == target) {
                maxLength = max(
                    maxLength,
                    right - left + 1
                );
            }
        }

        if (maxLength == -1)
            return -1;

        return n - maxLength;
    }
};
```

---

## Key Takeaways

- The problem can be reframed as finding a subarray with a specific sum, which is a classic application of the sliding window technique.
- The minimum number of operations corresponds to the length of the array minus the length of the longest subarray that satisfies the condition.
- The solution efficiently handles the case where the target is zero or negative, providing clear error conditions.
