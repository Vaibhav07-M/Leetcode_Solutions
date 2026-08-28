# 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target

**Difficulty:** `Hard`  
**Tags:** `Two Pointers`, `String`, `Enumeration`

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

[LeetCode — 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)

---

## Problem Summary

You are given two strings s and target, each of length n, consisting of lowercase English letters.  
Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around two pointers, string, enumeration. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:

    string result = "";
    char midChar = '$';
    int half = 0;

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if (i == half) {

            string candidate = curr; //left Half
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf)); //right half
            
            if(midChar != '$')
                candidate += midChar; //mid character

            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char ch : s) 
            count[ch - 'a']++;

        int oddCount = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) { 
                oddCount++; 
                midChar = c + 'a'; 
            }
        }
        if (oddCount > 1) 
            return "";

        // Left-half counts + middle char (only when n is odd).
        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        string curr;
        solve(curr, halfCount, target, 0, false);
        return result;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Two Pointers, String, Enumeration patterns often reduce an apparently complex problem to a few simple rules.
