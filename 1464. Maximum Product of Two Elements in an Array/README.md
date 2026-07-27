# 1464. Maximum Product of Two Elements in an Array

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

[LeetCode – 1464. Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

---

## Problem Summary

Given an integer array `nums`, choose two **different indices** `i` and `j` and maximize:

```text
(nums[i] - 1) × (nums[j] - 1)
```

Return the maximum possible value.

---

## Examples

### Example 1

**Input**

```text
nums = [3,4,5,2]
```

**Output**

```text
12
```

**Explanation**

Choose `4` and `5`:

```text
(4 - 1) × (5 - 1) = 3 × 4 = 12
```

---

### Example 2

**Input**

```text
nums = [1,5,4,5]
```

**Output**

```text
16
```

**Explanation**

Choose the two `5`s:

```text
(5 - 1) × (5 - 1) = 4 × 4 = 16
```

---

### Example 3

**Input**

```text
nums = [3,7]
```

**Output**

```text
12
```

---

## Intuition

Since every element is reduced by `1`, the maximum product is obtained by selecting the **two largest numbers** in the array.

Sorting the array makes these elements easy to access.

---

## Approach

1. Sort the array in ascending order.
2. Let the last two elements be the largest numbers.
3. Compute:

```text
(nums[n-1] - 1) × (nums[n-2] - 1)
```

4. Return the result.

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
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
```

---

## Key Takeaways

- The product increases with larger numbers, so only the two largest elements matter.
- Sorting places the two maximum values at the end of the array.
- After sorting, compute `(largest - 1) × (secondLargest - 1)`.
- The solution is concise and runs in **O(n log n)** time due to sorting.