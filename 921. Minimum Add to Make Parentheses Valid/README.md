# 921. Minimum Add to Make Parentheses Valid

**Difficulty:** `Medium`  
**Tags:** `String`, `Stack`, `Greedy`, `Bracket Sequences`

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

[LeetCode — 921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

---

## Problem Summary

The problem requires determining the minimum number of parentheses insertions needed to make a given string valid. A valid string must have balanced opening and closing parentheses, following the standard rules for nested expressions. The solution uses a single-pass algorithm with a counter to track the balance and calculate the necessary additions.

---

## Examples

### Example 1
**Input:** `s = "())"`  
**Output:** `1`  

### Example 2
**Input:** `s = "((("`  
**Output:** `3`  

---

## Intuition

The core insight is to track the 'depth' of the opening parentheses using a counter. As we iterate through the string, we increment the counter for each '(' and decrement it for each ')'. If the counter becomes negative (meaning there are more closing than opening parentheses), we must add an opening parenthesis to balance it. At the end of the string, any remaining positive counter value indicates the number of opening parentheses that need corresponding closing parentheses to complete the validation.

---

## Approach

1. Initialize a counter 'open' to 0 and an answer variable 'answer' to 0.
2. Iterate through each character in the string 's'.
3. If the character is '(', increment the 'open' counter.
4. If the character is ')', check the 'open' counter. If it is greater than 0, decrement it (indicating a valid pair). If it is 0 or less, increment the 'answer' (indicating a missing opening parenthesis).
5. After the loop, add the current value of the 'open' counter to the 'answer' (representing the missing closing parentheses).
6. Return the total 'answer' as the minimum number of insertions required.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single loop that iterates through the 'n' characters of the input string. Each character is processed in constant time, leading to a linear time complexity. |
| **Space** | `O(1)` — The solution uses only a few integer variables (open and answer) to store state, requiring constant space regardless of the input size. There are no dynamic data structures or recursion involved that would increase space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int answer = 0;

        for (char c : s) {

            if (c == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                }
                else {
                    answer++;
                }
            }
        }

        answer += open;

        return answer;
    }
};
```

---

## Key Takeaways

- A single-pass linear scan is sufficient to determine the validity of a parentheses string.
- A simple counter can effectively track the balance of opening and closing brackets.
- The final state of the counter directly indicates the number of missing closing parentheses, which is a key part of the solution.
