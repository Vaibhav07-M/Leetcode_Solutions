# 3047. Find the Largest Area of Square Inside Two Rectangles

**Difficulty:** `Medium`  
**Tags:** `Array`, `Geometry`, `Math`, `Enumeration`

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

[LeetCode - Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)

---

## Problem Summary

There exist `n` rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays `bottomLeft` and `topRight` where:
- `bottomLeft[i] = [ai, bi]` represents the bottom-left coordinates of the i-th rectangle
- `topRight[i] = [ci, di]` represents the top-right coordinates of the i-th rectangle

You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return `0` if such a square does not exist.

---

## Examples

### Example 1
**Input:** `bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]`  
**Output:** `1`  
**Explanation:**
- A square with side length 1 can fit inside the intersecting region of rectangles 0 and 1, or rectangles 1 and 2
- Maximum area is 1

### Example 2
**Input:** `bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]`  
**Output:** `4`  
**Explanation:**
- A square with side length 2 can fit inside the intersecting region of rectangles 0 and 1, or rectangles 1 and 2
- Maximum area is 2 × 2 = 4

### Example 3
**Input:** `bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]`  
**Output:** `1`  
**Explanation:**
- A square with side length 1 can fit inside the intersecting region of any two rectangles

### Example 4
**Input:** `bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]`  
**Output:** `0`  
**Explanation:**
- No pair of rectangles intersect, so the answer is 0

---

## Intuition

The key insight is that we need to:
1. **Find all pairwise intersections** of rectangles
2. **Determine the largest square** that fits in each intersection
3. **Track the maximum** across all intersections

For two rectangles to intersect, their x-ranges and y-ranges must overlap. The intersection region is also a rectangle.

For a rectangle with width `w` and height `h`, the largest square that fits inside has side length `min(w, h)`.

Therefore:
- Check all pairs of rectangles (O(n²) pairs)
- For each pair, compute their intersection rectangle
- Find the side length of the largest square that fits: `min(width, height)` of intersection
- Track the maximum side length across all pairs
- Return `side² `or `0` if no valid intersection exists

---

## Approach

1. **Iterate Through All Pairs**:
   - Use nested loops to check all pairs (i, j) where i < j
   
2. **Compute Intersection for Each Pair**:
   - Intersection bottom-left: `(max(x1_i, x1_j), max(y1_i, y1_j))`
   - Intersection top-right: `(min(x2_i, x2_j), min(y2_i, y2_j))`
   - Where (x1, y1) is bottom-left and (x2, y2) is top-right

3. **Check If Intersection is Valid**:
   - Valid if `intersectionX1 < intersectionX2` AND `intersectionY1 < intersectionY2`
   - This ensures the rectangles actually overlap

4. **Calculate Square Side Length**:
   - Width of intersection: `intersectionX2 - intersectionX1`
   - Height of intersection: `intersectionY2 - intersectionY1`
   - Maximum square side: `min(width, height)`

5. **Track Maximum and Return Area**:
   - Keep track of the maximum side length found
   - Return `maxSide * maxSide`
   - Return `0` if no valid intersection exists

---

## Complexity

- **Time Complexity:** `O(n²)` where n is the number of rectangles
  - We check all pairs of rectangles: C(n, 2) = n(n-1)/2 pairs
  - Each intersection check and calculation is O(1)
  
- **Space Complexity:** `O(1)` - only using constant extra space for variables

---

## Code (C++)

```cpp
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;
        
        // Check all pairs of rectangles
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Get coordinates for rectangle i
                int x1_i = bottomLeft[i][0], y1_i = bottomLeft[i][1];
                int x2_i = topRight[i][0], y2_i = topRight[i][1];
                
                // Get coordinates for rectangle j
                int x1_j = bottomLeft[j][0], y1_j = bottomLeft[j][1];
                int x2_j = topRight[j][0], y2_j = topRight[j][1];
                
                // Calculate intersection rectangle
                int interX1 = max(x1_i, x1_j);
                int interY1 = max(y1_i, y1_j);
                int interX2 = min(x2_i, x2_j);
                int interY2 = min(y2_i, y2_j);
                
                // Check if intersection is valid (rectangles actually overlap)
                if (interX1 < interX2 && interY1 < interY2) {
                    // Calculate dimensions of intersection
                    int width = interX2 - interX1;
                    int height = interY2 - interY1;
                    
                    // Largest square that fits has side = min(width, height)
                    int side = min(width, height);
                    maxSide = max(maxSide, (long long)side);
                }
            }
        }
        
        return maxSide * maxSide;
    }
};
```

---

## Key Takeaways

1. **Rectangle Intersection Formula**: For two rectangles to intersect, both their x-ranges and y-ranges must overlap. The intersection rectangle has:
   - Bottom-left: (max of x1s, max of y1s)
   - Top-right: (min of x2s, min of y2s)

2. **Valid Intersection Check**: An intersection is valid only if the bottom-left coordinates are strictly less than the top-right coordinates in both dimensions

3. **Square Constraint**: The largest square that fits in a rectangle with width w and height h has side length min(w, h)

4. **Brute Force Efficiency**: With n ≤ 1000, O(n²) brute force checking all pairs is acceptable and straightforward

5. **Geometric Insight**: This problem demonstrates how computational geometry problems often involve checking geometric primitives (like rectangle overlap) across all combinations

6. **Edge Case Handling**: If no rectangles intersect, maxSide remains 0, and we correctly return 0

7. **Long Long Precision**: Using `long long` for the area calculation prevents overflow since coordinates can be up to 10^7, making areas potentially up to 10^14
