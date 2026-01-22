# 3507. Minimum Pair Removal to Sort Array I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Greedy`, `Simulation`

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

[LeetCode — 3507. Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)

---

## Problem Summary

Given an array `nums`, you can perform the following operation any number of times:
- Select the adjacent pair with the **minimum sum** in `nums`
- If multiple such pairs exist, choose the **leftmost one**
- Replace the pair with their sum

Return the **minimum number of operations** needed to make the array non-decreasing.

An array is non-decreasing if each element is greater than or equal to its previous element.

---

## Examples

### Example 1
**Input:** `nums = [5,2,3,1]`  
**Output:** `2`  
**Explanation:**
- Operation 1: Pair (3,1) has minimum sum 4 → `nums = [5,2,4]`
- Operation 2: Pair (2,4) has minimum sum 6 → `nums = [5,6]`
- Array is now non-decreasing in 2 operations

### Example 2
**Input:** `nums = [1,2,2]`  
**Output:** `0`  
**Explanation:**
- Array is already non-decreasing

---

## Intuition

The problem requires us to simulate the process described:
1. Find the adjacent pair with minimum sum (leftmost if tie)
2. Replace it with the sum
3. Repeat until array is non-decreasing

The key insight is that we need to:
- Check if array is already sorted after each operation
- Find the minimum sum adjacent pair efficiently
- Keep track of operation count

Since we're always choosing the minimum sum pair, this is a **greedy simulation** problem.

---

## Approach

### Strategy:
1. **Check if already sorted:** Before any operations, verify if array is non-decreasing
2. **Repeat until sorted:**
   - Find the adjacent pair with minimum sum
   - If multiple pairs have the same minimum sum, choose the leftmost
   - Replace the pair with their sum
   - Increment operation count
3. **Return count**

### Algorithm:
```
operations = 0

while not isSorted(nums):
    minSum = INT_MAX
    minIdx = -1
    
    // Find minimum sum adjacent pair (leftmost)
    for i from 0 to n-2:
        sum = nums[i] + nums[i+1]
        if sum < minSum:
            minSum = sum
            minIdx = i
    
    // Replace pair with sum
    nums[minIdx] = minSum
    nums.erase(minIdx + 1)
    operations++

return operations
```

### Helper Function:
```cpp
bool isSorted(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i-1]) return false;
    }
    return true;
}
```

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n³)` — worst case: O(n) iterations × O(n) to find min pair × O(n) to check sorted |
| **Space** | `O(1)` — modifying array in-place |

For the given constraints (n ≤ 50), this is acceptable.

**Optimizations possible:**
- Only check sorting from modified position onwards
- Early termination when modification doesn't change sorted status

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (!isSorted(nums)) {
            // Find the adjacent pair with minimum sum (leftmost if tie)
            int minSum = INT_MAX;
            int minIdx = -1;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }
            
            // Replace the pair with their sum
            nums[minIdx] = minSum;
            nums.erase(nums.begin() + minIdx + 1);
            operations++;
        }
        
        return operations;
    }
    
private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
```

### Alternative Implementation (Without Erase):

```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (!isSorted(nums)) {
            // Find minimum sum pair
            int minSum = INT_MAX;
            int minIdx = -1;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }
            
            // Replace pair by setting first element to sum and removing second
            nums[minIdx] = minSum;
            nums.erase(nums.begin() + minIdx + 1);
            operations++;
        }
        
        return operations;
    }
    
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};
```

---

## Key Takeaways

1. **Greedy simulation** — follow the exact rules specified in problem statement
2. **Leftmost selection** matters when multiple pairs have the same minimum sum
3. **Array modification** — each operation reduces array size by 1
4. **Termination condition** — stop when array becomes non-decreasing
5. **Non-decreasing definition** — `nums[i] >= nums[i-1]` for all valid i
6. **Edge case:** Already sorted array returns 0 operations
7. **Small constraints** allow for O(n³) brute force simulation
8. **Vector erase** is O(n) operation but acceptable here due to small n

---
