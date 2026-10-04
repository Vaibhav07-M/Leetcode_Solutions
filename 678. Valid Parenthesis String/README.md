# 678. Valid Parenthesis String

**Difficulty:** `Medium`  
**Tags:** `String`, `Dynamic Programming`, `Stack`, `Greedy`, `Bracket Sequences`

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

[LeetCode — 678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

---

## Problem Summary

The problem requires determining if a string containing parentheses and asterisks is valid. A valid string must have a balanced number of opening and closing parentheses, with no closing parenthesis appearing before its corresponding opening one. The asterisk character can be interpreted as either an opening parenthesis, a closing parenthesis, or an empty string.

---

## Examples

### Example 1
**Input:** `s = "()"`  
**Output:** `true`  

### Example 2
**Input:** `s = "(*)"`  
**Output:** `true`  

### Example 3
**Input:** `s = "(*))"`  
**Output:** `true`  

### Example 4
**Input:** `s = "("`  
**Output:** `false`  

---

## Intuition

The solution employs a dynamic programming-like approach using two integer variables, 'low' and 'high', to track the minimum and maximum possible counts of unmatched opening parentheses. By iterating through the string and updating these bounds based on the character type, the algorithm can determine if a valid configuration exists. The key insight is that if the 'high' count ever becomes negative, the string is invalid, as there are too many closing parentheses or asterisks relative to the opening ones.

---

## Approach

1. Initialize two counters, 'low' and 'high', to zero. These represent the lower and upper bounds of the number of unmatched opening parentheses.
2. Iterate through each character in the string.
3. If the character is an opening parenthesis '(', increment both 'low' and 'high'.
4. If the character is a closing parenthesis ')', decrement both 'low' and 'high'.
5. If the character is an asterisk '*', decrement 'low' (to account for it being a closing parenthesis) and increment 'high' (to account for it being an opening parenthesis).
6. After each update, ensure 'low' does not drop below zero (using max(0, low)).
7. If 'high' becomes negative at any point, return false, as this indicates an imbalance where there are too many closing elements.
8. After the loop, check if 'low' is zero. If it is, the string is valid; otherwise, it is invalid.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single loop that iterates through the 'n' characters of the string, performing constant-time operations for each character. Therefore, the time complexity is linear. |
| **Space** | `O(1)` — The solution uses only two integer variables ('low' and 'high') to store the state, regardless of the input string length. This results in a constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;
                high++;
            }

            // We cannot have fewer than 0 unmatched '('
            low = max(0, low);

            // Even the maximum possible '(' count is negative
            if (high < 0)
                return false;
        }

        return low == 0;
    }
};
```

---

## Key Takeaways

- The use of two bounds ('low' and 'high') allows for efficient tracking of the valid range of parenthesis counts.
- The algorithm effectively handles the ambiguity of the asterisk character by expanding the possible state space.
- The check for 'high < 0' is a critical early-exit condition that prevents unnecessary computation on clearly invalid strings.
