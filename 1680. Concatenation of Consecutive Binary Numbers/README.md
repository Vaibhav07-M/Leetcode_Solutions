# 1680. Concatenation of Consecutive Binary Numbers

**Difficulty:** `Medium`  
**Tags:** `Math, Bit Manipulation, Simulation`

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

[LeetCode — 1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)

---

## Problem Summary

Given an integer `n`, return the **decimal value** of the binary string formed by concatenating the binary representations of `1` to `n` in order, **modulo 10^9 + 7**.

---

## Examples

### Example 1
**Input:** `n = 1`  
**Output:** `1`  
**Explanation:**  
`"1"` in binary corresponds to the decimal value 1.

### Example 2
**Input:** `n = 3`  
**Output:** `27`  
**Explanation:**  
In binary, 1, 2, and 3 corresponds to `"1"`, `"10"`, and `"11"`.  
After concatenating them, we have `"11011"`, which corresponds to the decimal value 27.

### Example 3
**Input:** `n = 12`  
**Output:** `505379714`  
**Explanation:**  
The concatenation results in `"1101110010111011110001001101010111100"`.  
The decimal value of that is 118505380540.  
After modulo 10^9 + 7, the result is 505379714.

---

## Intuition

We need to build a result by concatenating binary representations of numbers from 1 to n, then return it modulo 10^9 + 7.

**Key observations:**
- Concatenating in binary = shifting left and adding
- If result is `R` and we want to append number `i` with `b` bits, new result = `R << b | i` or `R * 2^b + i`
- We need to track how many bits each number has
- Powers of 2 increase the bit count (1→1 bit, 2→2 bits, 4→3 bits, 8→4 bits, etc.)

**Example walkthrough** (n=3):
- Start: result = 0
- i=1 (binary: `"1"`, 1 bit): result = (0 << 1) + 1 = 1
- i=2 (binary: `"10"`, 2 bits): result = (1 << 2) + 2 = 4 + 2 = 6 (binary: `"110"`)
- i=3 (binary: `"11"`, 2 bits): result = (6 << 2) + 3 = 24 + 3 = 27 (binary: `"11011"`)

**Pattern recognition:**
- Number of bits for number `i` = ⌊log₂(i)⌋ + 1
- Power of 2 check: `(i & (i-1)) == 0` means i is power of 2
- When we hit a power of 2, bit length increases

**Approach:**
1. Track current bit length
2. For each number 1 to n:
   - Check if it's a power of 2 (increase bit count)
   - Shift result left by bit count
   - Add current number
   - Apply modulo

---

## Approach

### Solution 1: Bit Manipulation with Power of 2 Detection

1. **Initialize**: `result = 0`, `bits = 0`, `MOD = 10^9 + 7`
2. **For each i from 1 to n**:
   - If `i` is a power of 2 (check: `(i & (i-1)) == 0`), increment `bits`
   - Update result: `result = ((result << bits) % MOD + i) % MOD`
3. **Return** result

**Why this works:**
- Left shift by `bits` positions makes room for the new number
- Adding `i` appends it to the binary representation
- Modulo at each step prevents overflow

### Solution 2: Calculate Bit Length Each Time

Instead of tracking bit changes, calculate bit length for each number.

### Solution 3: String Concatenation (Inefficient)

Actually build the binary string and convert to decimal (too slow for large n).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — iterate through numbers 1 to n once |
| **Space** | `O(1)` — only use a few variables |

---

## Code (C++)

### Solution 1: Optimal with Power of 2 Detection

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0;
        
        for(int i = 1; i <= n; i++) {
            // If i is power of 2, increase bit length
            if((i & (i - 1)) == 0) {
                bits++;
            }
            
            ans = ((ans << bits) % MOD + i) % MOD;
        }
        
        return ans;
    }
};
```

### Solution 2: Calculate Bit Length Each Time

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        
        for(int i = 1; i <= n; i++) {
            int bits = 0;
            int temp = i;
            while(temp > 0) {
                bits++;
                temp >>= 1;
            }
            
            result = ((result << bits) + i) % MOD;
        }
        
        return result;
    }
};
```

### Solution 3: Using __builtin_clz for Bit Count

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        
        for(int i = 1; i <= n; i++) {
            // Number of bits = 32 - leading zeros
            int bits = 32 - __builtin_clz(i);
            
            result = ((result << bits) + i) % MOD;
        }
        
        return result;
    }
};
```

### Solution 4: Log-based Bit Calculation

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        
        for(int i = 1; i <= n; i++) {
            int bits = (int)log2(i) + 1;
            
            result = ((result << bits) % MOD + i) % MOD;
        }
        
        return result;
    }
};
```

### Solution 5: Cleaner Power of 2 Version

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int len = 0;
        
        for(int i = 1; i <= n; i++) {
            // Check if power of 2
            if(!(i & (i - 1))) {
                len++;
            }
            
            // Append i to ans
            ans = (ans << len | i) % MOD;
        }
        
        return ans;
    }
};
```

### Solution 6: With Explicit Modulo Handling

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bitLength = 0;
        
        for(int i = 1; i <= n; i++) {
            // Update bit length when we reach power of 2
            if((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            // Shift and add with modulo
            result = ((result << bitLength) % MOD + i % MOD) % MOD;
        }
        
        return (int)result;
    }
};
```

---

## Key Takeaways

- **Binary concatenation**: Achieved by left shifting and adding
- **Bit shifting formula**: To append `b`-bit number `x` to result `R`: `R = (R << b) + x`
- **Power of 2 detection**: `(n & (n-1)) == 0` returns true only for powers of 2
  - Works because powers of 2 have only one bit set
  - Subtracting 1 flips all bits after that single bit
  - AND operation yields 0
- **Bit length calculation**:
  - Method 1: Track when we hit powers of 2
  - Method 2: Use `log2(n) + 1`
  - Method 3: Count bits manually
  - Method 4: Use `32 - __builtin_clz(n)` (count leading zeros)
- **Modulo arithmetic**:
  - Apply modulo at each step to prevent overflow
  - `(a << b) % MOD` can be computed as `((a % MOD) << b) % MOD`
  - Addition: `(a + b) % MOD`
- **Optimization insight**: Pre-detecting power of 2 is O(1) vs calculating bit length O(log n)
- **Why use long long**: Intermediate calculations can overflow int even with modulo
- **Bit count pattern**:
  - 1: 1 bit
  - 2-3: 2 bits
  - 4-7: 3 bits
  - 8-15: 4 bits
  - Pattern: [2^(k-1), 2^k - 1] has k bits
- **Concatenation in binary**:
  - "101" + "11" = "10111"
  - Decimal: 5 * 4 + 3 = 23 (shift left by 2, add 3)
- **Edge cases**:
  - n = 1: Just "1" → 1
  - n = 2: "1" + "10" = "110" → 6
  - Large n: Use modulo to keep result manageable
- **Alternative approaches**:
  - String manipulation: Build actual binary string (inefficient)
  - Digit DP: Overly complex for this problem
  - Mathematical formula: Pre-calculate bit ranges
- **Performance comparison**:
  - Power of 2 detection: O(1) per iteration
  - Log calculation: O(1) but slower constant factor
  - Manual bit counting: O(log i) per iteration
- **Modulo properties**:
  - `(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD`
  - Shifting is multiplication by power of 2
  - `(a << k) % MOD = (a * 2^k) % MOD`
- **Bit manipulation tricks**:
  - `x & (x-1)`: Clears rightmost set bit
  - `x & -x`: Isolates rightmost set bit
  - `x | (x-1)`: Sets all bits to right of rightmost set bit
- **Why track bit length separately**: More efficient than recalculating each time
- **Integer overflow prevention**: Use `long long` for intermediate results
- **Built-in functions**:
  - `__builtin_clz(n)`: Count leading zeros (GNU/Clang)
  - `__builtin_ctz(n)`: Count trailing zeros
  - `__builtin_popcount(n)`: Count set bits
- **Mathematical insight**: Number `i` has ⌊log₂(i)⌋ + 1 bits
- **When to increment bit count**: At 1, 2, 4, 8, 16, 32, 64, 128, ... (powers of 2)
- **Concatenation example breakdown** (n=4):
  - 1: "1" → 1
  - 2: "110" → 6
  - 3: "11011" → 27
  - 4: "11011100" → 220
- **Common mistakes**:
  - Forgetting modulo during shift operation
  - Using int instead of long long
  - Not handling power of 2 bit length increase
- **Real-world applications**:
  - Data compression
  - Binary protocol design
  - Hashing algorithms
  - Cryptography

