# 3069. Distribute Elements Into Two Arrays I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Simulation`

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

[LeetCode — 3069. Distribute Elements Into Two Arrays I](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/)

---

## Problem Summary

You are given a 1-indexed array of distinct integers nums of length n.  
You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

---

## Examples

### Example 1
**Input:** `nums = [2,1,3]`  
**Output:** `[2,3,1]`  
**Explanation:**
- After the first 2 operations, arr1 = [2] and arr2 = [1].
- In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (2 > 1), append nums[3] to arr1.
- After 3 operations, arr1 = [2,3] and arr2 = [1].
- Hence, the array result formed by concatenation is [2,3,1].

### Example 2
**Input:** `nums = [5,4,3,8]`  
**Output:** `[5,3,4,8]`  
**Explanation:**
- After the first 2 operations, arr1 = [5] and arr2 = [4].
- In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (5 > 4), append nums[3] to arr1, hence arr1 becomes [5,3].
- In the 4th operation, as the last element of arr2 is greater than the last element of arr1 (4 > 3), append nums[4] to arr2, hence arr2 becomes [4,8].
- After 4 operations, arr1 = [5,3] and arr2 = [4,8].
- Hence, the array result formed by concatenation is [5,3,4,8].

---

## Intuition

The problem revolves around array, simulation. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

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
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } 
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Combine arr1 and arr2
        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Simulation patterns often reduce an apparently complex problem to a few simple rules.
