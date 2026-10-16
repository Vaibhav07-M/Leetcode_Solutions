# 2916. Subarrays Distinct Element Sum of Squares II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Binary Indexed Tree`, `Segment Tree`

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

[LeetCode — 2916. Subarrays Distinct Element Sum of Squares II](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)

---

## Problem Summary

You are given a 0-indexed integer array nums.  
The distinct count of a subarray of nums is defined as:

---

## Examples

### Example 1
**Input:** `nums = [1,2,1]`  
**Output:** `15`  
**Explanation:**
- Six possible subarrays are:
- [1]: 1 distinct value
- [2]: 1 distinct value
- [1]: 1 distinct value
- [1,2]: 2 distinct values
- [2,1]: 2 distinct values
- [1,2,1]: 2 distinct values
- The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

### Example 2
**Input:** `nums = [2,2]`  
**Output:** `3`  
**Explanation:**
- Three possible subarrays are:
- [2]: 1 distinct value
- [2]: 1 distinct value
- [2,2]: 1 distinct value
- The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.

---

## Intuition

The problem revolves around array, hash table, binary indexed tree, segment tree. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

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
    typedef long long ll;
    int MOD = 1e9+7;
    int n;

    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r, int val) {
        int len = (r-l+1);

        sqSumSegTree[i] += 2*val*sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        if(lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if(l != r) {
                lazyTree[2*i+1] += lazyTree[i];
                lazyTree[2*i+2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }

        //out of range
        if(l > end || r < start || l > r) {
            return;
        }

        //Completelty within range
        if(l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if(l != r) {
                lazyTree[2*i+1] += val;
                lazyTree[2*i+2] += val;
            }
            return;
        }

        int mid = l + (r-l)/2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        sumSegTree[i]   = sumSegTree[2*i+1] + sumSegTree[2*i+2];
        sqSumSegTree[i] = sqSumSegTree[2*i+1] + sqSumSegTree[2*i+2];
    }
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSumSegTree.assign(4*n, 0);
        sumSegTree.assign(4*n, 0);
        lazyTree.assign(4*n, 0);

        vector<int> lastSeenIdx(100001, -1);
        ll result = 0;

        for(int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end   = i;

            updateRange(start, end, 0, 0, n-1, 1);

            result = (result + sqSumSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Hash Table, Binary Indexed Tree, Segment Tree patterns often reduce an apparently complex problem to a few simple rules.
