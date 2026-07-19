# 1081. Smallest Subsequence of Distinct Characters

**Difficulty:** `Medium`  
**Tags:** `String`, `Stack`, `Greedy`, `Monotonic Stack`

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

[LeetCode — 1081. Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

---

## Problem Summary

Given a string `s`, return the **lexicographically smallest subsequence** that contains **every distinct character exactly once**.

---

## Examples

### Example 1

**Input:** `s = "bcabc"`

**Output:** `"abc"`

---

### Example 2

**Input:** `s = "cbacdcbc"`

**Output:** `"acdb"`

---

## Intuition

To obtain the lexicographically smallest subsequence:

- Every character should appear exactly once.
- If a smaller character appears later, larger characters currently in the answer should be removed **only if they appear again later**.
- A stack naturally supports removing previously chosen characters when a better choice is found.

---

## Approach

1. Compute the last occurrence index of every character.
2. Maintain:
   - a stack (implemented using a string),
   - a `used` array to avoid duplicates.
3. Iterate through the string:
   - Skip the character if it is already included.
   - Otherwise, while:
     - the stack is not empty,
     - the top character is lexicographically larger,
     - and that character appears again later,
     remove it from the stack.
4. Push the current character and mark it as used.
5. The stack forms the required answer.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` *(26 lowercase letters)* |

---

## Code (C++)

```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> used(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (used[c - 'a']) continue;

            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};
```

---

## Key Takeaways

- Record the last occurrence of every character before processing.
- Use a monotonic increasing stack to maintain the lexicographically smallest subsequence.
- Only remove a character if it appears again later in the string.
- Track included characters with a boolean array to ensure each character appears exactly once.
- The algorithm processes each character at most twice, resulting in **O(n)** time complexity.