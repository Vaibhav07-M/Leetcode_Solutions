# 2975. Maximum Square Area by Removing Fences From a Field

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Enumeration`, `Math`

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

[LeetCode - Maximum Square Area by Removing Fences From a Field](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/)

---

## Problem Summary

There is a large `(m - 1) x (n - 1)` rectangular field with corners at `(1, 1)` and `(m, n)` containing some horizontal and vertical fences given in arrays `hFences` and `vFences` respectively.

- Horizontal fences are from coordinates `(hFences[i], 1)` to `(hFences[i], n)`
- Vertical fences are from coordinates `(1, vFences[i])` to `(m, vFences[i])`

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or `-1` if it is impossible to make a square field.

Since the answer may be large, return it modulo `10^9 + 7`.

**Note:** The field is surrounded by boundary fences at positions 1 and m (horizontal) and 1 and n (vertical). These boundary fences cannot be removed.

---

## Examples

### Example 1
**Input:** `m = 4, n = 3, hFences = [2,3], vFences = [2]`  
**Output:** `4`  
**Explanation:**
- Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4

### Example 2
**Input:** `m = 6, n = 7, hFences = [2], vFences = [4]`  
**Output:** `-1`  
**Explanation:**
- It can be proved that there is no way to create a square field by removing fences

---

## Intuition

The key insight is that to form a square of side length `s`, we need:
- Two horizontal boundaries (either boundary fences or internal fences) that are `s` units apart
- Two vertical boundaries (either boundary fences or internal fences) that are `s` units apart

The approach:
1. Consider all possible horizontal gaps (distances between any two horizontal positions including boundaries 1 and m)
2. Consider all possible vertical gaps (distances between any two vertical positions including boundaries 1 and n)
3. Find the maximum gap that exists in **both** horizontal and vertical directions
4. This common maximum gap determines the largest possible square

We need to compute all possible gaps in both directions and find the intersection to get valid square sizes.

---

## Approach

1. **Add Boundary Fences**:
   - Add positions `1` and `m` to horizontal positions
   - Add positions `1` and `n` to vertical positions
   - These represent the fixed outer boundaries

2. **Compute All Horizontal Gaps**:
   - Sort all horizontal positions (boundaries + hFences)
   - For each pair of positions (i, j), compute the gap: `positions[j] - positions[i]`
   - Store all unique gaps in a hash set

3. **Compute All Vertical Gaps**:
   - Sort all vertical positions (boundaries + vFences)
   - For each pair of positions (i, j), compute the gap: `positions[j] - positions[i]`
   - Store all unique gaps in a hash set

4. **Find Maximum Common Gap**:
   - Find the intersection of horizontal and vertical gap sets
   - The maximum gap in the intersection is the side length of the largest square
   - Return `side * side % MOD`, or `-1` if no common gap exists

5. **Handle Edge Cases**:
   - If no common gap exists, return `-1`
   - Apply modulo operation as required

---

## Complexity

- **Time Complexity:** `O(h² + v²)` where h = length of hFences and v = length of vFences
  - Computing all horizontal gaps: O(h²) for all pairs
  - Computing all vertical gaps: O(v²) for all pairs
  - Finding intersection: O(min(h², v²))
  
- **Space Complexity:** `O(h² + v²)` for storing all possible gaps in hash sets

---

## Code (C++)

```cpp
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        
        // Get all possible horizontal gaps
        unordered_set<int> hGaps = getAllGaps(hFences, m);
        
        // Get all possible vertical gaps
        unordered_set<int> vGaps = getAllGaps(vFences, n);
        
        // Find maximum common gap
        int maxSide = -1;
        for (int gap : hGaps) {
            if (vGaps.count(gap)) {
                maxSide = max(maxSide, gap);
            }
        }
        
        if (maxSide == -1) return -1;
        
        long long area = (long long)maxSide * maxSide;
        return area % MOD;
    }
    
private:
    unordered_set<int> getAllGaps(vector<int>& fences, int boundary) {
        unordered_set<int> gaps;
        
        // Add boundary positions
        vector<int> positions = {1, boundary};
        positions.insert(positions.end(), fences.begin(), fences.end());
        
        // Sort positions
        sort(positions.begin(), positions.end());
        
        // Compute all possible gaps
        for (int i = 0; i < positions.size(); i++) {
            for (int j = i + 1; j < positions.size(); j++) {
                gaps.insert(positions[j] - positions[i]);
            }
        }
        
        return gaps;
    }
};
```

---

## Key Takeaways

1. **Gap-Based Thinking**: Instead of thinking about which fences to remove, think about what gaps (distances) are achievable between any two fence positions

2. **Boundary Inclusion**: Don't forget to include the outer boundaries (1 and m for horizontal, 1 and n for vertical) as they form potential square edges

3. **Set Intersection**: The problem reduces to finding the maximum value in the intersection of two sets (horizontal gaps and vertical gaps)

4. **All Pairs Computation**: We need to consider all pairs of positions, not just consecutive ones, because we can remove multiple fences to create larger gaps

5. **Hash Set for Efficiency**: Using hash sets allows O(1) lookup when finding common gaps between horizontal and vertical directions

6. **Modulo Arithmetic**: Remember to apply modulo only to the final result to avoid overflow issues

7. **Square Constraint**: The gap must exist in both directions - a gap that only exists horizontally or only vertically cannot form a square
