# 1877. Minimize Maximum Pair Sum in Array

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`, `Two Pointers`

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

[LeetCode — 1877. Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)

---

## Problem Summary

Given an array `nums` of **even length** `n`, pair up the elements into `n/2` pairs such that:
- Each element is in exactly one pair
- The **maximum pair sum is minimized**

The pair sum of `(a, b)` is `a + b`.  
The maximum pair sum is the largest sum among all pairs.

Return the **minimized maximum pair sum** after optimally pairing elements.

---

## Examples

### Example 1
**Input:** `nums = [3,5,2,3]`  
**Output:** `7`  
**Explanation:**
- Pairs: (3,3) and (5,2)
- Pair sums: 3+3=6, 5+2=7
- Maximum pair sum = max(6, 7) = 7

### Example 2
**Input:** `nums = [3,5,4,2,4,6]`  
**Output:** `8`  
**Explanation:**
- Pairs: (3,5), (4,4), (6,2)
- Pair sums: 3+5=8, 4+4=8, 6+2=8
- Maximum pair sum = max(8, 8, 8) = 8

---

## Intuition

To minimize the maximum pair sum, we need to avoid pairing large numbers together.

**Key insight:** After sorting, pair the smallest element with the largest, the second smallest with the second largest, and so on.

**Why this works:**
- If we pair two large numbers, we get a very large sum
- If we pair two small numbers, we waste the opportunity to "balance out" large numbers
- Pairing smallest with largest creates more balanced sums

**Example:**
```
nums = [1, 4, 3, 2]
sorted: [1, 2, 3, 4]

Optimal pairing (smallest with largest):
(1,4) = 5
(2,3) = 5
max = 5

Bad pairing:
(1,2) = 3
(3,4) = 7
max = 7 (worse!)
```

---

## Approach

### Greedy Strategy:
1. **Sort the array** in ascending order
2. **Use two pointers:**
   - Left pointer at start (smallest elements)
   - Right pointer at end (largest elements)
3. **Pair elements:** `(nums[left], nums[right])`
4. **Track maximum:** Keep track of the maximum sum seen
5. **Move pointers inward** and repeat

### Algorithm:
```
1. Sort nums in ascending order
2. Initialize left = 0, right = n-1
3. maxSum = 0
4. While left < right:
   - currentSum = nums[left] + nums[right]
   - maxSum = max(maxSum, currentSum)
   - left++
   - right--
5. Return maxSum
```

### Why Greedy Works:
- Sorting ensures we can systematically pair elements
- Pairing smallest with largest minimizes the chance of creating an extremely large sum
- Any other pairing strategy would leave larger numbers to pair together, increasing the maximum

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting |
| **Space** | `O(1)` or `O(log n)` — depending on sort implementation |

---

## Code (C++)

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxSum = 0;
        
        // Use two pointers: pair smallest with largest
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            maxSum = max(maxSum, currentSum);
            left++;
            right--;
        }
        
        return maxSum;
    }
};
```

### Alternative Implementation (Explicit Loop):

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxSum = 0;
        
        // Pair first half with second half (reversed)
        for (int i = 0; i < n / 2; i++) {
            int sum = nums[i] + nums[n - 1 - i];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
```

### One-Liner Approach:

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            maxSum = max(maxSum, nums[i] + nums[nums.size() - 1 - i]);
        }
        return maxSum;
    }
};
```

---

## Key Takeaways

1. **Greedy + Sorting** — Classic combination for optimization problems
2. **Two pointers technique** — Efficient way to pair elements from both ends
3. **Balance strategy** — Pair extremes (min with max) to minimize the maximum
4. **Proof by contradiction** — Any other pairing creates larger maximum sums
5. **Even length guarantee** — Problem ensures perfect pairing is possible
6. **O(n log n) sorting** is the bottleneck, pairing itself is O(n)
7. **Similar problems:** This pattern appears in many pairing/matching optimization problems
8. **Invariant:** After sorting, optimal pairing is always first half with reversed second half

---
