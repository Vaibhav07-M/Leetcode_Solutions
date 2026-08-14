# 3090. Maximum Length Substring With Two Occurrences

**Difficulty:** `Easy`  
**Tags:** `String`, `Sliding Window`, `Hash Table`

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

[LeetCode — 3090. Maximum Length Substring With Two Occurrences](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)

---

## Problem Summary

Given a string `s`, return the **maximum length** of a substring such that it contains **at most two occurrences** of each character.

---

## Examples

### Example 1
**Input:** `s = "bcbbbcba"`  
**Output:** `4`  
**Explanation:**  
The following substring has a length of 4 and contains at most two occurrences of each character: `"bcbb"`.

### Example 2
**Input:** `s = "aaaa"`  
**Output:** `2`  
**Explanation:**  
The following substring has a length of 2 and contains at most two occurrences of each character: `"aa"`.

---

## Intuition

We need to find the longest substring where no character appears more than twice.  
This is a classic **sliding window** problem: maintain a window `[left, right]` and expand `right` while tracking character frequencies.  
If any character's frequency exceeds 2, shrink the window from the left until the condition is satisfied again.

---

## Approach

1. Use an array `freq[26]` to count character frequencies in the current window.
2. Initialize `left = 0`, `ans = 0`.
3. Iterate `right` from `0` to `s.length() - 1`:
   - Increment `freq[s[right] - 'a']`.
   - While `freq[s[right] - 'a'] > 2`:
     - Decrement `freq[s[left] - 'a']`.
     - Increment `left`.
   - Update `ans = max(ans, right - left + 1)`.
4. Return `ans`.

This ensures the window always satisfies the "at most two occurrences" constraint.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — each character is visited at most twice (once by `right`, once by `left`) |
| **Space** | `O(1)` — fixed-size frequency array of 26 |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- **Sliding window** is ideal for "longest substring with constraint on character frequencies".
- The window expands with `right` and contracts with `left` only when the constraint is violated.
- Since the alphabet is fixed (lowercase English letters), a simple array of size 26 is sufficient for frequency tracking.
- Time complexity is linear because each pointer moves monotonically forward.