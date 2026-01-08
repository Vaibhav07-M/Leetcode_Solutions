# 1458. Max Dot Product of Two Subsequences

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`

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

[LeetCode — 1458. Max Dot Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)

---

## Problem Summary

Given two arrays `nums1` and `nums2`, return the **maximum dot product** between non-empty subsequences of `nums1` and `nums2` with the **same length**.

A subsequence is formed by deleting some (can be none) elements without disturbing the relative positions of remaining elements.

The dot product of two sequences `[a1, a2, ..., an]` and `[b1, b2, ..., bn]` is:
`a1*b1 + a2*b2 + ... + an*bn`

---

## Examples

### Example 1
**Input:** `nums1 = [2,1,-2,5]`, `nums2 = [3,0,-6]`  
**Output:** `18`  
**Explanation:**
- Take subsequence [2,-2] from nums1
- Take subsequence [3,-6] from nums2
- Dot product = (2×3) + ((-2)×(-6)) = 6 + 12 = 18

### Example 2
**Input:** `nums1 = [3,-2]`, `nums2 = [2,-6,7]`  
**Output:** `21`  
**Explanation:**
- Take subsequence [3] from nums1
- Take subsequence [7] from nums2
- Dot product = 3×7 = 21

### Example 3
**Input:** `nums1 = [-1,-1]`, `nums2 = [1,1]`  
**Output:** `-1`  
**Explanation:**
- Take subsequence [-1] from nums1
- Take subsequence [1] from nums2
- Dot product = (-1)×1 = -1

---

## Intuition

This is a classic **2D Dynamic Programming** problem similar to longest common subsequence, but instead of finding length, we're maximizing the dot product.

Key insights:
1. We can choose to include or exclude elements from either array
2. When we include a pair `(nums1[i], nums2[j])`, we add their product to our total
3. We need to track the maximum dot product achievable using elements up to index i in nums1 and index j in nums2

The challenge is handling negative numbers:
- A negative product now might become positive when combined with other negative products
- We must select at least one pair (non-empty subsequences)

DP State Definition:
- `dp[i][j]` = maximum dot product using elements from `nums1[0...i-1]` and `nums2[0...j-1]`

---

## Approach

1. **Initialize DP Table**:
   - Create `dp[len1+1][len2+1]` where `len1` and `len2` are array lengths
   - Initialize with very small values (negative infinity)
   - `dp[0][0] = 0` (no elements chosen yet)

2. **DP Transition**:
   - For each position `(i, j)`:
     - Calculate `currentProduct = nums1[i-1] * nums2[j-1]`
     - **Option 1 - Take both elements**: 
       - If `dp[i-1][j-1] > 0`, add it: `takeBoth = currentProduct + dp[i-1][j-1]`
       - Otherwise, just take current: `takeBoth = currentProduct`
     - **Option 2 - Skip nums1[i-1]**: `dp[i][j] = dp[i-1][j]`
     - **Option 3 - Skip nums2[j-1]**: `dp[i][j] = dp[i][j-1]`
     - Take maximum of all options

3. **Handle Edge Cases**:
   - When adding previous DP value, only add if it's positive (to avoid reducing our product)
   - This ensures we can start fresh with any pair if previous sums were negative

4. **Return Result**:
   - Return `dp[len1][len2]`

---

## Complexity

- **Time Complexity**: `O(m × n)` where m and n are the lengths of nums1 and nums2.  
  We fill a 2D DP table with m×n cells, each requiring constant time.

- **Space Complexity**: `O(m × n)` for the DP table.  
  Can be optimized to O(min(m, n)) using space-optimized DP with rolling arrays.

---

## Code (C++)

```cpp
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        // dp[i][j] = max dot product using elements up to i-1 in nums1 and j-1 in nums2
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MIN));
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                int currentProduct = nums1[i - 1] * nums2[j - 1];
                
                // Option 1: take both elements
                int takeBoth = currentProduct;
                if (dp[i - 1][j - 1] > 0) {
                    takeBoth += dp[i - 1][j - 1];
                }
                
                // Option 2 & 3: skip one element
                int skipFirst = (i > 0) ? dp[i - 1][j] : INT_MIN;
                int skipSecond = (j > 0) ? dp[i][j - 1] : INT_MIN;
                
                dp[i][j] = max({takeBoth, skipFirst, skipSecond});
            }
        }
        
        return dp[len1][len2];
    }
};
```

---

## Key Takeaways

- **2D DP Pattern**: Similar to LCS but with product maximization instead of length counting.
- **Non-Empty Constraint**: Must select at least one pair, handled by comparing with previous states.
- **Negative Number Handling**: Only add previous DP value if positive, allowing fresh starts with new pairs.
- **Three Choices**: At each step, we can take both elements, skip from first array, or skip from second array.
- **State Representation**: `dp[i][j]` represents best solution using prefixes of both arrays up to i and j.
- **Optimization Opportunity**: Space can be reduced to O(min(m,n)) using rolling arrays since we only need previous row/column.
