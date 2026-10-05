# 856. Score of Parentheses

**Difficulty:** `Medium`  
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

[LeetCode — 856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)

---

## Problem Summary

The problem requires calculating the score of a balanced parentheses string based on specific rules: '()' scores 1, concatenation adds scores, and nesting doubles the score. The solution uses a stack to track the score of the current nesting level as it processes the string from left to right.

---

## Examples

### Example 1
**Input:** `s = "()"`  
**Output:** `1`  

### Example 2
**Input:** `s = "(())"`  
**Output:** `2`  

### Example 3
**Input:** `s = "()()"`  
**Output:** `2`  

---

## Intuition

The key insight is to use a stack to keep track of the 'current score' at each level of nesting. When opening a parenthesis, we push a 0 (or the current level's score) onto the stack. When closing a parenthesis, we pop the top value (which represents the score of the enclosed expression), double it if it's non-zero (indicating a nested expression), and add it to the score of the enclosing expression (the new top of the stack). This allows us to recursively compute the score of the entire string by processing the characters in order.

---

## Approach

1. Initialize a stack with a single element 0, which will hold the total score of the string.
2. Iterate through each character in the input string.
3. If the character is '(', push 0 onto the stack to start a new score counter for the nested expression.
4. If the character is ')', pop the top value from the stack (this is the score of the expression inside the parentheses).
5. If the popped value is 0, assign a score of 1 to it (base case for '()'). Otherwise, double the value (since it represents a nested expression).
6. Add the calculated score to the current top of the stack (the score of the enclosing expression).
7. After processing all characters, the top of the stack contains the final score of the entire string.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm processes each character in the string exactly once, performing constant-time operations (push, pop, add) for each character. Therefore, the time complexity is linear relative to the length of the input string. |
| **Space** | `O(n)` — The stack stores an integer for each opening parenthesis encountered. In the worst case (a string of only opening parentheses), the stack size will be proportional to the length of the string. However, since the string is balanced, the depth of the stack is limited by the nesting level, which is still linear in the context of the problem's constraints. |

---

## Code (C++)

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {

            if (c == '(') {
                st.push(0);
            }
            else {
                int inside = st.top();
                st.pop();

                int score;

                if (inside == 0)
                    score = 1;
                else
                    score = 2 * inside;

                st.top() += score;
            }
        }

        return st.top();
    }
};
```

---

## Key Takeaways

- A stack is an effective data structure for evaluating expressions with nested structures, such as parentheses or arithmetic operations.
- The solution demonstrates a recursive-like approach using iteration, where the stack keeps track of the 'state' (score) at different levels of the recursion.
- The base case for the score is explicitly handled when a pair of parentheses is found with no other characters between them.
