# 3702. Longest Subsequence With Non-Zero Bitwise XOR

**Difficulty:** `Medium`  
**Tags:** `Array`, `Bit Manipulation`, `XOR`

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

[LeetCode — 3702. Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/)

---

## Problem Summary

You are given an integer array `nums`.

Return the length of the longest subsequence in `nums` whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

---

## Examples

### Example 1
**Input:** `nums = [1,2,3]`  
**Output:** `2`  
**Explanation:**  
One longest subsequence is `[2, 3]`. The bitwise XOR is computed as `2 XOR 3 = 1`, which is non-zero.

### Example 2
**Input:** `nums = [2,3,4]`  
**Output:** `3`  
**Explanation:**  
The longest subsequence is `[2, 3, 4]`. The bitwise XOR is computed as `2 XOR 3 XOR 4 = 5`, which is non-zero.

---

## Intuition

The key insight is that the XOR of the entire array determines the answer:
- If the XOR of all elements is non-zero, we can take the entire array as the subsequence.
- If the XOR of all elements is zero, we need to remove at least one element to make the XOR non-zero.
- If all elements are zero, no non-zero XOR subsequence exists.

---

## Approach

1. **Compute the XOR of all elements** in the array.
2. **Check if there's at least one non-zero element** in the array.
3. **Return the result based on the XOR value:**
   - If total XOR ≠ 0: return `n` (the entire array works)
   - If total XOR = 0 and there's at least one non-zero element: return `n - 1` (remove one element)
   - If all elements are zero: return `0` (no valid subsequence)

This works because:
- XOR of all elements being non-zero means the whole array is a valid subsequence.
- XOR being zero means we need to exclude at least one element. Since there's at least one non-zero element, removing it will make the XOR non-zero (because 0 XOR x = x ≠ 0).
- If all elements are zero, any subsequence will have XOR = 0.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the array |
| **Space** | `O(1)` — constant extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            x ^= num;
            if (num != 0)
                hasNonZero = true;
        }

        if (x != 0)
            return n;

        if (hasNonZero)
            return n - 1;

        return 0;
    }
};
```

---

## Key Takeaways

- The XOR of the entire array determines whether we can use all elements.
- If total XOR is zero, removing any non-zero element makes it non-zero.
- Edge case: all zeros → no valid subsequence exists.
- Single pass solution with O(1) space.