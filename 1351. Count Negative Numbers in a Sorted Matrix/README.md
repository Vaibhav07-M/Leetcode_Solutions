# 1351. Count Negative Numbers in a Sorted Matrix

**Difficulty:** `Easy`  
**Tags:** `Array`, `Binary Search`, `Matrix`

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

[LeetCode — 1351. Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

---

## Problem Summary

Given an `m x n` matrix `grid` which is sorted in **non-increasing order** both row-wise and column-wise, return the number of negative numbers in the grid.

**Follow-up:** Can you find an `O(m + n)` solution?

---

## Examples

### Example 1
**Input:** `grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]`  
**Output:** `8`  
**Explanation:**
- There are 8 negative numbers in the matrix

### Example 2
**Input:** `grid = [[3,2],[1,0]]`  
**Output:** `0`  
**Explanation:**
- No negative numbers present

---

## Intuition

Since the matrix is sorted in non-increasing order both row-wise and column-wise, we can exploit this property to avoid checking every single element.

**Key Observation:** In each row, once we find a negative number, all elements to its right will also be negative (due to non-increasing order).

This allows us to:
1. Start from the rightmost column of each row
2. Count negatives and stop when we hit a non-negative number
3. Move to the next row

For an optimal `O(m + n)` solution, we can use a staircase approach starting from the bottom-left corner.

---

## Approach

### Current Implementation (Row-by-Row)
1. Iterate through each row from top to bottom
2. For each row, start from the **rightmost column** and move left
3. Count negative numbers until we encounter a non-negative number
4. Break early since all elements to the left will be non-negative (sorted property)

### Time Complexity: `O(m * n)` worst case, but often faster due to early breaks

### Optimal Approach (Staircase - O(m + n))
The commented code shows an optimal approach:
1. Start from **bottom-left corner** (row = m-1, col = 0)
2. If current element is negative:
   - All elements in that row from current column to the right are negative
   - Add `(columns - j)` to count
   - Move up one row
3. If current element is non-negative:
   - Move right one column
4. Continue until out of bounds

---

## Complexity

### Current Implementation
| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` worst case, typically better |
| **Space** | `O(1)` |

### Optimal Implementation (Staircase)
| Metric | Complexity |
|--------|------------|
| **Time** | `O(m + n)` |
| **Space** | `O(1)` |

---

## Code (C++)

### Current Solution (Row-by-Row with Early Break)
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;
        
        // Process each row from top to bottom
        for (int i = 0; i < rows; i++) {
            // Start from rightmost column, move left
            for (int j = columns - 1; j >= 0; j--) {
                if (grid[i][j] < 0) count++;
                else break;  // Early break: rest are non-negative
            }
        }
        return count;
    }
};
```

### Optimal Solution (Staircase - O(m + n))
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;
        int i = rows - 1;  // Start from bottom row
        int j = 0;         // Start from leftmost column

        // Staircase approach
        while (i >= 0 && j < columns) {
            if (grid[i][j] < 0) {
                // All elements from j to end of row are negative
                count += columns - j;
                i--;  // Move up
            }
            else {
                j++;  // Move right
            }
        }
        return count;
    }
};
```

---

## Key Takeaways

- Exploit sorted properties to avoid checking every element.
- Row-by-row with early breaks improves practical performance.
- Staircase approach from bottom-left achieves optimal `O(m + n)` complexity.
- Binary search on each row is another valid approach: `O(m log n)`.
