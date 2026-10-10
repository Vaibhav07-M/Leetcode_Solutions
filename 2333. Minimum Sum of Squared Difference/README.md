# 2333. Minimum Sum of Squared Difference

**Difficulty:** `Medium`  
**Tags:** `Array`, `Binary Search`, `Greedy`, `Sorting`, `Heap (Priority Queue)`

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

[LeetCode — 2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

---

## Problem Summary

The problem requires minimizing the sum of squared differences between two integer arrays, nums1 and nums2, by applying a limited number of +1 or -1 modifications to each array. The goal is to find the optimal distribution of these modifications to reduce the overall squared difference as much as possible.

---

## Examples

### Example 1
**Input:** `nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0`  
**Output:** `579`  
**Explanation:**
- The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0.
- The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.

### Example 2
**Input:** `nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1`  
**Output:** `43`  
**Explanation:**
- One way to obtain the minimum sum of square difference is:
- Increase nums1[0] once.
- Increase nums2[2] once.
- The minimum of the sum of square difference will be:
- (2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
- Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

---

## Intuition

The solution employs a greedy strategy based on the observation that reducing larger differences yields a greater decrease in the total sum of squares compared to reducing smaller ones. By sorting the differences and iteratively decreasing the largest values using the available modification budget (k1 + k2), the algorithm efficiently minimizes the objective function.

---

## Approach

1. Calculate the absolute difference between corresponding elements of nums1 and nums2, storing them in a vector 'diff'.
2. Determine the maximum difference value ('maxDiff') to establish the upper bound for the difference distribution.
3. Create a frequency array 'countDiff' to track the number of occurrences of each difference value from 0 to maxDiff.
4. Iterate from the largest difference down to 1, using the combined modification budget (K = k1 + k2) to reduce the count of higher-order differences and increase the count of the next lower difference.
5. Once the budget is exhausted or all differences are minimized, compute the final sum of squared differences using the updated frequency distribution.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + maxDiff)` — The algorithm involves linear scans of the input arrays to compute differences and update frequencies, with a final pass over the difference range. The dominant factor is the size of the difference range (maxDiff), making the complexity linear relative to the data range and input size. |
| **Space** | `O(maxDiff)` — The primary space consumption is the 'countDiff' array, which requires storage proportional to the maximum difference value. Other vectors are linear in input size but are dominated by the maxDiff-sized frequency table. |

---

## Code (C++)

```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps             = min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps;
            countDiff[currDiff - 1] += countOps;
            K                       -= countOps;
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};
```

---

## Key Takeaways

- A greedy approach is effective for this minimization problem, prioritizing the reduction of larger errors.
- The use of a frequency array allows for efficient tracking and manipulation of the difference distribution.
- The solution successfully combines the modification budgets of both arrays into a single optimization step.
