# 2784. Check if Array is Good

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`, `Counting`

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

[LeetCode — 2784. Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good/)

---

## Problem Summary

Given an integer array `nums`, determine if it is "good".  
An array is considered good if it is a permutation of `base[n]`:

```
base[n] = [1, 2, ..., n-1, n, n]
```

Essentially, it must contain:
- Each number from `1` to `n-1` exactly once
- The number `n` exactly twice
- Total length = `n + 1`

Return `true` if the array is good, otherwise `false`.

---

## Examples

### Example 1
**Input:** `nums = [2, 1, 3]`  
**Output:** `false`  
**Explanation:**
- Maximum element is 3, so `n = 3`
- `base[3] = [1, 2, 3, 3]` has 4 elements
- `nums` has only 3 elements, so it cannot be a permutation

### Example 2
**Input:** `nums = [1, 3, 3, 2]`  
**Output:** `true`  
**Explanation:**
- Maximum element is 3, so `n = 3`
- `base[3] = [1, 2, 3, 3]`
- `nums` is a permutation of `base[3]`

### Example 3
**Input:** `nums = [1, 1]`  
**Output:** `true`  
**Explanation:**
- Maximum element is 1, so `n = 1`
- `base[1] = [1, 1]`
- `nums` matches exactly

### Example 4
**Input:** `nums = [3, 4, 4, 1, 2, 1]`  
**Output:** `false`  
**Explanation:**
- Maximum element is 4, so `n = 4`
- `base[4] = [1, 2, 3, 4, 4]` has 5 elements
- `nums` has 6 elements, so it cannot match

---

## Intuition

The key observation is:
- The maximum element in the array determines `n`
- The array length must be exactly `n + 1`
- Every number from `1` to `n-1` must appear exactly once
- The number `n` must appear exactly twice

We can use a frequency counter or sorted approach to validate these conditions.

---

## Approach

1. **Find the maximum element** → this determines `n`
2. **Check if array length equals `n + 1`** → if not, return `false`
3. **Count frequency of each element**:
   - Numbers `1` to `n-1` must have frequency 1
   - Number `n` must have frequency 2
   - Any other number invalidates the array
4. Return `true` if all conditions are met

**Alternative (Sorting):**
- Sort the array
- Verify it matches `[1, 2, ..., n-1, n, n]` exactly

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass to count frequencies |
| **Space** | `O(n)` — hash map to store frequencies |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        // Check if length is correct
        if (nums.size() != n + 1) {
            return false;
        }
        
        // Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Validate frequencies
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1) {
                return false;
            }
        }
        
        // Check that n appears exactly twice
        if (freq[n] != 2) {
            return false;
        }
        
        return true;
    }
};
```

---

## Alternative Approach (Sorting)

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        // Check if length is correct
        if (nums.size() != n + 1) {
            return false;
        }
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Verify it matches [1, 2, ..., n-1, n, n]
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != i) {
                return false;
            }
        }
        
        return nums[n - 1] == n && nums[n] == n;
    }
};
```

---

## Key Takeaways

- Use frequency counting for validation problems when order doesn't initially matter.
- The maximum element can hint at expected structure (here, it determines `n`).
- Always validate constraints (length, element counts) to ensure correctness.
- Sorting is an alternative when permutation validation is needed.
