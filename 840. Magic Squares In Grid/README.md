# 840. Magic Squares In Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Math`, `Matrix`

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

[LeetCode — 840. Magic Squares In Grid](https://leetcode.com/problems/magic-squares-in-grid/)

---

## Problem Summary

A **3 x 3 magic square** is a grid filled with **distinct numbers from 1 to 9** where:
- Each row sums to the same value
- Each column sums to the same value
- Both diagonals sum to the same value

Given a `row x col` grid of integers, return the count of **3 x 3 magic square subgrids**.

**Note:** The grid may contain numbers up to 15, but magic squares can only use 1-9.

---

## Examples

### Example 1
**Input:** `grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]`  
**Output:** `1`  
**Explanation:**
- The subgrid starting at (0,0) is a valid magic square:
  ```
  4 3 8
  9 5 1
  2 7 6
  ```
- All rows, columns, and diagonals sum to 15
- Uses distinct numbers 1-9

### Example 2
**Input:** `grid = [[8]]`  
**Output:** `0`  
**Explanation:**
- Grid is too small (needs at least 3x3)

---

## Intuition

To find magic squares, we need to:
1. Check every possible 3x3 subgrid in the larger grid
2. For each subgrid, validate:
   - Contains only distinct numbers from 1 to 9
   - All rows have the same sum
   - All columns have the same sum
   - Both diagonals have the same sum

The key insight is that in a valid 3x3 magic square using numbers 1-9:
- The sum is always **15** (since (1+2+...+9)/3 = 15)
- All numbers must be distinct and in range [1, 9]

---

## Approach

1. **Early Exit:** If grid has fewer than 3 rows or 3 columns, return 0

2. **Iterate Through All Possible 3x3 Subgrids:**
   - Loop through positions (i, j) where a 3x3 subgrid can fit
   - For each position, validate if it's a magic square

3. **Validation Function (`isvalid`):**
   - **Check Distinct Numbers (1-9):**
     - Use a frequency array to ensure each number appears exactly once
     - Reject if any number is < 1, > 9, or appears multiple times
   
   - **Check Row Sums:**
     - Calculate sum of first row as reference
     - Verify all other rows have the same sum
   
   - **Check Column Sums:**
     - Verify all columns have the same sum as the reference
   
   - **Check Diagonal Sums:**
     - Verify both diagonals have the same sum as the reference

4. **Count Valid Squares:** Increment counter for each valid magic square found

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(row * col)` — iterate through all positions, validation is O(1) |
| **Space** | `O(1)` — constant extra space |

**Note:** Although validation involves checking 9 cells, since it's always a 3x3 grid, it's constant time O(9) = O(1).

---

## Code (C++)

```cpp
class Solution {
private:
    bool isvalid(vector<vector<int>>& grid, int r, int c) {
        // Check for distinct numbers 1-9
        vector<int> nums(10, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[i + r][j + c];
                // Must be in range [1, 9] and not duplicate
                if (num < 1 || num > 9 || nums[num]) return false;
                nums[num]++;
            }
        }

        // Calculate reference sum from first row
        int summ = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        
        // Check all rows have same sum
        for (int i = 1; i < 3; i++) {
            if (summ != grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2]) 
                return false;
        }
        
        // Check all columns have same sum
        for (int i = 0; i < 3; i++) {
            if (summ != grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i]) 
                return false;
        }
        
        // Check main diagonal
        if (summ != grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2]) 
            return false;
        
        // Check anti-diagonal
        if (summ != grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c]) 
            return false;
        
        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0, r = grid.size(), c = grid[0].size();
        
        // Early exit if grid too small
        if (r < 3 || c < 3) return 0;
        
        // Check every possible 3x3 subgrid
        for (int i = 0; i < r - 2; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (isvalid(grid, i, j)) count++;
            }
        }
        
        return count;
    }
};
```

---

## Key Takeaways

- Brute force validation is acceptable when the subgrid size is fixed and small (3x3).
- Use frequency arrays to check for distinct values efficiently.
- Pre-computing the reference sum from one dimension simplifies validation.
- Early termination checks prevent unnecessary computation.
