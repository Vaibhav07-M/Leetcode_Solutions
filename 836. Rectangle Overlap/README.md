# 836. Rectangle Overlap

**Difficulty:** `Easy`  
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

[LeetCode — 836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

---

## Problem Summary

The problem determines if two axis-aligned rectangles overlap by checking if their intersection area is positive. The solution uses a series of conditional statements to verify that the rectangles intersect in both the x and y dimensions.

---

## Examples

### Example 1
**Input:** `rec1 = [0,0,2,2], rec2 = [1,1,3,3]`  
**Output:** `true`  

### Example 2
**Input:** `rec1 = [0,0,1,1], rec2 = [1,0,2,1]`  
**Output:** `false`  

### Example 3
**Input:** `rec1 = [0,0,1,1], rec2 = [2,2,3,3]`  
**Output:** `false`  

---

## Intuition

The core insight is that for an overlap to occur, the rectangles must share a common region in both the horizontal (x) and vertical (y) axes. The code checks for non-overlap by verifying if the right edge of one rectangle is to the left of the left edge of the other (or vice versa) and if the top edge is below the bottom edge of the other (or vice versa). If none of these non-overlap conditions are met, the rectangles must overlap.

---

## Approach

1. Check if the right edge of rec1 (rec1[2]) is less than or equal to the left edge of rec2 (rec2[0]), indicating no horizontal overlap from the left/right perspective.
2. Check if the left edge of rec1 (rec1[0]) is greater than or equal to the right edge of rec2 (rec2[2]), indicating no horizontal overlap from the right/left perspective.
3. Check if the top edge of rec1 (rec1[3]) is less than or equal to the bottom edge of rec2 (rec2[1]), indicating no vertical overlap from the top/bottom perspective.
4. Check if the bottom edge of rec1 (rec1[1]) is greater than or equal to the top edge of rec2 (rec2[3]), indicating no vertical overlap from the bottom/top perspective.
5. If any of the above conditions are true, return false. Otherwise, return true, indicating an overlap.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — The solution performs a constant number of comparisons (four conditional checks) to determine the overlap, regardless of the size or position of the input rectangles. |
| **Space** | `O(1)` — The algorithm uses only a fixed amount of memory for the input variables and does not require any additional data structures or dynamic memory allocation. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // No overlap from left/right
        if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0])
            return false;

        // No overlap from top/bottom
        if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
            return false;

        return true;
    }
};
```

---

## Key Takeaways

- To check for rectangle overlap, verify that the ranges intersect in both the x and y dimensions.
- The problem can be efficiently solved by checking for the absence of overlap (i.e., if one edge is completely outside the range of the other) rather than calculating the intersection area directly.
