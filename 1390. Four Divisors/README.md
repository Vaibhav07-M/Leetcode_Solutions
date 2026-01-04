# 1390. Four Divisors

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`

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

[LeetCode — 1390. Four Divisors](https://leetcode.com/problems/four-divisors/)

---

## Problem Summary

Given an integer array `nums`, return the sum of divisors of the integers in that array that have **exactly four divisors**.

If there is no such integer in the array, return `0`.

---

## Examples

### Example 1
**Input:** `nums = [21,4,7]`  
**Output:** `32`  
**Explanation:**
- 21 has 4 divisors: 1, 3, 7, 21
- 4 has 3 divisors: 1, 2, 4
- 7 has 2 divisors: 1, 7
- The answer is the sum of divisors of 21 only: 1 + 3 + 7 + 21 = 32

### Example 2
**Input:** `nums = [21,21]`  
**Output:** `64`  
**Explanation:**
- Both occurrences of 21 have exactly 4 divisors
- Sum = (1 + 3 + 7 + 21) + (1 + 3 + 7 + 21) = 64

### Example 3
**Input:** `nums = [1,2,3,4,5]`  
**Output:** `0`  
**Explanation:**
- 1 has 1 divisor: 1
- 2 has 2 divisors: 1, 2
- 3 has 2 divisors: 1, 3
- 4 has 3 divisors: 1, 2, 4
- 5 has 2 divisors: 1, 5
- None have exactly 4 divisors, so return 0

---

## Intuition

The key insight is to efficiently find all divisors of a number and check if the count is exactly 4. 

For any number `n`, we can find divisors by iterating only up to `√n`. For each divisor `d` found:
- If `d * d == n`, we have a perfect square (only count `d` once)
- Otherwise, we found a pair: `d` and `n/d`

A number has exactly 4 divisors when:
- It's the product of two distinct primes: `p × q` (divisors: 1, p, q, p×q)
- It's the cube of a prime: `p³` (divisors: 1, p, p², p³)

We don't need to identify these patterns explicitly; we can just count divisors efficiently.

---

## Approach

1. **Initialize Result**: Create a variable `finalSum = 0` to store the total sum.

2. **Process Each Number**: For each number in the array:
   - Initialize `divisorCount = 0` and `divisorSum = 0`
   - Iterate from `candidate = 1` to `√number`:
     - If `candidate` divides the number:
       - If `candidate * candidate == number`: 
         - Count it once: `divisorCount++` and `divisorSum += candidate`
       - Otherwise (found a pair):
         - Count both divisors: `divisorCount += 2`
         - Add both to sum: `divisorSum += candidate + (number / candidate)`
     - If `divisorCount > 4`, break early (optimization)
   
3. **Check Condition**: If `divisorCount == 4`:
   - Add `divisorSum` to `finalSum`

4. **Return Result**: Return `finalSum`

**Optimization**: Break early if we find more than 4 divisors to avoid unnecessary computation.

---

## Complexity

- **Time Complexity**: `O(n × √m)` where n is the length of the array and m is the maximum value in the array.  
  For each number, we iterate up to its square root to find divisors.

- **Space Complexity**: `O(1)` - constant space.  
  We only use a few variables regardless of input size.

---

## Code (C++)

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int finalSum = 0;

        for(int number : nums) {
            int divisorCount = 0;
            int divisorSum = 0;

            for(int candidate = 1; candidate * candidate <= number; candidate++) {
                if(number % candidate == 0) {
                    if(candidate * candidate == number) {
                        // Perfect square: count the divisor once
                        divisorCount++;
                        divisorSum += candidate;
                    } else {
                        // Found a pair of divisors
                        divisorCount += 2;
                        divisorSum += candidate + (number / candidate);
                    }
                }
                
                // Early exit if more than 4 divisors
                if(divisorCount > 4) {
                    break;
                }
            }

            if(divisorCount == 4) {
                finalSum += divisorSum;
            }
        }

        return finalSum;
    }
};
```

---

## Key Takeaways

- **Square Root Optimization**: Finding divisors only up to √n reduces time complexity from O(n) to O(√n).
- **Divisor Pairing**: When we find a divisor `d`, we also find `n/d` (except for perfect squares).
- **Early Exit**: Breaking when divisor count exceeds 4 prevents unnecessary computation.
- **Mathematical Properties**: Numbers with exactly 4 divisors are either products of two distinct primes (p×q) or cubes of primes (p³).
- **Sum Accumulation**: We accumulate divisor sums only for numbers meeting the exact criteria, demonstrating conditional aggregation.
- **Efficiency Matters**: For arrays with large numbers, the √n optimization is crucial for acceptable performance.
