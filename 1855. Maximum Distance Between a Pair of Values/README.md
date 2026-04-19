# 1855. Maximum Distance Between a Pair of Values

**Difficulty:** `Medium`  
**Tags:** `Array`, `Two Pointers`

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

[LeetCode - 1855. Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

---

## Problem Summary

You are given two non-increasing arrays `nums1` and `nums2`.

A pair `(i, j)` is valid if:
- `i <= j`
- `nums1[i] <= nums2[j]`

Distance is `j - i`. Return the maximum possible distance among all valid pairs. If none exist, return `0`.

---

## Examples

### Example 1
**Input:** `nums1 = [55,30,5,4,2]`, `nums2 = [100,20,10,10,5]`  
**Output:** `2`

### Example 2
**Input:** `nums1 = [2,2,2]`, `nums2 = [10,10,1]`  
**Output:** `1`

### Example 3
**Input:** `nums1 = [30,29,19,5]`, `nums2 = [25,25,25,25,25]`  
**Output:** `2`

---

## Intuition

Both arrays are non-increasing, so a two-pointer scan works efficiently:
- If `(i, j)` is valid, try increasing `j` to get larger distance.
- If invalid, increase `i` to make `nums1[i]` smaller/easier to satisfy.

This monotonic movement guarantees linear time.

---

## Approach

1. Initialize `i = 0`, `j = 0`, `ans = 0`.
2. While `i < nums1.size()` and `j < nums2.size()`:
   - If `nums1[i] <= nums2[j]`, update `ans = max(ans, j - i)` and move `j++`.
   - Otherwise move `i++`.
3. Return `ans`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        int ans = 0;

        while(i < n && j < m) {

            if(nums1[i] <= nums2[j]) {
                // valid pair
                ans = max(ans, j - i);
                j++; // try to expand
            } else {
                // invalid -> move i
                i++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Non-increasing order enables a linear two-pointer strategy.
- Always advance `j` on valid pairs to maximize distance.
- Advance `i` only when constraint fails.