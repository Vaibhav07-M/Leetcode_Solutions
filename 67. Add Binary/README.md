# 67. Add Binary

**Difficulty:** `Easy`  
**Tags:** `Math`, `String`, `Bit Manipulation`, `Simulation`

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

[LeetCode — 67. Add Binary](https://leetcode.com/problems/add-binary/)

---

## Problem Summary

Given two binary strings `a` and `b`, return their sum as a binary string.

---

## Examples

### Example 1
**Input:** `a = "11", b = "1"`  
**Output:** `"100"`  
**Explanation:**  
Binary 11 (3 in decimal) + Binary 1 (1 in decimal) = Binary 100 (4 in decimal)

### Example 2
**Input:** `a = "1010", b = "1011"`  
**Output:** `"10101"`  
**Explanation:**  
Binary 1010 (10 in decimal) + Binary 1011 (11 in decimal) = Binary 10101 (21 in decimal)

---

## Intuition

The problem is similar to adding two numbers digit by digit, starting from the rightmost (least significant) bit.  
We need to handle:
- Different lengths of input strings
- Carrying over when the sum of two bits (plus previous carry) exceeds 1
- Building the result from right to left

Just like decimal addition, binary addition follows these rules:
- `0 + 0 = 0` (carry 0)
- `0 + 1 = 1` (carry 0)
- `1 + 1 = 10` (result 0, carry 1)
- `1 + 1 + 1 (carry) = 11` (result 1, carry 1)

---

## Approach

### Solution 1: Two Pointers with Carry (Optimal)

1. **Initialize pointers** at the end of both strings (`i` for `a`, `j` for `b`)
2. **Initialize carry** to `0` and result string as empty
3. **Loop while** either pointer is valid or carry exists:
   - Add the bit from string `a` (if `i >= 0`)
   - Add the bit from string `b` (if `j >= 0`)
   - Add the current carry
   - Append `sum % 2` to result (the bit value)
   - Update carry to `sum / 2`
   - Move both pointers left
4. **Reverse the result** string (since we built it backwards)
5. Return the result

This approach processes each bit once while properly handling different string lengths and carry propagation.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(max(n, m))` — where `n` and `m` are lengths of `a` and `b` |
| **Space** | `O(max(n, m))` — for the result string |

---

## Code (C++)

### Solution 1: Two Pointers with Carry

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            res.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
```

### Solution 2: String Building from Left

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        
        return result;
    }
};
```

### Solution 3: Using Bit Manipulation Concept

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        
        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) carry += a[i--] - '0';
            if(j >= 0) carry += b[j--] - '0';
            
            ans = to_string(carry % 2) + ans;
            carry /= 2;
        }
        
        return ans;
    }
};
```

### Solution 4: Cleaner Version

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;
            int sum = bitA + bitB + carry;
            
            result = char('0' + sum % 2) + result;
            carry = sum / 2;
        }
        
        return result;
    }
};
```

---

## Key Takeaways

- Binary addition follows the same principle as decimal addition with carries
- Process from right to left (least significant to most significant bit)
- Handle different string lengths by checking pointer bounds
- Don't forget to process remaining carry after both strings are exhausted
- Converting character to integer: `c - '0'`
- Converting integer to character: `'0' + n` or `char(n + '0')`
- The modulo operation `sum % 2` gives the current bit, `sum / 2` gives the carry
- Building string from right requires reversing at the end, or prepending during construction

