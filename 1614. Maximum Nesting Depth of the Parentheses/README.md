# 1614. Maximum Nesting Depth of the Parentheses

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

[LeetCode — 1614. Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

---

## Problem Summary

The problem requires determining the maximum nesting depth of parentheses in a given string. The nesting depth is defined as the maximum number of open parentheses that are simultaneously active at any point in the string. The solution involves iterating through the characters and tracking the current depth, updating the maximum depth whenever a new opening parenthesis is encountered.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to use a counter to track the current depth of nested parentheses. As we traverse the string, we increment the counter for each opening parenthesis and decrement it for each closing parenthesis. The maximum value of this counter during the traversal represents the maximum nesting depth of the parentheses.

---

## Approach

1. Initialize two variables: `depth` to track the current nesting level and `answer` to store the maximum depth observed.
2. Iterate through each character in the input string.
3. If the character is an opening parenthesis `(`, increment the `depth` counter and update the `answer` to the maximum of the current `answer` and the new `depth`.
4. If the character is a closing parenthesis `)`, decrement the `depth` counter.
5. After the loop, return the `answer`, which contains the maximum nesting depth found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm involves a single pass through the string, performing constant-time operations for each character. Therefore, the time complexity is linear relative to the length of the input string. |
| **Space** | `O(1)` — The solution uses a fixed number of integer variables (`depth` and `answer`) regardless of the input size. There are no dynamic data structures or arrays used that would scale with the input, resulting in constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxDepth(string s) {

        int depth = 0;
        int answer = 0;

        for (char c : s) {

            if (c == '(') {
                depth++;

                answer = max(answer, depth);
            }

            else if (c == ')') {
                depth--;
            }
        }

        return answer;
    }
};
```

---

## Key Takeaways

- This problem demonstrates a classic use of a stack-like counter to track nested structures. While a stack could be used, a simple integer counter is sufficient here because we only need the maximum depth, not the specific sequence of brackets.
- The solution is efficient, with linear time complexity and constant space complexity, making it suitable for large input strings.
