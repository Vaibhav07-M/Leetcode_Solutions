# 3653. XOR After Range Multiplication Queries I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Simulation`

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

[LeetCode - 3653. XOR After Range Multiplication Queries I](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/)

---

## Problem Summary

You are given:
- an integer array `nums`
- queries of form `[l, r, k, v]`

For each query:
- start from index `l`
- while index `<= r`, update every `k`-th position:
  - `nums[idx] = (nums[idx] * v) % (1e9 + 7)`

After processing all queries, return the bitwise XOR of all elements in `nums`.

---

## Examples

### Example 1
**Input:** `nums = [1,1,1], queries = [[0,2,1,4]]`  
**Output:** `4`

**Explanation:**
- Multiply indices `0,1,2` by `4` -> `[4,4,4]`
- XOR = `4 ^ 4 ^ 4 = 4`

### Example 2
**Input:** `nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]`  
**Output:** `31`

**Explanation:**
- Query 1 updates indices `1,3` -> `[2,9,1,15,4]`
- Query 2 updates indices `0,1,2` -> `[4,18,2,15,4]`
- XOR = `4 ^ 18 ^ 2 ^ 15 ^ 4 = 31`

---

## Intuition

The constraints are small (`n, q <= 1000`), so we can directly simulate each query exactly as described.

For each query, visit positions in arithmetic progression:
- `l, l + k, l + 2k, ... <= r`

Apply modular multiplication at each visited index, then compute final XOR over the resulting array.

---

## Approach

1. Define `MOD = 1e9 + 7`.
2. For every query `[l, r, k, v]`:
   - loop `i` from `l` to `r` with step `k`
   - update `nums[i] = (nums[i] * v) % MOD`
3. Initialize `ans = 0` and XOR all values in `nums`.
4. Return `ans`.

This is straightforward simulation and matches problem operations one-to-one.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(total updated indices + n)` (worst-case `O(q * n + n)`) |
| **Space** | `O(1)` extra |

---

## Code (C++)

```cpp
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        const int MOD = 1e9 + 7;
        
        for(auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            for(int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }
        
        int ans = 0;
        for(int x : nums) {
            ans ^= x;
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

- Small constraints often allow direct simulation.
- Arithmetic progression updates (`i += k`) are natural for stepped-range queries.
- Use `1LL * a * b` before modulo to avoid overflow in C++.
