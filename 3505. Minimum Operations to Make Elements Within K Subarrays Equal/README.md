# 3505. Minimum Operations to Make Elements Within K Subarrays Equal

**Difficulty:** `Hard`  
**Tags:** `Array`, `Hash Table`, `Math`, `Dynamic Programming`, `Sliding Window`, `Heap (Priority Queue)`

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

[LeetCode — 3505. Minimum Operations to Make Elements Within K Subarrays Equal](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)

---

## Problem Summary

The problem requires finding the minimum number of operations to create k non-overlapping subarrays of size x where all elements are equal. Each operation can increase or decrease an element by 1. The solution uses a combination of sliding window, multiset balancing, and dynamic programming to efficiently compute the minimum operations for each subarray and then find the optimal global solution.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to first compute the minimum operations required for any given subarray of size x using a sliding window and a balanced multiset. This allows for efficient calculation of the 'cost' to make a specific window uniform. Then, a dynamic programming approach is used to select the optimal k subarrays from the available options, ensuring they are non-overlapping and minimize the total operation count.

---

## Approach

1. Initialize a sliding window of size x and two multisets (left and right) to store the elements. The left multiset stores elements less than or equal to the median, and the right multiset stores elements greater than the median.
2. As the window slides across the array, balance the multisets to ensure the median is correctly identified. Calculate the minimum operations needed to make the current window uniform (minOpsSubarray[i]) based on the distance of elements from the median.
3. Once the subarray costs are calculated, use a recursive dynamic programming function (solve) to determine the optimal way to select k non-overlapping subarrays. The function explores options to either start a new subarray at index i or skip the index, minimizing the total operation count.
4. The final result is obtained by calling solve(0, 0), which returns the minimum operations needed to achieve the desired configuration.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The sliding window phase requires iterating through the array (O(n)) while performing multiset operations (O(log n)), resulting in O(n log n). The recursive DP phase has a complexity of O(k * n), which is dominated by the window phase for typical input sizes. |
| **Space** | `O(n + k)` — Space is used for the minOpsSubarray array (O(n)) and the memoization table for the DP function (O(k * n)), where k is the number of subarrays. The multisets also contribute to space, but their size is bounded by the window size x. |

---

## Code (C++)

```cpp
class Solution {
public:
    int n, x, k;

    long long minOpsSubarray[100001];
    //minOpsSubarray[i] = min operations required to make all elements of subarray[i...i+x-1] as equal

    long long memo[16][100001];

    long long solve(int count, int i) {
        if(count == k)
            return 0;
        
        int subArraysNeeded = k-count;
        int elementsNeeded  = subArraysNeeded*x;
        int lastIndex       = i + elementsNeeded - 1;

        if(lastIndex >= n) {
            return 1e16; //10^16
        }

        if(memo[count][i] != -1) {
            return memo[count][i];
        }

        //Took ith index as start of a subarray
        long long result = minOpsSubarray[i] + solve(count+1, i+x);


        //Skip index i
        result = min(result, solve(count, i+1));

        return memo[count][i] = result;

    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(memo, -1, sizeof(memo));

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            //Balancing
            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            //If we have found the subarray of size x
            if(j-i+1 == x) {
                long long median = *left.rbegin();
                long long leftSize = left.size();
                long long rightSize = right.size();

                minOpsSubarray[i] = (leftSize * median - leftSum) + (rightSum - rightSize*median);

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0); //recursion
    }
};
```

---

## Key Takeaways

- Using a balanced multiset allows for efficient computation of the median and the cost to make a subarray uniform.
- The combination of a sliding window for local optimization and dynamic programming for global selection is a powerful strategy for this type of problem.
- The solution effectively handles the constraint of non-overlapping subarrays by tracking the start indices in the recursive function.
