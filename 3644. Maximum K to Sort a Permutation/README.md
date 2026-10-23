# 3644. Maximum K to Sort a Permutation

**Difficulty:** `Medium`  
**Tags:** `Array`, `Bit Manipulation`

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

[LeetCode — 3644. Maximum K to Sort a Permutation](https://leetcode.com/problems/maximum-k-to-sort-a-permutation/)

---

## Problem Summary

You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [0..n - 1].  
You may swap elements at indices i and j only if nums[i] AND nums[j] == k, where AND denotes the bitwise AND operation and k is a non-negative integer.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, bit manipulation. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — each element/state processed once |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (ans == -1)
                    ans = nums[i] & i;
                else
                    ans &= (nums[i] & i);
            }
        }

        return max(ans, 0);
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Bit Manipulation patterns often reduce an apparently complex problem to a few simple rules.
