# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

**Difficulty:** `Easy`  
**Tags:** `Array`

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

[LeetCode — 3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)

---

## Problem Summary

The problem requires finding the length of the longest subarray in an integer array that is either strictly increasing or strictly decreasing. The solution iterates through the array, maintaining counters for both increasing and decreasing trends, and updates the maximum length found.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to track two separate counters (inc and dec) for the lengths of the current increasing and decreasing sequences. By iterating through the array, we can update these counters based on the comparison of the current element with the previous one, effectively identifying the longest monotonic segment.

---

## Approach

1. Initialize three variables: inc (increasing counter), dec (decreasing counter), and ans (maximum length found), all set to 1.
2. Iterate through the array starting from the second element (index 1).
3. If the current element is greater than the previous one, increment the inc counter and reset the dec counter to 1.
4. If the current element is less than the previous one, increment the dec counter and reset the inc counter to 1.
5. If the current element is equal to the previous one, reset both inc and dec counters to 1.
6. Update the ans variable to the maximum value between the current ans, inc, and dec.
7. Return the final value of ans.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single loop that iterates through the array of size n, performing constant-time operations for each element. Therefore, the time complexity is linear. |
| **Space** | `O(1)` — The solution uses a fixed number of integer variables (inc, dec, ans) regardless of the input size, indicating constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The problem can be solved efficiently with a single pass through the data.
- Maintaining separate counters for increasing and decreasing trends allows for easy identification of the longest monotonic sequence.
- The solution effectively handles the case where the sequence changes direction or remains flat by resetting the appropriate counters.
