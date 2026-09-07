# 940. Distinct Subsequences II

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

[LeetCode — 940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)

---

## Problem Summary

The problem requires calculating the number of distinct non-empty subsequences of a given string 's'. The solution employs a dynamic programming approach to efficiently count these subsequences, taking into account the presence of duplicate characters to avoid over-counting.

---

## Examples

### Example 1
**Input:** `s = "abc"`  
**Output:** `7`  
**Explanation:**
- The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

### Example 2
**Input:** `s = "aba"`  
**Output:** `6`  
**Explanation:**
- The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

### Example 3
**Input:** `s = "aaa"`  
**Output:** `3`  
**Explanation:**
- The 3 distinct subsequences are "a", "aa" and "aaa".

---

## Intuition

The core insight is to use a recursive or iterative DP strategy where the state 'dp[n]' represents the number of distinct subsequences ending at index n. The key optimization is the 'prev' array, which tracks the last occurrence of each character. This allows the algorithm to subtract the number of subsequences that would be duplicated if a character repeats, ensuring each unique subsequence is counted only once.

---

## Approach

1. Initialize a DP array 'dp' to store the number of distinct subsequences up to each index, and a 'prev' array to track the last seen index of each character.
2. Iterate through the string, updating the 'prev' array with the current index for each character encountered.
3. Define a recursive function 'solve(n)' that calculates the number of distinct subsequences for the first 'n' characters. The base case is 'solve(0) = 1'.
4. In 'solve(n)', calculate the total number of subsequences by doubling the result of 'solve(n-1)' (since each subsequence can be extended by the current character or not).
5. If the current character has appeared before (prev[n] != 0), subtract the number of subsequences that would be duplicated (i.e., those ending at the previous occurrence of the character) to ensure uniqueness.
6. The final result is obtained by calling 'solve(n)' and subtracting 1 to exclude the empty subsequence, then taking the modulo to fit the result within the required range.
7. The time complexity is O(n) because each state is computed once, and the space complexity is O(n) for the DP and auxiliary arrays.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the string once to build the 'prev' array, and the recursive DP function 'solve' is called for each index, resulting in a linear time complexity relative to the length of the string. |
| **Space** | `O(n)` — The space is dominated by the 'dp' array and the 'prev' array, both of which have a size proportional to the length of the input string 'n'. |

---

## Code (C++)

```cpp
class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    vector<int> prev; //prev[n] = last time when we saw this nth character (1-based indexing)

    int solve(int n) {
        if(n == 0)
            return 1;

        if(dp[n] != -1)
            return dp[n];
        
        int total = (2*solve(n-1)) % M;

        if(prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26, 0);
        for(int i = 1; i <= n; i++) {
            int idx = s[i-1] -'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + M) % M;

    }
};
```

---

## Key Takeaways

- This solution demonstrates an efficient way to count distinct subsequences by leveraging dynamic programming and tracking character repetitions.
- The use of the 'prev' array is a critical optimization that prevents over-counting of subsequences when duplicate characters are present.
- The approach highlights the importance of considering the order and repetition of elements when calculating combinatorial quantities in string processing.
