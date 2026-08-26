# 2904. Shortest and Lexicographically Smallest Beautiful String

**Difficulty:** `Medium`  
**Tags:** `String`, `Sliding Window`

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

[LeetCode — 2904. Shortest and Lexicographically Smallest Beautiful String](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/)

---

## Problem Summary

You are given a binary string s and a positive integer k.  
A substring of s is beautiful if the number of 1's in it is exactly k.

---

## Examples

### Example 1
**Input:** `s = "100011001", k = 3`  
**Output:** `"11001"`  
**Explanation:**
- There are 7 beautiful substrings in this example:
- 1. The substring "100011001".
- 2. The substring "100011001".
- 3. The substring "100011001".
- 4. The substring "100011001".
- 5. The substring "100011001".
- 6. The substring "100011001".
- 7. The substring "100011001".
- The length of the shortest beautiful substring is 5.
- The lexicographically smallest beautiful substring with length 5 is the substring "11001".

### Example 2
**Input:** `s = "1011", k = 2`  
**Output:** `"11"`  
**Explanation:**
- There are 3 beautiful substrings in this example:
- 1. The substring "1011".
- 2. The substring "1011".
- 3. The substring "1011".
- The length of the shortest beautiful substring is 2.
- The lexicographically smallest beautiful substring with length 2 is the substring "11".

### Example 3
**Input:** `s = "000", k = 1`  
**Output:** `""`  
**Explanation:**
- There are no beautiful substrings in this example.

---

## Intuition

The problem revolves around string, sliding window. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

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
| **Space** | `O(1)` — only a few variables |

---

## Code (C++)

```cpp
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                // Remove leading zeros while still keeping k ones
                while (s[left] == '0')
                    left++;

                int len = right - left + 1;
                string cur = s.substr(left, len);

                if (len < minLen) {
                    minLen = len;
                    ans = cur;
                }
                else if (len == minLen && cur < ans) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- String, Sliding Window patterns often reduce an apparently complex problem to a few simple rules.
