# 2124. Check if All A's Appears Before All B's

**Difficulty:** `Easy`  
**Tags:** `String`

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

[LeetCode — 2124. Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)

---

## Problem Summary

The problem requires checking if a string containing only 'a' and 'b' characters has all 'a's appearing before all 'b's. The solution iterates through the string to verify this ordering constraint.

---

## Examples

### Example 1
**Input:** `s = "aaabbb"`  
**Output:** `true`  
**Explanation:**
- The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
- Hence, every 'a' appears before every 'b' and we return true.

### Example 2
**Input:** `s = "abab"`  
**Output:** `false`  
**Explanation:**
- There is an 'a' at index 2 and a 'b' at index 1.
- Hence, not every 'a' appears before every 'b' and we return false.

### Example 3
**Input:** `s = "bbb"`  
**Output:** `true`  
**Explanation:**
- There are no 'a's, hence, every 'a' appears before every 'b' and we return true.

---

## Intuition

The core insight is that the string must maintain a specific order: 'a' characters first, followed by 'b' characters. If a 'b' is encountered before an 'a', or if an 'a' appears after a 'b', the constraint is violated. The solution checks for this violation by scanning the string for any instance where a 'b' precedes an 'a'.

---

## Approach

1. Initialize a loop to iterate through the string starting from the second character (index 1).
2. For each character at index i, check the previous character at index i-1.
3. If the previous character is 'b' and the current character is 'a', return false immediately as this violates the ordering constraint.
4. If no such violation is found after scanning the entire string, return true.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm performs a single linear scan of the string, checking each character once. The time complexity is directly proportional to the length of the string n. |
| **Space** | `O(1)` — The solution uses only a few integer variables for indexing and does not require any additional data structures or arrays that scale with the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == 'b' && s[i] == 'a') 
                return false;
        }
        return true;
    }
};
```

---

## Key Takeaways

- The solution demonstrates a simple linear scan approach to verify a specific ordering constraint in a binary string.
- It highlights the importance of checking for specific edge cases (like 'b' appearing before 'a') to determine the validity of the string's structure.
