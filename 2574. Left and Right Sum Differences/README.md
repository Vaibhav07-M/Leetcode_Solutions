# 2574. Left and Right Sum Differences

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

[LeetCode — 2574. Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/)

---

## Problem Summary

Given a 0-indexed integer array `nums` of size `n`, define two arrays `leftSum` and `rightSum` where:

- `leftSum[i]` is the sum of elements to the left of index `i` (0 if none).
- `rightSum[i]` is the sum of elements to the right of index `i` (0 if none).

Return an integer array `answer` of size `n` where `answer[i] = |leftSum[i] - rightSum[i]|`.

Constraints: `1 <= nums.length <= 1000`, `1 <= nums[i] <= 1e5`.

---

## Examples

### Example 1
**Input:** `nums = [10,4,8,3]`  
**Output:** `[15,1,11,22]`

### Example 2
**Input:** `nums = [1]`  
**Output:** `[0]`

---

## Intuition

Compute prefix sums so you can get left and right sums in O(1) per index. The difference is then absolute value of left and right sums.

---

## Approach

1. Build prefix sum array `pref` where `pref[i]` is sum of `nums[0..i-1]` (pref[0]=0).
2. For each index `i`, `left = pref[i]`, `right = pref[n] - pref[i+1]`.
3. `answer[i] = abs(left - right)`.

This runs in O(n) time and O(n) extra space (or O(1) if you compute right sum on the fly).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` (can be `O(1)` with in-place computation) |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + nums[i];
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            long long left = pref[i];
            long long right = pref[n] - pref[i+1];
            ans[i] = (int) llabs(left - right);
        }
        return ans;
    }
};
```

---

## Key Takeaways

- Prefix sums make range-sum queries O(1).
- Pay attention to off-by-one when building prefix arrays.
- This problem is an O(n) straightforward application of prefix sums.
