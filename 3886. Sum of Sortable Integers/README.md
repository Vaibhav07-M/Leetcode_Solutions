# 3886. Sum of Sortable Integers

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Sorting`, `Enumeration`

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

[LeetCode — 3886. Sum of Sortable Integers](https://leetcode.com/problems/sum-of-sortable-integers/)

---

## Problem Summary

The problem requires finding the sum of all integers k that divide the array length n and allow the array to be sorted via cyclic rotations of subarrays of size k. The solution iterates through potential divisors, checking if each is a valid 'sortable integer' by verifying that the array can be partitioned and rotated to achieve a non-decreasing order.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is that a valid sortable integer k must allow the array to be partitioned into subarrays where each subarray can be rotated to fit into the global sorted order. The solution checks this by ensuring that within each subarray, there are no more than one 'descent' (a pair of adjacent elements where the second is smaller), and that the maximum of a previous subarray does not exceed the minimum of the next, which would prevent a valid global sort.

---

## Approach

1. Iterate through all possible divisors k of the array length n (up to the square root of n, since larger divisors are redundant).
2. For each divisor k, use the 'canSort' function to check if the array can be sorted. This involves partitioning the array into subarrays of size k.
3. In 'canSort', for each subarray, count the number of 'descents' (adjacent elements where the second is smaller). If there are more than one descent, the subarray cannot be rotated to a valid state.
4. Also in 'canSort', track the maximum value of each subarray. If the maximum of a previous subarray is greater than the minimum of the current subarray, the global sort is impossible.
5. If 'canSort' returns true for a given k, add k to the total sum of sortable integers. Also, check the corresponding divisor (n/k) if it is different from k, as it is also a valid divisor to check.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * sqrt(n))` — The outer loop iterates over approximately sqrt(n) divisors. The inner 'canSort' function processes the entire array of length n, resulting in a total time complexity of O(n * sqrt(n)). |
| **Space** | `O(1)` — The solution uses a constant amount of extra space for variables like 'prevMax', 'mn', and 'mx', regardless of the input array size. |

---

## Code (C++)

```cpp

class Solution {
public:
    bool canSort(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = -1;

        for (int start = 0; start < n; start += k) {
            int mn = INT_MAX, mx = INT_MIN;
            int descents = 0;

            for (int j = 0; j < k; j++) {
                int curr = nums[start + j];
                int next = nums[start + (j + 1) % k];

                if (curr > next)
                    descents++;

                mn = min(mn, curr);
                mx = max(mx, curr);
            }

            if (descents > 1)
                return false;

            if (start > 0 && prevMax > mn)
                return false;

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k != 0)
                continue;

            if (canSort(nums, k))
                ans += k;

            int other = n / k;

            if (other != k && canSort(nums, other))
                ans += other;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- The problem combines concepts of divisibility, array partitioning, and cyclic permutations to determine sortability.
- The 'canSort' function provides a robust check by ensuring local order (no more than one descent) and global compatibility (max < min between subarrays).
- The efficiency of the solution relies on only checking up to the square root of the array length, as larger divisors are symmetric to smaller ones.
