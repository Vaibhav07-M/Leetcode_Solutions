# 66. Plus One

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

[LeetCode — 66. Plus One](https://leetcode.com/problems/plus-one/)

---

## Problem Summary

You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `i-th` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

---

## Examples

### Example 1
**Input:** `digits = [1,2,3]`  
**Output:** `[1,2,4]`  
**Explanation:**
- The array represents the integer 123.
- Incrementing by one gives 123 + 1 = 124.
- Thus, the result should be [1,2,4].

### Example 2
**Input:** `digits = [4,3,2,1]`  
**Output:** `[4,3,2,2]`  
**Explanation:**
- The array represents the integer 4321.
- Incrementing by one gives 4321 + 1 = 4322.
- Thus, the result should be [4,3,2,2].

### Example 3
**Input:** `digits = [9]`  
**Output:** `[1,0]`  
**Explanation:**
- The array represents the integer 9.
- Incrementing by one gives 9 + 1 = 10.
- Thus, the result should be [1,0].

---

## Intuition

The problem simulates adding 1 to a number represented as an array of digits. The key challenge is handling the **carry** when a digit is 9:
- If a digit is 9, it becomes 0 and we carry 1 to the next significant digit (left).
- The special case occurs when **all digits are 9** (e.g., 999), which becomes 1000, requiring an additional digit at the front.

The solution traverses from right to left (least significant to most significant digit), managing the carry propagation efficiently.

---

## Approach

1. **Traverse from Right to Left**: Start from the least significant digit (rightmost position).

2. **Check for Carry**:
   - If the current digit is less than 9, simply increment it by 1 and return the array immediately (no further carry needed).
   - If the digit is 9, set it to 0 and continue to the next digit to the left (carry the 1).

3. **Handle All 9's Case**: 
   - If the loop completes without returning (meaning all digits were 9), insert 1 at the beginning of the array.
   - Example: [9,9,9] becomes [1,0,0,0].

4. **Return Result**: Return the modified array.

This approach efficiently handles both normal cases and the edge case where all digits roll over.

---

## Complexity

- **Time Complexity**: `O(n)` where `n` is the number of digits.  
  In the worst case (all 9's), we traverse all digits once.

- **Space Complexity**: `O(1)` excluding the input array modification.  
  In the worst case (all 9's), we need `O(n)` space for the new array with an extra digit.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

## Key Takeaways

- **Carry Logic**: The solution elegantly handles carry propagation by checking if a digit is less than 9.
- **Early Return Optimization**: Once we find a digit that doesn't require carry, we can immediately return.
- **Edge Case Handling**: The all-9's case (999 → 1000) is handled naturally by inserting 1 at the beginning after the loop completes.
- **In-Place Modification**: The solution modifies the input array in-place (except for the all-9's case), making it space-efficient.
- **Array Manipulation**: This problem demonstrates fundamental array traversal and manipulation techniques commonly used in digit-based arithmetic problems.
