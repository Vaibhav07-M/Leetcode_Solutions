# 3713. Longest Balanced Substring I

**Difficulty:** `Medium`  
**Tags:** `String`, `Hash Table`, `Counting`

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

[LeetCode — 3713. Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/)

---

## Problem Summary

You are given a string `s` consisting of lowercase English letters.

A substring of `s` is called **balanced** if **all distinct characters** in the substring appear **the same number of times**.

Return the **length of the longest balanced substring** of `s`.

---

## Examples

### Example 1
**Input:** `s = "abbac"`  
**Output:** `4`  
**Explanation:**
- The longest balanced substring is `"abba"`.
- Both distinct characters 'a' and 'b' each appear exactly 2 times.

### Example 2
**Input:** `s = "zzabccy"`  
**Output:** `4`  
**Explanation:**
- The longest balanced substring is `"zabc"`.
- The distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.

### Example 3
**Input:** `s = "aba"`  
**Output:** `2`  
**Explanation:**
- One of the longest balanced substrings is `"ab"`.
- Both distinct characters 'a' and 'b' each appear exactly 1 time.
- Another longest balanced substring is `"ba"`.

---

## Intuition

A **balanced substring** means all distinct characters present have equal frequency—not that all characters in the alphabet appear equally, but that whichever characters **do** appear, they appear the same number of times.

For example:
- `"abba"` is balanced: 'a' appears 2 times, 'b' appears 2 times → min = max = 2 ✓
- `"abc"` is balanced: each appears 1 time → min = max = 1 ✓
- `"aab"` is **not** balanced: 'a' appears 2 times, 'b' appears 1 time → min ≠ max ✗

**Key insight:** For each substring, track the frequency of each character and check if all non-zero frequencies are equal (min frequency == max frequency among present characters).

---

## Approach

### Approach 1: Brute Force with Frequency Array

1. For each starting position `i`:
   - Initialize a frequency array `freq[26]` to count each character
2. For each ending position `j` from `i` to `n-1`:
   - Add `s[j]` to the frequency array
   - Find the minimum and maximum frequencies among characters that appear (freq > 0)
   - If `min == max`, this substring is balanced → update answer with length `j - i + 1`
3. Return the maximum length found

**Why this works:**
- We check all possible substrings: O(n²) substrings
- For each substring, we verify if all present characters have equal frequency
- By tracking min and max frequency, we can quickly check balance condition

---

## Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| **Brute Force with Frequency Check** | `O(n² × 26)` = `O(n²)` | `O(26)` = `O(1)` |

Where `n = s.length`.

- **Time:** O(n²) substrings, each requiring O(26) to check min/max frequencies
- **Space:** Fixed frequency array of size 26

Since `n ≤ 1000`, O(n²) = 10⁶ operations is acceptable.

---

## Code (C++)

### Solution 1: Brute Force with Min/Max Frequency Check

```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int freq[26] = {0};

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int minFreq = INT_MAX;
                int maxFreq = 0;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }

                if(minFreq == maxFreq) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
```

---

### Solution 2: Using unordered_map for Cleaner Code

```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for(int j = i; j < n; j++) {
                freq[s[j]]++;

                // Find min and max frequencies
                int minF = INT_MAX, maxF = 0;
                for(auto& [ch, count] : freq) {
                    minF = min(minF, count);
                    maxF = max(maxF, count);
                }

                // If all characters have same frequency
                if(minF == maxF) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
```

---

### Solution 3: Early Termination Optimization

```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // Early termination: remaining length can't beat current answer
            if(n - i <= ans) break;

            int freq[26] = {0};

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mn = 1e9, mx = 0;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        mn = min(mn, freq[k]);
                        mx = max(mx, freq[k]);
                    }
                }

                if(mn == mx) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
```

---

### Solution 4: Compact Version

```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int freq[26] = {0};
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int mn = 1e9, mx = 0;
                for(int k = 0; k < 26; k++) 
                    if(freq[k]) mn = min(mn, freq[k]), mx = max(mx, freq[k]);
                if(mn == mx) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- **"Balanced" definition varies:** Here it means equal frequency for all present characters, not equal distribution of specific types
- **Brute force is acceptable:** O(n²) works fine when n ≤ 1000 (constraints matter!)
- **Fixed-size array advantage:** For lowercase letters, `int[26]` is faster than `unordered_map`
- **Min/Max technique:** To check if all values are equal, verify `min == max`
- **Early termination:** Skip iterations when remaining length can't improve answer
- **Character indexing:** Use `s[j] - 'a'` to map 'a'-'z' to indices 0-25
- **Difference from similar problems:**
  - 3719/3721: Balanced subarray (equal distinct even/odd count)
  - 3713: Balanced substring (equal frequency for all present characters)
- **When to use frequency array:**
  - Limited alphabet (26 letters) → use `int[26]`
  - Arbitrary values → use `unordered_map`
- **Optimization strategy:** Early termination when `n - i <= ans` reduces unnecessary iterations
- **Template pattern:** Nested loop for all substrings + condition check is common for substring problems
- Related concepts: Frequency counting, substring enumeration, character distribution

---
