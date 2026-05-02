# 788. Rotated Digits

**Difficulty:** `Medium`  
**Tags:** `Math`, `Dynamic Programming`

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

[LeetCode — 788. Rotated Digits](https://leetcode.com/problems/rotated-digits/)

---

## Problem Summary

An integer is considered **good** if after rotating each digit individually by 180 degrees, we get a valid number that is **different** from the original.

**Rotation rules:**
- `0, 1, 8` rotate to themselves
- `2 ↔ 5` (rotate to each other)
- `6 ↔ 9` (rotate to each other)
- `3, 4, 7` are invalid (cannot be rotated to valid digits)

Given an integer `n`, return the **count of good integers** in the range `[1, n]`.

---

## Examples

### Example 1
**Input:** `n = 10`  
**Output:** `4`  
**Explanation:** The good numbers in [1, 10] are: 2, 5, 6, 9. Numbers 1 and 10 remain unchanged after rotation, so they don't count.

### Example 2
**Input:** `n = 1`  
**Output:** `0`

### Example 3
**Input:** `n = 2`  
**Output:** `1`  
**Explanation:** Only 2 is a good number (it rotates to 5, which is different).

---

## Intuition

A number is "good" if:
1. All its digits are valid (not 3, 4, 7)
2. At least one digit changes after rotation (at least one digit is 2, 5, 6, or 9)

We can iterate through each number from 1 to n and check if it satisfies both conditions.

---

## Approach

1. Create a helper function `isGood(num)` that:
   - Iterates through each digit of the number
   - Returns `false` if any invalid digit (3, 4, 7) is found
   - Tracks if at least one digit changes (2, 5, 6, or 9)
   - Returns `true` only if all digits are valid AND at least one changed
2. Iterate from 1 to n and count how many numbers pass the `isGood()` check
3. Return the count

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n · log n)` — for each of n numbers, we check ~log10(n) digits |
| **Space** | `O(1)` — only using a few variables |

---

## Code (C++)

```cpp
class Solution {
public:
    
    bool isGood(int num) {
        bool changed = false;
        
        while(num > 0) {
            int d = num % 10;
            
            // invalid digit
            if(d == 3 || d == 4 || d == 7) return false;
            
            // causes change
            if(d == 2 || d == 5 || d == 6 || d == 9) {
                changed = true;
            }
            
            num /= 10;
        }
        
        return changed;
    }
    
    int rotatedDigits(int n) {
        int count = 0;
        
        for(int i = 1; i <= n; i++) {
            if(isGood(i)) count++;
        }
        
        return count;
    }
};
```

---

## Key Takeaways

- Breaking down conditions into helper functions improves code readability.
- Digit validation problems often require iterating through individual digits.
- Even simple brute-force solutions can be correct within problem constraints (n ≤ 10^4).
- Tracking state (like "changed") while validating ensures all conditions are met.
