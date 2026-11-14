# 3364. Minimum Positive Sum Subarray 

**Difficulty:** `Easy`  
**Tags:** `Array`, `Sliding Window`, `Prefix Sum`

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

[LeetCode — 3364. Minimum Positive Sum Subarray ](https://leetcode.com/problems/minimum-positive-sum-subarray/)

---

## Problem Summary

The problem requires finding the minimum sum of a subarray within a given integer array, where the subarray's length is constrained between l and r, and its sum must be greater than zero. The solution employs a brute-force approach to iterate through all possible subarrays, calculating their sums and checking against the constraints to determine the minimum positive sum.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to systematically explore every potential subarray combination. By nesting two loops—one for the starting index (i) and one for the ending index (j)—the algorithm can compute the sum of each contiguous segment. The condition checks ensure that only valid subarrays (length within bounds and positive sum) are considered for the minimum calculation.

---

## Approach

1. Initialize a variable 'ans' to store the minimum sum, starting at a large value (INT_MAX).
2. Iterate through the array with an outer loop (index i) representing the start of the subarray.
3. For each starting index, use an inner loop (index j) to extend the subarray and calculate its cumulative sum.
4. Check if the current subarray length is within the specified range [l, r] and if the sum is positive.
5. If the conditions are met, update 'ans' with the smaller of the current sum and the previously stored minimum.
6. After all iterations, return 'ans' if it was updated; otherwise, return -1 to indicate no valid subarray was found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — The algorithm uses two nested loops to iterate over all possible subarray combinations, resulting in a quadratic time complexity relative to the size of the input array. |
| **Space** | `O(1)` — The solution requires only a constant amount of extra space for variables such as 'sum' and 'ans', regardless of the input size. |

---

## Code (C++)

```cpp

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                int len = j - i + 1;

                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

---

## Key Takeaways

- This brute-force method is effective for small datasets but may be inefficient for larger arrays due to its O(n^2) complexity.
- The problem constraints (subarray length and positive sum) are explicitly checked during the iteration to filter out invalid results.
- The use of INT_MAX as an initial value for 'ans' provides a robust way to identify if no valid subarray was found.
