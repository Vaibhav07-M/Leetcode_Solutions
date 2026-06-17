# 3614. Process String with Special Operations II

**Difficulty:** `Hard`  
**Tags:** `String`, `Simulation`, `Greedy`

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

[LeetCode — 3614. Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/)

---

## Problem Summary

You are given a string `s` consisting of lowercase English letters and the special characters:

- `'*'` → Remove the last character from the current result (if it exists).
- `'#'` → Duplicate the current result and append it to itself.
- `'%'` → Reverse the current result.

You are also given an integer `k`.

After processing the entire string, return the character at index `k` of the final result.

If `k` is outside the bounds of the final string, return `'.'`.

---

## Examples

### Example 1
**Input:** `s = "a#b%*"`, `k = 1`  
**Output:** `"a"`

**Explanation:**

Processing produces:

`"a" → "aa" → "aab" → "baa" → "ba"`

Final string = `"ba"`

Character at index `1` = `'a'`.

### Example 2
**Input:** `s = "cd%#*#"`, `k = 3`  
**Output:** `"d"`

**Explanation:**

Processing produces:

`"c" → "cd" → "dc" → "dcdc" → "dcd" → "dcddcd"`

Character at index `3` = `'d'`.

### Example 3
**Input:** `s = "z*#"`, `k = 0`  
**Output:** `"."`

**Explanation:**

Processing produces an empty string.

Since index `0` does not exist, return `'.'`.

---

## Intuition

The final string can become extremely large (up to `10^15` characters), making it impossible to construct directly.

Instead, we only track the **length** of the resulting string after each operation.

Once we know the final length:

- If `k` is outside the final string, return `'.'`.
- Otherwise, work **backwards** through the operations.
- Reverse each operation to determine where the current index originated.

This allows us to find the required character without ever building the full string.

---

## Approach

### 1. Track Lengths

Create an array `len` where:

```cpp
len[i]
```

stores the length of the result after processing the first `i` characters.

Operations affect length as follows:

- Letter → `+1`
- `'*'` → `-1` (if possible)
- `'#'` → `×2`
- `'%'` → unchanged

To avoid overflow, cap lengths at:

```cpp
1e15 + 1
```

which is sufficient because `k ≤ 10^15`.

---

### 2. Validate k

If:

```cpp
k >= len[n]
```

then the requested position does not exist, so return:

```cpp
'.'
```

---

### 3. Traverse Backwards

Process `s` from right to left.

For every operation, map the current index `k` to the position it had **before** that operation.

#### Letter

A character was appended at position:

```cpp
prev
```

If:

```cpp
k == prev
```

then that letter is the answer.

---

#### '*'

The operation removed only the last character.

All remaining positions stay unchanged, so no update to `k` is required.

---

#### '#'

The string became:

```text
original + original
```

If `k` lies in the second copy:

```cpp
k -= prev;
```

to map it back into the first copy.

---

#### '%'

The string was reversed.

Convert the current position back to its original position:

```cpp
k = cur - 1 - k;
```

---

### 4. Return the Character

Eventually, the traced index reaches the character that originally created it.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    char processStr(string s, long long k) {

        const long long LIM = 1000000000000000LL;

        int n = s.size();

        vector<long long> len(n + 1, 0);

        for(int i = 0; i < n; i++) {

            char c = s[i];

            if('a' <= c && c <= 'z') {
                len[i + 1] = min(LIM + 1, len[i] + 1);
            }
            else if(c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if(c == '#') {
                len[i + 1] = min(LIM + 1, len[i] * 2);
            }
            else { // %
                len[i + 1] = len[i];
            }
        }

        if(k >= len[n]) return '.';

        for(int i = n - 1; i >= 0; i--) {

            char c = s[i];

            long long prev = len[i];
            long long cur  = len[i + 1];

            if('a' <= c && c <= 'z') {

                if(k == prev)
                    return c;
            }
            else if(c == '*') {

                // surviving positions unchanged

            }
            else if(c == '#') {

                if(k >= prev)
                    k -= prev;
            }
            else { // %

                if(cur > 0)
                    k = cur - 1 - k;
            }
        }

        return '.';
    }
};
```

---

## Key Takeaways

- Never construct the final string when its size can reach `10^15`.
- Store only the length after each operation.
- Work backwards to trace the desired index.
- Duplication and reversal operations can be reversed mathematically.
- Reverse simulation is a powerful technique for problems involving huge transformed strings.