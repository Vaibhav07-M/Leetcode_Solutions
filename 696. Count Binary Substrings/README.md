# 696. Count Binary Substrings

**Difficulty:** `Easy`  
**Tags:** `String`, `Two Pointers`

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

[LeetCode — 696. Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)

---

## Problem Summary

Given a binary string `s`, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

---

## Examples

### Example 1
**Input:** `s = "00110011"`  
**Output:** `6`  
**Explanation:**  
There are 6 substrings that have equal number of consecutive 1's and 0's: 
- `"0011"`, `"01"`, `"1100"`, `"10"`, `"0011"`, and `"01"`

Notice that some of these substrings repeat and are counted the number of times they occur.  
Also, `"00110011"` is not a valid substring because all the 0's (and 1's) are not grouped together.

### Example 2
**Input:** `s = "10101"`  
**Output:** `4`  
**Explanation:**  
There are 4 substrings: `"10"`, `"01"`, `"10"`, `"01"` that have equal number of consecutive 1's and 0's.

---

## Intuition

The key observation is that valid substrings must have:
1. **Consecutive 0's followed by consecutive 1's** (or vice versa)
2. **Equal count** of 0's and 1's

For example:
- `"0011"` is valid: 2 consecutive 0's followed by 2 consecutive 1's
- `"0101"` is NOT valid: 0's and 1's are not grouped consecutively
- `"000111"` can form: `"01"`, `"0011"`, `"000111"` (3 substrings)

The insight is that if we have `m` consecutive 0's followed by `n` consecutive 1's, we can form `min(m, n)` valid substrings:
- With `"000111"` (3 zeros, 3 ones): we can form `"01"`, `"0011"`, `"000111"` = `min(3, 3) = 3` substrings
- With `"0011"` (2 zeros, 2 ones): we can form `"01"`, `"0011"` = `min(2, 2) = 2` substrings
- With `"00111"` (2 zeros, 3 ones): we can form `"01"`, `"0011"` = `min(2, 3) = 2` substrings

We don't need to track the actual substrings, just count groups of consecutive characters.

---

## Approach

### Solution 1: Group Counting (Optimal)

1. **Track consecutive groups**: Count the length of each group of consecutive same characters
2. **For each pair of adjacent groups**: Add `min(prev_group_length, curr_group_length)` to result
3. **Implementation**:
   - Keep `prev` to store the length of previous group
   - Keep `curr` to track the current group length
   - When character changes, add `min(prev, curr)` and update counters
   - Don't forget to add the last pair after the loop

**Example walkthrough for `"00110011"`:**
- Start: `prev=0, curr=1` (first '0')
- Position 1: same char ('0'), `curr=2`
- Position 2: change to '1', add `min(0,2)=0`, `prev=2, curr=1`
- Position 3: same char ('1'), `curr=2`
- Position 4: change to '0', add `min(2,2)=2`, `prev=2, curr=1`, total=2
- Position 5: same char ('0'), `curr=2`
- Position 6: change to '1', add `min(2,2)=2`, `prev=2, curr=1`, total=4
- Position 7: same char ('1'), `curr=2`
- After loop: add `min(2,2)=2`, total=6

### Alternative: Store All Group Lengths

First pass: collect all group lengths in an array  
Second pass: sum `min(groups[i], groups[i+1])` for all adjacent pairs

This uses O(n) space but is easier to understand.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the string |
| **Space** | `O(1)` — only a few variables used |

---

## Code (C++)

### Solution 1: One-Pass Group Counting (Optimal)

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0;
        int curr = 1;
        int ans = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        ans += min(prev, curr);
        return ans;
    }
};
```

### Solution 2: Two-Pass with Group Array

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;
        
        // First pass: collect group lengths
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);
        
        // Second pass: sum min of adjacent groups
        int result = 0;
        for(int i = 1; i < groups.size(); i++) {
            result += min(groups[i-1], groups[i]);
        }
        
        return result;
    }
};
```

### Solution 3: Cleaner Version with Helper Variables

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroupLen = 0;
        int currGroupLen = 1;
        int result = 0;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                currGroupLen++;
            } else {
                result += min(prevGroupLen, currGroupLen);
                prevGroupLen = currGroupLen;
                currGroupLen = 1;
            }
        }
        
        // Don't forget the last group pair
        result += min(prevGroupLen, currGroupLen);
        return result;
    }
};
```

### Solution 4: Using Index Tracking

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int result = 0;
        int i = 0;
        
        while(i < n) {
            char current = s[i];
            int count1 = 0;
            
            // Count current group
            while(i < n && s[i] == current) {
                count1++;
                i++;
            }
            
            // Count next group
            int count2 = 0;
            while(i < n && s[i] != current) {
                count2++;
                i++;
            }
            
            // Add min of two groups
            result += min(count1, count2);
            
            // Move back to start of second group for next iteration
            i -= count2;
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- **Group consecutive characters**: The problem reduces to counting groups of consecutive same characters
- **Adjacent groups form substrings**: Each pair of adjacent groups can form `min(length1, length2)` valid substrings
- **Why minimum?**: If we have 3 zeros followed by 2 ones, we can only form 2 substrings (`"01"` and `"0011"`), limited by the smaller group
- **One-pass solution**: We only need to track the previous and current group lengths, not all groups
- **Edge case**: Don't forget to add the result for the last pair after the loop ends
- **Two pointers concept**: Though not explicitly using two pointers, we're tracking two adjacent groups
- **Pattern recognition**: Similar to problems that involve grouping consecutive elements
- **Space optimization**: By only keeping prev and curr group lengths instead of storing all groups, we achieve O(1) space
- **String traversal**: Single pass through string with state tracking is a common pattern
- **Mathematical insight**: The number of valid substrings between two groups equals the minimum of their lengths

