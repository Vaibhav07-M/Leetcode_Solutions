# 693. Binary Number with Alternating Bits

**Difficulty:** `Easy`  
**Tags:** `Bit Manipulation`

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

[LeetCode — 693. Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)

---

## Problem Summary

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

---

## Examples

### Example 1
**Input:** `n = 5`  
**Output:** `true`  
**Explanation:** The binary representation of 5 is: `101`

### Example 2
**Input:** `n = 7`  
**Output:** `false`  
**Explanation:** The binary representation of 7 is: `111`

### Example 3
**Input:** `n = 11`  
**Output:** `false`  
**Explanation:** The binary representation of 11 is: `1011`

---

## Intuition

A number has alternating bits if no two adjacent bits are the same. In other words, the pattern should be like `101010...` or `010101...`.

We need to check each bit against its adjacent bit. If we find any two consecutive bits that are the same, we return `false`. If we process all bits without finding matching adjacent bits, we return `true`.

The key insight is to extract bits one by one (from right to left) and compare each bit with the previous one.

---

## Approach

### Solution 1: Bit-by-Bit Comparison (Iterative)

1. **Initialize** a `prev` variable to `-1` (a value that's neither 0 nor 1)
2. **While** `n > 0`:
   - Extract the least significant bit using `n & 1`
   - Compare with the previous bit
   - If they're the same, return `false`
   - Update `prev` to the current bit
   - Right shift `n` by 1 to process the next bit
3. **Return** `true` if all bits pass the check

### Solution 2: XOR and Shift Trick

An elegant mathematical approach:
- If bits alternate, then `n XOR (n >> 1)` will produce all 1s
- For example: `101 XOR 010 = 111` (all 1s)
- But `111 XOR 011 = 100` (not all 1s)
- A number with all 1s has the property that `num & (num + 1) = 0`

### Solution 3: Compare with Shifted Version

Compare each bit with the next bit directly using bit operations without storing the previous bit.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` — process each bit, and there are log₂(n) bits |
| **Space** | `O(1)` — only use a few variables |

---

## Code (C++)

### Solution 1: Iterative Bit Comparison

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n > 0) {
            int cur = n & 1;
            if (cur == prev) return false;
            prev = cur;
            n >>= 1;
        }
        return true;
    }
};
```

### Solution 2: XOR and Shift Trick

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        // XOR n with n shifted right by 1
        // If alternating, result will be all 1s
        long xor_result = n ^ (n >> 1);
        
        // Check if xor_result is all 1s
        // A number with all 1s: (num & (num + 1)) == 0
        return (xor_result & (xor_result + 1)) == 0;
    }
};
```

### Solution 3: Direct Bit Comparison

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0) {
            // Get last two bits
            int last_two = n & 3; // 3 in binary is 11
            
            // Check if they're the same (00 or 11)
            if(last_two == 0 || last_two == 3) {
                return false;
            }
            
            n >>= 1;
        }
        return true;
    }
};
```

### Solution 4: Comparing Adjacent Bits with Modulo

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last_bit = n % 2;
        n /= 2;
        
        while(n > 0) {
            int current_bit = n % 2;
            if(current_bit == last_bit) {
                return false;
            }
            last_bit = current_bit;
            n /= 2;
        }
        
        return true;
    }
};
```

### Solution 5: One-Liner Using Math Property

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n >> 1) & n + 1);
    }
};
```

---

## Key Takeaways

- **Bit extraction**: Use `n & 1` to get the least significant bit, or `n % 2`
- **Right shift**: `n >>= 1` or `n /= 2` moves to the next bit
- **XOR property**: `n ^ (n >> 1)` produces all 1s if bits alternate
  - Example: `101 ^ 010 = 111` (all 1s)
  - Example: `111 ^ 011 = 100` (not all 1s)
- **All 1s check**: A number with all 1s satisfies `(num & (num + 1)) == 0`
  - Example: `111 & 1000 = 0` ✓
  - Example: `100 & 101 = 100` ✗
- **Last two bits**: `n & 3` gives the last two bits
  - If they're both 0 (`00`) or both 1 (`11`), bits aren't alternating
  - Valid patterns for last two bits: `01` or `10`
- **Edge cases**: Single bit numbers (like 1) are considered alternating
- **Mathematical elegance**: Bit manipulation problems often have clever one-liner solutions using properties of XOR, AND, OR operations
- **Multiple approaches**: Same problem can be solved iteratively or with mathematical tricks
- **Performance**: All solutions are O(log n) but the XOR trick is slightly faster with fewer operations

