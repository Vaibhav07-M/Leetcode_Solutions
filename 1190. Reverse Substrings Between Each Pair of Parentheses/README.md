# 1190. Reverse Substrings Between Each Pair of Parentheses

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

[LeetCode — 1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

---

## Problem Summary

The problem involves a string containing lowercase letters and parentheses. The goal is to reverse the characters between each pair of matching parentheses, starting from the innermost pair, and then remove all parentheses to produce the final output string.

---

## Examples

### Example 1
**Input:** `s = "(abcd)"`  
**Output:** `"dcba"`  

### Example 2
**Input:** `s = "(u(love)i)"`  
**Output:** `"iloveu"`  
**Explanation:**
- The substring "love" is reversed first, then the whole string is reversed.

### Example 3
**Input:** `s = "(ed(et(oc))el)"`  
**Output:** `"leetcode"`  
**Explanation:**
- First, we reverse the substring "oc", then "etco", and finally, the whole string.

---

## Intuition

The solution uses a stack to process the string from left to right. When a closing parenthesis ')' is encountered, it indicates the end of a substring to be reversed. The characters are popped from the stack into a temporary string until the corresponding opening parenthesis '(' is found. The reversed temporary string is then pushed back onto the stack. This process effectively reverses the substrings enclosed by parentheses. Finally, the stack is emptied to form the answer string, which is then reversed to correct the overall order.

---

## Approach

1. Initialize an empty stack to hold characters.
2. Iterate through the input string character by character.
3. If the current character is a closing parenthesis '):
4. Pop characters from the stack into a temporary string until an opening parenthesis '(' is found.
5. Remove the opening parenthesis from the stack.
6. Push the characters from the temporary string back onto the stack (effectively reversing the substring).
7. If the current character is not a closing parenthesis, push it onto the stack.
8. After processing the entire string, pop all remaining characters from the stack to form the answer string.
9. Reverse the answer string to correct the order of the reversed substrings.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the input string once (O(n)) and performs stack operations (push and pop) for each character. The reversal of the final string is also O(n). Thus, the overall time complexity is linear. |
| **Space** | `O(n)` — The stack requires space proportional to the length of the input string to hold the characters. Additionally, temporary strings are used during the reversal process, but the dominant space factor is the stack itself. |

---

## Code (C++)

```cpp
class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;

        for (char c : s) {

            // Closing bracket
            if (c == ')') {

                string temp = "";

                // Get everything inside the parentheses
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // temp is already reversed
                // because we removed characters from the stack
                for (char ch : temp) {
                    st.push(ch);
                }
            }

            else {
                // Normal character or '('
                st.push(c);
            }
        }

        // Build final answer
        string answer = "";

        while (!st.empty()) {
            answer += st.top();
            st.pop();
        }

        // Stack gives reverse order,
        // so reverse it back
        reverse(answer.begin(), answer.end());

        return answer;
    }
};
```

---

## Key Takeaways

- A stack is an effective data structure for managing nested structures like parentheses.
- Reversing a substring can be achieved by popping elements into a temporary container and pushing them back in reverse order.
- The final output requires a second reversal to correct the order of the reversed substrings.
