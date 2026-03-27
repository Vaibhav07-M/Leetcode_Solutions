# 2946. Matrix Similarity After Cyclic Shifts

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

[LeetCode — 2946. Matrix Similarity After Cyclic Shifts](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/)

---

## Problem Summary

You are given an `m x n` integer matrix `mat` and an integer `k`.

In each of k iterations:
- **Even-indexed rows** (0, 2, 4, ...) are **cyclically shifted to the left**
- **Odd-indexed rows** (1, 3, 5, ...) are **cyclically shifted to the right**

Return `true` if the final modified matrix after k steps is **identical** to the original matrix, and `false` otherwise.

---

## Examples

### Example 1
**Input:** `mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4`  
**Output:** `false`  
**Explanation:**
- Row 0 (even): [1,2,3] → left shift by 4 → [3,1,2]
- Row 1 (odd): [4,5,6] → right shift by 4 → [4,5,6]
- Row 2 (even): [7,8,9] → left shift by 4 → [9,7,8]
- Result: [[3,1,2],[4,5,6],[9,7,8]] ≠ original

### Example 2
**Input:** `mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2`  
**Output:** `true`  
**Explanation:**
- Row 0 (even): [1,2,1,2] → left shift by 2 → [1,2,1,2] (period = 2)
- Row 1 (odd): [5,5,5,5] → right shift by 2 → [5,5,5,5] (all same)
- Row 2 (even): [6,3,6,3] → left shift by 2 → [6,3,6,3] (period = 2)
- Result: [[1,2,1,2],[5,5,5,5],[6,3,6,3]] = original

### Example 3
**Input:** `mat = [[2,2],[2,2]], k = 3`  
**Output:** `true`  
**Explanation:**
- All elements are identical, so any shift returns the same matrix

---

## Intuition

The key insight is understanding **cyclic shift patterns**:

1. **Left shift by k** in a row of size n brings element at index `j` to index `(j - k) % n`
   - Equivalently, position `j` receives element from index `(j + k) % n`

2. **Right shift by k** in a row of size n brings element at index `j` to index `(j + k) % n`
   - Equivalently, position `j` receives element from index `(j - k + n) % n`

3. **Periodicity:** After `n` shifts, a row returns to its original state (because shifts are cyclic)
   - Therefore, we can optimize: `k = k % n` (reduce k to its equivalent within one period)

4. **No need to actually perform shifts** — we can directly check if the shifted position matches the original:
   - For each position `(i, j)`, calculate where it gets its value from after k shifts
   - Compare with the original value at `(i, j)`
   - If all match, return true; otherwise return false

---

## Approach

### Key Observation:
Instead of simulating k shifts (which could be expensive if k is large), we use modular arithmetic to directly compute what value ends up at each position.

### Algorithm:
```
1. m = number of rows, n = number of columns
2. Optimize: k = k % n (reduce to equivalent shift within one period)
3. For each cell (i, j):
   - If i is even (left shift):
     - The value at (i, j) comes from position (i, (j + k) % n)
   - If i is odd (right shift):
     - The value at (i, j) comes from position (i, (j - k + n) % n)
   - If original_value[i][j] != shifted_value[i][j]:
     - Return false
4. If all cells match, return true
```

### Why This Works:
- After `k` left shifts, the element originally at position `j+k` appears at position `j`
- After `k` right shifts, the element originally at position `j-k` appears at position `j`
- Using modulo ensures wraparound behavior is handled correctly
- Time complexity is O(1) per cell — we don't actually shift, just calculate positions

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m × n)` — check each cell once |
| **Space** | `O(1)` — only constant extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Optimize: k % n because shifts repeat after n positions
        k = k % n;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int original = mat[i][j];
                int shifted;
                
                if(i % 2 == 0) {
                    // Even row: left shift
                    // Position j receives value from (j + k) % n
                    shifted = mat[i][(j + k) % n];
                } 
                else {
                    // Odd row: right shift
                    // Position j receives value from (j - k + n) % n
                    shifted = mat[i][(j - k + n) % n];
                }
                
                // If the value at position j doesn't match what should be there, not similar
                if(original != shifted)
                    return false;
            }
        }
        
        return true; // All cells matched
    }
};
```

### Inline Comments Version:

```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();    // number of rows
        int n = mat[0].size(); // number of columns
        
        k = k % n; // Reduce k to equivalent shift within [0, n)
        
        // Check each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int shifted_from;
                
                if(i % 2 == 0) {
                    // Even row: shift left k positions
                    // Current position j gets value from position (j + k) % n
                    shifted_from = mat[i][(j + k) % n];
                } 
                else {
                    // Odd row: shift right k positions
                    // Current position j gets value from position (j - k + n) % n
                    shifted_from = mat[i][(j - k + n) % n];
                }
                
                // Check if value matches after shifting
                if(mat[i][j] != shifted_from)
                    return false;
            }
        }
        
        return true;
    }
};
```

---

## Key Takeaways

1. **Cyclic Shift Formula** — understand how indices map after left/right shifts
   - Left shift by k: index j ← index (j + k) % n
   - Right shift by k: index j ← index (j - k + n) % n

2. **Periodicity & Optimization** — shifts repeat every n positions
   - `k % n` reduces unnecessary computation and avoids overflow for large k

3. **Direct Comparison vs. Simulation** — no need to actually perform shifts
   - Calculate source position directly using modular arithmetic
   - Early termination if mismatch found

4. **Modulo Arithmetic** — handle wraparound correctly
   - For left shift: `(j + k) % n` (always positive)
   - For right shift: `(j - k + n) % n` (add n to handle negative modulo correctly)

5. **Row Parity** — logic depends on whether row index is even or odd
   - Separate conditions for even vs. odd rows

6. **Time vs. Space Trade-off** — O(m×n) time, O(1) space
   - No auxiliary matrix needed, in-place comparison

7. **Edge Cases:**
   - k = 0 → always returns true (no shifts needed)
   - All identical elements → always returns true
   - k = n → equivalent to k = 0 (one full rotation)
   - Single column matrix → no shifts happen, always true

---
