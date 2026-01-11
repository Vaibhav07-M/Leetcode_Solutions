# 85. Maximal Rectangle

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Stack`, `Matrix`, `Monotonic Stack`

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

[LeetCode — 85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

---

## Problem Summary

Given a `rows x cols` binary matrix filled with `0`'s and `1`'s, find the **largest rectangle** containing only `1`'s and return its **area**.

---

## Examples

### Example 1
```
Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 6
```
**Explanation:** The maximal rectangle has area 6 (2 rows × 3 columns of 1's)

### Example 2
```
Input: matrix = [["0"]]
Output: 0
```

### Example 3
```
Input: matrix = [["1"]]
Output: 1
```

---

## Intuition

This problem can be solved by reducing it to the **"Largest Rectangle in Histogram"** problem for each row.

Key insight:
- Treat each row as the base of a histogram
- For each cell, calculate the **height** of consecutive 1's above it (including current cell)
- For each row, find the maximum rectangle area in the histogram formed by those heights

The approach:
1. Build a height array for each row where `height[j]` = number of consecutive 1's above and including position `j`
2. For each row, use the "Largest Rectangle in Histogram" algorithm to find max area
3. Track the overall maximum across all rows

The histogram problem is efficiently solved using a **monotonic stack** that maintains indices in increasing order of heights.

---

## Approach

### Step 1: Build Heights Array
- For each row, calculate heights:
  - If `matrix[i][j] == '1'`: `heights[j] = heights[j] + 1` (extend height from previous row)
  - If `matrix[i][j] == '0'`: `heights[j] = 0` (reset height)

### Step 2: Largest Rectangle in Histogram (for each row)
Use a monotonic stack approach:
1. **Initialize**: Empty stack, iterate through heights array
2. **For each position i**:
   - While stack is not empty and `current height < stack top height`:
     - Pop from stack (this height can't extend further right)
     - Calculate area with popped height as the smallest height
     - Width = current position - position after new stack top
   - Push current index to stack
3. **After iteration**: Process remaining elements in stack

### Step 3: Track Maximum
- Update global maximum after processing each row's histogram

---

## Complexity

- **Time Complexity**: `O(rows × cols)`  
  - Building heights: O(rows × cols)
  - For each row, histogram calculation: O(cols) using monotonic stack
  - Total: O(rows × cols)

- **Space Complexity**: `O(cols)`  
  - Heights array: O(cols)
  - Stack: O(cols) in worst case

---

## Code (C++)

```cpp
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for(int i = 0; i < rows; i++) {
            // Update heights array for current row
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Find max rectangle in histogram for this row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
```

---

## Key Takeaways

- **Problem Reduction**: Converting 2D problem to multiple 1D histogram problems simplifies the solution.
- **Monotonic Stack**: Essential technique for "next smaller/larger element" problems, used here for histogram calculation.
- **Height Array**: Cleverly tracks consecutive 1's vertically, resetting on 0's.
- **Row-by-Row Processing**: Each row creates a new histogram opportunity using accumulated heights.
- **Stack Efficiency**: Monotonic stack ensures O(n) time for histogram problem instead of O(n²).
- **Width Calculation**: When popping from stack, width is distance to next smaller element on both sides.
