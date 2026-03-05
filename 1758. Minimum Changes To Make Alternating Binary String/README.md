# 1758. Minimum Changes To Make Alternating Binary String

**Difficulty:** `Easy`  
**Tags:** `String`, `Greedy`

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

[LeetCode — 1758. Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)

---

## Problem Summary

You are given a binary string `s` (only `'0'` and `'1'`).  
In one operation, you can change any character to `'0'` or `'1'`.

A string is **alternating** if no two adjacent characters are equal (e.g., `"0101"`, `"1010"`).

Return the **minimum number of operations** to make `s` alternating.

---

## Examples

### Example 1
**Input:** `s = "0100"`  
**Output:** `1`  
**Explanation:** Change last character → `"0101"`, which is alternating.

### Example 2
**Input:** `s = "10"`  
**Output:** `0`  
**Explanation:** `"10"` is already alternating.

### Example 3
**Input:** `s = "1111"`  
**Output:** `2`  
**Explanation:** Need 2 changes to reach `"0101"` or `"1010"`.

---

## Intuition

There are exactly **two** valid alternating binary strings of any given length:
- **Pattern A:** starts with `'0'` → `"010101..."`
- **Pattern B:** starts with `'1'` → `"101010..."`

Key observation: if making `s` match **Pattern A** requires `x` changes, then making it match **Pattern B** requires exactly `n - x` changes. This is because every mismatch with Pattern A is a match with Pattern B and vice versa.

So we only need to count mismatches with one pattern, and the answer is `min(x, n - x)`.

---

## Approach

1. Iterate over the string once.
2. Count how many positions mismatch the expected character for Pattern A (`"0101..."`):
   - Even index → expected `'0'`
   - Odd index → expected `'1'`
3. Let `x` = mismatch count with Pattern A. Mismatches with Pattern B = `n - x`.
4. Return `min(x, n - x)`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the string |
| **Space** | `O(1)` — only counters used |

---

## Code (C++)

### Solution 1 — Track Both Patterns Simultaneously (Submitted)

```cpp
class Solution {
public:
    int minOperations(string s) {
        int changeStart0 = 0;
        int changeStart1 = 0;

        for (int i = 0; i < s.size(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0) changeStart0++;
            if (s[i] != expected1) changeStart1++;
        }

        return min(changeStart0, changeStart1);
    }
};
```

---

### Solution 2 — Exploit Symmetry (One Counter)

Count mismatches with only Pattern A; Pattern B mismatches = `n - x`.

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mismatch = 0;

        for (int i = 0; i < n; i++) {
            // Pattern A: even index → '0', odd index → '1'
            if (s[i] - '0' != i % 2) mismatch++;
        }

        return min(mismatch, n - mismatch);
    }
};
```

---

### Solution 3 — Count Matching Chars with XOR

`s[i] ^ (i % 2)` equals `0` when `s[i]` matches Pattern A at position `i`.  
Count matches with Pattern A, then answer = `min(matches, n - matches)`.

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int matchA = 0;

        for (int i = 0; i < n; i++) {
            // s[i] - '0' XOR (i % 2): 0 means matches Pattern A
            if ((s[i] - '0') == (i % 2)) matchA++;
        }

        // matchA positions already correct for Pattern A
        // n - matchA positions correct for Pattern B
        return min(n - matchA, matchA);
    }
};
```

---

### Solution 4 — Count Odd/Even Position Characters

Separately count `'1'`s at even positions and `'0'`s at even positions.

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int onesAtEven = 0;

        for (int i = 0; i < n; i += 2) {
            if (s[i] == '1') onesAtEven++;
        }

        // Pattern A ("0101..."): need zerosAtEven = (n+1)/2 - onesAtEven
        // changes for A = onesAtEven + (n/2 - zerosAtOdd) = onesAtEven + ...
        // Simpler: changes for "0101" = onesAtEven + zerosAtOdd
        int zerosAtOdd = 0;
        for (int i = 1; i < n; i += 2) {
            if (s[i] == '0') zerosAtOdd++;
        }

        int changesA = onesAtEven + zerosAtOdd;
        return min(changesA, n - changesA);
    }
};
```

---

## Key Takeaways

- There are only **2** valid alternating patterns for any length → always compare against both.
- **Symmetry trick:** `changes(PatternA) + changes(PatternB) = n`, so one counter suffices.
- `s[i] - '0' != i % 2` is a clean condition to check mismatch against the `"0101..."` pattern.
- Greedy single-pass is optimal — no sorting or extra data structures needed.
