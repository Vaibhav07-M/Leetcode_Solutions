# 2472. Maximum Number of Non-overlapping Palindrome Substrings

**Difficulty:** `Hard`  
**Tags:** `Two Pointers`, `String`, `Dynamic Programming`, `Greedy`

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

[LeetCode — 2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

---

## Problem Summary

The problem requires finding the maximum number of non-overlapping substrings in a given string, where each substring is a palindrome and has a length of at least k. The solution employs a dynamic programming approach to systematically explore the string and determine the optimal selection of palindromic segments.

---

## Examples

### Example 1
**Input:** `s = "abaccdbbd", k = 3`  
**Output:** `2`  
**Explanation:**
- We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
- It can be shown that we cannot find a selection with more than two valid substrings.

### Example 2
**Input:** `s = "adbcda", k = 2`  
**Output:** `0`  
**Explanation:**
- There is no palindrome substring of length at least 2 in the string.

---

## Intuition

The core insight is to use a recursive, memoized function to evaluate the potential for forming palindromes at different positions. By checking if a segment is a palindrome, the algorithm decides whether to 'take' the current segment (adding to the count) or to 'slide' the window to look for better options, ensuring that the chosen segments do not overlap.

---

## Approach

1. Initialize a 2D memoization table to store results for subproblems defined by the start and end indices of the string segment.
2. Define a recursive function that checks if the current segment is a palindrome. If it is, calculate the maximum count by either growing the window, taking the current segment, or sliding the window. If it is not a palindrome, simply slide the window.
3. The base case for the recursion is when the indices are out of bounds, returning 0. The final result is obtained by calling the recursive function with the initial parameters (start index 0 and end index k-1).
4. The time complexity is optimized by memoization, preventing redundant calculations for overlapping subproblems.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — The algorithm iterates over all possible pairs of indices (i, j) to check for palindromes, resulting in a quadratic number of operations. However, the memoization significantly reduces the effective number of computations by storing intermediate results. |
| **Space** | `O(n^2)` — The space complexity is dominated by the 2D memoization table, which requires storage for approximately n^2 entries to keep track of the results for each subproblem. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    //max non-overlapping palindromic pieces (length >= k) from s[i..j]
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (isPalindrome(s, i, j)) {
            int growWindow  = solve(s, k, i, j + 1, t);
            int takeIt      = 1 + solve(s, k, j + 1, j + k, t);
            int slideWindow = solve(s, k, i + 1, j + 1, t);

            return t[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, t);
        int growWindow  = solve(s, k, i, j + 1, t);

        return t[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n; //each character can be a substring

        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, t);
    }
};
```

---

## Key Takeaways

- The solution effectively combines palindrome checking with dynamic programming to solve a complex substring selection problem.
- The use of memoization is critical to avoid exponential time complexity, as it allows the algorithm to reuse results from previous calculations.
- The approach demonstrates a clear strategy for maximizing the number of valid segments while adhering to the non-overlapping constraint.
