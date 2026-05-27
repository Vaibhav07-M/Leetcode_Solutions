# 3121. Count the Number of Special Characters II

**Difficulty:** `Medium`  
**Tags:** `String`, `Counting`

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

[LeetCode — 3121. Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)

---

## Problem Summary

A letter `c` is called special if:
- It appears both in lowercase and uppercase in `word`, and
- Every lowercase occurrence of `c` appears before the first uppercase occurrence of `c`.

Return the number of special letters in `word`.

---

## Examples

### Example 1
**Input:** `word = "aaAbcBC"`  
**Output:** `3`

### Example 2
**Input:** `word = "abc"`  
**Output:** `0`

### Example 3
**Input:** `word = "AbBCab"`  
**Output:** `0`

---

## Intuition

Track for each letter whether lowercase occurrences end before the first uppercase occurrence; this can be done by recording first uppercase index and last lowercase index.

---

## Approach

1. Iterate once and record for each character:
   - `firstUpper[i]` = index of first uppercase occurrence of letter `i` (or INF if none)
   - `lastLower[i]` = index of last lowercase occurrence of letter `i` (or -INF if none)
2. A letter is special if `lastLower[i] != -INF && firstUpper[i] != INF && lastLower[i] < firstUpper[i]`.
3. Count such letters and return the count.

This runs in `O(n)` time and `O(1)` extra space (alphabet size).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int countSpecialCharacters(string word) {
        const int INF = 1e9;
        vector<int> firstUpper(26, INF), lastLower(26, -INF);
        for (int i = 0; i < (int)word.size(); ++i) {
            char c = word[i];
            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } else {
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) if (lastLower[i] != -INF && firstUpper[i] != INF && lastLower[i] < firstUpper[i]) ++ans;
        return ans;
    }
};
```

---

## Key Takeaways

- Record positional information (first/last indices) to evaluate order constraints.
- Single-pass scans plus fixed-size tables give linear time and constant extra space.
- This pattern generalizes to many order-based character checks.
