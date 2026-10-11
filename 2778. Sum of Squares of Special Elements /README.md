# 2778. Sum of Squares of Special Elements 

**Difficulty:** `Easy`  
**Tags:** `Array`, `Enumeration`

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

[LeetCode — 2778. Sum of Squares of Special Elements ](https://leetcode.com/problems/sum-of-squares-of-special-elements/)

---

## Problem Summary

The problem requires calculating the sum of the squares of specific elements in an integer array. An element is considered 'special' if its index (1-based) is a divisor of the total number of elements in the array. The solution iterates through the array, checking for these special indices and accumulating the squared values.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3,4]`  
**Output:** `21`  
**Explanation:**
- There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4.
- Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.

### Example 2
**Input:** `nums = [2,7,1,19,18,3]`  
**Output:** `63`  
**Explanation:**
- There are exactly 4 special elements in nums: nums[1] since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6.
- Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63.

---

## Intuition

The core insight is to identify the divisors of the array's length. Since the problem states that an element is special if 'i divides n', we need to find all integers i such that n % i == 0. In the context of the array, this corresponds to checking if the current index (i+1, since arrays are 0-indexed) is a divisor of the total size n. Once a special index is found, the square of the corresponding element is added to the total sum.

---

## Approach

1. Initialize a variable 'answer' to 0 to store the accumulated sum of squares.
2. Iterate through the array 'nums' using a for loop with index 'i' from 0 to n-1.
3. For each iteration, check if the current index (i+1) is a divisor of the total size n by evaluating the condition 'n % (i + 1) == 0'.
4. If the condition is true, indicating a special element, calculate the square of the current element 'nums[i] * nums[i]' and add it to the 'answer'.
5. After the loop completes, return the final 'answer' containing the sum of squares of all special elements.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The solution involves a single loop that iterates through the entire array of length n. Within the loop, the operations (checking divisibility and squaring) are constant time, leading to a linear time complexity. |
| **Space** | `O(1)` — The algorithm uses only a few integer variables (n, answer, i) to store intermediate values and the result. There are no dynamic data structures or recursion stacks that grow with the input size, resulting in constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                answer += nums[i] * nums[i];
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- The problem demonstrates the application of basic number theory concepts (divisibility) to filter elements in an array.
- It highlights the importance of understanding the relationship between index positions and the overall structure of the data (array length) to identify specific subsets of elements.
- The solution is efficient, utilizing a simple linear scan to achieve the required result without complex algorithms or excessive memory usage.
