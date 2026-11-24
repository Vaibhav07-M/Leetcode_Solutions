# 3411. Maximum Subarray With Equal Products

**Difficulty:** `Easy`  
**Tags:** `Array`, `Math`, `Sliding Window`, `Enumeration`, `Number Theory`

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

[LeetCode — 3411. Maximum Subarray With Equal Products](https://leetcode.com/problems/maximum-subarray-with-equal-products/)

---

## Problem Summary

The problem requires finding the longest subarray in a given array of positive integers where the product of the elements is equal to the product of their greatest common divisor (GCD) and least common multiple (LCM). The solution involves iterating through all possible subarrays and checking if this condition holds, while optimizing the search by breaking early when the product exceeds a calculated upper bound.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is that for a subarray to be product-equivalent, the relationship `prod(arr) = lcm(arr) * gcd(arr)` must be satisfied. The solution leverages the fact that the LCM of a set of numbers is always less than or equal to their product, and the GCD is always less than or equal to the smallest number. By calculating an upper bound for the product (`maxP`) based on the maximum element and the LCM of the entire array, the algorithm can efficiently prune the search space by stopping the iteration for a specific starting index once the product exceeds this bound.

---

## Approach

1. Calculate the maximum element (`mx`) and the least common multiple (`ml`) of the entire input array to establish an upper bound for the product (`maxP`).
2. Iterate through the array with a nested loop to consider all possible subarrays starting from each index `i`.
3. For each subarray, compute the product (`p`), GCD (`g`), and LCM (`l`) of the elements.
4. Check if the product is equal to the product of the GCD and LCM. If true, update the maximum subarray length (`ans`).
5. If the product exceeds the calculated upper bound (`maxP`), break the inner loop as no longer subarray can satisfy the condition.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — The algorithm uses a nested loop to iterate over all possible subarrays, resulting in a quadratic time complexity. The early termination based on the product bound helps reduce the number of operations but does not change the asymptotic bound. |
| **Space** | `O(1)` — The solution uses only a few integer variables to store the maximum length, product, GCD, and LCM, requiring constant space regardless of the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mx = 0, ml = 1;
        for (int x : nums) {
            mx = max(mx, x);
            ml = lcm(ml, x);
        }

        long long maxP = (long long) ml * mx;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long p = 1, g = 0, l = 1;
            for (int j = i; j < n; ++j) {
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                }
                if (p > maxP) {
                    break;
                }
            }
        }
        return ans;
    }
};
```

---

## Key Takeaways

- The problem relies on the mathematical relationship between the product, GCD, and LCM of a set of numbers.
- An effective optimization strategy is to calculate an upper bound for the target value and prune the search space when that bound is exceeded.
- The solution demonstrates a brute-force approach to finding a maximum subsequence, which is acceptable here due to the constraints on the input size.
