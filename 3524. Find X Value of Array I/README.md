# 3524. Find X Value of Array I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Dynamic Programming`

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

[LeetCode — 3524. Find X Value of Array I](https://leetcode.com/problems/find-x-value-of-array-i/)

---

## Problem Summary

The problem requires finding the number of ways to remove a non-overlapping prefix and suffix from an array of positive integers such that the product of the remaining elements leaves a specific remainder when divided by a given modulus k. The solution uses dynamic programming to count the number of subarrays ending at each index with a particular product remainder, and then sums these counts to determine the total number of valid operations for each possible remainder.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to use dynamic programming to track the product remainders of subarrays. By iterating through the array and updating the count of subarrays with each possible remainder, we can efficiently determine how many valid operations exist for each target remainder. The final answer is the sum of these counts across all indices, representing the total number of ways to achieve the desired product remainder after removing the prefix and suffix.

---

## Approach

1. Initialize a vector 'dp' of size k to store the count of subarrays ending at the previous index with each product remainder. Initialize a vector 'ans' of size k to store the final results.
2. Iterate through each number 'num' in the input array 'nums'.
3. For each number, create a new vector 'newdp' to store the updated counts. Set 'newdp[num % k]' to 1, representing a new subarray starting with just this number.
4. Iterate through the current 'dp' array. For each non-zero count, update the 'newdp' array by adding the count to the index corresponding to the new product remainder (calculated as (current_remainder * num) % k).
5. Add the values from 'newdp' to the 'ans' vector, as these represent the valid operations for this index.
6. Update the 'dp' array to be the 'newdp' array for the next iteration.
7. Return the 'ans' vector, which contains the total number of valid operations for each possible remainder.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * k^2)` — The time complexity is dominated by the nested loops. The outer loop runs over the n elements of the array. The inner loop, which updates the 'newdp' array, runs over the k possible remainders. Additionally, there is a loop to sum the results into the 'ans' array, which also runs over k. This results in a total complexity of O(n * k^2). |
| **Space** | `O(k)` — The space complexity is determined by the size of the 'dp' and 'newdp' arrays, which are both of size k. The 'ans' array is also of size k. There are no other significant data structures used, so the total space complexity is O(k). |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            int x = num % k;

            // Start a new subarray with only num
            newdp[x]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * x) % k;
                    newdp[newRemainder] += dp[r];
                }
            }

            // All subarrays ending here contribute to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            dp = newdp;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- This problem demonstrates the use of dynamic programming to solve a combinatorial counting problem involving modular arithmetic.
- The key to the solution is maintaining a state vector that tracks the number of subarrays with each possible product remainder, allowing for efficient updates as new elements are added to the subarray.
- The final answer is obtained by summing the counts of valid subarrays across all indices, which corresponds to the total number of ways to perform the specified operation.
