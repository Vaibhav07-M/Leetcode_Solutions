# 1385. Find the Distance Value Between Two Arrays

**Difficulty:** `Easy`  
**Tags:** `Array`, `Two Pointers`, `Binary Search`, `Sorting`

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

[LeetCode — 1385. Find the Distance Value Between Two Arrays](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/)

---

## Problem Summary

The problem requires calculating the 'distance value' between two integer arrays, arr1 and arr2. This value represents the number of elements in arr1 that are not within a specified distance d of any element in arr2. The solution iterates through each element in arr1, checking if it is valid (i.e., not close to any arr2 element) and counting the valid ones.

---

## Examples

### Example 1
**Input:** `arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2`  
**Output:** `2`  
**Explanation:**
- For arr1[0]=4 we have:
- |4-10|=6 > d=2
- |4-9|=5 > d=2
- |4-1|=3 > d=2
- |4-8|=4 > d=2
- For arr1[1]=5 we have:
- |5-10|=5 > d=2
- |5-9|=4 > d=2
- |5-1|=4 > d=2
- |5-8|=3 > d=2
- For arr1[2]=8 we have:
- |8-10|=2 <= d=2
- |8-9|=1 <= d=2
- |8-1|=7 > d=2
- |8-8|=0 <= d=2

### Example 2
**Input:** `arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3`  
**Output:** `2`  

### Example 3
**Input:** `arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6`  
**Output:** `1`  

---

## Intuition

The core insight is to define a 'valid' element as one that has no 'neighbors' in the other array within the given distance threshold. The solution employs a brute-force approach, checking every pair of elements between the two arrays to determine if they are too close, which invalidates the current arr1 element.

---

## Approach

1. Initialize a counter variable 'count' to zero.
2. Iterate through each element 'i' in the first array (arr1).
3. For each element in arr1, set a boolean flag 'valid' to true.
4. Iterate through the second array (arr2) to check for proximity. If the absolute difference between arr1[i] and arr2[j] is less than or equal to d, set 'valid' to false and break the inner loop.
5. If the element in arr1 is valid (no close neighbors in arr2), increment the 'count'.
6. Return the final count of valid elements.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m * n)` — The solution uses two nested loops: one to iterate over arr1 (m elements) and another to iterate over arr2 (n elements) for each arr1 element. This results in a total of approximately m * n operations, making the time complexity quadratic. |
| **Space** | `O(1)` — The space complexity is constant because the solution only uses a few integer variables (count, i, j, d) and a boolean flag. There are no large data structures or recursive calls that would increase space usage based on the input size. |

---

## Code (C++)

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2, int d) {

        int count = 0;

        // Check every element of arr1
        for (int i = 0; i < arr1.size(); i++) {

            bool valid = true;

            // Compare with every element of arr2
            for (int j = 0; j < arr2.size(); j++) {

                if (abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            // Count only valid elements
            if (valid) {
                count++;
            }
        }

        return count;
    }
};
```

---

## Key Takeaways

- The problem involves a pairwise comparison between two sets of data to determine mutual exclusion based on a distance metric.
- The brute-force method of nested loops is effective here because the arrays are relatively small (max 1000 elements), but it would be inefficient for much larger datasets.
- The concept of 'distance value' is a specific application of set difference or exclusion, where an element is considered 'valid' if it is sufficiently isolated from a specific subset.
