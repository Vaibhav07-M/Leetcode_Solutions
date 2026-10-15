# 2913. Subarrays Distinct Element Sum of Squares I

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`, `Binary Indexed Tree`, `Segment Tree`

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

[LeetCode — 2913. Subarrays Distinct Element Sum of Squares I](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)

---

## Problem Summary

The problem requires calculating the sum of the squares of distinct element counts for all possible subarrays of a given integer array. A subarray's distinct count is the number of unique values it contains. The goal is to iterate through all contiguous segments of the array, determine the number of distinct elements in each, square that count, and sum these squared values to produce the final result.

---

## Examples

### Example 1
**Input:** `nums = [1,2,1]`  
**Output:** `15`  
**Explanation:**
- Six possible subarrays are:
- [1]: 1 distinct value
- [2]: 1 distinct value
- [1]: 1 distinct value
- [1,2]: 2 distinct values
- [2,1]: 2 distinct values
- [1,2,1]: 2 distinct values
- The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

### Example 2
**Input:** `nums = [1,1]`  
**Output:** `3`  
**Explanation:**
- Three possible subarrays are:
- [1]: 1 distinct value
- [1]: 1 distinct value
- [1,1]: 1 distinct value
- The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.

---

## Intuition

The solution employs a brute-force approach to directly compute the distinct counts. It uses nested loops to define every possible subarray (from index i to j) and an unordered set to track the unique elements encountered within each window. As the window expands, the set size is updated, and its square is added to the total sum. This method ensures that every subarray is examined and its contribution to the sum is accurately calculated.

---

## Approach

1. Initialize a variable 'ans' to store the total sum of squared distinct counts.
2. Iterate through the array with an outer loop (index 'i') to define the start of each subarray.
3. For each starting index 'i', initialize an empty unordered set 'st' to track distinct elements.
4. Use an inner loop (index 'j') to expand the subarray window from 'i' to 'j'.
5. In each iteration of the inner loop, insert the current element 'nums[j]' into the set.
6. Calculate the distinct count 'count' as the size of the set, square it, and add it to 'ans'.
7. Continue expanding the window until the end of the array is reached, then move to the next starting index 'i'.
8. Return the final accumulated sum 'ans'.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^3)` — The algorithm features three nested loops: one for the starting index, one for the ending index, and an implicit loop within the set insertion operation. This results in a cubic time complexity relative to the size of the input array. |
| **Space** | `O(n)` — The space complexity is dominated by the unordered set used to store distinct elements. In the worst case (where all elements are distinct), the set will contain up to 'n' elements, leading to a linear space requirement. |

---

## Code (C++)

```cpp

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                int count = st.size();
                ans += count * count;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- This solution provides a straightforward, albeit inefficient, method to calculate the sum of squared distinct counts by explicitly enumerating all subarrays.
- The use of an unordered set is effective for quickly determining the number of unique elements within a specific window.
- While the logic is correct, the cubic time complexity makes this approach unsuitable for large datasets, suggesting that more advanced algorithms (like hashing or dynamic programming) would be necessary for optimization.
