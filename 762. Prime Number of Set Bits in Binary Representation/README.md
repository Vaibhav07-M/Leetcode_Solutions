# 762. Prime Number of Set Bits in Binary Representation

**Difficulty:** `Easy`  
**Tags:** `Math`, `Bit Manipulation`

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

[LeetCode — 762. Prime Number of Set Bits in Binary Representation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)

---

## Problem Summary

Given two integers `left` and `right`, return the **count** of numbers in the inclusive range `[left, right]` having a **prime number of set bits** in their binary representation.

Recall that the **number of set bits** an integer has is the number of `1`'s present when written in binary.

---

## Examples

### Example 1
**Input:** `left = 6, right = 10`  
**Output:** `4`  
**Explanation:**
```
6  -> 110  (2 set bits, 2 is prime)
7  -> 111  (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
```
4 numbers have a prime number of set bits.

### Example 2
**Input:** `left = 10, right = 15`  
**Output:** `5`  
**Explanation:**
```
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
```
5 numbers have a prime number of set bits.

---

## Intuition

The problem has two parts:
1. **Count set bits** in a number's binary representation
2. **Check if the count is prime**

**Key observations:**
- The constraint `right <= 10^6` means the maximum number is around 1,000,000
- Binary representation of 10^6 is approximately 20 bits (2^20 = 1,048,576)
- So the maximum number of set bits is at most 20
- We only need to check if numbers from 1 to 20 are prime

**Prime numbers from 1 to 20:** 2, 3, 5, 7, 11, 13, 17, 19

**Optimization:** Instead of checking primality every time, we can:
- Use `__builtin_popcount()` to count set bits efficiently
- Either check primality with a simple function or use a precomputed set of primes

---

## Approach

### Solution 1: With Prime Check Function

1. **Create a helper function** `isPrime(n)` to check if a number is prime
2. **Iterate** through all numbers from `left` to `right`
3. **For each number**:
   - Count set bits using `__builtin_popcount()`
   - Check if the count is prime
   - Increment counter if true
4. **Return** the count

### Solution 2: With Precomputed Prime Set

Since we know the maximum set bits is around 20, we can:
1. **Precompute** all primes up to 20 in a set or use bit masking
2. **For each number** in the range:
   - Count set bits
   - Check if count is in the prime set
   - Increment counter if true

### Solution 3: Using Bitmask for Primes

Primes up to 20: {2, 3, 5, 7, 11, 13, 17, 19}
We can represent this as a bitmask where bit `i` is set if `i` is prime.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((right - left) × log(right))` — iterate through range, count bits in O(log n), check primality in O(√20) = O(1) |
| **Space** | `O(1)` — only use a few variables |

---

## Code (C++)

### Solution 1: With Prime Check Function

```cpp
class Solution {
public:
    bool isPrime(int n) {
        if(n == 1) {
            return false;
        }
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            if(isPrime(__builtin_popcount(i))) {
                ans++;
            }
        }
        return ans;
    }
};
```

### Solution 2: With Precomputed Prime Set

```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Primes up to 20 (max possible set bits for 10^6)
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;
        for(int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if(primes.count(setBits)) {
                count++;
            }
        }
        
        return count;
    }
};
```

### Solution 3: Using Bitmask for Primes

```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Bitmask for primes: 2, 3, 5, 7, 11, 13, 17, 19
        // Binary: 10100010100010101100 (bits 2,3,5,7,11,13,17,19 are set)
        int primeMask = 0b10100010100010101100;
        
        int count = 0;
        for(int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            // Check if bit at position setBits is set in primeMask
            if(primeMask & (1 << setBits)) {
                count++;
            }
        }
        
        return count;
    }
};
```

### Solution 4: Manual Bit Counting

```cpp
class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i = 3; i * i <= n; i += 2) {
            if(n % i == 0) return false;
        }
        return true;
    }
    
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for(int num = left; num <= right; num++) {
            int bits = countSetBits(num);
            if(isPrime(bits)) {
                result++;
            }
        }
        return result;
    }
};
```

### Solution 5: Most Optimized with Inline Check

```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        // Prime bitmask for numbers up to 20
        int primes = 0b10100010100010101100; // positions 2,3,5,7,11,13,17,19
        
        for(int i = left; i <= right; i++) {
            if(primes & (1 << __builtin_popcount(i))) {
                count++;
            }
        }
        
        return count;
    }
};
```

---

## Key Takeaways

- **Set bit counting**: `__builtin_popcount(n)` efficiently counts the number of 1s in binary representation
- **Manual bit counting**: Use `n & 1` to check if LSB is 1, then right shift `n >>= 1`
- **Constraint analysis**: Understanding that `right <= 10^6` means at most ~20 bits is crucial for optimization
- **Prime checking optimization**: 
  - For small ranges, precomputing primes is more efficient than checking each time
  - Primes up to 20: {2, 3, 5, 7, 11, 13, 17, 19}
- **Bitmask technique**: Can represent a set of small integers as bits in a single integer
  - Check membership: `mask & (1 << n)`
  - Binary literal: `0b...` notation in C++14 and later
- **Prime checking basics**:
  - 1 is not prime
  - 2 is the only even prime
  - Check divisibility up to √n
- **Space-time tradeoff**: Using precomputed values trades space for speed
- **Optimization levels**:
  1. Basic: Check primality each time
  2. Better: Use precomputed set
  3. Best: Use bitmask for O(1) lookup
- **Binary representation insights**:
  - Number of bits in n: ⌊log₂(n)⌋ + 1
  - Maximum set bits: same as number of bits
  - For 10^6: approximately 20 bits

