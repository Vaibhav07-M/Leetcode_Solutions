# 190. Reverse Bits

**Difficulty:** `Easy`  
**Tags:** `Divide and Conquer`, `Bit Manipulation`

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

[LeetCode — 190. Reverse Bits](https://leetcode.com/problems/reverse-bits/)

---

## Problem Summary

Reverse bits of a given 32-bit unsigned integer.

**Note:** In some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same.

---

## Examples

### Example 1
**Input:** `n = 43261596`  
**Output:** `964176192`  
**Explanation:**  
```
Integer       Binary
43261596      00000010100101000001111010011100
964176192     00111001011110000010100101000000
```

### Example 2
**Input:** `n = 2147483644`  
**Output:** `1073741822`  
**Explanation:**  
```
Integer       Binary
2147483644    01111111111111111111111111111100
1073741822    00111111111111111111111111111110
```

---

## Intuition

To reverse the bits of a 32-bit integer, we need to:
1. Extract each bit from the rightmost position of the input
2. Place it in the leftmost available position of the result
3. Continue this process for all 32 bits

The key insight is that we can build the result bit by bit:
- Shift the result left to make room for the next bit
- Extract the rightmost bit from the input using `& 1`
- Add this bit to the result using `|`
- Shift the input right to process the next bit

This is similar to reversing a string character by character, but we're working with bits.

---

## Approach

### Solution 1: Bit-by-Bit Reversal (Optimal)

1. **Initialize result** to 0
2. **Loop 32 times** (for each bit in a 32-bit integer):
   - Shift result left by 1 to make space for the next bit
   - Extract the least significant bit (LSB) from input using `n & 1`
   - OR the extracted bit with result
   - Shift input right by 1 to process the next bit
3. **Return** the reversed result

The loop processes each bit from right to left in the input and builds the result from left to right.

### Solution 2: Divide and Conquer

We can also reverse bits using a divide-and-conquer approach:
1. Swap adjacent bits
2. Swap adjacent pairs of bits
3. Swap adjacent nibbles (4 bits)
4. Continue swapping until all bits are reversed

This approach uses bit masking and is very efficient.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — always processes exactly 32 bits |
| **Space** | `O(1)` — only uses a few variables |

---

## Code (C++)

### Solution 1: Bit-by-Bit Reversal

```cpp
class Solution {
public:
    int reverseBits(int n) {
        unsigned int x = (unsigned int)n;
        unsigned int ans = 0;

        for(int i = 0; i < 32; i++) {
            ans = (ans << 1) | (x & 1);
            x >>= 1;
        }

        return (int)ans;
    }
};
```

### Solution 2: Alternative Bit-by-Bit

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++) {
            // Extract the i-th bit from the right
            uint32_t bit = (n >> i) & 1;
            // Place it in the (31-i)-th position from the right
            result = result | (bit << (31 - i));
        }
        
        return result;
    }
};
```

### Solution 3: Divide and Conquer (Most Optimized)

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Swap adjacent bits
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        
        // Swap adjacent pairs
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        
        // Swap adjacent nibbles (4 bits)
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        
        // Swap adjacent bytes
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        
        // Swap adjacent 16-bit blocks
        n = (n >> 16) | (n << 16);
        
        return n;
    }
};
```

### Solution 4: With Lookup Table (Follow-up Optimization)

```cpp
class Solution {
private:
    // Cache for 8-bit reversals
    unordered_map<uint8_t, uint8_t> cache;
    
    uint8_t reverseByte(uint8_t byte) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        
        uint8_t result = 0;
        for(int i = 0; i < 8; i++) {
            result = (result << 1) | (byte & 1);
            byte >>= 1;
        }
        
        cache[byte] = result;
        return result;
    }
    
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        // Process byte by byte
        for(int i = 0; i < 4; i++) {
            result = (result << 8) | reverseByte((n >> (i * 8)) & 0xFF);
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- **Bit extraction**: Use `n & 1` to get the least significant bit
- **Bit placement**: Use left shift `<<` to position bits and OR `|` to set them
- **Right shift**: `>>` moves bits right, effectively dividing by powers of 2
- **Left shift**: `<<` moves bits left, effectively multiplying by powers of 2
- **Unsigned integers**: Important to use `unsigned int` or `uint32_t` to avoid sign extension issues
- **Divide and Conquer**: Can significantly optimize bit manipulation problems by working on multiple bits at once
- **Caching**: For repeated calls (follow-up), caching byte-level reversals can improve performance
- **Fixed iterations**: Since we always process 32 bits, the algorithm is O(1) time
- **Bit masks**: Hexadecimal masks like `0xAAAAAAAA` are useful for selecting specific bit patterns
  - `0x55555555` = `01010101...` (odd bits)
  - `0xAAAAAAAA` = `10101010...` (even bits)
  - `0x33333333` = `00110011...` (pairs)
  - `0xCCCCCCCC` = `11001100...` (pairs)

