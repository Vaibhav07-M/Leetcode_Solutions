# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Difficulty:** `Medium`  
**Tags:** `Array`, `Binary Search`, `Matrix`, `Prefix Sum`

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

[LeetCode — 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

---

## Problem Summary

Given an `m x n` matrix `mat` and an integer `threshold`, return the **maximum side-length** of a square with a sum less than or equal to `threshold`.  
Return `0` if there is no such square.

---

## Examples

### Example 1
**Input:** `mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4`  
**Output:** `2`  
**Explanation:**  
The maximum side length of a square with sum less than or equal to 4 is 2.

### Example 2
**Input:** `mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1`  
**Output:** `0`  
**Explanation:**  
No square can have a sum ≤ 1 since the minimum element is 2.

---

## Intuition

To find the maximum side length of a square with sum ≤ threshold:
1. We need to efficiently compute the sum of any square submatrix.
2. **Prefix sums** (2D) allow us to compute any rectangle sum in O(1) time.
3. We can use **binary search** on the side length to optimize the search.

Alternatively, we can iterate through all possible side lengths and check if any valid square exists.

---

## Approach

### Step 1: Build 2D Prefix Sum Array
Create a prefix sum array `prefixSum` where:
```
prefixSum[i][j] = sum of all elements in rectangle from (0,0) to (i-1, j-1)
```

This allows us to compute the sum of any submatrix in O(1):
```
sum of square from (r, c) to (r+k-1, c+k-1) = 
    prefixSum[r+k][c+k] - prefixSum[r][c+k] - prefixSum[r+k][c] + prefixSum[r][c]
```

### Step 2: Check All Possible Squares
For each possible side length `k` from `1` to `min(m, n)`:
- For each top-left corner `(r, c)`:
  - Compute the sum of the `k x k` square starting at `(r, c)`
  - If sum ≤ threshold, update the maximum side length

### Step 3: Optimization with Binary Search (Optional)
Since larger squares have larger sums (all elements ≥ 0), we can binary search on the side length:
- If a square of size `k` exists with sum ≤ threshold, try larger `k`
- Otherwise, try smaller `k`

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n * min(m, n))` — checking all squares with prefix sum queries in O(1) |
| **Space** | `O(m * n)` — for the prefix sum array |

With binary search optimization: `O(m * n * log(min(m, n)))`

---

## Code (C++)

```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Build 2D prefix sum array
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i-1][j-1] 
                                + prefixSum[i-1][j] 
                                + prefixSum[i][j-1] 
                                - prefixSum[i-1][j-1];
            }
        }
        
        int maxLen = 0;
        
        // Try all possible side lengths
        for (int k = 1; k <= min(m, n); k++) {
            bool found = false;
            
            // Try all possible top-left corners
            for (int r = 0; r <= m - k; r++) {
                for (int c = 0; c <= n - k; c++) {
                    // Compute sum of k x k square starting at (r, c)
                    int sum = prefixSum[r + k][c + k] 
                            - prefixSum[r][c + k] 
                            - prefixSum[r + k][c] 
                            + prefixSum[r][c];
                    
                    if (sum <= threshold) {
                        found = true;
                        maxLen = k;
                        break;
                    }
                }
                if (found) break;
            }
        }
        
        return maxLen;
    }
};
```

---

## Key Takeaways

1. **2D prefix sums** enable O(1) rectangle sum queries — essential for matrix problems
2. **Prefix sum formula:** `sum(r1:r2, c1:c2) = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]`
3. **Index carefully:** Prefix sum arrays are typically 1-indexed to avoid boundary issues
4. **Binary search optimization** works when property is monotonic (larger squares → larger sums)
5. **Early exit optimization:** Once a valid square of size `k` is found, can break inner loops
6. **All elements ≥ 0** ensures monotonicity — larger squares always have larger or equal sums
7. **Matrix constraints** (m, n ≤ 300) make O(m * n * min(m, n)) feasible

---
