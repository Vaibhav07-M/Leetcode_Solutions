# 1888. Minimum Number of Flips to Make the Binary String Alternating

**Difficulty:** `Medium`  
**Tags:** `String`, `Sliding Window`

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

[LeetCode — 1888. Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

---

## Problem Summary

You are given a binary string `s`. You can perform two types of operations:
1. **Type-1:** Remove the character at the start of the string and append it to the end.
2. **Type-2:** Pick any character and flip its value (`'0'` to `'1'` or vice-versa).

Return the **minimum number of type-2 operations** (flips) required to make the string alternating (no two adjacent characters are equal).

---

## Examples

### Example 1
**Input:** `s = "111000"`  
**Output:** `2`  
**Explanation:** 
- Use Type-1 twice to make `s = "100011"`.
- Use Type-2 on the third and sixth elements to make `s = "101010"`.

### Example 2
**Input:** `s = "010"`  
**Output:** `0`  
**Explanation:** The string is already alternating.

### Example 3
**Input:** `s = "1110"`  
**Output:** `1`  
**Explanation:** Use Type-2 on the second element to make `s = "1010"`.

---

## Intuition

The Type-1 operation effectively shifts the string circularly. If we consider the string duplicated as `s + s`, a window of length `n` sliding through `s + s` represents all possible states of the string after any number of Type-1 operations.

An alternating binary string of length `n` can only have two forms:
- `target1`: starts with `'1'` (e.g., `"101010..."`)
- `target2`: starts with `'0'` (e.g., `"010101..."`)

Instead of trying all operations and regenerating strings, we can track the differences between a sliding window of size `n` in `s + s` against the infinite repeating alternating patterns. The minimum difference found determines the least number of flips needed.

---

## Approach

1. **Duplicate the String:** Concatenate `s` to itself. Let `s2 = s + s` of length `2n`. This naturally simulates the Type-1 operation as a sliding window of size `n` moving along `s2`.
2. **Define Alternating Targets:** We maintain running counts of differences (`alt1` and `alt2`) against the two alternating patterns:
   - Pattern 1: `1, 0, 1, 0, ...` (where index `i % 2 == 1` has `'0'` and `i % 2 == 0` has `'1'`)
   - Pattern 2: `0, 1, 0, 1, ...` (where index `i % 2 == 0` has `'0'` and `i % 2 == 1` has `'1'`)
3. **Sliding Window:**
   - As we iterate through `s2`, we compare the current character `s2[i]` against what it should be in both patterns, incrementing `alt1` or `alt2` if there is a mismatch.
   - If our window exceeds size `n` (i.e., `i >= n`), we remove the effect of the character that just slid out of the window from the left (`s2[i - n]`).
   - If the window has reached the required size `n` (i.e., `i >= n - 1`), we take the minimum of `alt1` and `alt2` and update our global minimum `res`.
   
---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — we iterate over the string of size `2n` exactly once |
| **Space** | `O(n)` — to store the concatenated string `s2 = s + s` |

---

## Code (C++)

```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        int alt1 = 0, alt2 = 0;
        int res = INT_MAX;

        for(int i = 0; i < s2.size(); i++) {

            if(s2[i] != (i % 2 ? '1' : '0')) alt1++;
            if(s2[i] != (i % 2 ? '0' : '1')) alt2++;

            if(i >= n) {
                if(s2[i-n] != ((i-n) % 2 ? '1' : '0')) alt1--;
                if(s2[i-n] != ((i-n) % 2 ? '0' : '1')) alt2--;
            }

            if(i >= n-1) {
                res = min(res, min(alt1, alt2));
            }
        }

        return res;
    }
};
```

---

## Key Takeaways

- Circular shifts of a string can often be handled elegantly by concatenating the string to itself (`s + s`) and using a sliding window.
- When there are only a few possible target states (like the two alternating patterns), compare the sliding window dynamically against all targets instead of generating new strings.
- Sliding window permits updating counts optimally in `O(1)` time by only processing the elements entering and exiting the window.
