# 796. Rotate String

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

[LeetCode — 796. Rotate String](https://leetcode.com/problems/rotate-string/)

---

## Problem Summary

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.

A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.

For example, if `s = "abcde"`, then after one shift it becomes `"bcdea"`.

---

## Examples

### Example 1
**Input:** `s = "abcde", goal = "cdeab"`  
**Output:** `true`  
**Explanation:** After 2 shifts, s becomes "cdeab" which equals goal.

### Example 2
**Input:** `s = "abcde", goal = "abced"`  
**Output:** `false`  
**Explanation:** No matter how many shifts we perform, s cannot become "abced".

---

## Intuition

The key insight is that all rotations of a string `s` will appear as **substrings in `s + s`** (concatenation of `s` with itself).

For example:
- `s = "abcde"`
- `s + s = "abcdeabcde"`
- Rotations: "abcde", "bcdea", "cdeab", "deabc", "eabcd"
- All of these appear in "abcdeabcde"!

So we just need to check if `goal` is a substring of `s + s` and both have the same length.

---

## Approach

1. **Length Check:** If `s` and `goal` have different lengths, return `false` immediately.
2. **Substring Check:** Create `s + s` and check if `goal` is a substring of it using the `find()` method.
3. Return the result.

This is elegant and avoids explicit rotation simulation.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — substring search using optimized string matching (amortized) |
| **Space** | `O(n)` — for storing the concatenated string `s + s` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};
```

---

## Key Takeaways

- Concatenating a string with itself reveals all possible rotations as substrings.
- This trick avoids the need for explicit loop-based rotation simulation.
- String's `find()` method efficiently searches for substrings.
- Always validate preconditions (length check) before more complex operations.
