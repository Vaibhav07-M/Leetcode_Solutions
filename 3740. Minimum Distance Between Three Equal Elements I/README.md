# 3740. Minimum Distance Between Three Equal Elements I

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

[LeetCode - 3740. Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)

---

## Problem Summary

You are given an integer array `nums`.

A tuple of distinct indices `(i, j, k)` is good if `nums[i] == nums[j] == nums[k]`.
The distance of a good tuple is `abs(i - j) + abs(j - k) + abs(k - i)`.

Return the minimum possible distance of any good tuple, or `-1` if no such tuple exists.

---

## Examples

### Example 1
**Input:** `nums = [1,2,1,1,3]`  
**Output:** `6`

**Explanation:**
- The tuple `(0, 2, 3)` uses three `1`s.
- Its distance is `abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6`.

### Example 2
**Input:** `nums = [1,1,2,3,2,1,2]`  
**Output:** `8`

**Explanation:**
- The tuple `(2, 4, 6)` uses three `2`s.
- Its distance is `abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8`.

### Example 3
**Input:** `nums = [1]`  
**Output:** `-1`

**Explanation:**
- There are no values that appear at least three times.

---

## Intuition

For any value, only the positions where it appears matter.
If we collect all indices for the same number in increasing order, the best triple must come from three consecutive occurrences.

That works because for a sorted triple `a < b < c`, the distance becomes `2 * (c - a)`, so the middle index does not change the result.

---

## Approach

1. Build a map from each value to the list of indices where it appears.
2. For every list of indices:
   - If it has fewer than 3 entries, skip it.
   - For every consecutive window of 3 indices, compute `2 * (indices[i + 2] - indices[i])`.
3. Track the minimum distance across all values.
4. If no valid triple exists, return `-1`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` overall, since each index is stored once and each occurrence list is scanned once |
| **Space** | `O(n)` for the index lists |

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        int answer = INT_MAX;

        for (auto &entry : positions) {
            vector<int> &indices = entry.second;

            if (indices.size() < 3) {
                continue;
            }

            for (int i = 0; i + 2 < indices.size(); i++) {
                int distance = 2 * (indices[i + 2] - indices[i]);
                answer = min(answer, distance);
            }
        }

        return (answer == INT_MAX ? -1 : answer);
    }
};
```

---

## Key Takeaways

- Grouping equal values by index makes the problem easy to scan.
- For a triple of equal values, only the first and third positions matter.
- Consecutive occurrences are enough to find the minimum distance.