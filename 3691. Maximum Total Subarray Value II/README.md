# 3691. Maximum Total Subarray Value II

**Difficulty:** `Hard`  
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

[LeetCode — 3691. Maximum Total Subarray Value II](https://leetcode.com/problems/maximum-total-subarray-value-ii/)

---

## Problem Summary

You are given an integer array `nums` of length `n` and an integer `k`. You must select exactly `k` distinct subarrays `nums[l..r]`. Subarrays may overlap, but the same `(l, r)` cannot be chosen more than once. The value of a subarray is `max(nums[l..r]) - min(nums[l..r])`. Return the maximum possible total value you can achieve.

---

## Examples

### Example 1
**Input:** `nums = [1,3,2], k = 2`  
**Output:** `4`

### Example 2
**Input:** `nums = [4,2,5,1], k = 3`  
**Output:** `12`

---

## Intuition

Enumerate all subarrays and compute their individual values; then select the top-`k` values. While enumeration is O(n^2) in the naive form, this approach is acceptable only for small `n`. The provided reference solution collects all subarray values and picks the largest `k` using `nth_element` and sorting.

---

## Approach

1. Enumerate all subarrays `nums[l..r]` and compute `mx - mn` for each.
2. Store these values in a vector `vals`.
3. Use `nth_element` to partition so that the top `k` values are at the end, then sort those `k` values and sum them.

This is O(n^2) time and O(n^2) space in the worst case; the solution is straightforward and practical for the given constraints when applied carefully.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` |
| **Space** | `O(n^2)` |

---

## Code (C++)

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> vals;
        vals.reserve(1LL * n * (n + 1) / 2);

        for(int l = 0; l < n; l++) {
            int mx = nums[l];
            int mn = nums[l];
            for(int r = l; r < n; r++) {
                mx = max(mx, nums[r]);
                mn = min(mn, nums[r]);
                vals.push_back((long long)mx - mn);
            }
        }

        nth_element(vals.begin(), vals.end() - k, vals.end());
        sort(vals.end() - k, vals.end());

        long long ans = 0;
        for(int i = (int)vals.size() - k; i < vals.size(); i++) ans += vals[i];
        return ans;
    }
};
```

---

## Key Takeaways

- Enumerate and rank subarray values when constraints allow; `nth_element` helps pick top `k` efficiently without full sort.
- This approach is straightforward but can be expensive for large `n` due to O(n^2) memory/time.
