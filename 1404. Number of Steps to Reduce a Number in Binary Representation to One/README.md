# 1404. Number of Steps to Reduce a Number in Binary Representation to One

**Difficulty:** `Medium`  
**Tags:** `String, Bit Manipulation`

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

[LeetCode — 1404. Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

---

## Problem Summary

Given the binary representation of an integer as a string `s`, return the **number of steps** to reduce it to `1` under the following rules:

- If the current number is **even**, you have to **divide it by 2**.
- If the current number is **odd**, you have to **add 1** to it.

It is guaranteed that you can always reach `1` for all test cases.

---

## Examples

### Example 1
**Input:** `s = "1101"`  
**Output:** `6`  
**Explanation:**  
`"1101"` corresponds to number `13` in decimal representation.
- Step 1) 13 is odd, add 1 and obtain 14.
- Step 2) 14 is even, divide by 2 and obtain 7.
- Step 3) 7 is odd, add 1 and obtain 8.
- Step 4) 8 is even, divide by 2 and obtain 4.
- Step 5) 4 is even, divide by 2 and obtain 2.
- Step 6) 2 is even, divide by 2 and obtain 1.

### Example 2
**Input:** `s = "10"`  
**Output:** `1`  
**Explanation:**  
`"10"` corresponds to number `2` in decimal representation.
- Step 1) 2 is even, divide by 2 and obtain 1.

### Example 3
**Input:** `s = "1"`  
**Output:** `0`  
**Explanation:**  
Already at 1, no steps needed.

---

## Intuition

We need to count steps to reduce a binary number to 1. The naive approach would be to convert to decimal, perform operations, but this fails for large numbers (up to 500 bits).

**Key observations:**
- **Even number** in binary: Last bit is `0` → divide by 2 = right shift (remove last bit)
- **Odd number** in binary: Last bit is `1` → add 1 → may cause carry propagation
- We can simulate operations directly on the binary string
- When we add 1 to an odd number, we get an even number (which we then divide)

**Clever insight:**
- If last bit is `0`: 1 step (divide by 2 = remove bit)
- If last bit is `1`: 2 steps (add 1, then divide = turn bit to 0 with potential carry)
- We can track a carry and process from right to left without actually modifying the string

**Pattern recognition:**
- `...0` → 1 step to remove
- `...1` with no carry → 2 steps (becomes `0`, then remove)
- `...1` with carry → 1 step (carry makes it `10`, which becomes `0` after division)
- `...0` with carry → 1 step (becomes `1`, then next iteration handles it)

---

## Approach

### Solution 1: Carry-based Simulation (Optimal)

1. **Initialize**: `steps = 0`, `carry = 0`
2. **Process from right to left** (LSB to MSB), excluding the first bit:
   - `bit = current_bit + carry`
   - If `bit == 1` (odd):
     - Add 2 steps (add 1, then divide)
     - Set `carry = 1`
   - If `bit == 0` or `bit >= 2` (even):
     - Add 1 step (divide by 2)
     - If `bit >= 2`, keep `carry = 1`
3. **After loop**: If carry remains, add 1 more step
4. **Return** total steps

**Why this works:**
- When bit + carry = 1 (odd): we add 1 (making it even), then divide → 2 steps, carry propagates
- When bit + carry = 0 (even): we just divide → 1 step
- When bit + carry = 2 (from `1 + carry`): it's `10` in binary, divide gives `1` → 1 step, carry continues

### Solution 2: Simulation with String Manipulation

Actually modify the string by removing last character or performing addition.

### Solution 3: Count Trailing Ones

Observe that consecutive trailing 1s cause carry propagation.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the string, where n = length of string |
| **Space** | `O(1)` — only use a few variables |

---

## Code (C++)

### Solution 1: Carry-based Simulation (Optimal)

```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Process from right to left (LSB to MSB), excluding first bit
        for(int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if(bit == 1) {
                // Odd: add 1, then divide = 2 steps
                steps += 2;
                carry = 1;
            } else {
                // Even: just divide = 1 step
                steps += 1;
                // carry remains as is (0 or 1)
            }
        }
        
        // If carry remains at MSB, it adds one more step
        return steps + carry;
    }
};
```

### Solution 2: Cleaner Carry Logic

```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for(int i = s.size() - 1; i > 0; i--) {
            if((s[i] - '0') + carry == 1) {
                carry = 1;
                steps += 2;
            } else {
                steps += 1;
            }
        }
        
        return steps + carry;
    }
};
```

### Solution 3: Detailed Explanation Version

```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Start from the least significant bit (rightmost)
        // Stop before the most significant bit (leftmost)
        for(int i = s.length() - 1; i > 0; i--) {
            int currentBit = s[i] - '0';
            int sum = currentBit + carry;
            
            if(sum % 2 == 1) {
                // Number is odd
                // Add 1: creates carry for next position
                // Then divide by 2: one more step
                steps += 2;
                carry = 1;
            } else {
                // Number is even
                // Just divide by 2
                steps += 1;
                // Carry propagates if sum was 2
                if(sum == 2) carry = 1;
                else carry = 0;
            }
        }
        
        // If there's still a carry after processing all bits
        // The MSB becomes 10..., which needs one more division
        return steps + carry;
    }
};
```

### Solution 4: Simulation with Actual Operations

```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while(s != "1") {
            if(s.back() == '0') {
                // Even: divide by 2 (remove last bit)
                s.pop_back();
            } else {
                // Odd: add 1
                int i = s.length() - 1;
                while(i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if(i < 0) {
                    s = "1" + s;
                } else {
                    s[i] = '1';
                }
            }
            steps++;
        }
        
        return steps;
    }
};
```

### Solution 5: Count Pattern

```cpp
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int steps = 0;
        int carry = 0;
        
        for(int i = n - 1; i >= 1; i--) {
            int digit = (s[i] - '0') + carry;
            
            if(digit == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps++;
            }
        }
        
        return steps + carry;
    }
};
```

---

## Key Takeaways

- **Binary operations on strings**: Can simulate bit operations without converting to integers
- **Large number handling**: String representation allows handling numbers beyond integer limits (500 bits >> 64 bits)
- **Binary number properties**:
  - Even number: last bit is `0`
  - Odd number: last bit is `1`
  - Divide by 2: remove rightmost bit (right shift)
  - Add 1: may cause carry propagation
- **Carry propagation**: When adding 1 to `...1111`, it becomes `...10000`
- **Optimization insight**: Don't need to actually perform operations, just count steps
- **Key pattern recognition**:
  - `0` bit: 1 step (divide)
  - `1` bit without carry: 2 steps (add 1, then divide)
  - `1` bit with carry: 1 step (carry makes it `10`, removing one bit)
- **Why exclude first bit**: We process until we reach the MSB, which is always `1`
- **Carry at end**: If carry persists after processing all bits, we need one more step
- **Simulation vs counting**: 
  - Simulation (modifying string): O(n²) worst case due to carry propagation
  - Counting with carry tracking: O(n) single pass
- **Edge cases**:
  - `"1"`: 0 steps (already at target)
  - `"10"`: 1 step (divide once)
  - `"11"`: 3 steps (add 1 → `100`, divide → `10`, divide → `1`)
  - `"1111"`: Multiple carry propagations
- **Mathematical insight**:
  - Each `0` bit: contributes 1 step
  - Each `1` bit (except leading): contributes 2 steps if it starts a new odd phase
  - Consecutive `1`s: cause carry chain
- **Alternative formulation**:
  - Count zeros: each is 1 step
  - Count transitions to odd: each adds extra step
  - Plus final carry if any
- **Why process backwards**: LSB (rightmost) determines even/odd
- **Invariant**: After each odd→even conversion (add 1), we always divide
- **Carry logic**:
  - `0 + 0 = 0` (even, no carry): 1 step
  - `1 + 0 = 1` (odd, creates carry): 2 steps, carry = 1
  - `0 + 1 = 1` (odd from previous carry): 2 steps, carry = 1
  - `1 + 1 = 2` (even, carry continues): 1 step, carry = 1
- **Space optimization**: No need to modify the string, just track carry
- **Comparison to regular division**: Binary makes it easy to see even/odd and division
- **Real-world application**: Understanding binary arithmetic, bitwise operations
- **String indexing**: `s[i] - '0'` converts char to int
- **Loop boundary**: `i > 0` because we stop at the leading `1`
- **Time complexity note**: Although simulation approach seems O(n²), carry optimization makes it O(n)

