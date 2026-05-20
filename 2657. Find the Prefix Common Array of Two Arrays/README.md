# 2657. Find the Prefix Common Array of Two Arrays

**Difficulty:** `Medium`  
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

[LeetCode — 2657. Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)

---

## Problem Summary

Given two 0-indexed permutations `A` and `B` of length `n`, return an array `C` where `C[i]` is the count of numbers that appear at or before index `i` in both `A` and `B`.

---

## Examples

### Example 1
**Input:** `A = [1,3,2,4], B = [3,1,2,4]`  
**Output:** `[0,2,3,4]`

### Example 2
**Input:** `A = [2,3,1], B = [3,1,2]`  
**Output:** `[0,1,3]`

---

## Intuition

We need to track which numbers have appeared so far in each array. Since `A` and `B` are permutations of `1..n`, we can use a small frequency/seen array to mark occurrences. After each index `i` we update counts for `A[i]` and `B[i]` and increase the common count when an element has been seen in both arrays.

---

## Approach

1. Initialize `freq` array of size `n+1` to zero and `common = 0`.
2. For each `i` from `0` to `n-1`:
   - Increment `freq[A[i]]`. If it becomes `2`, increment `common`.
   - Increment `freq[B[i]]`. If it becomes `2`, increment `common`.
   - Append `common` to the answer.
3. Return the answer array.

This works because the first time a value appears its freq becomes 1; when it appears in the other array at or before the same index it becomes 2.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass over arrays |
| **Space** | `O(n)` — frequency array and output |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if (++freq[A[i]] == 2) ++common;
            if (++freq[B[i]] == 2) ++common;
            ans.push_back(common);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Use a frequency array to detect when an element has appeared in both prefixes.
- Since inputs are permutations, the freq array size is `n+1` and updates are constant time.
- This yields an optimal linear-time solution.
