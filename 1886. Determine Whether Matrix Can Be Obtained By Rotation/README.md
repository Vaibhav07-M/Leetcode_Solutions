# 1886. Determine Whether Matrix Can Be Obtained By Rotation

**Difficulty:** `Easy`  
**Tags:** `Matrix`, `Simulation`

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

[LeetCode — 1886. Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

---

## Problem Summary

Given two `n x n` binary matrices `mat` and `target`, determine if it's possible to make `mat` equal to `target` by rotating `mat` in 90-degree increments (clockwise).

Return `true` if this is possible, `false` otherwise.

---

## Examples

### Example 1
**Input:** `mat = [[0,1],[1,0]], target = [[1,0],[0,1]]`  
**Output:** `true`  
**Explanation:**  
Rotate `mat` 90 degrees clockwise to get `[[1,0],[0,1]]` which equals `target`.

### Example 2
**Input:** `mat = [[0,1],[1,1]], target = [[1,0],[0,1]]`  
**Output:** `false`  
**Explanation:**  
It's impossible to make `mat` equal to `target` by rotating.

### Example 3
**Input:** `mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]`  
**Output:** `true`  
**Explanation:**  
Rotate `mat` 90 degrees clockwise twice to get the target.

---

## Intuition

Since we can only rotate in 90-degree increments, there are only 4 possible states for the matrix: 0°, 90°, 180°, and 270°. We simply need to check if any of these rotations matches the target matrix.

The key insight is that we don't need to check 360° (which returns to the original) since that's identical to 0°. So we perform up to 4 rotations (including the initial state) and check for equality at each step.

---

## Approach

1. Check if `mat` already equals `target` (0° rotation)
2. For each of the next 3 rotations:
   - Perform a 90-degree clockwise rotation by:
     - **Transposing** the matrix (swap `mat[i][j]` with `mat[j][i]`)
     - **Reversing** each row
   - Check if the rotated matrix equals `target`
3. If any state matches, return `true`; otherwise return `false`

The rotation formula for 90° clockwise: `new[j][n-1-i] = old[i][j]`

---

## Complexity

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time** | O(n²) | We perform up to 4 rotations, each requiring O(n²) operations. Checking equality between two n×n matrices is O(n²). |
| **Space** | O(1) or O(n²) | Depends on implementation. In-place rotation requires O(1) extra space (excluding output). Using temporary matrices increases to O(n²). |

---

## Code (C++)

```cpp
class Solution {
public:
    // Function to rotate matrix 90 degrees clockwise
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));
        
        // Rotate: new[j][n - 1 - i] = old[i][j]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = mat[i][j];
            }
        }
        
        mat = temp;
    }
    
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return mat == target;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // Check all 4 possible rotations (0°, 90°, 180°, 270°)
        for(int i = 0; i < 4; i++) {
            if(isEqual(mat, target)) return true;
            rotate(mat);
        }
        
        return false;
    }
};
```

---

## Key Takeaways

1. **Brute Force Optimization:** When there are limited discrete states (4 rotations), checking all of them is often simpler and more efficient than trying to infer the answer mathematically.

2. **Matrix Rotation:** The 90° clockwise rotation formula `temp[j][n-1-i] = mat[i][j]` can be derived by understanding the transformation geometrically.

3. **Alternative Rotation Method:** Transpose followed by row reversal is another way to rotate clockwise and may be more intuitive:
   ```cpp
   // Transpose
   for(int i = 0; i < n; i++) 
       for(int j = i+1; j < n; j++) 
           swap(mat[i][j], mat[j][i]);
   // Reverse each row
   for(int i = 0; i < n; i++) 
       reverse(mat[i].begin(), mat[i].end());
   ```

4. **Complexity Trade-off:** O(4n²) = O(n²) time complexity makes this approach efficient even though we check 4 different states.
