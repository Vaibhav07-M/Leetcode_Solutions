# 1848. Minimum Distance to the Target Element

**Difficulty:** `Easy`  
**Tags:** `Array`

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

[LeetCode - 1848. Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/)

---

## Problem Summary

You are given:
- an integer array `nums`
- an integer `target`
- an integer `start`

Find an index `i` such that `nums[i] == target` and `abs(i - start)` is minimum.
Return that minimum distance.

It is guaranteed that `target` exists in `nums`.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3,4,5], target = 5, start = 3`  
**Output:** `1`

**Explanation:**
- The only target index is `4`.
- Distance is `abs(4 - 3) = 1`.

### Example 2
**Input:** `nums = [1], target = 1, start = 0`  
**Output:** `0`

### Example 3
**Input:** `nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0`  
**Output:** `0`

---

## Intuition

Instead of scanning every index and tracking the minimum, the given solution expands outward from `start` by distance `d = 0, 1, 2, ...`.

As soon as a valid target is found on either side, that `d` is the minimum possible distance by construction.

---

## Approach

1. Let `n = nums.size()`.
2. For distance `d` from `0` to `n - 1`:
   - Check left index `start - d` if it is in bounds.
   - Check right index `start + d` if it is in bounds.
   - If either position contains `target`, return `d` immediately.
3. Return `-1` as fallback (the constraints guarantee this line is never used).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` in the worst case |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {

        int n = nums.size();

        for(int d = 0; d < n; d++) {
            if(start - d >= 0 && nums[start - d] == target)
                return d;

            if(start + d < n && nums[start + d] == target)
                return d;
        }

        return -1; // won't happen (guaranteed exists)
    }
};
```

---

## Key Takeaways

- Expanding symmetrically from `start` finds the nearest match directly.
- Early return is natural because distances are checked in increasing order.
- For this problem, no auxiliary data structures are needed.