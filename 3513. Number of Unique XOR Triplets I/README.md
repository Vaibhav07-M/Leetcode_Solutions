# 3513. Number of Unique XOR Triplets I

**Difficulty:** `Medium`  
**Tags:** `Bit Manipulation`, `Math`, `XOR`

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

[LeetCode – 3513. Number of Unique XOR Triplets I](https://leetcode.com/problems/number-of-unique-xor-triplets-i/)

---

## Problem Summary

You are given a permutation `nums` containing the integers from `1` to `n`.

A XOR triplet is defined as:

```text
nums[i] XOR nums[j] XOR nums[k]
```

where `i ≤ j ≤ k`.

Return the number of **distinct XOR values** that can be obtained from all possible triplets. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
nums = [1,2]
```

**Output**

```text
2
```

**Explanation**

The unique XOR values are `{1,2}`.

---

### Example 2

**Input**

```text
nums = [3,1,2]
```

**Output**

```text
4
```

**Explanation**

The unique XOR values are `{0,1,2,3}`.

---

## Intuition

Since `nums` is a permutation of the numbers from `1` to `n`, the answer depends **only on `n`**, not on the arrangement of the array.

- If `n < 3`, only the existing numbers can be produced, so the answer is simply `n`.
- For `n ≥ 3`, every XOR value in the range `[0, 2^k - 1]` becomes achievable, where `2^k` is the smallest power of two **strictly greater than** `n`.

Thus, the answer is that power of two.

---

## Approach

1. Let `n` be the size of the array.
2. If `n < 3`, return `n`.
3. Initialize `p = 1`.
4. Keep doubling `p` until `p > n`.
5. Return `p`.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(log n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return n;

        int p = 1;
        while (p <= n) p <<= 1;

        return p;
    }
};
```

---

## Key Takeaways

- The permutation order is irrelevant; only `n` determines the answer.
- For arrays with fewer than three elements, the answer is simply the number of elements.
- For `n ≥ 3`, the number of distinct XOR values equals the smallest power of two greater than `n`.
- The implementation requires only a simple loop to find the next power of two.
- The solution runs in **O(log n)** time with **O(1)** extra space.