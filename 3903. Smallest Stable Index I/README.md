# 3903. Smallest Stable Index I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Prefix Sum`

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

[LeetCode — 3903. Smallest Stable Index I](https://leetcode.com/problems/smallest-stable-index-i/)

---

## Problem Summary

You are given an integer array nums of length n and an integer k.  
For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, prefix sum. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        // Maximum from index 0 to i
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        // Minimum from index i to n-1
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        // Find the first stable index
        for (int i = 0; i < n; i++) {
            if (prefixMax[i] - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Prefix Sum patterns often reduce an apparently complex problem to a few simple rules.
