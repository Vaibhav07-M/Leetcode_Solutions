# 3488. Closest Equal Element Queries

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Binary Search`

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

[LeetCode - 3488. Closest Equal Element Queries](https://leetcode.com/problems/closest-equal-element-queries/)

---

## Problem Summary

You are given:
- a circular array `nums`
- an array `queries`

For each query index `q = queries[i]`, find the minimum circular distance from `q` to any other index `j` such that:

`nums[j] == nums[q]`

If no such `j` exists, return `-1` for that query.

Return an answer array for all queries.

---

## Examples

### Example 1
**Input:** `nums = [1,3,1,4,1,3,2]`, `queries = [0,3,5]`  
**Output:** `[2,-1,3]`

**Explanation:**
- For index `0` (value `1`), nearest same value is at index `2` => distance `2`.
- For index `3` (value `4`), no other `4` exists => `-1`.
- For index `5` (value `3`), nearest same value is index `1` with circular distance `3`.

### Example 2
**Input:** `nums = [1,2,3,4]`, `queries = [0,1,2,3]`  
**Output:** `[-1,-1,-1,-1]`

---

## Intuition

Group indices by value. For a queried index `q`, only indices that share the same value matter.

Inside that sorted index list, the closest match must be either:
- the previous occurrence, or
- the next occurrence

in circular sense. So we find `q` in its value-group using binary search, then only check these two neighbors.

---

## Approach

1. Build `unordered_map<int, vector<int>>` from value to sorted occurrence indices.
2. For each query `q`:
   - Let `v = mp[nums[q]]`.
   - If `v.size() == 1`, answer is `-1`.
   - Find position `idx` of `q` in `v` using `lower_bound`.
   - Check:
     - next occurrence `v[(idx + 1) % v.size()]`
     - previous occurrence `v[(idx - 1 + v.size()) % v.size()]`
   - For each candidate, compute linear difference `d = abs(candidate - q)` and circular distance `min(d, n - d)`.
   - Take the minimum of both candidates.
3. Return all answers.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + q log k)` where `k` is occurrences of queried value (`k <= n`) |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        // Map value -> indices
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries) {
            int val = nums[q];
            auto &v = mp[val];

            // If only one occurrence
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Binary search
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();

            int res = INT_MAX;

            // Check next
            int next = v[(idx + 1) % v.size()];
            int d1 = abs(next - q);
            res = min(res, min(d1, n - d1));

            // Check previous
            int prev = v[(idx - 1 + v.size()) % v.size()];
            int d2 = abs(prev - q);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Grouping equal values turns each query into a local-neighbor search problem.
- In a sorted occurrence list, only previous and next neighbors can be optimal.
- Circular distance is computed as `min(d, n - d)` from linear gap `d`.