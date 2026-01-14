# 3454. Separate Squares II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Binary Search`, `Geometry`, `Line Sweep`, `Coordinate Compression`, `Sorting`

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

[LeetCode - Separate Squares II](https://leetcode.com/problems/separate-squares-ii/)

---

## Problem Summary

You are given a 2D integer array `squares`. Each `squares[i] = [xi, yi, li]` represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

**Note:** 
- Squares may overlap. **Overlapping areas should be counted only once** (this is the key difference from Separate Squares I).
- Answers within 10^-5 of the actual answer will be accepted.

---

## Examples

### Example 1
**Input:** `squares = [[0,0,1],[2,2,1]]`  
**Output:** `1.00000`  
**Explanation:**
- Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below
- The minimum y-value is 1

### Example 2
**Input:** `squares = [[0,0,2],[1,1,1]]`  
**Output:** `1.00000`  
**Explanation:**
- Since the blue square overlaps with the red square, it will not be counted again
- Thus, the line y = 1 splits the squares into two equal parts

---

## Intuition

This is a significantly harder version of Separate Squares I because **overlapping areas must be counted only once**. This means we can't simply process each square independently.

The key insights:
1. **Binary search on y-coordinate** still works because the area function is monotonic
2. **Coordinate compression + Line sweep** is needed to calculate the actual covered area at any y-coordinate
3. For each horizontal slice, we need to compute the union of all rectangle intervals (handling overlaps)

The challenge is efficiently computing the total covered area above and below a horizontal line when rectangles can overlap arbitrarily.

---

## Approach

### High-Level Strategy
1. **Binary Search** on the y-coordinate to find the balance point
2. For each candidate y-coordinate, calculate the **actual covered area** (with overlaps counted once) above and below the line
3. Use **coordinate compression** and **line sweep** to handle overlapping rectangles efficiently

### Detailed Steps

1. **Determine Search Boundaries**:
   - Find the minimum y-coordinate: `min(yi)` across all squares
   - Find the maximum y-coordinate: `max(yi + li)` across all squares
   - These define our binary search range

2. **Binary Search Loop**:
   - While `high - low > 1e-6`:
     - Calculate `mid = (low + high) / 2`
     - Compute `areaBelow` = covered area below line y = mid
     - Compute `areaAbove` = covered area above line y = mid
     - If `areaBelow >= areaAbove`, move to lower half
     - Otherwise, move to upper half

3. **Calculate Covered Area** (most complex part):
   - For a given y-coordinate, we need the total area covered by all squares in a region
   - Use **sweep line algorithm** with y-coordinates as events
   - At each horizontal slice, compute the union of all active x-intervals
   - Sum up the areas of all slices

4. **Union of Intervals**:
   - For each horizontal slice at a specific y-level, collect all overlapping squares
   - Extract their x-intervals: `[xi, xi + li]`
   - Merge overlapping intervals to get the total x-coverage
   - Multiply by the height of the slice to get area

### Algorithm for Area Calculation

```
function calculateArea(squares, yMin, yMax):
    events = []
    
    // Create events for each square's top and bottom edges
    for each square [x, y, len]:
        if square intersects [yMin, yMax]:
            clippedBottom = max(y, yMin)
            clippedTop = min(y + len, yMax)
            events.add((clippedBottom, x, x + len, START))
            events.add((clippedTop, x, x + len, END))
    
    sort events by y-coordinate
    
    totalArea = 0
    activeIntervals = []
    prevY = yMin
    
    for each event at currentY:
        // Calculate area for the slice [prevY, currentY]
        if currentY > prevY:
            width = calculateUnionWidth(activeIntervals)
            totalArea += width * (currentY - prevY)
        
        // Update active intervals
        if event is START:
            add interval to activeIntervals
        else:
            remove interval from activeIntervals
        
        prevY = currentY
    
    return totalArea
```

---

## Complexity

- **Time Complexity:** `O(n² log(R))` where n is the number of squares and R is the range of y-coordinates
  - Binary search: O(log(R)) iterations with precision 1e-6
  - Each iteration calculates area: O(n² log n)
    - Creating events: O(n)
    - Sorting events: O(n log n)
    - Processing events and merging intervals: O(n²) worst case for interval merging
  
- **Space Complexity:** `O(n)` for storing events and active intervals

---

## Code (C++)

```cpp
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        
        // Determine search boundaries
        for (auto& sq : squares) {
            double y = sq[1];
            double len = sq[2];
            low = min(low, y);
            high = max(high, y + len);
        }
        
        // Binary search for the optimal y-coordinate
        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            double areaBelow = calculateArea(squares, low, mid);
            double areaAbove = calculateArea(squares, mid, high);
            
            if (areaBelow >= areaAbove)
                high = mid;
            else
                low = mid;
        }
        
        return low;
    }
    
private:
    double calculateArea(vector<vector<int>>& squares, double yMin, double yMax) {
        vector<tuple<double, double, double, int>> events; // (y, xStart, xEnd, type)
        
        // Create events for squares intersecting [yMin, yMax]
        for (auto& sq : squares) {
            double x = sq[0], y = sq[1], len = sq[2];
            double bottom = max(y, yMin);
            double top = min(y + len, yMax);
            
            if (bottom < top) {
                events.push_back({bottom, x, x + len, 1});  // Start
                events.push_back({top, x, x + len, -1});     // End
            }
        }
        
        sort(events.begin(), events.end());
        
        double totalArea = 0;
        vector<pair<double, double>> activeIntervals;
        double prevY = yMin;
        
        for (auto& [currentY, xStart, xEnd, type] : events) {
            // Calculate area for slice [prevY, currentY]
            if (currentY > prevY && !activeIntervals.empty()) {
                double width = getUnionWidth(activeIntervals);
                totalArea += width * (currentY - prevY);
            }
            
            // Update active intervals
            if (type == 1) {
                activeIntervals.push_back({xStart, xEnd});
            } else {
                // Remove the interval
                auto it = find(activeIntervals.begin(), activeIntervals.end(), 
                              make_pair(xStart, xEnd));
                if (it != activeIntervals.end()) {
                    activeIntervals.erase(it);
                }
            }
            
            prevY = currentY;
        }
        
        return totalArea;
    }
    
    double getUnionWidth(vector<pair<double, double>>& intervals) {
        if (intervals.empty()) return 0;
        
        vector<pair<double, double>> sorted = intervals;
        sort(sorted.begin(), sorted.end());
        
        double totalWidth = 0;
        double currentStart = sorted[0].first;
        double currentEnd = sorted[0].second;
        
        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i].first <= currentEnd) {
                // Overlapping or adjacent
                currentEnd = max(currentEnd, sorted[i].second);
            } else {
                // Non-overlapping
                totalWidth += currentEnd - currentStart;
                currentStart = sorted[i].first;
                currentEnd = sorted[i].second;
            }
        }
        
        totalWidth += currentEnd - currentStart;
        return totalWidth;
    }
};
```

---

## Key Takeaways

1. **Counting Overlaps Once Changes Everything**: Unlike Separate Squares I where we could process each square independently, handling overlaps requires sophisticated geometric algorithms

2. **Line Sweep Algorithm**: Essential technique for computing the union of overlapping rectangles. Process events (rectangle edges) in sorted order and maintain active intervals

3. **Coordinate Compression**: By processing events at critical y-coordinates only, we avoid checking every possible y-value

4. **Binary Search Still Applies**: Even with complex area calculations, the monotonicity property allows binary search on the answer

5. **Interval Union Problem**: Computing the total width covered by overlapping intervals is a classic problem solved by sorting and merging

6. **Precision Management**: With floating-point binary search, careful handling of precision (1e-6) is crucial to ensure the answer is within the required tolerance (1e-5)

7. **Event-Driven Computation**: By treating rectangle edges as events (start/end), we can efficiently track which rectangles are active at each horizontal slice
