# 2161. Partition Array According to Given Pivot

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

[LeetCode — 2161. Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

---

## Problem Summary

Given an integer array `nums` and an integer `pivot`, rearrange `nums` so that:
- All elements less than `pivot` appear before elements greater than `pivot`.
- All elements equal to `pivot` appear between the less-than and greater-than sections.
- The relative order among elements in the same partition is preserved.

Return the rearranged array.

---

## Examples

### Example 1
**Input:** `nums = [9,12,5,10,14,3,10], pivot = 10`  
**Output:** `[9,5,3,10,10,12,14]`

### Example 2
**Input:** `nums = [-3,4,3,2], pivot = 2`  
**Output:** `[-3,2,4,3]`

---

## Intuition

Collect elements into three lists — `less`, `equal`, and `greater` — while iterating once over `nums`. Concatenate these lists to produce the required ordering while preserving relative order inside each partition.

---

## Approach

1. Initialize three vectors: `less`, `equal`, `greater`.
2. Iterate through `nums` and push each element into the appropriate vector based on comparison with `pivot`.
3. Build the result by appending `less`, then `equal`, then `greater`.

This preserves relative order and is linear-time.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        less.reserve(nums.size());
        equal.reserve(nums.size());
        greater.reserve(nums.size());

        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else greater.push_back(x);
        }

        vector<int> res;
        res.reserve(nums.size());
        res.insert(res.end(), less.begin(), less.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), greater.begin(), greater.end());
        return res;
    }
};
```

---

## Key Takeaways

- Simple one-pass partition with three buckets preserves relative order.
- Use extra space for clarity and linear time; optimal in practice for the constraints.
