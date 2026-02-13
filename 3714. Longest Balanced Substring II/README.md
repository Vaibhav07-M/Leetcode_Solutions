# 3714. Longest Balanced Substring II

**Difficulty:** `Medium`  
**Tags:** `String`, `Hash Table`, `Prefix Sum`

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

[LeetCode — 3714. Longest Balanced Substring II](https://leetcode.com/problems/longest-balanced-substring-ii/)

---

## Problem Summary

You are given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`.

A substring of `s` is called **balanced** if **all distinct characters** in the substring appear **the same number of times**.

Return the **length of the longest balanced substring** of `s`.

**Note:** This is the optimized version with larger constraints (`n ≤ 10^5`) compared to problem 3713 (`n ≤ 1000`).

---

## Examples

### Example 1
**Input:** `s = "abbac"`  
**Output:** `4`  
**Explanation:**
- The longest balanced substring is `"abba"`.
- Both distinct characters 'a' and 'b' each appear exactly 2 times.

### Example 2
**Input:** `s = "aabcc"`  
**Output:** `3`  
**Explanation:**
- The longest balanced substring is `"abc"`.
- All distinct characters 'a', 'b', and 'c' each appear exactly 1 time.

### Example 3
**Input:** `s = "aba"`  
**Output:** `2`  
**Explanation:**
- One of the longest balanced substrings is `"ab"`.
- Both distinct characters 'a' and 'b' each appear exactly 1 time.
- Another longest balanced substring is `"ba"`.

---

## Intuition

Unlike problem 3713 where `n ≤ 1000` allows O(n²) brute force, this problem has `n ≤ 10^5`, requiring an **O(n) solution**.

**Key Insight:** Since the string contains only 3 characters ('a', 'b', 'c'), we can break the problem into **three cases**:

1. **One-character substrings:** Consecutive same characters (e.g., "aaaa")
2. **Two-character substrings:** Use **prefix sum difference** technique
3. **Three-character substrings:** Use **2D state hashing** with prefix sums

**Prefix Sum Technique:**
- For two characters, track difference: `countA - countB`
- If we see the same difference again, the substring between has equal counts
- For three characters, track two differences: `(countA - countB, countA - countC)`

---

## Approach

### Approach: Three-Case Analysis with Prefix Sum

**Case 1: Single Character Substrings**
- Find longest consecutive sequence of same character
- Example: "aaaa" → length 4

**Case 2: Two Character Substrings**
- For each pair (a,b), (a,c), (b,c):
  - Use prefix sum: treat one char as +1, other as -1
  - Use hash map to store first occurrence of each difference
  - If same difference appears again, substring between has equal counts
  - Reset when encountering the third character

**Case 3: Three Character Substrings**
- Track counts of all three: `countA`, `countB`, `countC`
- Use 2D state: `(diffAB, diffAC)` where:
  - `diffAB = countA - countB`
  - `diffAC = countA - countC`
- If we see same state `(diffAB, diffAC)` again:
  - The substring between has equal count changes
  - Which means all three characters have equal counts
- Store state as string key in hash map

**Algorithm:**
```
1. Case 1: Find longest consecutive same characters
2. Case 2: For each pair of characters:
   a. Use hash map with difference as key
   b. Track when third char appears (reset state)
3. Case 3: All three characters:
   a. Use hash map with (diffAB, diffAC) as key
   b. Update max length when same state reappears
4. Return maximum across all cases
```

---

## Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| **Prefix Sum with Hash Map** | `O(n)` | `O(n)` |

- **Time:** Single pass for each case (4 passes total: 1 + 3 pairs + 1 three-char)
- **Space:** Hash map stores at most O(n) states

---

## Code (C++)

### Solution 1: Complete Three-Case Solution

```cpp
class Solution {
public:
    int helper(string& s, int ch1, int ch2) {
        int n = s.length();
        unordered_map<int, int> diffMap;
        int maxL = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++) {
            // Reset when encountering third character
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;

            // Equal counts case
            if(count1 == count2) {
                maxL = max(maxL, count1 + count2);
            }

            // Check if we've seen this difference before
            int diff = count1 - count2;
            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;

        // Case 1: Single character substrings
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        // Case 2: Two character substrings
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        // Case 3: Three character substrings
        int countA = 0, countB = 0, countC = 0;
        unordered_map<string, int> diffMap;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            // All three equal
            if(countA == countB && countA == countC) {
                maxL = max(maxL, countA + countB + countC);
            }

            // Store 2D state as string key
            int diffAB = countA - countB;
            int diffAC = countA - countC;
            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(key)) {
                maxL = max(maxL, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxL;
    }
};
```

---

### Solution 2: Using pair<int,int> for 2D State

```cpp
class Solution {
public:
    int twoCharHelper(string& s, char ch1, char ch2) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int diff = 0, maxLen = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ch1) diff++;
            else if(s[i] == ch2) diff--;
            else {
                mp.clear();
                mp[0] = i;
                diff = 0;
            }
            
            if(!mp.count(diff)) mp[diff] = i;
            maxLen = max(maxLen, i - mp[diff]);
        }
        return maxLen;
    }
    
    int longestBalanced(string s) {
        int ans = 1, n = s.length();
        
        // Case 1: Consecutive same characters
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        
        // Case 2: Two characters
        ans = max({ans, twoCharHelper(s, 'a', 'b'), 
                   twoCharHelper(s, 'b', 'c'), 
                   twoCharHelper(s, 'a', 'c')});
        
        // Case 3: Three characters
        map<pair<int,int>, int> state;
        state[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;
            
            pair<int,int> key = {a - b, a - c};
            if(!state.count(key)) state[key] = i;
            ans = max(ans, i - state[key]);
        }
        
        return ans;
    }
};
```

---

### Solution 3: Compact Version

```cpp
class Solution {
public:
    int helper(string& s, char x, char y) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int d = 0, mx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == x) d++;
            else if(s[i] == y) d--;
            else { mp.clear(); mp[0] = i; d = 0; }
            if(!mp.count(d)) mp[d] = i;
            mx = max(mx, i - mp[d]);
        }
        return mx;
    }
    
    int longestBalanced(string s) {
        int ans = 1, cnt = 1;
        for(int i = 1; i < s.size(); i++)
            ans = max(ans, s[i] == s[i-1] ? ++cnt : cnt = 1);
        
        ans = max({ans, helper(s, 'a', 'b'), helper(s, 'b', 'c'), helper(s, 'a', 'c')});
        
        map<pair<int,int>, int> mp;
        mp[{0,0}] = -1;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') a++; else if(s[i] == 'b') b++; else c++;
            auto k = make_pair(a-b, a-c);
            if(!mp.count(k)) mp[k] = i;
            ans = max(ans, i - mp[k]);
        }
        return ans;
    }
};
```

---

## Key Takeaways

- **Constraint-driven optimization:** O(n²) → O(n) when n increases from 1000 to 10^5
- **Character limitation exploitation:** With only 3 characters, enumerate all cases
- **Prefix sum difference technique:** For equal counts, track difference instead of absolute values
- **2D state representation:** Use `(diffAB, diffAC)` to capture three-character state
- **Hash map for first occurrence:** Store first index where each state appears
- **Reset strategy:** Clear state when encountering incompatible character
- **Multiple case handling:** Check 1-char, 2-char, and 3-char cases separately
- **String vs pair for keys:** String concatenation works but `pair<int,int>` is cleaner
- **Initial state matters:** Initialize map with `{0: -1}` or `{(0,0): -1}` for substrings starting at index 0
- **Three characters = four cases:** 1 single-char + 3 two-char pairs + 1 three-char
- Related technique: Subarray sum equals k, contiguous array with equal 0s and 1s
- **From brute force to optimized:** 3713 (O(n²)) vs 3714 (O(n)) - same problem, different constraints

---
