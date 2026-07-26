# 628. Maximum Product of Three Numbers

**Difficulty:** `Easy`  
**Tags:** `Array`, `Sorting`, `Greedy`, `Math`

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

[LeetCode – 628. Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

---

## Problem Summary

Given an integer array `nums`, return the maximum possible product that can be obtained by multiplying any **three** numbers from the array.

The array may contain positive, negative, and zero values.

---

## Examples

### Example 1

**Input**

```text
nums = [1,2,3]
```

**Output**

```text
6
```

---

### Example 2

**Input**

```text
nums = [1,2,3,4]
```

**Output**

```text
24
```

---

### Example 3

**Input**

```text
nums = [-1,-2,-3]
```

**Output**

```text
-6
```

---

## Intuition

After sorting the array, there are only **two possible candidates** for the maximum product:

1. The product of the **three largest numbers**.
2. The product of the **two smallest (most negative) numbers** and the **largest positive number**.

The second case is important because multiplying two negative numbers produces a positive value, which can result in a larger product.

---

## Approach

1. Sort the array in non-decreasing order.
2. Compute:
   - `nums[n-1] × nums[n-2] × nums[n-3]`
   - `nums[0] × nums[1] × nums[n-1]`
3. Return the larger of the two products.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n log n)` |
| **Space** | `O(1)` *(excluding the sorting algorithm's internal space)* |

---

## Code (C++)

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[0] * nums[1] * nums[n - 1]);
    }
};
```

---

## Key Takeaways

- Sorting makes it easy to identify the largest and smallest values.
- The maximum product can come from either:
  - the **three largest numbers**, or
  - the **largest number and the two smallest (most negative) numbers**.
- Checking only these two cases guarantees the optimal answer.
- The solution is simple and runs in **O(n log n)** time due to sorting.