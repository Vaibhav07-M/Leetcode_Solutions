# 2948. Make Lexicographically Smallest Array by Swapping Elements

**Difficulty:** `Medium`  
**Tags:** `Array`, `Union-Find`, `Sorting`

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

[LeetCode — 2948. Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)

---

## Problem Summary

You are given a 0-indexed array of positive integers nums and a positive integer limit.  
In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

---

## Examples

### Example 1
**Input:** `nums = [1,5,3,9,8], limit = 2`  
**Output:** `[1,3,5,8,9]`  
**Explanation:**
- Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
- We cannot obtain a lexicographically smaller array by applying any more operations.
- Note that it may be possible to get the same result by doing different operations.

### Example 2
**Input:** `nums = [1,7,6,18,2,1], limit = 3`  
**Output:** `[1,6,7,18,1,2]`  
**Explanation:**
- Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
- We cannot obtain a lexicographically smaller array by applying any more operations.

### Example 3
**Input:** `nums = [1,7,28,19,10], limit = 3`  
**Output:** `[1,7,28,19,10]`  
**Explanation:**
- [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.

---

## Intuition

The problem revolves around array, union-find, sorting. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — dominated by sorting |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        vector<int> ans = nums;

        int i = 0;

        while (i < n) {

            int j = i;

            // Find one connected group
            while (j + 1 < n &&
                   a[j + 1].first - a[j].first <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(a[k].second);
            }

            // Indices should be filled from left to right
            sort(indices.begin(), indices.end());

            // Values are already sorted
            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = a[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Union-Find, Sorting patterns often reduce an apparently complex problem to a few simple rules.
