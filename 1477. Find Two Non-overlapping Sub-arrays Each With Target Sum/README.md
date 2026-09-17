# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Binary Search`, `Dynamic Programming`, `Sliding Window`

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

[LeetCode — 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

---

## Problem Summary

The problem requires finding two distinct, non-overlapping subarrays within a given integer array, each with a sum equal to a specified target value. The goal is to minimize the total length of these two subarrays. If no such pair exists, the function should return -1.

---

## Examples

### Example 1
**Input:** `arr = [3,2,2,4,3], target = 3`  
**Output:** `2`  
**Explanation:**
- Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

### Example 2
**Input:** `arr = [7,3,4,7], target = 7`  
**Output:** `2`  
**Explanation:**
- Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.

### Example 3
**Input:** `arr = [4,3,2,6,2,3,4], target = 6`  
**Output:** `-1`  
**Explanation:**
- We have only one sub-array of sum = 6.

---

## Intuition

The solution employs a sliding window approach to efficiently identify subarrays with the target sum. It maintains a 'best' array to store the minimum length of a valid subarray found up to each index. By iterating through the array and adjusting the window size, the algorithm can quickly determine if a second valid subarray exists that does not overlap with the first, allowing for the calculation of the minimum combined length.

---

## Approach

1. Initialize an array 'best' to track the minimum length of valid subarrays, setting all values to a large number (n + 1).
2. Use a sliding window with two pointers (left and right) to scan the array. Calculate the sum of elements within the window.
3. If the sum exceeds the target, shrink the window from the left until the sum is less than or equal to the target.
4. When a subarray with the target sum is found, update the 'best' array with the current minimum length and check if a previous non-overlapping subarray exists to calculate the total minimum length.
5. If no valid pair of subarrays is found during the iteration, return -1; otherwise, return the minimum sum of lengths.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the array once with a single loop, and the sliding window operations (shrinking and expanding) are performed in linear time relative to the data scanned, resulting in a total time complexity of O(n). |
| **Space** | `O(n)` — The space complexity is dominated by the 'best' array, which stores an integer value for each index in the input array, requiring O(n) space. Other variables are constant. |

---

## Code (C++)

```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, n + 1);

        int left = 0;
        int sum = 0;
        int ans = n + 1;
        int minLength = n + 1;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a subarray with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // If there is a previous non-overlapping subarray,
                // combine their lengths
                if (left > 0 && best[left - 1] != n + 1) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Keep the shortest valid subarray seen so far
                minLength = min(minLength, len);
            }

            best[right] = minLength;
        }

        if (ans == n + 1)
            return -1;

        return ans;
    }
};
```

---

## Key Takeaways

- The sliding window technique is highly effective for finding subarrays with specific sum constraints in linear time.
- Dynamic programming (memoization) can be used to store intermediate results (like the 'best' array) to avoid redundant calculations and improve efficiency.
- Careful management of window boundaries is crucial to ensure that the subarrays remain non-overlapping and valid.
