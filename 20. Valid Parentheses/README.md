# 20. Valid Parentheses

**Difficulty:** `Easy`  
**Tags:** `String`, `Stack`, `Bracket Sequences`

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

[LeetCode — 20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

---

## Problem Summary

The problem requires determining if a string of parentheses is valid, meaning all opening brackets are correctly matched with closing brackets of the same type in the correct order. The solution uses a stack to track unmatched opening brackets and checks for valid pairs as closing brackets are encountered.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is that a valid sequence of brackets can be verified by processing characters from left to right. When an opening bracket is seen, it is pushed onto a stack. When a closing bracket is seen, it must match the most recently added opening bracket (the top of the stack). If the stack is empty or the types don't match, the sequence is invalid. A valid sequence will result in an empty stack at the end.

---

## Approach

1. Initialize an empty stack to hold unmatched opening brackets.
2. Iterate through each character in the input string.
3. If the character is an opening bracket ('(', '[', or '{'), push it onto the stack.
4. If the character is a closing bracket, check if the stack is empty. If it is, return false (no matching opening bracket).
5. If the stack is not empty, pop the top element and compare it to the current closing bracket. If they do not form a valid pair, return false.
6. After processing all characters, check if the stack is empty. If it is, the sequence is valid; otherwise, it is invalid.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the string once, performing constant-time operations (push and pop) for each character. Therefore, the time complexity is linear relative to the length of the string. |
| **Space** | `O(n)` — In the worst case, all characters are opening brackets, requiring them all to be stored on the stack. The space complexity is proportional to the maximum depth of the stack, which can be up to the length of the string. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {

                // No opening bracket to match
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if (c == ')' && top != '(')
                    return false;

                if (c == ']' && top != '[')
                    return false;

                if (c == '}' && top != '{')
                    return false;
            }
        }

        // All brackets must be matched
        return st.empty();
    }
};
```

---

## Key Takeaways

- A stack is an ideal data structure for verifying bracket sequences because it naturally supports the Last-In-First-Out (LIFO) order required for matching.
- The solution demonstrates a simple but effective algorithm for parsing and validating structured data (like parentheses) by maintaining state with a stack.
