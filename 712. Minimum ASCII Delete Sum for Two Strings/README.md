# 712. Minimum ASCII Delete Sum for Two Strings

**Difficulty:** `Medium`  
**Tags:** `String`, `Dynamic Programming`

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

[LeetCode — 712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

---

## Problem Summary

Given two strings `s1` and `s2`, return the **lowest ASCII sum** of deleted characters to make two strings equal.

---

## Examples

### Example 1
**Input:** `s1 = "sea"`, `s2 = "eat"`  
**Output:** `231`  
**Explanation:**
- Deleting "s" from "sea" adds ASCII value 115 to the sum
- Deleting "t" from "eat" adds ASCII value 116 to the sum
- Result: 115 + 116 = 231

### Example 2
**Input:** `s1 = "delete"`, `s2 = "leet"`  
**Output:** `403`  
**Explanation:**
- Deleting "dee" from "delete" adds 100[d] + 101[e] + 101[e] = 302
- Deleting "e" from "leet" adds 101[e]
- Both strings become "let"
- Total: 302 + 101 = 403

---

## Intuition

This is a variant of the classic **Longest Common Subsequence (LCS)** problem, but instead of maximizing the length of common subsequence, we're minimizing the cost of deletions measured by ASCII values.

Key insights:
1. We want to keep the maximum common subsequence and delete the rest
2. Instead of counting characters, we track ASCII values
3. The minimum deletion cost = (sum of all ASCII in s1) + (sum of all ASCII in s2) - 2 × (maximum ASCII sum of common subsequence)

However, we can solve this directly using DP without calculating the common subsequence separately:
- `dp[i][j]` = minimum ASCII deletion sum to make `s1[0...i-1]` equal to `s2[0...j-1]`

---

## Approach

1. **Define DP State**:
   - `dp[i][j]` = minimum ASCII sum of deleted characters to make `s1[0...i-1]` and `s2[0...j-1]` equal
   - Dimensions: `(n+1) × (m+1)` where n = s1.length, m = s2.length

2. **Base Cases**:
   - `dp[0][0] = 0` (both empty strings, no deletions needed)
   - `dp[i][0]` = sum of ASCII values of first i characters in s1 (delete all from s1)
   - `dp[0][j]` = sum of ASCII values of first j characters in s2 (delete all from s2)

3. **DP Transition**:
   - If `s1[i-1] == s2[j-1]`:
     - Characters match, no deletion needed: `dp[i][j] = dp[i-1][j-1]`
   - If `s1[i-1] != s2[j-1]`:
     - **Option 1**: Delete from s1: `dp[i][j] = dp[i-1][j] + ASCII(s1[i-1])`
     - **Option 2**: Delete from s2: `dp[i][j] = dp[i][j-1] + ASCII(s2[j-1])`
     - Take minimum of both options

4. **Return Result**:
   - Return `dp[n][m]`

---

## Complexity

- **Time Complexity**: `O(n × m)` where n and m are the lengths of s1 and s2.  
  We fill a 2D DP table with n×m cells, each requiring constant time.

- **Space Complexity**: `O(n × m)` for the DP table.  
  Can be optimized to O(min(n, m)) using space-optimized DP with rolling arrays.

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: delete all from s1
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        // Base case: delete all from s2
        for(int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        // Fill DP table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    // Characters match, no deletion
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Delete from s1 or s2, take minimum
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1],  // Delete from s1
                        dp[i][j - 1] + s2[j - 1]   // Delete from s2
                    );
                }
            }
        }

        return dp[n][m];
    }
};
```

---

## Key Takeaways

- **LCS Variant**: This problem is a weighted version of finding longest common subsequence, where weights are ASCII values.
- **DP State Design**: `dp[i][j]` represents the minimum cost to make prefixes equal.
- **Character Matching**: When characters match, we don't need to delete, so we carry forward the previous state.
- **Optimal Substructure**: The minimum cost for making full strings equal depends on minimum costs of smaller subproblems.
- **ASCII Values**: Using character values directly as costs makes this a weighted string matching problem.
- **Space Optimization Possible**: Can reduce space to O(min(n,m)) by keeping only two rows/columns of the DP table.
