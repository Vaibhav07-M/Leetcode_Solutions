# 3751. Total Waviness of Numbers in Range I

**Difficulty:** `Medium`  
**Tags:** `Math`, `Enumeration`

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

[LeetCode — 3751. Total Waviness of Numbers in Range I](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)

---

## Problem Summary

Given integers `num1` and `num2` defining an inclusive range `[num1, num2]`, the waviness of a number is the count of peaks and valleys among its digits (a peak is a digit strictly greater than both neighbors; a valley is strictly less than both neighbors). The first and last digits cannot be peaks/valleys. Numbers with fewer than 3 digits have waviness `0`.

Return the total waviness summed over all numbers in the range `[num1, num2]`.

Constraints: `1 <= num1 <= num2 <= 1e5`.

---

## Examples

### Example 1
**Input:** `num1 = 120, num2 = 130`  
**Output:** `3`

### Example 2
**Input:** `num1 = 198, num2 = 202`  
**Output:** `3`

### Example 3
**Input:** `num1 = 4848, num2 = 4848`  
**Output:** `2`

---

## Intuition

Because `num2 - num1` is at most 1e5 and each number's waviness can be computed in O(digits) time, a straightforward enumeration (check waviness for each number in the range) is fast enough and simplest.

---

## Approach

1. For each integer `x` from `num1` to `num2`:
   - Convert `x` to string `s` (or extract digits).
   - For each index `i` from `1` to `s.length()-2`, check if `s[i]` is a peak or valley and accumulate count.
2. Sum the waviness counts for all `x` and return the total.

This is O((num2 - num1) * D) time where `D` is digits count (≤ 6 here), and O(1) extra space.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((num2-num1) * D)` — D ≤ 6 |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int waviness(int x) {
        string s = to_string(x);
        int n = s.size();
        if (n < 3) return 0;
        int cnt = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] > s[i-1] && s[i] > s[i+1]) ++cnt;
            else if (s[i] < s[i-1] && s[i] < s[i+1]) ++cnt;
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int x = num1; x <= num2; ++x) ans += waviness(x);
        return ans;
    }
};
```

---

## Key Takeaways

- Enumeration is fine when the numeric range is small (~1e5).  
- Be careful with digit extraction and index bounds when checking neighbors.  
- For larger ranges, consider digit DP.
