# 3741. Minimum Distance Between Three Equal Elements II

**Difficulty:** `Medium`  
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

[LeetCode - 3741. Minimum Distance Between Three Equal Elements II](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/)

---

## Problem Summary

You are given an integer array `nums`.

A tuple `(i, j, k)` of distinct indices is good if `nums[i] == nums[j] == nums[k]`.
The distance of a good tuple is:

`abs(i - j) + abs(j - k) + abs(k - i)`.

Return the minimum possible distance among all good tuples, or `-1` if no such tuple exists.

---

## Examples

### Example 1
**Input:** `nums = [1,2,1,1,3]`  
**Output:** `6`

**Explanation:**
- A minimum tuple is `(0, 2, 3)` with equal value `1`.
- Distance = `abs(0-2) + abs(2-3) + abs(3-0) = 2 + 1 + 3 = 6`.

### Example 2
**Input:** `nums = [1,1,2,3,2,1,2]`  
**Output:** `8`

**Explanation:**
- A minimum tuple is `(2, 4, 6)` with equal value `2`.
- Distance = `abs(2-4) + abs(4-6) + abs(6-2) = 2 + 2 + 4 = 8`.

### Example 3
**Input:** `nums = [1]`  
**Output:** `-1`

**Explanation:**
- No value appears at least three times.

---

## Intuition

For any sorted triple of indices `a < b < c` with equal values, the distance simplifies to:

`(b - a) + (c - b) + (c - a) = 2 * (c - a)`.

So only the first and third indices matter. That means for each value, we only need to test windows of three consecutive occurrences.

---

## Approach

1. Build a hash map from value to all positions where it appears.
2. For each position list `v`:
   - skip if `v.size() < 3`
   - for each consecutive triple `(v[i], v[i+1], v[i+2])`, compute `2 * (v[i+2] - v[i])`
   - keep the global minimum
3. Return `-1` if no valid triple is found.

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
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> pos;

        // Store positions
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Process each value
        for (auto &p : pos) {
            auto &v = p.second;

            if (v.size() < 3) continue;

            // Check consecutive triples
            for (int i = 0; i + 2 < v.size(); i++) {
                ans = min(ans, 2 * (v[i+2] - v[i]));
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
```

---

## Key Takeaways

- Group equal values by positions.
- For three sorted indices, the middle index does not affect the distance formula.
- Sliding a size-3 window over occurrence positions gives the minimum efficiently.