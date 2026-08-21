# 13. Roman to Integer

**Difficulty:** `Easy`  
**Tags:** `Hash Table`, `Math`, `String`

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

[LeetCode — 13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

---

## Problem Summary

The problem requires converting a Roman numeral to an integer. Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M. The numerals are usually written largest to smallest from left to right, but there are six instances where subtraction is used to represent numbers like 4, 9, 40, 90, 400, and 900.

---

## Examples

### Example 1
**Input:** `s = "III"`  
**Output:** `3`  
**Explanation:**
- III = 3.

### Example 2
**Input:** `s = "LVIII"`  
**Output:** `58`  
**Explanation:**
- L = 50, V= 5, III = 3.

### Example 3
**Input:** `s = "MCMXCIV"`  
**Output:** `1994`  
**Explanation:**
- M = 1000, CM = 900, XC = 90 and IV = 4.

---

## Intuition

The solution uses a simple yet effective approach to handle the subtraction cases in Roman numerals. It iterates through the input string from left to right, adding the value of each numeral to the result. However, when it encounters a numeral that is smaller than the next one, it subtracts the value of the current numeral instead of adding it. This way, the solution correctly handles the subtraction cases and produces the correct integer result.

---

## Approach

1. Create a hash map to store the values of the Roman numerals. Initialize the result variable to zero. Iterate through the input string, checking if the current numeral is smaller than the next one. If it is, subtract the value of the current numeral from the result; otherwise, add the value of the current numeral to the result. Return the final result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — where n is the length of the input string, because the solution iterates through the string once. |
| **Space** | `O(1)` — because the solution uses a constant amount of space to store the hash map and the result variable, regardless of the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]]) {
                ans -= value[s[i]];
            } else {
                ans += value[s[i]];
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- This solution demonstrates the importance of understanding the problem constraints and using a simple yet effective approach to solve it. It also highlights the use of a hash map to store the values of the Roman numerals, which allows for efficient lookups and calculations.
