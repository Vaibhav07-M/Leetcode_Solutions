# 3718. Smallest Missing Multiple of K

**Difficulty:** `Easy`  
**Tags:** `Array`, `Hash Table`

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

[LeetCode — 3718. Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/)

---

## Problem Summary

The problem asks to find the smallest positive multiple of a given integer k that is missing from an array of integers. The input array and the integer k are provided, and the goal is to return the smallest multiple of k that does not exist in the array. The array can contain any integers, not necessarily multiples of k. The problem requires finding the smallest missing multiple of k in the array.

---

## Examples

_No examples provided._

---

## Intuition

The solution uses a simple iterative approach to find the smallest missing multiple of k. It starts from the first multiple of k and checks if it exists in the array. If it does, it moves on to the next multiple. If it doesn't, it returns that multiple as the smallest missing one. This approach relies on the fact that the multiples of k are evenly spaced, so checking each multiple in order is sufficient to find the smallest missing one.

---

## Approach

1. Start from the first multiple of k. Check if the current multiple exists in the array by iterating over the array. If the multiple is found, move on to the next multiple by adding k to the current multiple. If the multiple is not found, return it as the smallest missing multiple.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n*m)` — where n is the size of the input array and m is the number of multiples of k checked before finding the smallest missing one |
| **Space** | `O(1)` — The solution uses a constant amount of space to store the current multiple and the found flag |

---

## Code (C++)

```cpp
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = k;

        while (true) {
            bool found = false;

            for (int num : nums) {
                if (num == multiple) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return multiple;

            multiple += k;
        }
    }
};
```

---

## Key Takeaways

- The solution demonstrates a simple iterative approach to finding the smallest missing multiple of k in an array. It highlights the importance of checking each multiple in order to ensure that the smallest missing one is found. The solution also shows how to use a flag to indicate whether a multiple is found in the array.
