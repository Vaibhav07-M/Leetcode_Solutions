# 48. Rotate Image

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Matrix`

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

[LeetCode — 48. Rotate Image](https://leetcode.com/problems/rotate-image/)

---

## Problem Summary

You are given an `n x n` matrix representing an image. Rotate the image by `90` degrees clockwise, **in place**.

You must modify the input matrix directly and cannot allocate another `n x n` matrix for the rotation.

---

## Examples

### Example 1
**Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`  
**Output:** `[[7,4,1],[8,5,2],[9,6,3]]`

### Example 2
**Input:** `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`  
**Output:** `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`

---

## Intuition

A clockwise rotation can be broken into two simple steps:

1. **Transpose** the matrix, swapping `matrix[i][j]` with `matrix[j][i]`.
2. **Reverse each row**.

After transposing, rows become columns. Reversing each row then places the elements in the correct clockwise order.

---

## Approach

1. Iterate over the upper triangle of the matrix and swap each `matrix[i][j]` with `matrix[j][i]`.
2. After transposing, reverse every row in the matrix.
3. Return the matrix in its modified form.

This works in-place and avoids any extra matrix allocation.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — every element is visited a constant number of times |
| **Space** | `O(1)` — rotation is done in place |

---

## Code (C++)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

## Key Takeaways

- Matrix rotation problems often become simpler after decomposing them into smaller transformations.
- Transpose + row reversal is a common in-place pattern for 90-degree clockwise rotation.
- This approach avoids extra memory while staying easy to reason about.
