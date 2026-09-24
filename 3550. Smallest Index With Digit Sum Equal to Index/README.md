# 3550. Smallest Index With Digit Sum Equal to Index

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

[LeetCode — 3550. Smallest Index With Digit Sum Equal to Index](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

---

## Problem Summary

The problem requires finding the smallest index in an integer array where the sum of the digits at that index equals the index itself. If no such index exists, the function should return -1.

---

## Examples

_No examples provided._

---

## Intuition

The solution employs a linear search strategy, iterating through the array to compute the digit sum for each element. By comparing this sum to the current index, it identifies the first instance where the condition is met, ensuring the smallest index is returned.

---

## Approach

1. Iterate through the array using a for loop from index 0 to the end of the array.
2. For each element, calculate the sum of its digits by repeatedly extracting the last digit and dividing the number by 10 until the number is zero.
3. Compare the calculated digit sum with the current index. If they are equal, return the index immediately.
4. If the loop completes without finding a match, return -1 to indicate no such index exists.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * m)` — The time complexity is determined by the need to iterate through the array (O(n)) and, for each element, calculate the digit sum, which takes time proportional to the number of digits in the element (O(m)). Since the elements are integers, this operation is linear relative to the size of the number, making the overall complexity O(n * m). |
| **Space** | `O(1)` — The space complexity is constant because the algorithm uses only a fixed amount of extra memory for variables (such as 'num' and 'sum') regardless of the size of the input array. No additional data structures or recursive calls are employed that would scale with the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            int sum = 0;

            // Calculate digit sum
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            // Check if digit sum equals index
            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- Linear search is an effective method for finding specific conditions within an array when the condition can be efficiently checked.
- Calculating the sum of digits involves a simple while loop to extract and accumulate the digits of an integer.
- The solution correctly handles the case where no valid index is found by returning -1.
