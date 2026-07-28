# 3517. Smallest Palindromic Rearrangement I

**Difficulty:** `Medium`  
**Tags:** `String`, `Greedy`, `Counting`, `Hash Table`

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

[LeetCode – 3517. Smallest Palindromic Rearrangement I](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/)

---

## Problem Summary

You are given a **palindromic** string `s`.

Return the **lexicographically smallest** palindrome that can be formed by rearranging the characters of `s`.

It is guaranteed that `s` can always be rearranged into a palindrome.

---

## Examples

### Example 1

**Input**

```text
s = "z"
```

**Output**

```text
"z"
```

---

### Example 2

**Input**

```text
s = "babab"
```

**Output**

```text
"abbba"
```

**Explanation**

Rearranging `"babab"` into `"abbba"` produces the smallest lexicographical palindrome.

---

### Example 3

**Input**

```text
s = "daccad"
```

**Output**

```text
"acddca"
```

**Explanation**

Rearranging `"daccad"` into `"acddca"` gives the smallest possible palindrome.

---

## Intuition

A palindrome is completely determined by:

- its **left half**,
- an optional **middle character** (for odd-length strings),
- and the mirrored **right half**.

To obtain the lexicographically smallest palindrome:

- Place the smallest available characters as early as possible in the left half.
- If a character has an odd frequency, it becomes the middle character.
- Mirror the left half to construct the right half.

---

## Approach

1. Count the frequency of each lowercase letter.
2. For every character from `'a'` to `'z'`:
   - Add `frequency / 2` copies to the left half.
   - If its frequency is odd, store it as the middle character.
3. Reverse the left half to obtain the right half.
4. Concatenate:

```text
left + middle + right
```

5. Return the resulting palindrome.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

where `n` is the length of the string.

---

## Code (C++)

```cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "", mid = "";

        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
```

---

## Key Takeaways

- Count character frequencies to determine how many copies belong in each half.
- Build the left half in alphabetical order to ensure the smallest lexicographical result.
- Any character with an odd frequency becomes the middle character.
- Mirror the left half to complete the palindrome.
- The solution runs in **O(n)** time using simple frequency counting.