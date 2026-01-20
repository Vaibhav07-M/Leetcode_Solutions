# 3314. Construct the Minimum Bitwise Array I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Bit Manipulation`

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

[LeetCode — 3314. Construct the Minimum Bitwise Array I](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/)

---

## Problem Summary

You are given an array `nums` consisting of `n` prime integers.

Construct an array `ans` of length `n` such that for each index `i`:
- `ans[i] OR (ans[i] + 1) == nums[i]`
- `ans[i]` is minimized

If no such value exists for `ans[i]`, set `ans[i] = -1`.

---

## Examples

### Example 1
**Input:** `nums = [2,3,5,7]`  
**Output:** `[-1,1,4,3]`  
**Explanation:**
- i=0: No value satisfies `ans[0] OR (ans[0] + 1) = 2`, so `ans[0] = -1`
- i=1: `1 OR 2 = 3` ✓
- i=2: `4 OR 5 = 5` ✓
- i=3: `3 OR 4 = 7` ✓

### Example 2
**Input:** `nums = [11,13,31]`  
**Output:** `[9,12,15]`  
**Explanation:**
- i=0: `9 OR 10 = 11` ✓
- i=1: `12 OR 13 = 13` ✓
- i=2: `15 OR 16 = 31` ✓

---

## Intuition

The key insight is understanding when `x OR (x+1)` produces a specific value.

When we increment a number `x` to `x+1`, the rightmost sequence of consecutive `1` bits becomes `0`, and the bit to the left becomes `1`.

For example:
- `x = 5 (101)` → `x+1 = 6 (110)` → `x OR (x+1) = 7 (111)`
- `x = 3 (011)` → `x+1 = 4 (100)` → `x OR (x+1) = 7 (111)`

The OR operation will produce a result where all bits that are set in either `x` or `x+1` are set.

**Key observation:** If `nums[i]` is even (LSB = 0), then it's impossible because `x OR (x+1)` always has LSB = 1.

For odd numbers, we need to find the rightmost `1` bit and turn it to `0` to get the minimum `ans[i]`.

---

## Approach

1. **Check if nums[i] is even:**
   - If even, return `-1` (impossible case)
   - Reason: `x` is either even or odd. If even, `x+1` is odd (LSB=1). If odd, `x` has LSB=1. So `x OR (x+1)` always has LSB=1.

2. **For odd numbers, find the rightmost consecutive 1s:**
   - Starting from the LSB, find the first `0` bit after consecutive `1`s
   - Turn off the rightmost `1` bit before that position
   
3. **Formula approach:**
   - Find the position of the rightmost `0` bit in `nums[i]`
   - Remove the `1` bit just before it
   - This gives the minimum value

4. **Alternative simple approach:**
   - For odd `nums[i]`, we can use: `ans[i] = nums[i] - ((nums[i] + 1) & -(nums[i] + 1)) / 2`
   - Or simply iterate and find the rightmost bit to flip

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * log(max(nums)))` — for each number, we check bits |
| **Space** | `O(1)` extra space (excluding output array) |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            // If num is even, impossible
            if (num % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            
            // For odd numbers, find the minimum ans[i]
            // We need to find rightmost position where flipping a 1 to 0 works
            int result = -1;
            
            // Try flipping each bit position from right to left
            for (int bit = 0; bit < 31; bit++) {
                if ((num >> bit) & 1) {  // If bit is set in num
                    int candidate = num ^ (1 << bit);  // Flip this bit
                    
                    // Check if candidate OR (candidate + 1) == num
                    if ((candidate | (candidate + 1)) == num) {
                        result = candidate;
                        break;
                    }
                }
            }
            
            ans.push_back(result);
        }
        
        return ans;
    }
};
```

### Alternative Optimized Solution:

```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }
            
            // For num > 2, find the first 0 bit after consecutive 1s from LSB
            int temp = num;
            int pos = 0;
            
            // Find rightmost 0 after consecutive 1s
            while ((temp & 1) == 1) {
                temp >>= 1;
                pos++;
            }
            
            // Turn off the bit at position (pos-1)
            int result = num ^ (1 << (pos - 1));
            ans.push_back(result);
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

1. **Even numbers are impossible** — `x OR (x+1)` always produces odd result
2. **Bit manipulation insight** — Adding 1 flips rightmost consecutive 1s to 0s and next 0 to 1
3. **OR operation preserves all set bits** from both operands
4. **Finding minimum** requires flipping the rightmost appropriate bit
5. **Prime constraint** is mostly informational — solution works for all odd numbers
6. **Edge case:** `num = 2` is the only even prime and returns `-1`
7. **Pattern recognition:** For numbers like `111...111` (all 1s), answer is `011...111` (turn off leftmost 1)

---
