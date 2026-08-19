# 1386. Cinema Seat Allocation

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Greedy`, `Bit Manipulation`

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

[LeetCode — 1386. Cinema Seat Allocation](https://leetcode.com/problems/cinema-seat-allocation/)

---

## Problem Summary

A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.  
You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

---

## Examples

### Example 1
**Input:** `n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]`  
**Output:** `4`  
**Explanation:**
- The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.

### Example 2
**Input:** `n = 2, reservedSeats = [[2,1],[1,8],[2,6]]`  
**Output:** `2`  

### Example 3
**Input:** `n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]`  
**Output:** `4`  

---

## Intuition

The problem revolves around array, hash table, greedy, bit manipulation. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << s);
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {
            bool left  = !(mask & (1 << 2)) &&
                         !(mask & (1 << 3)) &&
                         !(mask & (1 << 4)) &&
                         !(mask & (1 << 5));

            bool middle = !(mask & (1 << 4)) &&
                          !(mask & (1 << 5)) &&
                          !(mask & (1 << 6)) &&
                          !(mask & (1 << 7));

            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Hash Table, Greedy, Bit Manipulation patterns often reduce an apparently complex problem to a few simple rules.
