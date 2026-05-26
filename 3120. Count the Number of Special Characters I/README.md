# 3120. Count the Number of Special Characters I

**Difficulty:** `Easy`  
**Tags:** `String`, `Hash Table`, `Counting`

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

[LeetCode — 3120. Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/)

---

## Problem Summary

Given a string `word`, a letter is "special" if it appears in both lowercase and uppercase in `word`. Return the number of special letters.

---

## Examples

### Example 1
**Input:** `word = "aaAbcBC"`  
**Output:** `3`

### Example 2
**Input:** `word = "abc"`  
**Output:** `0`

### Example 3
**Input:** `word = "abBCab"`  
**Output:** `1`

---

## Intuition

Count occurrences of each character in lowercase and uppercase forms; a character is special if both counts are positive.

---

## Approach

1. Use two boolean arrays or bitmasks to track which lowercase and uppercase letters appear.
2. Iterate through `word` and set the appropriate flag for each character.
3. For each letter `a` to `z`, increment the answer if both lowercase and uppercase flags are set.

This runs in O(n) time and O(1) extra space (alphabet size).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int countSpecialCharacters(string word) {
        vector<bool> lower(26, false), upper(26, false);
        for (char c : word) {
            if (islower(c)) lower[c - 'a'] = true;
            else if (isupper(c)) upper[c - 'A'] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) if (lower[i] && upper[i]) ++ans;
        return ans;
    }
};
```

---

## Key Takeaways

- Use small fixed-size tables for character presence when alphabet is limited.
- Convert characters to indices for efficient bookkeeping.
- This pattern is useful for many case-insensitive or case-sensitive frequency problems.
