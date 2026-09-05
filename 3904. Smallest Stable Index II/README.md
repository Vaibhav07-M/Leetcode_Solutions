# 3904. Smallest Stable Index II

**Difficulty:** `Medium`  
**Tags:** `Array`, `Prefix Sum`

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

[LeetCode — 3904. Smallest Stable Index II](https://leetcode.com/problems/smallest-stable-index-ii/)

---

## Problem Summary

The problem requires finding the smallest index 'i' in an integer array 'nums' where the difference between the maximum value in the prefix [0..i] and the minimum value in the suffix [i..n-1] is less than or equal to a given threshold 'k'. If no such index exists, the function should return -1.

---

## Examples

_No examples provided._

---

## Intuition

To efficiently determine the instability score for each index, the solution uses a 'sweep' approach. It calculates the minimum value for each suffix (from right to left) and the maximum value for each prefix (from left to right). By comparing these values at each index, it can quickly identify the first index where the score meets the stability criterion.

---

## Approach

1. Initialize a vector 'right' to store the minimum value for each suffix. Set the last element to the value at index n-1.
2. Iterate from index n-2 down to 0, updating 'right[i]' to be the minimum of the current element and the next element's minimum.
3. Initialize a variable 'left' to 0 to track the maximum value in the prefix.
4. Iterate from index 0 to n-1. At each step, update 'left' to be the maximum of the current element and the previous maximum.
5. Check if the difference between 'left' and 'right[i]' is less than or equal to 'k'. If true, return the current index 'i' as the first stable index.
6. If no index satisfies the condition after the loop, return -1.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The solution involves two linear passes through the array: one to compute the suffix minima and another to compute the prefix maxima and check the stability condition. This results in a total time complexity of O(n). |
| **Space** | `O(n)` — An additional vector 'right' of size 'n' is used to store the suffix minimum values. This extra storage is necessary to perform the comparison in the second loop, leading to a space complexity of O(n). |

---

## Code (C++)

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> right(n);

        // Suffix minimum
        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        // Prefix maximum
        int left = 0;

        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);

            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- The use of prefix and suffix arrays is a powerful technique for solving problems that require comparing values across different segments of an array.
- By pre-computing the minimums and maximums, the algorithm avoids redundant calculations and can make decisions in constant time during the sweep.
