# 1. Two Sum

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

[LeetCode — 1. Two Sum](https://leetcode.com/problems/two-sum/)

---

## Problem Summary

You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.  
You may assume that each input would have exactly one solution, and you may not use the same element twice.

---

## Examples

### Example 1
**Input:** `nums = [2,7,11,15], target = 9`  
**Output:** `[0,1]`  
**Explanation:**
- Because nums[0] + nums[1] == 9, we return [0, 1].

### Example 2
**Input:** `nums = [3,2,4], target = 6`  
**Output:** `[1,2]`  

### Example 3
**Input:** `nums = [3,3], target = 6`  
**Output:** `[0,1]`  

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
	#include <vector>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // If no solution found
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Hash Table patterns often reduce an apparently complex problem to a few simple rules.
