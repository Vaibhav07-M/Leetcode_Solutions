# 2897. Apply Operations on Array to Maximize Sum of Squares

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Greedy`, `Bit Manipulation`

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

[LeetCode — 2897. Apply Operations on Array to Maximize Sum of Squares](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/)

---

## Problem Summary

The problem involves an array of integers and a parameter k. We can perform a specific bitwise operation on any two distinct elements of the array. The goal is to select k elements from the final array and maximize the sum of their squares. The solution must be returned modulo 10^9 + 7.

---

## Examples

### Example 1
**Input:** `nums = [2,6,5,8], k = 2`  
**Output:** `261`  
**Explanation:**
- We can do the following operations on the array:
- Choose i = 0 and j = 3, then change nums[0] to (2 AND 8) = 0 and nums[3] to (2 OR 8) = 10. The resulting array is nums = [0,6,5,10].
- Choose i = 2 and j = 3, then change nums[2] to (5 AND 10) = 0 and nums[3] to (5 OR 10) = 15. The resulting array is nums = [0,6,0,15].
- We can choose the elements 15 and 6 from the final array. The sum of squares is 152 + 62 = 261.
- It can be shown that this is the maximum value we can get.

### Example 2
**Input:** `nums = [4,5,4,7], k = 3`  
**Output:** `90`  
**Explanation:**
- We do not need to apply any operations.
- We can choose the elements 7, 5, and 4 with a sum of squares: 72 + 52 + 42 = 90.
- It can be shown that this is the maximum value we can get.

---

## Intuition

The key insight is that the bitwise operations (AND and OR) allow us to manipulate the binary representation of the numbers. By strategically applying these operations, we can construct numbers with specific bit patterns. The solution aims to create the largest possible numbers by maximizing the number of '1' bits in the selected elements, which will result in the highest sum of squares.

---

## Approach

1. Initialize a frequency array 'count' to track the number of '1' bits at each bit position (0 to 31) across all input numbers.
2. Iterate through the input array, updating the 'count' array to reflect the distribution of '1' bits.
3. Perform k iterations to select the top k elements. In each iteration, construct a new number 'curr' by setting bits where the frequency is greater than 0, effectively 'borrowing' the most common '1' bits.
4. Calculate the square of the current number and add it to the result, taking the modulo at each step to prevent overflow.
5. Return the final result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * log(max(nums)) + k * log(max(nums)))` — The first term accounts for the initial pass to count bits in the array. The second term represents the time taken to construct and square the top k numbers, which involves iterating over the bit positions for each selection. |
| **Space** | `O(log(max(nums)))` — The space complexity is dominated by the 'count' array, which requires storage proportional to the number of bits in the largest integer (typically 32 for standard int). The other variables are constant in size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int MOD = 1e9+7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        for(int &num : nums) {
            for(int b = 0; b < 32; b++) {
                if(num & (1 << b)) {
                    count[b]++; //found a '1' in this bit position b
                }
            }
        }


        long long result = 0;

        while(k--) {
            long long curr = 0;

            for(int b = 0; b < 32; b++) {
                if(count[b] > 0) {
                    count[b]--;

                    curr = (curr | (1 << b));
                }
            }

            result = (result + (curr*curr)) % MOD;
        }

        return result;

    }
};
```

---

## Key Takeaways

- The solution demonstrates a greedy approach to bit manipulation, selecting the most significant bits first to maximize the value of the constructed numbers.
- It effectively uses a frequency counter to determine the availability of '1' bits, allowing for efficient construction of the optimal subset.
- The modular arithmetic ensures that the result remains within the specified range, which is crucial for large sums of squares.
