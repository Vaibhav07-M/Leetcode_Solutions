# 1545. Find Kth Bit in Nth Binary String

**Difficulty:** `Medium`  
**Tags:** `String`, `Recursion`, `Divide and Conquer`

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

[LeetCode — 1545. Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)

---

## Problem Summary

The binary string `Sn` is built recursively:

- `S1 = "0"`
- `Si = Si-1 + "1" + reverse(invert(Si-1))` for `i > 1`

Where `+` is concatenation, `invert(x)` flips all bits, and `reverse(x)` reverses the string.

Given `n` and `k`, return the `k`-th bit (1-indexed) of `Sn`.

The first four strings are:
```
S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
```

---

## Examples

### Example 1
**Input:** `n = 3, k = 1`  
**Output:** `"0"`  
**Explanation:** `S3 = "0111001"`. The 1st bit is `'0'`.

### Example 2
**Input:** `n = 4, k = 11`  
**Output:** `"1"`  
**Explanation:** `S4 = "011100110110001"`. The 11th bit is `'1'`.

---

## Constraints
- `1 <= n <= 20`
- `1 <= k <= 2^n - 1`

---

## Intuition

The string `Sn` has length `2^n - 1`. It has a **symmetric structure**:
- The **first half** is `Sn-1`.
- The **middle bit** (position `2^(n-1)`) is always `'1'`.
- The **second half** is the reverse-inverted mirror of the first half.

So for any position `k` in `Sn`:
- If `k` falls in the **first half** → it's the same as asking `Sn-1[k]`.
- If `k` is the **middle** → it's `'1'`.
- If `k` falls in the **second half** → it maps to the **mirrored position** in the first half, but **inverted**.

This lets us recurse down from `Sn` to `S1` in `O(n)` steps.

---

## Approach

1. **Base case:** `n == 1` → return `'0'`.
2. Compute the length of `Sn`: `len = (1 << n) - 1`.
3. Find the middle index: `mid = (len + 1) / 2`.
4. If `k == mid` → return `'1'`.
5. If `k < mid` → recurse into `Sn-1` with the same `k`.
6. If `k > mid` → the bit is the inverse of position `len - k + 1` in `Sn-1` (the mirrored position).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — one recursive call per level |
| **Space** | `O(n)` — recursion stack depth |

---

## Code (C++)

### Solution 1: Recursive Divide and Conquer (Submitted)
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;

        if (k == mid) return '1';
        else if (k < mid)
            return findKthBit(n - 1, k);
        else {
            char bit = findKthBit(n - 1, len - k + 1);
            return (bit == '0') ? '1' : '0';
        }
    }
};
```

### Solution 2: Iterative with Inversion Tracking
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        int inverted = 0;  // tracks how many times we've mirrored (flips parity)

        while (n > 1) {
            int len = (1 << n) - 1;
            int mid = (len + 1) / 2;

            if (k == mid) return (inverted % 2 == 0) ? '1' : '0';

            if (k > mid) {
                k = len - k + 1;  // mirror to first half
                inverted++;       // mirroring also inverts
            }
            n--;
        }

        // S1 = "0"; apply accumulated inversions
        return (inverted % 2 == 0) ? '0' : '1';
    }
};
```

### Solution 3: Build the String (Only Feasible for Small n)
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 2; i <= n; i++) {
            string inv = s;
            for (char& c : inv) c = (c == '0') ? '1' : '0';
            reverse(inv.begin(), inv.end());
            s = s + "1" + inv;
        }

        return s[k - 1];
    }
};
```

---

## Key Takeaways

- The string has a **recursive mirror structure** — second half is the reverse-invert of the first half.
- The **middle bit is always `'1'`** by construction.
- Recursive divide-and-conquer reduces the problem from size `2^n - 1` down to `S1` in exactly `O(n)` steps.
- The iterative version avoids recursion overhead by tracking how many inversions have accumulated.
- Building the full string works for small `n` (up to 20 → string length ≈ 1M) but the recursive approach is cleaner and more efficient.
