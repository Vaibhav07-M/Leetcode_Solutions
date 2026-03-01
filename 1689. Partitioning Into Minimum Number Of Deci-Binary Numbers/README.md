# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

**Difficulty:** `Medium`  
**Tags:** `String`, `Greedy`, `Math`

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

[LeetCode — 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

---

## Problem Summary

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros.  
For example, `101` and `1100` are deci-binary, while `112` and `3001` are not.

Given a string `n` representing a positive decimal integer, return the **minimum number of positive deci-binary numbers** needed so that they sum up to `n`.

---

## Examples

### Example 1
**Input:** `n = "32"`  
**Output:** `3`  
**Explanation:**
- `10 + 11 + 11 = 32`
- We need 3 deci-binary numbers.

### Example 2
**Input:** `n = "82734"`  
**Output:** `8`  
**Explanation:**
- The digit `8` is the largest digit, so at minimum 8 deci-binary numbers are required.

### Example 3
**Input:** `n = "27346209830709182346"`  
**Output:** `9`  
**Explanation:**
- The digit `9` appears, so the answer is `9`.

---

## Intuition

Each deci-binary number can contribute at most `1` to any digit position.  
If a digit in `n` is `d`, we need at least `d` deci-binary numbers just to sum up that digit.  
The most demanding digit is the **maximum digit** in `n` — that determines the answer.

So: **minimum count = maximum digit in `n`**.

---

## Approach

1. Scan every character in `n`.
2. Keep track of the maximum digit seen so far.
3. **Early stop** if the current max reaches `9` (the highest possible digit).
4. Return the maximum digit found.

This is a single-pass greedy observation — no construction needed.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single scan of the string |
| **Space** | `O(1)` extra space |

---

## Code (C++)

### Solution 1: Simple Scan with Early Exit (Submitted)
```cpp
class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;

        for (char c : n) {
            maxDigit = max(maxDigit, c - '0');

            // Early stop if we find 9 (maximum possible)
            if (maxDigit == 9) return 9;
        }

        return maxDigit;
    }
};
```

### Solution 2: One-liner using `max_element`
```cpp
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
```

### Solution 3: Character Comparison (no int conversion)
```cpp
class Solution {
public:
    int minPartitions(string n) {
        char best = '0';

        for (char c : n) {
            if (c > best) {
                best = c;
                if (best == '9') return 9;
            }
        }

        return best - '0';
    }
};
```

### Solution 4: Check for `'9'` First
```cpp
class Solution {
public:
    int minPartitions(string n) {
        if (n.find('9') != string::npos) return 9;

        int maxDigit = 0;
        for (char c : n) {
            maxDigit = max(maxDigit, c - '0');
        }

        return maxDigit;
    }
};
```

### Solution 5: Functional Style with `accumulate`
```cpp
class Solution {
public:
    int minPartitions(string n) {
        return accumulate(n.begin(), n.end(), 0,
            [](int cur, char c) {
                return max(cur, c - '0');
            });
    }
};
```

---

## Key Takeaways

- The answer is simply the **maximum digit** in the string — a clean greedy observation.
- No need to actually construct the deci-binary numbers; the maximum digit tells us everything.
- Early stopping at digit `9` is a practical optimization for large inputs.
- `max_element` on a string works naturally since characters are ordered by ASCII value.
