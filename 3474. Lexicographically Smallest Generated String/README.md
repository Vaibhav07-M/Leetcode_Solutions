# 3474. Lexicographically Smallest Generated String

**Difficulty:** `Hard`  
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

[LeetCode - 3474. Lexicographically Smallest Generated String](https://leetcode.com/problems/lexicographically-smallest-generated-string/)

---

## Problem Summary

You are given two strings:
- `str1` of length `n`, containing only `T` and `F`
- `str2` of length `m`, containing lowercase English letters

Build a string `word` of length `n + m - 1` such that for every index `i` in `[0, n - 1]`:

- If `str1[i] == 'T'`, then `word[i..i + m - 1]` must be exactly `str2`
- If `str1[i] == 'F'`, then `word[i..i + m - 1]` must **not** be `str2`

Return the lexicographically smallest valid `word`, or `""` if impossible.

---

## Examples

### Example 1
**Input:** `str1 = "TFTF", str2 = "ab"`  
**Output:** `"ababa"`

### Example 2
**Input:** `str1 = "TFTF", str2 = "abc"`  
**Output:** `""`

### Example 3
**Input:** `str1 = "F", str2 = "d"`  
**Output:** `"a"`

---

## Intuition

1. Every `T` position forces a full copy of `str2` at that index, so these are hard constraints.
2. To get the lexicographically smallest result, all unconstrained positions should be filled with `'a'` first.
3. Then verify each `F` window. If an `F` window accidentally equals `str2`, we must break it by changing one character.
4. While breaking an `F` window, we should modify as far right as possible and with the smallest possible replacement character that keeps all `T` windows valid.

This gives the smallest possible string under all constraints.

---

## Approach

1. Create `word` of length `n + m - 1`, initialized with `'?'`.
2. Apply all `T` constraints:
   - For every `i` with `str1[i] == 'T'`, force `word[i + j] = str2[j]`.
   - If a forced character conflicts with an already forced different character, return `""`.
3. Fill all remaining `'?'` positions with `'a'`.
4. Process all `F` constraints:
   - If the current length-`m` window already differs from `str2`, continue.
   - If it matches exactly, try to break it:
     - Scan positions from right to left inside this window.
     - Try replacement letters from `'a'` to `'z'` excluding current letter.
     - Keep a change only if all `T` constraints still remain valid.
   - If no valid change exists, return `""`.
5. Return the built string.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | Worst case can be high due to repeated validation while fixing `F` windows |
| **Space** | `O(n + m)` for the constructed string and checks |

---

## Code (C++)

```cpp
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        int len = n + m - 1;
        vector<char> word(len, '?');
        
        // STEP 1: Apply 'T' constraints
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return ""; // conflict
                    }
                }
            }
        }
        
        // STEP 2: Fill remaining with 'a'
        for(int i = 0; i < len; i++) {
            if(word[i] == '?') word[i] = 'a';
        }
        
        // STEP 3: Fix 'F' constraints
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                
                bool match = true;
                for(int j = 0; j < m; j++) {
                    if(word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                if(match) {
                    // break it -> change a character
                    bool fixed = false;
                    
                    for(int j = m - 1; j >= 0; j--) {
                        int idx = i + j;
                        
                        for(char c = 'a'; c <= 'z'; c++) {
                            if(c != word[idx]) {
                                char old = word[idx];
                                word[idx] = c;
                                
                                // check if still valid for T constraints
                                bool ok = true;
                                for(int k = 0; k < n; k++) {
                                    if(str1[k] == 'T') {
                                        for(int x = 0; x < m; x++) {
                                            if(word[k + x] != str2[x]) {
                                                ok = false;
                                                break;
                                            }
                                        }
                                        if(!ok) break;
                                    }
                                }
                                
                                if(ok) {
                                    fixed = true;
                                    break;
                                }
                                
                                word[idx] = old;
                            }
                        }
                        
                        if(fixed) break;
                    }
                    
                    if(!fixed) return "";
                }
            }
        }
        
        return string(word.begin(), word.end());
    }
};
```

---

## Key Takeaways

- First satisfy mandatory equality (`T`) constraints and detect conflicts early.
- Use greedy lexicographic initialization (`'a'`) to minimize the answer.
- For `F` constraints, only modify when forced, and prefer rightmost/local minimal changes.
- Always re-check hard constraints after any local modification.
