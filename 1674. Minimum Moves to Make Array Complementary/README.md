# 1674. Minimum Moves to Make Array Complementary

**Difficulty:** `Medium`  
**Tags:** `Array`, `Greedy`, `Prefix Sum`

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

[LeetCode — 1674. Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

---

## Problem Summary

You are given an integer array `nums` of even length `n` and an integer `limit`. In one move, you can change any element to any integer in the range `[1, limit]`.
A complementary pair is `(nums[i], nums[n-1-i])` for `0 <= i < n/2`. The goal is to make all complementary pairs have the same sum. Return the minimum number of moves required.

---

## Examples

### Example 1
**Input:** `nums = [1,2,4,3], limit = 4`  
**Output:** `1`

### Example 2
**Input:** `nums = [1,2,2,1], limit = 2`  
**Output:** `2`

### Example 3
**Input:** `nums = [1,2,1,2], limit = 2`  
**Output:** `0`

---

## Intuition

Each pair contributes a sum `s = x + y`. For a target sum `t`, the number of moves for pair `(x,y)` is:
- 0 moves if `s == t`.
- 1 move if by changing one element we can reach `t` (i.e., `t` in `[min(x,y)+1, max(x,y)+limit]`).
- 2 moves otherwise.

We can compute for every possible target sum `t` in `[2, 2*limit]` how many pairs require 0,1,2 moves using a difference array over the sum range, then take the minimum total moves.

---

## Approach

1. For each pair `(x,y)` with `a=min(x,y)`, `b=max(x,y)`:
   - By default, each pair needs 2 moves for any sum.
   - For sums in `[a+1, b+limit]`, the pair can be done in 1 move (mark range with -1 in diff array).
   - For sum `a+b` the pair needs 0 moves (adjust diff to reflect -1 at `a+b` and +1 after `a+b`).
2. Accumulate the diff array over sums `2..2*limit` to get the number of moves for each target sum, and add base `2 * (n/2)` then take min.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + limit)` |
| **Space** | `O(limit)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        int pairs = n / 2;
        // initially each pair contributes 2 moves
        // we will compute reductions via diff array
        for (int i = 0; i < pairs; ++i) {
            int x = nums[i];
            int y = nums[n - 1 - i];
            int a = min(x, y);
            int b = max(x, y);
            // for sums where 1 move is possible: [a+1, b+limit]
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;
            // for exact sum a+b, reduce one more (0 moves instead of 1)
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }
        int res = INT_MAX;
        int curr = 2 * pairs; // base moves
        int running = 0;
        for (int s = 2; s <= 2 * limit; ++s) {
            running += diff[s];
            res = min(res, curr + running);
        }
        return res;
    }
};
```

---

## Key Takeaways

- Difference arrays can convert range updates into linear passes, enabling O(n + limit) solutions.
- Consider cases per complementary pair and aggregate efficiently across all possible target sums.
- This transforms a per-target-sum O(n) check into a linear sweep.
