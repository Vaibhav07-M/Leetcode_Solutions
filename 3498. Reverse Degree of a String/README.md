# 3498. Reverse Degree of a String

**Difficulty:** `Easy`  
**Tags:** `String`, `Simulation`

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

[LeetCode — 3498. Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string/)

---

## Problem Summary

The problem requires calculating the 'reverse degree' of a given string. This involves assigning a numerical value to each character based on its position in the reversed alphabet (e.g., 'a' is 26, 'z' is 1) and multiplying it by the character's index in the string. The final result is the sum of these products.

---

## Examples

_No examples provided._

---

## Intuition

The solution iterates through the string, calculating the reverse value for each character by subtracting its ASCII offset from 26. It then multiplies this value by the character's 1-indexed position in the string and accumulates the result. This approach directly implements the definition of the reverse degree provided in the problem statement.

---

## Approach

1. Initialize a variable 'answer' to store the total reverse degree.
2. Iterate through each character in the string using a for loop.
3. For each character, calculate its 'reverseValue' by subtracting its ASCII value ('a' is 0, 'b' is 1, etc.) from 26.
4. Determine the character's 'position' in the string (1-indexed) by adding 1 to the loop index 'i'.
5. Multiply the 'reverseValue' by the 'position' and add the result to the 'answer' accumulator.
6. After the loop completes, return the 'answer' as the final reverse degree.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm consists of a single for-loop that iterates through the 'n' characters of the string. Within the loop, constant-time operations are performed (subtraction, multiplication, addition), resulting in a linear time complexity. |
| **Space** | `O(1)` — The space complexity is constant. The solution uses a fixed number of integer variables ('answer', 'reverseValue', 'position') regardless of the input string's length. No additional data structures or arrays are required. |

---

## Code (C++)

```cpp
class Solution {
public:
    int reverseDegree(string s) {
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            int reverseValue = 26 - (s[i] - 'a');
            int position = i + 1;

            answer += reverseValue * position;
        }

        return answer;
    }
};
```

---

## Key Takeaways

- The problem demonstrates a specific string manipulation technique where character values are derived from their position in the alphabet.
- The solution effectively uses the ASCII character encoding to map letters to integers for calculation.
- The approach is straightforward, relying on a single loop and basic arithmetic operations to solve the problem.
