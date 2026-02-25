# 1356. Sort Integers by The Number of 1 Bits

**Difficulty:** `Easy`  
**Tags:** `Array, Bit Manipulation, Sorting, Counting`

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

[LeetCode — 1356. Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)

---

## Problem Summary

You are given an integer array `arr`. Sort the integers in the array in **ascending order** by the number of `1`'s in their binary representation and in case of two or more integers have the same number of `1`'s you have to sort them in **ascending order**.

Return the array after sorting it.

---

## Examples

### Example 1
**Input:** `arr = [0,1,2,3,4,5,6,7,8]`  
**Output:** `[0,1,2,4,8,3,5,6,7]`  
**Explanation:**
- `[0]` is the only integer with 0 bits.
- `[1,2,4,8]` all have 1 bit.
- `[3,5,6]` have 2 bits.
- `[7]` has 3 bits.
- The sorted array by bits is `[0,1,2,4,8,3,5,6,7]`

### Example 2
**Input:** `arr = [1024,512,256,128,64,32,16,8,4,2,1]`  
**Output:** `[1,2,4,8,16,32,64,128,256,512,1024]`  
**Explanation:**  
All integers have 1 bit in the binary representation, you should just sort them in ascending order.

---

## Intuition

We need to sort numbers by a custom criterion: first by the count of `1` bits in their binary representation, then by their actual value as a tiebreaker.

**Key observations:**
- Primary sorting key: number of set bits (1 bits) in binary representation
- Secondary sorting key: the actual value (ascending order)
- For counting set bits, we can use `__builtin_popcount()` function
- We need a custom comparator for sorting

**Approach:**
1. Use the built-in `sort()` function with a custom comparator
2. The comparator should:
   - First compare by count of set bits
   - If equal, compare by actual value
3. Use `__builtin_popcount()` to efficiently count set bits

---

## Approach

### Solution 1: Custom Comparator with Lambda

1. **Define comparator**:
   - Calculate set bits for both numbers
   - If counts differ, sort by count (ascending)
   - If counts same, sort by value (ascending)
2. **Use std::sort** with the custom comparator
3. **Return** the sorted array

### Solution 2: Pair-based Approach

1. **Create pairs**: `(bit_count, value)` for each number
2. **Sort pairs**: Natural sorting will work (sorts by first element, then second)
3. **Extract values**: Build result array from sorted pairs

### Solution 3: Manual Bit Counting

Instead of using `__builtin_popcount()`, manually count bits for educational purposes.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting, counting bits is O(log(max_value)) per element |
| **Space** | `O(log n)` or `O(n)` — depending on sort implementation and approach |

**Note:** `__builtin_popcount()` is typically O(1) or O(number of bits) which is constant for 32-bit integers.

---

## Code (C++)

### Solution 1: Custom Comparator with Lambda (Optimal)

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            if(ca == cb) return a < b;   // tie-break by value
            return ca < cb;              // sort by set bits
        });
        return arr;
    }
};
```

### Solution 2: Pair-based Approach

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> temp;
        
        for(int num : arr) {
            temp.push_back({__builtin_popcount(num), num});
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i].second;
        }
        
        return arr;
    }
};
```

### Solution 3: Helper Function for Bit Counting

```cpp
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int ca = countBits(a);
            int cb = countBits(b);
            if(ca == cb) return a < b;
            return ca < cb;
        });
        return arr;
    }
};
```

### Solution 4: Using Stable Sort

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // First sort by value
        sort(arr.begin(), arr.end());
        
        // Then stable sort by bit count
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            return __builtin_popcount(a) < __builtin_popcount(b);
        });
        
        return arr;
    }
};
```

### Solution 5: Brian Kernighan's Algorithm for Bit Counting

```cpp
class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while(n) {
            n &= (n - 1);  // Remove rightmost set bit
            count++;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int ca = countBits(a);
            int cb = countBits(b);
            return ca == cb ? a < b : ca < cb;
        });
        return arr;
    }
};
```

### Solution 6: Compact Ternary Version

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            return ca == cb ? a < b : ca < cb;
        });
        return arr;
    }
};
```

---

## Key Takeaways

- **Custom sorting**: Use custom comparator for multi-criteria sorting
- **Lambda functions**: Modern C++ allows inline lambda comparators
- **__builtin_popcount()**: GCC built-in function to count set bits efficiently
  - Returns number of 1 bits in the binary representation
  - Hardware-optimized on most platforms
  - Alternative: `__builtin_popcountll()` for `long long`
- **Multi-level sorting**:
  - Primary key: bit count
  - Secondary key: actual value
  - Implement as: if primary equal, compare secondary
- **Comparator logic**:
  - Return `true` if first argument should come before second
  - Must implement strict weak ordering
  - `if(ca == cb) return a < b; return ca < cb;`
- **Alternative approaches**:
  - Create pairs and use natural sorting
  - Use stable_sort for secondary key naturally
  - Manual bit counting for educational purposes
- **Bit counting techniques**:
  1. **Simple loop**: Check each bit with `n & 1`, shift right
  2. **Brian Kernighan's**: `n &= (n-1)` removes rightmost set bit, count iterations
  3. **Built-in**: `__builtin_popcount()` is usually fastest
  4. **Lookup table**: Precompute for small ranges
- **Comparison operators**:
  - `<` for ascending order
  - `>` for descending order
  - Can combine multiple conditions
- **Stable sort consideration**: If we first sort by value, then stable_sort by bits, achieves same result
- **Space optimization**: In-place sorting modifies original array
- **Time complexity breakdown**:
  - Sorting: O(n log n)
  - Per comparison: O(1) with built-in popcount
  - Total: O(n log n)
- **Edge cases**:
  - All same bit count: sorts by value only
  - Single element: returns as-is
  - All zeros: already sorted
  - Powers of 2: all have 1 bit, sort by value
- **Practical applications**:
  - Data compression algorithms
  - Hamming distance calculations
  - Error detection/correction codes
  - Network routing algorithms
- **Ternary operator**: Can combine comparisons: `return ca == cb ? a < b : ca < cb;`
- **C++ sort stability**: `std::sort` is not stable, `std::stable_sort` preserves relative order of equal elements
- **Bit manipulation refresher**:
  - `n & 1`: Check if LSB is set
  - `n >> 1`: Shift right (divide by 2)
  - `n & (n-1)`: Clear rightmost set bit
  - `n | (1 << k)`: Set k-th bit
- **Performance notes**:
  - Built-in functions are usually optimized in assembly
  - Modern CPUs have POPCNT instruction
  - Manual counting is educational but slower
- **Constraint awareness**: With values up to 10^4, max 14 bits needed
- **Return value**: Problem says "return the array" but modifying in-place is fine in C++

