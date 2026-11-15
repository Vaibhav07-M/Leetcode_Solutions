# 1524. Number of Sub-arrays With Odd Sum

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Dynamic Programming`, `Prefix Sum`

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

[LeetCode — 1524. Number of Sub-arrays With Odd Sum](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

---

## Problem Summary

The problem requires counting the number of subarrays in a given integer array that have an odd sum. The solution utilizes a prefix sum approach combined with state tracking to efficiently determine the number of valid subarrays without needing to calculate the sum of every possible subarray explicitly.

---

## Examples

### Example 1
**Input:** `arr = [1,3,5]`  
**Output:** `4`  
**Explanation:**
- All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
- All sub-arrays sum are [1,4,9,3,8,5].
- Odd sums are [1,9,3,5] so the answer is 4.

### Example 2
**Input:** `arr = [2,4,6]`  
**Output:** `0`  
**Explanation:**
- All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
- All sub-arrays sum are [2,6,12,4,10,6].
- All sub-arrays have even sum and the answer is 0.

### Example 3
**Input:** `arr = [1,2,3,4,5,6,7]`  
**Output:** `16`  

---

## Intuition

The core insight is to track the parity of the prefix sum. By maintaining two counters (one for even sums and one for odd sums) and updating them as we iterate through the array, we can determine how many subarrays have an odd sum by checking the parity of the current sum against the accumulated counts. The result is the sum of the counts of the opposite parity at each step.

---

## Approach

1. Initialize two counters, 'even' and 'odd', to track the number of prefix sums that are even and odd, respectively. Set 'even' to 1 (for the empty subarray) and 'odd' to 0.
2. Iterate through the array, updating the current sum ('sum') by adding the current element.
3. If the current sum is even, add the current count of odd sums ('odd') to the answer, as these represent the number of subarrays ending at this point with an odd sum. Then, increment the 'even' counter.
4. If the current sum is odd, add the current count of even sums ('even') to the answer. Then, increment the 'odd' counter.
5. The final answer is the total number of subarrays with an odd sum, which is the sum of the counts of the opposite parity at each step.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the array once, performing constant-time operations (addition and comparison) at each step. Therefore, the time complexity is linear relative to the length of the input array. |
| **Space** | `O(1)` — The space complexity is constant because the solution uses a fixed number of variables (counters and a sum) regardless of the size of the input array. No additional data structures or arrays are required to store intermediate results. |

---

## Code (C++)

```cpp

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;

        int sum = 0;

        for (int num : arr) {
            sum += num;

            if (sum % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } 
            else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- This problem demonstrates the power of prefix sums in analyzing subarray properties. By tracking the parity of the sum, we can efficiently count subarrays with specific characteristics without exhaustive enumeration.
- The solution highlights the importance of state tracking. The 'even' and 'odd' counters serve as a memory of the distribution of sums seen so far, allowing for quick decision-making in the current iteration.
