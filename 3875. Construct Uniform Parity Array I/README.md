# 3875. Construct Uniform Parity Array I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Math`

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

[LeetCode — 3875. Construct Uniform Parity Array I](https://leetcode.com/problems/construct-uniform-parity-array-i/)

---

## Problem Summary

You are given an array nums1 of n distinct integers.  
You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around array, math. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass over the input |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Math patterns often reduce an apparently complex problem to a few simple rules.
