# 1415. The k-th Lexicographical String of All Happy Strings of Length n

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

[LeetCode - 1415. The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

---

## Problem Summary

A happy string:
- uses only `a`, `b`, `c`
- has no two adjacent equal characters

Given `n` and `k`, consider all happy strings of length `n` in lexicographical order.

Return the `k`-th string, or `""` if there are fewer than `k` happy strings.

---

## Examples

### Example 1
**Input:** `n = 1, k = 3`  
**Output:** `"c"`

### Example 2
**Input:** `n = 1, k = 4`  
**Output:** `""`

### Example 3
**Input:** `n = 3, k = 9`  
**Output:** `"cab"`

---

## Intuition

Total number of happy strings of length `n` is:
- first character: `3` choices
- each next character: `2` choices (cannot match previous)

So total = `3 * 2^(n-1)`.

For lexicographical construction:
- at position `i`, each valid candidate character contributes a block of `2^(remaining)` strings
- use `k` to skip whole blocks until landing in the target block

This builds the answer directly without generating all strings.

---

## Approach

1. Compute `total = 3 * 2^(n-1)`. If `k > total`, return empty string.
2. Build answer left to right.
3. At each position:
- iterate `a`, `b`, `c`
- skip same as previous character
- each valid character has `cnt = 2^(remaining positions)` strings under it
- if `k > cnt`, skip this block (`k -= cnt`)
- otherwise choose this character and continue
4. Return the built string.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` (constant alphabet size 3) |
| **Space** | `O(1)` extra (excluding output string) |

---

## Code (C++)

### Solution 1 - Block Counting Construction (Submitted)

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        
        int total = 3 * (1 << (n-1));
        if(k > total) return "";

        string ans = "";
        vector<char> letters = {'a','b','c'};

        char prev = '#';

        for(int i=0;i<n;i++) {

            int remain = n - i - 1;

            for(char c : letters) {

                if(c == prev) continue;

                int cnt = 1 << remain;

                if(k > cnt) {
                    k -= cnt;
                }
                else {
                    ans += c;
                    prev = c;
                    break;
                }
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Count-based construction can replace full backtracking generation.
- Lexicographical order can be navigated by skipping fixed-size blocks.
- The `3 * 2^(n-1)` formula gives an immediate invalid-`k` check.
