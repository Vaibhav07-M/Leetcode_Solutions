# 1846. Maximum Element After Decreasing and Rearranging

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Sorting`

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

[LeetCode — 1846. Maximum Element After Decreasing and Rearranging](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

---

## Problem Summary

You are given an array `arr` of positive integers.

You may perform the following operations any number of times:

- Rearrange the elements in any order.
- Decrease any element to any smaller positive integer.

After performing the operations, the array must satisfy:

- The first element is `1`.
- The absolute difference between every pair of adjacent elements is at most `1`.

Return the **maximum possible value** of the largest element after the rearrangement.

---

## Examples

### Example 1

**Input:** `arr = [2,2,1,2,1]`  

**Output:** `2`

**Explanation:**

A valid arrangement is:

```text
[1,2,2,2,1]
```

The maximum element is `2`.

### Example 2

**Input:** `arr = [100,1,1000]`  

**Output:** `3`

**Explanation:**

One possible arrangement is:

```text
[1,2,3]
```

The maximum element becomes `3`.

### Example 3

**Input:** `arr = [1,2,3,4,5]`  

**Output:** `5`

---

## Intuition

To maximize the largest element, we should first sort the array.

Once sorted, the first element must always become `1`. Every following element can be at most one greater than the previous element. If an element is larger than this limit, we simply decrease it.

This greedy strategy keeps every value as large as possible while satisfying the required conditions.

---

## Approach

1. Sort the array in ascending order.
2. Set the first element to `1`.
3. Traverse the remaining elements:
   - Replace each element with:
     - `min(arr[i], arr[i - 1] + 1)`
   - This guarantees the adjacent difference is at most `1`.
4. Return the last element, which is the maximum achievable value.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — due to sorting |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};
```

---

## Key Takeaways

- Sort the array before making any changes.
- The first element must always be `1`.
- Greedily limit each element to at most `previous + 1`.
- Keeping each value as large as possible maximizes the final element.
- The last element after processing is the answer.