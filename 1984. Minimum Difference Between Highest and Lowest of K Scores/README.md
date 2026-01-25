# 1984. Minimum Difference Between Highest and Lowest of K Scores

**Difficulty:** `Easy`  
**Tags:** `Array`, `Sorting`, `Sliding Window`

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

[LeetCode — 1984. Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)

---

## Problem Summary

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the i-th student.  
You are also given an integer `k`.

Pick the scores of any `k` students from the array so that the **difference between the highest and the lowest** of the `k` scores is **minimized**.

Return the **minimum possible difference**.

---

## Examples

### Example 1
**Input:** `nums = [90], k = 1`  
**Output:** `0`  
**Explanation:**
- Only one way to pick 1 student: [90]
- Difference = 90 - 90 = 0

### Example 2
**Input:** `nums = [9,4,1,7], k = 2`  
**Output:** `2`  
**Explanation:**
Six ways to pick 2 students:
- [9,4]: diff = 9 - 4 = 5
- [9,1]: diff = 9 - 1 = 8
- [9,7]: diff = 9 - 7 = 2 ✓ (minimum)
- [4,1]: diff = 4 - 1 = 3
- [7,4]: diff = 7 - 4 = 3
- [7,1]: diff = 7 - 1 = 6

Minimum difference = 2

---

## Intuition

To minimize the difference between the highest and lowest scores in a group of `k` students, we want to select students whose scores are **close together**.

**Key insight:** After sorting, consecutive elements are closest together. A sliding window of size `k` on the sorted array will give us groups of students with minimal spread.

**Why this works:**
- Sorting arranges scores in ascending order
- Any `k` consecutive scores in sorted array form the most compact group
- The difference is simply `nums[i+k-1] - nums[i]` for window starting at index `i`

**Example:**
```
nums = [9,4,1,7], k = 2
sorted: [1,4,7,9]

Windows of size 2:
[1,4]: diff = 4-1 = 3
[4,7]: diff = 7-4 = 3
[7,9]: diff = 9-7 = 2 ← minimum
```

---

## Approach

### Sliding Window Strategy:
1. **Handle edge case:** If `k == 1`, return 0 (single element has no difference)
2. **Sort the array** in ascending order
3. **Use sliding window of size k:**
   - For each position `i` where a window of size `k` fits
   - Calculate difference: `nums[i+k-1] - nums[i]`
   - Track the minimum difference
4. **Return the minimum**

### Algorithm:
```
1. If k <= 1, return 0
2. Sort nums in ascending order
3. Initialize minDiff = INT_MAX
4. For i from 0 to n-k:
   - Calculate diff = nums[i+k-1] - nums[i]
   - minDiff = min(minDiff, diff)
5. Return minDiff
```

### Why Sliding Window Works:
- After sorting, we only need to check consecutive groups
- Any non-consecutive group would have a larger spread
- Window size `k` ensures we always pick exactly `k` students

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting |
| **Space** | `O(1)` or `O(log n)` — depending on sort implementation |

The sliding window pass is O(n), but sorting dominates the complexity.

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Edge case: single student has 0 difference
        if (k <= 1) {
            return 0;
        }
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int result = INT_MAX;
        
        // Sliding window of size k
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            int diff = nums[i + k - 1] - nums[i];
            result = min(result, diff);
        }
        
        return result;
    }
};
```

### Alternative Implementation (More Explicit):

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int minDiff = INT_MAX;
        
        // Check all windows of size k
        for (int i = 0; i <= n - k; i++) {
            int highest = nums[i + k - 1];
            int lowest = nums[i];
            int diff = highest - lowest;
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};
```

### Clean One-Pass Version:

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;
        for (int i = 0; i + k <= nums.size(); i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }
        
        return minDiff;
    }
};
```

---

## Key Takeaways

1. **Sorting + Sliding Window** — Classic combination for range minimization problems
2. **Consecutive elements** in sorted array have minimal spread
3. **Edge case handling** — k=1 returns 0 immediately
4. **Window bounds** — Be careful with `i + k - 1 < nums.size()` vs `i + k <= nums.size()`
5. **Greedy correctness** — Sorting guarantees we find optimal groupings
6. **O(n log n) bottleneck** — Sorting dominates the time complexity
7. **Similar pattern** — This approach applies to many "minimize range" problems
8. **Alternative:** Could use heap/priority queue, but sorting is simpler and equally efficient

---
