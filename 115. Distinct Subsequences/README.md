# 115. Distinct Subsequences

**Difficulty:** `Hard`  
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

[LeetCode — 115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

---

## Problem Summary

The problem requires finding the number of distinct subsequences of a source string 's' that match a target string 't'. The solution employs a dynamic programming approach to efficiently count these matches, utilizing a 2D array to store intermediate results and avoid redundant calculations.

---

## Examples

### Example 1
**Input:** `s = "rabbbit", t = "rabbit"`  
**Output:** `3`  
**Explanation:**
- As shown below, there are 3 ways you can generate "rabbit" from s.
- rabbbit
- rabbbit
- rabbbit

### Example 2
**Input:** `s = "babgbag", t = "bag"`  
**Output:** `5`  
**Explanation:**
- As shown below, there are 5 ways you can generate "bag" from s.
- babgbag
- babgbag
- babgbag
- babgbag
- babgbag

---

## Intuition

The core insight is to break the problem into smaller sub-problems. For each character in 't', we determine if it matches the current character in 's'. If there's a match, the count of subsequences is the sum of those that include the current character (moving diagonally) and those that don't (moving horizontally). If there's no match, we only consider subsequences that don't include the current character.

---

## Approach

1. Initialize a 2D dynamic programming array 'dp' where 'dp[i][j]' represents the number of distinct subsequences of 's[0...i-1]' that match 't[0...j-1]'.
2. Define a recursive function 'solve' that takes the current indices 'm' and 'n' for 's' and 't' respectively.
3. In the 'solve' function, check if the current characters 's[m-1]' and 't[n-1]' are equal. If they are, add the results of two recursive calls: one that includes the current character (moving diagonally) and one that excludes it (moving horizontally). If they are not equal, only move horizontally.
4. The main function 'numDistinct' initializes the 'dp' array with -1 (indicating uncomputed values) and calls the 'solve' function with the full lengths of the strings to get the final count.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The time complexity is determined by the size of the dynamic programming table. Since the table has dimensions m (length of s) by n (length of t), and each cell requires a constant amount of time to compute (either a lookup or a simple addition), the total time is proportional to the product of the two lengths. |
| **Space** | `O(m * n)` — The space complexity is dominated by the 2D 'dp' array used to store the intermediate results. This array requires m * n units of space to hold the counts for all possible substrings of 's' and 't'. |

---

## Code (C++)

```cpp
class Solution {
public:

    int dp[1001][1001];
    int solve(string& s, string& t, int m, int n) {
        if(n == 0)
            return dp[m][n] = 1;
        if(m == 0)
            return dp[m][n] = 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        /*
            (rabb) b (it)
            (ra)   b (bbit)
            (rab)  b (bit)
            This can help to understand the if condition below
        */
        if(s[m-1] == t[n-1])
            return dp[m][n] = solve(s, t, m-1, n) + solve(s, t, m-1, n-1);
        else
            return dp[m][n] = solve(s, t, m-1, n);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(s, t, m, n);
    }
};
```

---

## Key Takeaways

- This problem demonstrates a classic application of dynamic programming to solve a counting problem involving string matching.
- The key to the solution is the recursive definition that splits the problem into two cases based on whether the current characters match, allowing for efficient computation of the total number of distinct subsequences.
