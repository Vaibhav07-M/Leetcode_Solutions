# 1401. Circle and Rectangle Overlapping

**Difficulty:** `Medium`  
**Tags:** `Math`, `Geometry`

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

[LeetCode — 1401. Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

---

## Problem Summary

The problem determines if a circle and a rectangle overlap. The circle is defined by its radius and center coordinates, while the rectangle is defined by the coordinates of its bottom-left and top-right corners. The goal is to check if there is any point that belongs to both the circle and the rectangle simultaneously.

---

## Examples

### Example 1
**Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1`  
**Output:** `true`  
**Explanation:**
- Circle and rectangle share the point (1,0).

### Example 2
**Input:** `radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1`  
**Output:** `false`  

### Example 3
**Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1`  
**Output:** `true`  

---

## Intuition

The solution uses a geometric approach to find the point on the rectangle that is closest to the circle's center. It then calculates the Euclidean distance between the circle's center and this closest point. If this distance is less than or equal to the circle's radius, the circle overlaps the rectangle; otherwise, it does not.

---

## Approach

1. Identify the closest point on the rectangle to the circle's center. This is done by taking the maximum of the rectangle's left x-coordinate and the minimum of the circle's x-coordinate and the rectangle's right x-coordinate for the x-axis, and similarly for the y-axis.
2. Calculate the x-distance (dx) and y-distance (dy) between the circle's center and the identified closest point.
3. Compute the square of the distance (dx^2 + dy^2) and compare it to the square of the circle's radius. If the distance is less than or equal to the radius, the shapes overlap.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — The solution involves a constant number of arithmetic operations (comparisons, additions, and multiplications) to determine the overlap, regardless of the size of the input values. |
| **Space** | `O(1)` — The algorithm uses a fixed number of integer variables to store the coordinates and distances, resulting in constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};
```

---

## Key Takeaways

- To check for overlap between a circle and a rectangle, it is efficient to find the closest point on the rectangle to the circle's center and measure the distance.
- The Euclidean distance formula (dx^2 + dy^2) is used to determine if the circle's radius encompasses the closest point of the rectangle.
