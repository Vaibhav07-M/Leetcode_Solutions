# 32. Longest Valid Parentheses

**Difficulty:** `Hard`  
**Tags:** `String`, `Dynamic Programming`, `Stack`, `Bracket Sequences`

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

[LeetCode — 32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

---

## Problem Summary

The problem requires finding the length of the longest valid (well-formed) parentheses substring within a given string. A valid substring must have an equal number of opening and closing parentheses, and the closing parentheses must appear after the corresponding opening ones. The solution uses a two-pass approach, scanning from left to right and then from right to left, to identify the longest segment where the balance of parentheses is maintained.

---

## Examples

### Example 1
**Input:** `s = "(()"`  
**Output:** `2`  
**Explanation:**
- The longest valid parentheses substring is "()".

### Example 2
**Input:** `s = ")()())"`  
**Output:** `4`  
**Explanation:**
- The longest valid parentheses substring is "()()".

### Example 3
**Input:** `s = ""`  
**Output:** `0`  

---

## Intuition

The core insight is to track the balance of parentheses using two counters (open and close) as we traverse the string. If the number of closing parentheses exceeds the number of opening parentheses, the current segment is invalid and we reset the counters. Conversely, if the number of opening parentheses exceeds the number of closing parentheses, the segment is also invalid (in the second pass). The maximum length of a valid substring is recorded whenever the counters are equal, indicating a perfectly balanced segment.

---

## Approach

1. Initialize two counters, open and close, to 0, and a variable result to 0 to store the maximum valid length.
2. Perform a left-to-right scan of the string. For each character, increment the corresponding counter (open for '(', close for ')').
3. If the counters are equal (open == close), update the result with the current total count (open + close), as this represents a valid substring length.
4. If the close counter exceeds the open counter, reset both counters to 0, as the current segment is no longer valid.
5. Repeat the same process in a right-to-left scan, resetting the counters if the open counter exceeds the close counter.
6. Return the final result, which contains the length of the longest valid parentheses substring found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The solution involves two linear scans of the input string (one from left to right and one from right to left), where each character is processed once. Therefore, the time complexity is linear relative to the length of the string. |
| **Space** | `O(1)` — The algorithm uses a fixed number of integer variables (open, close, result) regardless of the input size. There are no dynamic data structures or arrays used that would scale with the input length, resulting in constant space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int open  = 0;
        int close = 0;

        int result = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(close > open) { //going from left to right, if close is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        open  = 0;
        close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                result = max(result, open+close);
            } else if(open > close) { //going from right to left, if open is more, it's no more valid
                open  = 0;
                close = 0;
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- A two-pass scanning technique can effectively identify the longest valid substring by checking the balance of parentheses from both directions.
- Tracking the difference or equality of opening and closing parentheses counts allows for efficient detection of valid segments without needing to store the entire string structure.
- This approach is particularly useful for bracket sequence problems where the goal is to find the maximum valid segment rather than validating the entire string.
