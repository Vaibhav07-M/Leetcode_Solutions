# 396. Rotate Function

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Dynamic Programming`

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

[LeetCode — 396. Rotate Function](https://leetcode.com/problems/rotate-function/)

---

## Problem Summary

You are given an integer array `nums` of length `n`.

For each rotation `k`, let `arrk` be the array obtained by rotating `nums` clockwise by `k` positions. The rotation function is defined as:

`F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]`

Return the maximum value among `F(0), F(1), ..., F(n - 1)`.

---

## Examples

### Example 1
**Input:** `nums = [4,3,2,6]`  
**Output:** `26`  
**Explanation:**
- `F(0) = 25`
- `F(1) = 16`
- `F(2) = 23`
- `F(3) = 26`

### Example 2
**Input:** `nums = [100]`  
**Output:** `0`

---

## Intuition

Brute force recomputes each rotation from scratch, which is too slow. The key observation is that consecutive rotation values are related by a simple recurrence, so once we know `F(0)`, we can derive every next value in constant time.

---

## Approach

1. Compute the sum of all elements in `nums`.
2. Compute `F(0)` directly using the original array.
3. For each next rotation, use the recurrence:
   - `F(k) = F(k - 1) + sum(nums) - n * nums[n - k]`
4. Track the maximum value seen across all rotations.

This gives an `O(n)` solution with constant extra space.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long current = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            current += 1LL * i * nums[i];
        }

        long long answer = current;

        for (int k = 1; k < n; k++) {
            current = current + sum - 1LL * n * nums[n - k];
            answer = max(answer, current);
        }

        return (int)answer;
    }
};
```

---

## Key Takeaways

- Use a recurrence when consecutive states are tightly related.
- The total sum of the array is enough to update each rotation in constant time.
- This problem is a good example of combining array observation with a math-based DP-style transition.
