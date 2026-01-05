# 1975. Maximum Matrix Sum

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Matrix`

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

[LeetCode — 1975. Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/)

---

## Problem Summary

You are given an `n x n` integer matrix. You can perform the following operation **any number of times**:

- Choose any two **adjacent** elements of the matrix and multiply each of them by `-1`.
- Two elements are considered adjacent if and only if they share a border.

Your goal is to **maximize the summation** of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

---

## Examples

### Example 1
**Input:** `matrix = [[1,-1],[-1,1]]`  
**Output:** `4`  
**Explanation:**
- Multiply the 2 elements in the first row by -1: [[−1,1],[−1,1]]
- Multiply the 2 elements in the first column by -1: [[1,1],[1,1]]
- Sum = 1 + 1 + 1 + 1 = 4

### Example 2
**Input:** `matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]`  
**Output:** `16`  
**Explanation:**
- Multiply the 2 last elements in the second row by -1: [[1,2,3],[-1,2,3],[1,2,3]]
- Sum = 1 + 2 + 3 + (-1) + 2 + 3 + 1 + 2 + 3 = 16

---

## Intuition

The key insight is understanding what happens when we flip adjacent pairs:

1. **Flipping pairs of adjacent elements** effectively allows us to move negativity around the matrix.
2. Since we flip two elements at once, each operation changes the sign of exactly 2 elements.
3. This means:
   - If we have an **even number** of negative elements, we can make all elements positive (flip them in pairs).
   - If we have an **odd number** of negative elements, we'll be left with exactly one negative element (we can't eliminate all negatives).

4. When we're forced to keep one negative element, we should choose the one with the **smallest absolute value** to minimize the loss.

The strategy is:
- Calculate the sum of absolute values of all elements
- Count how many negative elements exist
- If the count is odd, subtract twice the minimum absolute value (since it will be negative instead of positive)

---

## Approach

1. **Initialize Variables**:
   - `absoluteSum = 0`: Sum of absolute values of all elements
   - `negativeElements = 0`: Count of negative elements
   - `minimumAbsoluteValue = INT_MAX`: Track the smallest absolute value

2. **Traverse the Matrix**:
   - For each cell value:
     - If negative, increment `negativeElements`
     - Add the absolute value to `absoluteSum`
     - Update `minimumAbsoluteValue` with the minimum absolute value seen

3. **Calculate Result**:
   - If `negativeElements` is **even**: Return `absoluteSum` (all can be made positive)
   - If `negativeElements` is **odd**: Return `absoluteSum - 2 * minimumAbsoluteValue`
     - We subtract twice because the minimum element contributes negatively instead of positively

4. **Return the Maximum Sum**

---

## Complexity

- **Time Complexity**: `O(n²)` where n is the dimension of the matrix.  
  We traverse all elements in the n×n matrix once.

- **Space Complexity**: `O(1)` - constant space.  
  We only use a fixed number of variables regardless of matrix size.

---

## Code (C++)

```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absoluteSum = 0;
        int negativeElements = 0;
        int minimumAbsoluteValue = INT_MAX;

        for (const auto& currentRow : matrix) {
            for (int cellValue : currentRow) {
                if (cellValue < 0) {
                    negativeElements++;
                }
                
                int absValue = abs(cellValue);
                absoluteSum += absValue;
                minimumAbsoluteValue = min(minimumAbsoluteValue, absValue);
            }
        }

        // If odd number of negatives, one must remain negative
        // Choose the one with smallest absolute value
        if (negativeElements % 2 == 1) {
            absoluteSum -= 2 * minimumAbsoluteValue;
        }

        return absoluteSum;
    }
};
```

---

## Key Takeaways

- **Parity Matters**: The even/odd count of negative numbers determines whether we can make all elements positive.
- **Greedy Strategy**: When forced to keep one negative, choose the smallest absolute value to minimize loss.
- **Operation Effect**: Each operation flips exactly 2 elements, preserving parity of negative count.
- **Mathematical Insight**: The sum of absolute values minus 2× minimum gives the optimal result for odd negative counts.
- **Optimization Focus**: We don't need to simulate operations; mathematical analysis reveals the optimal sum directly.
- **Sign Manipulation**: Understanding how operations propagate signs through the matrix is key to solving this efficiently.
