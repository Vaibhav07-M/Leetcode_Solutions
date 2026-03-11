# 1009. Complement of Base 10 Integer

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

[LeetCode — 1009. Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer/)

---

## Problem Summary

The complement of an integer is the integer you get when you flip all the `0`'s to `1`'s and all the `1`'s to `0`'s in its binary representation.

Given an integer `n`, return its complement.

---

## Examples

### Example 1
**Input:** `n = 5`  
**Output:** `2`  
**Explanation:**  
- 5 is "101" in binary.
- Its complement is "010" in binary.
- "010" is 2 in base-10.

### Example 2
**Input:** `n = 7`  
**Output:** `0`  
**Explanation:**  
- 7 is "111" in binary.
- Its complement is "000" in binary.
- "000" is 0 in base-10.

### Example 3
**Input:** `n = 10`  
**Output:** `5`  
**Explanation:**  
- 10 is "1010" in binary.
- Its complement is "0101" in binary.
- "0101" is 5 in base-10.

---

## Intuition

To flip bits computationally, we can use the XOR operator (`^`). XORing any bit with `1` will flip it. 
We need to isolate only the significant bits of `n`. We can do this by constructing a mask formed entirely of `1`s that matches the exact bit-length of `n`. Once constructed, `n ^ mask` yields the true complement.

---

## Approach

1. **Edge Case:** If `n == 0`, its complement is `1`. Handle this immediately.
2. Initialize `mask = 0` and copy `temp = n`.
3. Loop while `temp > 0`:
   - Shift the mask left by `1` and add `1` using bitwise OR (`mask = (mask << 1) | 1`).
   - Shift `temp` right by `1` (`temp >>= 1`) to countdown the length of the number.
4. Finally, XOR `n` with the constructed mask and return the result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(log n)` — representing the length of bits being iterated over (max 32 ops) |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int mask = 0;
        int temp = n;

        while(temp > 0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return n ^ mask;
    }
};
```

---

## Key Takeaways

- Using bitwise XOR (`^`) against a mask of `1`s is the standard way to flip bits.
- Building the mask dynamically prevents flipping leading inactive zeros.
- Don't forget the `0` edge case when dealing with loop conditions like `> 0`.
