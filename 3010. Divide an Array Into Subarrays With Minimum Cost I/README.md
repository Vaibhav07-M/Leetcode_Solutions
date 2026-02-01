# 3010. Divide an Array Into Subarrays With Minimum Cost I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Greedy`

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

[LeetCode — 3010. Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)

---

## Problem Summary

You are given an array of integers `nums` of length `n`.

The **cost** of an array is the value of its **first element**. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into **3 disjoint contiguous subarrays**.

Return the **minimum possible sum** of the cost of these subarrays.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3,12]`  
**Output:** `6`  
**Explanation:**
- Best way: `[1]`, `[2]`, and `[3,12]` with total cost = 1 + 2 + 3 = 6
- Other ways:
  - `[1]`, `[2,3]`, and `[12]` → cost = 1 + 2 + 12 = 15
  - `[1,2]`, `[3]`, and `[12]` → cost = 1 + 3 + 12 = 16

### Example 2
**Input:** `nums = [5,4,3]`  
**Output:** `12`  
**Explanation:**
- Best way: `[5]`, `[4]`, and `[3]` with total cost = 5 + 4 + 3 = 12

### Example 3
**Input:** `nums = [10,3,1,1]`  
**Output:** `12`  
**Explanation:**
- Best way: `[10,3]`, `[1]`, and `[1]` with total cost = 10 + 1 + 1 = 12

---

## Intuition

The key insight is understanding what contributes to the total cost:
- **First subarray** must start at index 0, so its cost is always `nums[0]`
- **Second subarray** starts somewhere in the middle, contributing its first element
- **Third subarray** starts somewhere after the second, contributing its first element

Since we need exactly 3 subarrays and the first must start at index 0, we have:
- Cost = `nums[0]` + (cost of 2nd subarray's first element) + (cost of 3rd subarray's first element)

To minimize total cost, we need to minimize the sum of the starting elements of the 2nd and 3rd subarrays. These starting elements must come from `nums[1..n-1]` (everything except the first element).

**Key observation**: To minimize the cost, we should choose the **two smallest elements** from `nums[1..n-1]` to be the starting elements of the 2nd and 3rd subarrays.

This is a **greedy** approach: pick the smallest available values for the costs we can control.

---

## Approach

1. **Fix the first cost**: The first subarray must start at index 0, so `cost1 = nums[0]` (fixed, cannot change)

2. **Find two smallest from remaining elements**:
   - Iterate through `nums[1..n-1]`
   - Track the **smallest** and **second smallest** values
   - These will be the optimal starting elements for subarrays 2 and 3

3. **Calculate total cost**: `nums[0] + smallest + secondSmallest`

### Algorithm:
```
1. first = nums[0]
2. smallest = INT_MAX
3. secondSmallest = INT_MAX
4. For i from 1 to n-1:
   - If nums[i] < smallest:
     - secondSmallest = smallest
     - smallest = nums[i]
   - Else if nums[i] < secondSmallest:
     - secondSmallest = nums[i]
5. Return first + smallest + secondSmallest
```

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the array |
| **Space** | `O(1)` — only a few variables used |

---

## Code (C++)

### Solution 1: Greedy (Track Two Smallest)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }
        
        return first + smallest + secondSmallest;
    }
};
```

### Solution 2: Using Sorting (Less Optimal)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        
        // Create vector of remaining elements and sort
        vector<int> remaining(nums.begin() + 1, nums.end());
        sort(remaining.begin(), remaining.end());
        
        // Take two smallest
        return first + remaining[0] + remaining[1];
    }
};
```

### Solution 3: Using Min Heap (Overkill but Demonstrates Concept)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        
        // Min heap to track smallest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 1; i < nums.size(); i++) {
            minHeap.push(nums[i]);
        }
        
        int smallest = minHeap.top();
        minHeap.pop();
        int secondSmallest = minHeap.top();
        
        return first + smallest + secondSmallest;
    }
};
```

### Solution 4: Brute Force (For Verification)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minCost = INT_MAX;
        
        // Try all possible split points
        for (int i = 1; i < n; i++) {          // End of first subarray
            for (int j = i + 1; j < n; j++) {  // End of second subarray
                // Three subarrays: [0..i-1], [i..j-1], [j..n-1]
                int cost = nums[0] + nums[i] + nums[j];
                minCost = min(minCost, cost);
            }
        }
        
        return minCost;
    }
};
```

---

## Key Takeaways

1. **Understand cost definition**: The cost is the **first element** of each subarray, not the sum of all elements in the subarray.

2. **Fixed vs variable costs**: When some costs are fixed (like `nums[0]` here), focus on optimizing the variable costs.

3. **Greedy choice**: When you need to select k smallest (or largest) elements and the order doesn't matter, a greedy approach of tracking the k smallest values in one pass is optimal.

4. **Tracking two minimums**: The pattern of maintaining `smallest` and `secondSmallest` while iterating is reusable for many problems requiring the k smallest/largest elements.

5. **Contiguous subarrays**: "Disjoint contiguous subarrays" means the subarrays don't overlap, are consecutive segments, and together cover the entire array.

6. **Space-time tradeoff**: The O(n) time, O(1) space solution is better than O(n log n) sorting solution for this problem.

7. **Verification with brute force**: The brute force O(n²) solution trying all split points helps verify the greedy approach is correct.

---
