# 2770. Maximum Number of Jumps to Reach the Last Index

**Difficulty:** `Medium`  
**Tags:** `Dynamic Programming`, `Segment Tree` (optional optimization)

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

[LeetCode — 2770. Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

---

## Problem Summary

Given an integer array `nums` and an integer `target`, start at index `0`. In one step you may jump from index `i` to index `j` with `i < j` if `-target <= nums[j] - nums[i] <= target`.
Return the maximum number of jumps to reach index `n-1`, or `-1` if unreachable.

---

## Examples

### Example 1
**Input:** `nums = [1,3,6,4,1,2], target = 2`  
**Output:** `3`

### Example 2
**Input:** `nums = [1,3,6,4,1,2], target = 3`  
**Output:** `5`

### Example 3
**Input:** `nums = [1,3,6,4,1,2], target = 0`  
**Output:** `-1`

---

## Intuition

We want the longest path (maximum jumps) from index 0 to n-1 under a local constraint on differences. This is a longest-path problem in a DAG (edges only go from lower index to higher index), so dynamic programming over indices works. For each index `j`, consider all prior `i < j` where the jump is allowed and take the maximum `dp[i] + 1`.

---

## Approach

Simple, correct approach (sufficient for `n <= 1000`):
1. Initialize `dp` array length `n` with `-inf` (or `INT_MIN/large negative`), set `dp[0] = 0`.
2. For `j` from `1` to `n-1`:
   - For each `i` from `0` to `j-1`, if `abs(nums[j] - nums[i]) <= target` and `dp[i]` is valid, set `dp[j] = max(dp[j], dp[i] + 1)`.
3. If `dp[n-1]` is still invalid, return `-1`, otherwise return `dp[n-1]`.

This is O(n^2) time and simple to implement. For larger constraints, you can optimize via coordinate compression + segment tree / Fenwick tree keyed by values to query the best `dp[i]` within a value range; that reduces the inner loop.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested loops over indices (works for `n <= 1000`) |
| **Space** | `O(n)` for `dp` |

---

## Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        const int NEG = -1e9;
        vector<int> dp(n, NEG);
        dp[0] = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (abs((long long)nums[j] - nums[i]) <= target && dp[i] > NEG/2) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n-1] <= NEG/2 ? -1 : dp[n-1];
    }
};
```

---

## Key Takeaways

- The index-ordering makes the graph acyclic; DP over indices yields the longest path.
- O(n^2) is acceptable for `n <= 1000`; for larger inputs use value-based data structures (segment tree / Fenwick tree) after coordinate compression to query the best `dp[i]` in a value range.
- Careful initialization with a sentinel negative value avoids confusion between unreachable and zero jumps.
