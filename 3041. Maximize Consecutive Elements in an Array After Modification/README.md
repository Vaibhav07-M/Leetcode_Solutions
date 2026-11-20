# 3041. Maximize Consecutive Elements in an Array After Modification

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Sorting`

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

[LeetCode — 3041. Maximize Consecutive Elements in an Array After Modification](https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/)

---

## Problem Summary

The problem requires selecting a subset of elements from a given array such that they form a consecutive sequence when sorted. Before selection, you can increase the value of any element by at most 1. The goal is to maximize the number of elements in the selected subset.

---

## Examples

### Example 1
**Input:** `nums = [2,1,5,1,1]`  
**Output:** `3`  
**Explanation:**
- We can increase the elements at indices 0 and 3. The resulting array is nums = [3,1,5,2,1].
- We select the elements [3,1,5,2,1] and we sort them to obtain [1,2,3], which are consecutive.
- It can be shown that we cannot select more than 3 consecutive elements.

### Example 2
**Input:** `nums = [1,4,7,10]`  
**Output:** `1`  
**Explanation:**
- The maximum consecutive elements that we can select is 1.

---

## Intuition

The solution uses a dynamic programming approach with memoization. The key insight is to consider two possibilities for each element: either use it as-is (increment = 0) or increment it by 1. For each state (index and increment), the algorithm searches for the next element that continues the sequence and recursively calculates the maximum length achievable from that point.

---

## Approach

1. Sort the input array to facilitate binary search for the next element in the sequence.
2. Define a recursive function 'solve' that takes the current index 'i' and the increment 'inc' as parameters.
3. Within 'solve', calculate the current value 'currVal' based on the index and increment.
4. Search for the next element in the sequence (currVal + 1) using a binary search function 'findMethod'. If found, recursively call 'solve' with the new index and increment 0.
5. Alternatively, search for the current value 'currVal' and recursively call 'solve' with the new index and increment 1.
6. Store the maximum length found for each state in a memoization table to avoid redundant calculations.
7. Iterate through the array, calling 'solve' for each index with both increment options (0 and 1), and return the maximum value found.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — The dominant factor is the sorting step, which takes O(n log n). The recursive calls are optimized by memoization, preventing exponential growth and keeping the overall complexity linear-logarithmic. |
| **Space** | `O(n)` — The space complexity is determined by the memoization table, which has a size of n x 2 (for index and increment). This linear space is used to store the results of sub-problems. |

---

## Code (C++)

```cpp
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target) {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);

        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {

        if(memo[i][inc] != -1) {
            return memo[i][inc];
        }

        int currVal = nums[i] + inc; //inc = 0/1
        int len = 1;

        //1st Option = find (currVal+1)
        int j = findMethod(nums, i+1, currVal+1);
        if(j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        //2nd Option = find (currVal) and then inc by +1
        j = findMethod(nums, i+1, currVal);
        if(j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(begin(nums), end(nums));

        memo.assign(n+1, vector<int>(2, -1));

        int result = 1;
        for(int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};
```

---

## Key Takeaways

- The problem demonstrates the use of dynamic programming with memoization to solve a combinatorial optimization problem.
- Binary search is effectively used to quickly locate the next element in the sequence, significantly improving the efficiency of the algorithm.
- The solution highlights the importance of considering multiple states (in this case, the 'increment' variable) to explore all possible configurations of the data.
