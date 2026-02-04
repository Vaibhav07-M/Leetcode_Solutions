# 3640. Trionic Array II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`

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

[LeetCode — 3640. Trionic Array II](https://leetcode.com/problems/trionic-array-ii/)

---

## Problem Summary

You are given an integer array `nums` of length `n`.

A **trionic subarray** is a contiguous subarray `nums[l...r]` (with `0 <= l < r < n`) for which there exist indices `l < p < q < r` such that:
- `nums[l...p]` is strictly increasing
- `nums[p...q]` is strictly decreasing
- `nums[q...r]` is strictly increasing

Return the **maximum sum** of any trionic subarray in `nums`.

**Constraints:**
- `4 <= n = nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- It is guaranteed that at least one trionic subarray exists

---

## Examples

### Example 1
**Input:** `nums = [0,-2,-1,-3,0,2,-1]`  
**Output:** `-4`  
**Explanation:**
- Pick `l = 1`, `p = 2`, `q = 3`, `r = 5`:
  - `nums[1...2] = [-2, -1]` is strictly increasing (-2 < -1)
  - `nums[2...3] = [-1, -3]` is strictly decreasing (-1 > -3)
  - `nums[3...5] = [-3, 0, 2]` is strictly increasing (-3 < 0 < 2)
  - Sum = (-2) + (-1) + (-3) + 0 + 2 = -4

### Example 2
**Input:** `nums = [1,4,2,7]`  
**Output:** `14`  
**Explanation:**
- Pick `l = 0`, `p = 1`, `q = 2`, `r = 3`:
  - `nums[0...1] = [1, 4]` is strictly increasing (1 < 4)
  - `nums[1...2] = [4, 2]` is strictly decreasing (4 > 2)
  - `nums[2...3] = [2, 7]` is strictly increasing (2 < 7)
  - Sum = 1 + 4 + 2 + 7 = 14

---

## Intuition

This problem extends the trionic array concept from problem 3637 to finding the maximum sum among all possible trionic subarrays.

Key observations:
1. Unlike problem 3637 where we check if the entire array is trionic, here we need to consider all possible subarrays
2. A trionic subarray requires at least 4 elements (minimum 2 in each increasing segment and 1 transition through the decreasing segment)
3. The segments can overlap at the peak (`p`) and valley (`q`) indices
4. We need to track three phases: increasing → decreasing → increasing

The challenge is efficiently finding all valid trionic subarrays and computing their sums. A naive approach would be O(n³) or worse, but we can optimize using dynamic programming.

---

## Approach

### Method 1: Dynamic Programming with State Tracking (Optimal)

The key insight is to track, for each position, the maximum sum we can achieve ending at that position in each of the three phases:

**Define DP states:**
- `inc1[i]` = maximum sum of strictly increasing subarray ending at `i` (phase 1)
- `dec[i]` = maximum sum of trionic subarray ending at `i` where we're in the decreasing phase (phase 2)
- `inc2[i]` = maximum sum of complete trionic subarray ending at `i` (phase 3)

**Transitions:**
1. **Phase 1 (Strictly Increasing):**
   - If `nums[i] > nums[i-1]`: `inc1[i] = inc1[i-1] + nums[i]`
   - Otherwise: `inc1[i] = nums[i]` (start new sequence)

2. **Phase 2 (Strictly Decreasing from Phase 1):**
   - If `nums[i] < nums[i-1]`: 
     - Start decreasing from previous increasing: `dec[i] = inc1[i-1] + nums[i]`
     - Continue existing decreasing: `dec[i] = max(dec[i], dec[i-1] + nums[i])`

3. **Phase 3 (Strictly Increasing from Phase 2):**
   - If `nums[i] > nums[i-1]`:
     - Start final increasing from previous decreasing: `inc2[i] = dec[i-1] + nums[i]`
     - Continue existing final increasing: `inc2[i] = max(inc2[i], inc2[i-1] + nums[i])`

The answer is the maximum value in `inc2[]`.

**Algorithm:**
1. Initialize arrays to track the three phases
2. For each position, compute all valid transitions
3. Track the maximum value achieved in the final phase (inc2)
4. Return the maximum

### Method 2: Enumerate All Trionic Subarrays (Brute Force)

For each possible starting position `l`:
1. Enumerate all possible peak positions `p` where `nums[l...p]` is strictly increasing
2. For each `p`, enumerate all valley positions `q` where `nums[p...q]` is strictly decreasing
3. For each `q`, enumerate all ending positions `r` where `nums[q...r]` is strictly increasing
4. Calculate sum and track maximum

This approach is straightforward but has O(n⁴) time complexity in the worst case.

---

## Complexity

### Method 1: Dynamic Programming
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass with constant state updates |
| **Space** | `O(n)` — three DP arrays; can be optimized to O(1) with variables |

### Method 2: Brute Force
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n⁴)` — four nested loops in worst case |
| **Space** | `O(1)` — only tracking maximum sum |

---

## Code (C++)

### Solution 1: Dynamic Programming (Optimal)

```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        // DP arrays for three phases
        vector<long long> inc1(n), dec(n), inc2(n);
        
        // Initialize
        inc1[0] = nums[0];
        dec[0] = LLONG_MIN;  // Can't have decreasing phase at start
        inc2[0] = LLONG_MIN;  // Can't complete trionic at start
        
        long long maxSum = LLONG_MIN;
        
        for (int i = 1; i < n; i++) {
            // Phase 1: Strictly increasing
            if (nums[i] > nums[i-1]) {
                inc1[i] = inc1[i-1] + nums[i];
            } else {
                inc1[i] = nums[i];  // Start new increasing sequence
            }
            
            // Phase 2: Strictly decreasing (from phase 1)
            dec[i] = LLONG_MIN;
            if (nums[i] < nums[i-1]) {
                // Start decreasing from previous increasing
                if (inc1[i-1] != LLONG_MIN) {
                    dec[i] = inc1[i-1] + nums[i];
                }
                // Continue existing decreasing
                if (dec[i-1] != LLONG_MIN) {
                    dec[i] = max(dec[i], dec[i-1] + nums[i]);
                }
            }
            
            // Phase 3: Strictly increasing (from phase 2) - Complete trionic
            inc2[i] = LLONG_MIN;
            if (nums[i] > nums[i-1]) {
                // Start final increasing from previous decreasing
                if (dec[i-1] != LLONG_MIN) {
                    inc2[i] = dec[i-1] + nums[i];
                }
                // Continue existing final increasing
                if (inc2[i-1] != LLONG_MIN) {
                    inc2[i] = max(inc2[i], inc2[i-1] + nums[i]);
                }
            }
            
            // Track maximum completed trionic sum
            if (inc2[i] != LLONG_MIN) {
                maxSum = max(maxSum, inc2[i]);
            }
        }
        
        return maxSum;
    }
};
```

### Solution 2: Space-Optimized DP

```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        long long inc1 = nums[0];      // Phase 1: increasing
        long long dec = LLONG_MIN;     // Phase 2: decreasing
        long long inc2 = LLONG_MIN;    // Phase 3: increasing (complete)
        
        long long prevInc1 = inc1;
        long long prevDec = dec;
        long long prevInc2 = inc2;
        
        long long maxSum = LLONG_MIN;
        
        for (int i = 1; i < n; i++) {
            long long newInc1 = nums[i];
            long long newDec = LLONG_MIN;
            long long newInc2 = LLONG_MIN;
            
            // Phase 1: Strictly increasing
            if (nums[i] > nums[i-1]) {
                newInc1 = prevInc1 + nums[i];
            }
            
            // Phase 2: Strictly decreasing
            if (nums[i] < nums[i-1]) {
                if (prevInc1 != LLONG_MIN) {
                    newDec = prevInc1 + nums[i];
                }
                if (prevDec != LLONG_MIN) {
                    newDec = max(newDec, prevDec + nums[i]);
                }
            }
            
            // Phase 3: Strictly increasing (complete trionic)
            if (nums[i] > nums[i-1]) {
                if (prevDec != LLONG_MIN) {
                    newInc2 = prevDec + nums[i];
                }
                if (prevInc2 != LLONG_MIN) {
                    newInc2 = max(newInc2, prevInc2 + nums[i]);
                }
            }
            
            // Update for next iteration
            prevInc1 = inc1 = newInc1;
            prevDec = dec = newDec;
            prevInc2 = inc2 = newInc2;
            
            // Track maximum
            if (inc2 != LLONG_MIN) {
                maxSum = max(maxSum, inc2);
            }
        }
        
        return maxSum;
    }
};
```

### Solution 3: Enumerate with Early Termination

```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        
        // Try all possible starting positions
        for (int l = 0; l < n - 3; l++) {
            long long currentSum = nums[l];
            
            // Phase 1: Extend strictly increasing
            int p = l;
            while (p + 1 < n && nums[p + 1] > nums[p]) {
                p++;
                currentSum += nums[p];
                
                // Phase 2: Try strictly decreasing from p
                long long sumWithDec = currentSum;
                int q = p;
                while (q + 1 < n && nums[q + 1] < nums[q]) {
                    q++;
                    sumWithDec += nums[q];
                    
                    // Phase 3: Try strictly increasing from q
                    long long sumComplete = sumWithDec;
                    int r = q;
                    while (r + 1 < n && nums[r + 1] > nums[r]) {
                        r++;
                        sumComplete += nums[r];
                        maxSum = max(maxSum, sumComplete);
                    }
                }
            }
        }
        
        return maxSum;
    }
};
```

---

## Key Takeaways

- **Problem Extension**: This extends 3637 from checking if array is trionic to finding maximum sum trionic subarray
- **Dynamic Programming States**: Track three phases (inc → dec → inc) with separate DP states
- **State Transitions**: Only transition between phases when monotonicity changes
- **Minimum 4 Elements**: A valid trionic subarray needs at least 4 elements (2 + 1 + 1 minimum)
- **Overlapping Segments**: Peak and valley indices are shared between adjacent phases
- **Sentinel Values**: Use `LLONG_MIN` to indicate impossible/incomplete states
- **Space Optimization**: Can reduce O(n) space to O(1) by tracking only previous values
- **Maximum Tracking**: Answer is the maximum value achieved in phase 3 (complete trionic)
- **Strict Inequalities**: Must use strict `<` and `>` for monotonic checks
- **Related Problem**: This is the "maximum sum" variant of problem 3637's "existence check"

