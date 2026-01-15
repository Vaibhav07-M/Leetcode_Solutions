# 2943. Maximize Area of Square Hole in Grid

**Difficulty:** `Medium`  
**Tags:** `Array`, `Sorting`, `Greedy`

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

[LeetCode - Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/)

---

## Problem Summary

You are given two integers `n` and `m`, and two integer arrays `hBars` and `vBars`. The grid has `n + 2` horizontal and `m + 2` vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in `hBars` from horizontal bars and some of the bars in `vBars` from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid after removing some bars (possibly none).

---

## Examples

### Example 1
**Input:** `n = 2, m = 1, hBars = [2,3], vBars = [2]`  
**Output:** `4`  
**Explanation:**
- The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3]
- One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2

### Example 2
**Input:** `n = 1, m = 1, hBars = [2], vBars = [2]`  
**Output:** `4`  
**Explanation:**
- To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2

### Example 3
**Input:** `n = 2, m = 3, hBars = [2,3], vBars = [2,4]`  
**Output:** `4`  
**Explanation:**
- One way to get the maximum square-shaped hole is by removing horizontal bar 3 and vertical bar 4

---

## Intuition

The key insight is understanding what creates a square hole:
- To create a hole of size k × k, we need to remove **k consecutive bars** from both horizontal and vertical directions
- The bars that can be removed are given in `hBars` and `vBars`
- The maximum square area is limited by the minimum of:
  - Longest consecutive sequence in horizontal bars
  - Longest consecutive sequence in vertical bars

For example, if we can remove 3 consecutive horizontal bars and 5 consecutive vertical bars, the maximum square hole we can create is 3 × 3 = 9.

The problem reduces to finding the **longest consecutive sequence** in both sorted arrays.

---

## Approach

1. **Sort Both Arrays**:
   - Sort `hBars` and `vBars` to easily find consecutive sequences
   
2. **Find Longest Consecutive Sequence**:
   - For each array, iterate through and count consecutive integers
   - Track the maximum consecutive count
   - A sequence is consecutive if `arr[i+1] == arr[i] + 1`

3. **Calculate Maximum Square**:
   - The side length of the maximum square = `min(maxConsecutiveH, maxConsecutiveV) + 1`
   - The `+1` accounts for the fact that removing k consecutive bars creates a hole of size (k+1)
   - Return `side * side` as the area

4. **Edge Cases**:
   - If no bars can be removed consecutively, minimum hole size is 2 × 2 = 4 (removing at least 1 bar from each direction)

---

## Complexity

- **Time Complexity:** `O(n log n + m log m)` where n = length of hBars and m = length of vBars
  - Sorting hBars: O(n log n)
  - Sorting vBars: O(m log m)
  - Finding consecutive sequences: O(n + m)
  
- **Space Complexity:** `O(1)` if we don't count the space used by sorting (or O(log n + log m) for sorting stack space)

---

## Code (C++)

```cpp
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Find longest consecutive sequence in both arrays
        int maxH = findMaxConsecutive(hBars);
        int maxV = findMaxConsecutive(vBars);
        
        // The side length of the square hole
        int side = min(maxH, maxV) + 1;
        
        return side * side;
    }
    
private:
    int findMaxConsecutive(vector<int>& bars) {
        if (bars.empty()) return 0;
        
        // Sort the array to find consecutive sequences
        sort(bars.begin(), bars.end());
        
        int maxConsecutive = 1;  // At least 1 bar can be removed
        int currentConsecutive = 1;
        
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) {
                // Consecutive bar found
                currentConsecutive++;
                maxConsecutive = max(maxConsecutive, currentConsecutive);
            } else {
                // Reset consecutive count
                currentConsecutive = 1;
            }
        }
        
        return maxConsecutive;
    }
};
```

---

## Key Takeaways

1. **Problem Transformation**: The key is recognizing that this is a consecutive sequence problem in disguise. The grid and bars setup is just context for finding longest consecutive integers.

2. **Square Constraint**: The maximum square hole is limited by the smaller dimension. We can't create a 5×3 hole and call it a square - it must be k×k.

3. **Off-by-One Insight**: Removing k consecutive bars creates a hole of size (k+1). For example, removing bars 2,3,4 creates a hole from position 1 to position 5, which is size 4.

4. **Sorting Strategy**: Sorting allows us to easily identify consecutive sequences by just checking if adjacent elements differ by 1.

5. **Greedy Approach**: We greedily find the longest consecutive sequence in each direction, as this maximizes the square area.

6. **Minimum Guarantee**: Even with no consecutive removals, we can always create at least a 2×2 hole by removing one bar from each direction (since all bars in hBars and vBars are removable).
