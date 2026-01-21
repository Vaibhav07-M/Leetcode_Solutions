# 3315. Construct the Minimum Bitwise Array II

**Difficulty:** `Medium`  
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

[LeetCode — 3315. Construct the Minimum Bitwise Array II](https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/)

---

## Problem Summary

You are given an array `nums` consisting of `n` prime integers.

Construct an array `ans` of length `n` such that for each index `i`:
- `ans[i] OR (ans[i] + 1) == nums[i]`
- `ans[i]` is minimized

If no such value exists for `ans[i]`, set `ans[i] = -1`.

**Note:** This is the medium version with larger constraints (`nums[i]` up to 10⁹).

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

This problem requires understanding the bitwise behavior of `x OR (x+1)`.

When we add 1 to a number `x`:
- The rightmost sequence of consecutive `1` bits becomes `0`
- The bit immediately to the left becomes `1`

For example:
```
x = 9  (1001) → x+1 = 10 (1010) → x OR (x+1) = 11 (1011)
x = 12 (1100) → x+1 = 13 (1101) → x OR (x+1) = 13 (1101)
x = 15 (1111) → x+1 = 16 (10000) → x OR (x+1) = 31 (11111)
```

**Key observations:**
1. If `nums[i]` is even (LSB = 0), it's **impossible** — `x OR (x+1)` always has LSB = 1
2. For odd numbers, we need to find which bit to flip from `1` to `0` to get the minimum value
3. The answer is found by turning off the rightmost `1` bit before the first `0` bit (when scanning from LSB)

---

## Approach

### Strategy:
For each `nums[i]`:

1. **Check if even:**
   - If `nums[i] == 2`, return `-1` (only even prime)
   - All other cases with even numbers are impossible

2. **For odd numbers:**
   - Find the rightmost `0` bit after scanning consecutive `1`s from LSB
   - Turn off the `1` bit just before this `0` bit position
   - This gives the minimum `ans[i]`

### Algorithm:
```
For each num in nums:
    if num == 2:
        ans[i] = -1
    else:
        pos = 0
        temp = num
        // Count consecutive 1s from LSB
        while (temp & 1) == 1:
            temp >>= 1
            pos++
        
        // Turn off bit at position (pos-1)
        result = num XOR (1 << (pos-1))
        ans[i] = result
```

### Why this works:
- Turning off the rightmost appropriate `1` bit ensures that when we OR with `+1`, we get back the original number
- This gives the minimum value because we're flipping the rightmost possible bit

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * log(max(nums)))` — for each number, we check at most log(num) bits |
| **Space** | `O(1)` extra space (excluding output array) |

With `nums[i]` up to 10⁹, we check at most 30 bits per number.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            // Special case: num = 2 (only even prime)
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }
            
            // For odd numbers, find the first 0 bit after consecutive 1s from LSB
            int temp = num;
            int pos = 0;
            
            // Count consecutive 1s from the right
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

### Alternative Implementation (More Explicit):

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
            
            // For odd numbers
            // Find position of first 0 after consecutive 1s from LSB
            int mask = 1;
            int pos = 0;
            
            while ((num & mask) != 0) {
                mask <<= 1;
                pos++;
            }
            
            // Clear the bit at position pos-1
            int result = num & ~(1 << (pos - 1));
            ans.push_back(result);
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

1. **Even numbers are impossible** — `x OR (x+1)` always produces an odd result
2. **Binary addition pattern** — Adding 1 flips consecutive rightmost 1s to 0s and next 0 to 1
3. **XOR for bit flipping** — `num ^ (1 << pos)` flips bit at position `pos`
4. **Bitwise AND for testing** — `(num & 1)` checks if LSB is set
5. **Minimum value optimization** — Flip the rightmost appropriate bit to minimize result
6. **Prime constraint** — While stated, the solution works for all odd integers
7. **Scalability** — With 10⁹ constraint, solution must be O(log n) per element, not O(n)
8. **Edge case:** Only `num = 2` returns `-1` for valid inputs

---
