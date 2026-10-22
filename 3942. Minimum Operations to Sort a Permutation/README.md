# 3942. Minimum Operations to Sort a Permutation

**Difficulty:** `Medium`  
**Tags:** `Array`

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

[LeetCode — 3942. Minimum Operations to Sort a Permutation](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/)

---

## Problem Summary

The problem requires sorting a permutation of integers using only two operations: reversing the entire array and rotating it left by one position. The goal is to determine the minimum number of operations needed to achieve a sorted order, or to identify if sorting is impossible with the given constraints.

---

## Examples

_No examples provided._

---

## Intuition

The solution relies on identifying specific patterns in the permutation. It checks if the array is already sorted, then examines whether the elements follow a cyclic ascending or descending order. If a cyclic pattern is detected, the algorithm calculates the number of rotations required to align the first element with its correct position (0), taking into account the possibility of reversing the array to minimize the total number of operations.

---

## Approach

1. Check if the array is already sorted; if so, return 0 operations.
2. Determine the starting value 'c' (the first element of the permutation).
3. Verify if the elements are in a cyclic ascending order (e.g., [0, 1, 2, 3] or [2, 3, 0, 1]). If true, calculate the number of rotations 'k' needed to move the first element to index 0. The total operations are the minimum of 'k' (rotate) and 'n - k + 2' (reverse and rotate).
4. If not ascending, check for a cyclic descending order. If true, calculate the rotation 'd' to align the first element. The total operations are the minimum of 'd' and 'n - d', plus 1 for the initial reverse.
5. If neither pattern is found, return -1, indicating the array cannot be sorted with the given operations.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The algorithm iterates through the array once to check for the sorted condition and twice more to verify the cyclic patterns, resulting in a linear time complexity relative to the number of elements. |
| **Space** | `O(1)` — The solution uses only a few integer variables (n, c, k, d) and boolean flags, requiring no additional data structures or memory proportional to the input size. |

---

## Code (C++)

```cpp

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Already sorted
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted)
            return 0;

        int c = nums[0];

        // Check ascending cyclic order
        bool ascending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (c + i) % n) {
                ascending = false;
                break;
            }
        }

        if (ascending) {
            int k = (n - c) % n;
            return min(k, n - k + 2);
        }

        // Check descending cyclic order
        bool descending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (c - i + n) % n) {
                descending = false;
                break;
            }
        }

        if (descending) {
            int d = (c + 1) % n;
            return min(d, n - d) + 1;
        }

        return -1;
    }
};
```

---

## Key Takeaways

- The problem demonstrates the importance of recognizing cyclic permutations and their properties in combinatorial optimization.
- The solution effectively uses the periodicity of the rotation operation to calculate the most efficient path to the sorted state.
- The inclusion of the reverse operation provides a critical optimization, allowing the algorithm to choose the shortest route (clockwise or counterclockwise) to the target configuration.
