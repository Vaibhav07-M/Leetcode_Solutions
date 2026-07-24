# 3514. Number of Unique XOR Triplets II

**Difficulty:** `Medium`  
**Tags:** `Dynamic Programming`, `Bit Manipulation`, `XOR`

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

[LeetCode – 3514. Number of Unique XOR Triplets II](https://leetcode.com/problems/number-of-unique-xor-triplets-ii/)

---

## Problem Summary

You are given an integer array `nums`.

A XOR triplet is defined as:

```text
nums[i] XOR nums[j] XOR nums[k]
```

where `i ≤ j ≤ k`.

Return the number of **distinct XOR values** obtainable from all valid triplets. Unlike Part I, `nums` is **not necessarily a permutation**. Therefore, the answer depends on the actual values in the array.

---

## Examples

### Example 1

**Input**

```text
nums = [1,3]
```

**Output**

```text
2
```

**Explanation**

The unique XOR values are `{1,3}`.

---

### Example 2

**Input**

```text
nums = [6,7,8,9]
```

**Output**

```text
4
```

**Explanation**

The unique XOR values are `{6,7,8,9}`.

---

## Intuition

Since indices may repeat (`i ≤ j ≤ k`), an element can contribute:

- **once** → XOR changes by `x`
- **twice** → `x ^ x = 0`
- **three times** → `x ^ x ^ x = x`

Maintain DP where:

- `dp[c][v]` indicates whether XOR value `v` is achievable after selecting exactly `c` elements.

For every number, update the DP by considering selecting it one, two, or three times.

Because every value is at most `1500`, all XOR results fit within `2048`, making the state space small.

---

## Approach

1. Let `MAXX = 2048`, the maximum possible XOR value.
2. Initialize DP:
   - `dp[0][0] = true`.
3. Process every element in `nums`.
4. For every reachable state:
   - Select the element once.
   - Select it twice (`x ^ x = 0`).
   - Select it three times (`x ^ x ^ x = x`).
5. Update the DP accordingly.
6. Count how many XOR values are reachable using exactly three selected elements.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n × 2048 × 4)` ≈ `O(n)` |
| **Space** | `O(2048 × 4)` ≈ `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int x : nums) {
            auto ndp = dp;

            for (int c = 0; c <= 3; c++) {
                for (int v = 0; v < MAXX; v++) {
                    if (!dp[c][v]) continue;

                    if (c + 1 <= 3)
                        ndp[c + 1][v ^ x] = true;

                    if (c + 2 <= 3)
                        ndp[c + 2][v] = true;      // x ^ x = 0

                    if (c + 3 <= 3)
                        ndp[c + 3][v ^ x] = true;  // x ^ x ^ x = x
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (int v = 0; v < MAXX; v++)
            if (dp[3][v]) ans++;

        return ans;
    }
};
```

---

## Key Takeaways

- Unlike Part I, the answer depends on the array values because duplicates and arbitrary numbers are allowed.
- Dynamic Programming tracks reachable XOR values after selecting exactly `0–3` elements.
- Selecting an element twice contributes nothing to the XOR (`x ^ x = 0`).
- The XOR state space is bounded by `2048`, making DP efficient.
- The algorithm runs in linear time with respect to `n` (up to a constant factor of `2048`) while using constant extra space.