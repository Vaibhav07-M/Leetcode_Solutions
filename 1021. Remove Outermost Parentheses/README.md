# 1021. Remove Outermost Parentheses

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

[LeetCode — 1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)

---

## Problem Summary

The problem requires removing the outermost parentheses from a valid parentheses string, specifically targeting the 'primitive' components of the string. A primitive component is a non-empty valid parentheses string that cannot be split into two smaller non-empty valid strings. The goal is to return the string with only the innermost parentheses retained for each primitive block.

---

## Examples

### Example 1
**Input:** `s = "(()())(())"`  
**Output:** `"()()()"`  
**Explanation:**
- The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
- After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

### Example 2
**Input:** `s = "(()())(())(()(()))"`  
**Output:** `"()()()()(())"`  
**Explanation:**
- The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
- After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

### Example 3
**Input:** `s = "()()"`  
**Output:** `""`  
**Explanation:**
- The input string is "()()", with primitive decomposition "()" + "()".
- After removing outer parentheses of each part, this is "" + "" = "".

---

## Intuition

The solution uses a depth counter to track the nesting level of parentheses. By iterating through the string, we can identify when we are inside a primitive block (depth > 0) and when we are at the outermost level (depth == 0). The key insight is that the outermost parentheses of a primitive block are the first '(' and last ')' that are not part of a deeper nested structure, so they should be excluded from the final answer.

---

## Approach

1. Initialize an empty string 'answer' to store the result and an integer 'depth' to track the nesting level.
2. Iterate through each character 'c' in the input string 's'.
3. If 'c' is '(', increment the depth counter. If the depth is greater than 0 (meaning we are not at the outermost level), append '(' to the answer.
4. If 'c' is ')', decrement the depth counter. If the depth is greater than 0 (meaning we are still within a nested structure), append ')' to the answer.
5. The outermost parentheses (which correspond to depth == 0) are not added to the answer, effectively removing them.
6. Return the final string 'answer' containing only the innermost parentheses.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single loop that iterates through the 'n' characters of the input string. Each character is processed in constant time, leading to a linear time complexity. |
| **Space** | `O(n)` — The space complexity is determined by the output string 'answer'. In the worst case, if the input string contains no nested structures (i.e., it is a single primitive block), the output will be nearly the same length as the input, resulting in a linear space requirement. |

---

## Code (C++)

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int depth = 0;

        for (char c : s) {

            if (c == '(') {
                if (depth > 0)
                    answer += '(';

                depth++;
            }
            else {
                depth--;

                if (depth > 0)
                    answer += ')';
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- The problem highlights the concept of 'primitive' parentheses strings and the importance of identifying the outermost boundaries of such structures.
- The solution demonstrates a simple yet effective use of a counter (depth) to distinguish between nested and outermost elements in a linear scan.
- This approach can be generalized to other problems involving hierarchical or nested data structures where the outermost layer needs to be removed or identified.
