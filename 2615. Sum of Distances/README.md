# 2615. Sum of Distances

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Prefix Sum`

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

[LeetCode — 2615. Sum of Distances](https://leetcode.com/problems/sum-of-distances/)

---

## Problem Summary

You are given an integer array `nums`. Define `arr[i]` as the sum of `|i - j|` for all `j != i` where `nums[j] == nums[i]`.

If no other index has the same value as `nums[i]`, then `arr[i] = 0`.

Return the array `arr`.

---

## Examples

### Example 1
**Input:** `nums = [1,3,1,1,2]`  
**Output:** `[5,0,3,4,0]`  
**Explanation:**
- For index 0 (value 1): matching indices are 2 and 3, so `|0-2| + |0-3| = 5`.
- For index 1 (value 3): no other match, so `0`.
- For index 2 (value 1): matching indices are 0 and 3, so `|2-0| + |2-3| = 3`.
- For index 3 (value 1): matching indices are 0 and 2, so `|3-0| + |3-2| = 4`.
- For index 4 (value 2): no other match, so `0`.

### Example 2
**Input:** `nums = [0,5,3]`  
**Output:** `[0,0,0]`

---

## Intuition

For each value, only indices having that same value matter.

If those indices are sorted, for a current position we can split the total distance into:
- distance to all equal indices on the left
- distance to all equal indices on the right

Using prefix sums of indices lets us compute both parts in O(1) per position after grouping.

---

## Approach

1. Group indices by value using a hash map: `value -> list of indices`.
2. For each group of indices `v`:
   - Build prefix sums over `v`.
   - For each `v[i] = idx`, compute:
     - `left = idx * i - prefix[i]`
     - `right = (prefix[m] - prefix[i+1]) - idx * (m - i - 1)`
   - Set `ans[idx] = left + right`.
3. Return `ans`.

This avoids O(k^2) pairwise comparisons inside each group.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` overall (each index processed a constant number of times) |
| **Space** | `O(n)` for grouping and prefix sums |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group indices by value
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        // Step 2: process each value group with prefix sums
        for(auto &p : mp) {
            auto &v = p.second;
            int m = v.size();
            
            vector<long long> prefix(m + 1, 0);
            for(int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }
            
            for(int i = 0; i < m; i++) {
                long long idx = v[i];
                long long left = idx * i - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - idx * (m - i - 1);
                ans[idx] = left + right;
            }
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

- Grouping equal values turns the problem into independent index lists.
- Prefix sums help convert repeated absolute-distance sums into O(1) formulas.
- This pattern is the same core idea used in LeetCode 2121.
