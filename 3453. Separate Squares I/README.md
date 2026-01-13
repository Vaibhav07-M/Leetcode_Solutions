# 3453. Separate Squares I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Binary Search`, `Geometry`, `Math`, `Sorting`

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

[LeetCode - Separate Squares I](https://leetcode.com/problems/separate-squares-i/)

---

## Problem Summary

You are given a 2D integer array `squares`. Each `squares[i] = [xi, yi, li]` represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

**Note:** 
- Squares may overlap. Overlapping areas should be counted multiple times.
- Answers within 10^-5 of the actual answer will be accepted.

---

## Examples

### Example 1
**Input:** `squares = [[0,0,1],[2,2,1]]`  
**Output:** `1.00000`  
**Explanation:**
- Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it
- The lowest option is 1

### Example 2
**Input:** `squares = [[0,0,2],[1,1,1]]`  
**Output:** `1.16667`  
**Explanation:**
- Below the line: 7/6 × 2 (Red) + 1/6 (Blue) = 15/6 = 2.5
- Above the line: 5/6 × 2 (Red) + 5/6 (Blue) = 15/6 = 2.5
- Since the areas above and below the line are equal, the output is 7/6 = 1.16667

---

## Intuition

The key insight is that this is an optimization problem where we need to find a y-coordinate that balances the areas. Since the answer requires high precision and we're looking for a continuous value, **binary search** on the y-coordinate is the natural approach.

For any given horizontal line at y-coordinate `y`:
- We can calculate the total area of squares (or portions of squares) below the line
- We can calculate the total area above the line
- The optimal y-coordinate is where these areas are equal

Since increasing y monotonically increases the area below and decreases the area above, binary search can efficiently find the balance point.

---

## Approach

1. **Determine Search Boundaries**:
   - Find the minimum y-coordinate: `min(yi)` across all squares
   - Find the maximum y-coordinate: `max(yi + li)` across all squares
   - These define our binary search range

2. **Binary Search**:
   - Use binary search with high precision (iterate until `high - low < 1e-6`)
   - For each midpoint `mid`, calculate:
     - `areaBelow`: total area of all squares below line y = mid
     - `areaAbove`: total area of all squares above line y = mid

3. **Calculate Area for Each Square**:
   - For square `[x, y, len]`:
     - If `mid <= y`: entire square is above the line (contributes `len²` to areaAbove)
     - If `mid >= y + len`: entire square is below the line (contributes `len²` to areaBelow)
     - If `y < mid < y + len`: square is split:
       - Area below = `len × (mid - y)`
       - Area above = `len × (y + len - mid)`

4. **Adjust Search Range**:
   - If `areaBelow >= areaAbove`: the line is too high or at the right position, search lower half
   - If `areaBelow < areaAbove`: the line is too low, search upper half

5. **Return Result**: The converged value of `low` (or `high`) after binary search

---

## Complexity

- **Time Complexity:** `O(n × log(R))` where n is the number of squares and R is the range of y-coordinates. Binary search runs in O(log(R)) iterations (with precision 1e-6), and each iteration processes all n squares.

- **Space Complexity:** `O(1)`. Only using constant extra space for variables.

---

## Code (C++)

```cpp
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        // Determine search boundaries
        for(auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];
            low = min(low, y);
            high = max(high, y + len);
        }

        // Binary search for the optimal y-coordinate
        while(high - low > 1e-6) {
            double mid = (low + high) / 2;
            double areaBelow = 0, areaAbove = 0;

            // Calculate areas for each square
            for(auto &sq : squares) {
                double y = sq[1];
                double len = sq[2];
                
                if(mid <= y) {
                    // Entire square is above the line
                    areaAbove += len * len;
                }
                else if(mid >= y + len) {
                    // Entire square is below the line
                    areaBelow += len * len;
                }
                else {
                    // Square is split by the line
                    areaBelow += len * (mid - y);
                    areaAbove += len * (y + len - mid);
                }
            }

            // Adjust search range
            if(areaBelow >= areaAbove)
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
```

---

## Key Takeaways

1. **Binary Search on Real Numbers**: This problem demonstrates binary search on continuous values with precision requirements, not just discrete integers

2. **Geometric Area Calculation**: Breaking down overlapping squares into regions above and below a line requires careful case analysis

3. **Monotonicity Property**: The key to applying binary search is recognizing that area below the line increases monotonically with y-coordinate

4. **Precision Handling**: Using `1e-6` as the convergence threshold ensures the answer is within the required `1e-5` tolerance

5. **Overlapping Areas Count Multiple Times**: The problem explicitly states overlapping areas should be counted multiple times, simplifying the calculation to process each square independently

6. **Optimization via Binary Search**: Instead of trying all possible y-coordinates, binary search efficiently narrows down to the optimal value in logarithmic time
