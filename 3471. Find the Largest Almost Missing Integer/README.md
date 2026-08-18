# 3471. Find the Largest Almost Missing Integer

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`

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

[LeetCode — 3471. Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)

---

## Problem Summary

You are given an integer array nums and an integer k.  
An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, hash table. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

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
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of subarrays of size k
        // that contain x
        vector<int> count(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            // To make sure a number is counted only once
            // inside the current window
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                int x = nums[j];

                if (!seen[x]) {
                    count[x]++;
                    seen[x] = true;
                }
            }
        }

        int ans = -1;

        // Find the largest number appearing
        // in exactly one subarray
        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Hash Table patterns often reduce an apparently complex problem to a few simple rules.
