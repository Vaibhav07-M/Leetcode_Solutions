# 1784. Check if Binary String Has at Most One Segment of Ones

**Difficulty:** `Easy`  
**Tags:** `String`

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

[LeetCode — 1784. Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

---

## Problem Summary

Given a binary string `s` without leading zeros, return `true` if `s` contains at most one contiguous segment of ones. Otherwise, return `false`.

Constraints:
- `1 <= s.length <= 100`
- `s[i]` is either `'0'` or `'1'`.
- `s[0]` is `'1'`.

---

## Examples

### Example 1
**Input:** `s = "1001"`  
**Output:** `false`  
**Explanation:** The ones do not form a contiguous segment.

### Example 2
**Input:** `s = "110"`  
**Output:** `true`  
**Explanation:**  The ones form exactly one contiguous segment.

---

## Intuition

Since the string always starts with `'1'`, there is at least one segment of ones at the beginning of the string. If there is more than one segment of ones, it means that a segment of zeros must appear between them. In other words, a `'0'` must be followed by a `'1'`. 
So we can just check if the substring `"01"` exists in the string `s`. If it does, then there are at least two segments of ones. If it does not, then there is at most one segment of ones.

---

## Approach

1. Search for the occurrence of the substring `"01"` in the string `s`.
2. If `"01"` is found, return `false` because a new segment of ones has started after a zero.
3. If `"01"` is not found, return `true` because all ones must be contiguous since the string starts with `'1'`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — to scan the string once for `"01"` |
| **Space** | `O(1)` — no extra space required |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
```

---

## Key Takeaways

- We can deduce the logical condition to simplify the problem: since `s` starts with `'1'`, the presence of `"01"` is the only way a second segment of ones can occur.
- Utilizing built-in string functions like `find` can yield concise and highly readable code.
