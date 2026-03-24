# 2906. Construct Product Matrix

**Difficulty:** `Medium`  
**Tags:** `Array`, `Matrix`, `Math`, `Prefix Sum`

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

[LeetCode — 2906. Construct Product Matrix](https://leetcode.com/problems/construct-product-matrix/)

---

## Problem Summary

Given a 0-indexed 2D integer matrix `grid` of size `n × m`, construct a product matrix `p` where:
- Each element `p[i][j]` is calculated as the product of all elements in `grid` except `grid[i][j]`
- The product is taken modulo `12345`

Return the product matrix `p`.

---

## Examples

### Example 1
**Input:** `grid = [[1,2],[3,4]]`  
**Output:** `[[24,12],[8,6]]`  
**Explanation:**
- `p[0][0] = 2 * 3 * 4 = 24`
- `p[0][1] = 1 * 3 * 4 = 12`
- `p[1][0] = 1 * 2 * 4 = 8`
- `p[1][1] = 1 * 2 * 3 = 6`

### Example 2
**Input:** `grid = [[12345],[2],[1]]`  
**Output:** `[[2],[0],[0]]`  
**Explanation:**
- `p[0][0] = 2 * 1 = 2`
- `p[0][1] = 12345 * 1 = 12345 % 12345 = 0`
- `p[0][2] = 12345 * 2 = 24690 % 12345 = 0`

---

## Intuition

A naive approach would multiply all elements except the current one for each cell—this would be O(n² × m²) which is too slow.

Instead, we can:
1. Flatten the 2D matrix into a 1D array
2. For each position, calculate the product of all other elements using prefix and suffix products
3. Convert back to the 2D result matrix

This reduces the problem to a classic "Product of Array Except Self" problem, achievable in O(n × m) time.

---

## Approach

1. **Flatten the matrix** into a 1D array (size = n × m)
2. **Compute prefix products**: `prefix[i]` = product of all elements before index i
3. **Compute suffix products**: `suffix[i]` = product of all elements after index i
4. **For each position i**: `result[i] = (prefix[i] * suffix[i]) % 12345`
5. **Reshape** back to 2D matrix form

This approach handles modulo arithmetic properly by applying modulo at each multiplication step to prevent overflow.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n × m)` — single pass through all elements |
| **Space** | `O(n × m)` — for prefix, suffix, and result arrays |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        int size = n * m;
        vector<int> arr(size);
        
        // Flatten the grid
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[idx++] = grid[i][j];
            }
        }
        
        // Compute product matrix
        vector<int> prefix(size, 1);
        vector<int> suffix(size, 1);
        
        // Build prefix array
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }
        
        // Build suffix array
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }
        
        // Construct result
        vector<vector<int>> result(n, vector<int>(m));
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (prefix[idx] * suffix[idx]) % mod;
                idx++;
            }
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- Converting 2D to 1D helps apply classic array algorithms
- Prefix and suffix products enable efficient computation of products excluding one element
- Always apply modulo during multiplication to prevent overflow
- Consider flattening when 2D logic becomes complex
