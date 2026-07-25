# 3536. Maximum Product of Two Digits

**Difficulty:** `Easy`  
**Tags:** `Math`, `Enumeration`

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

[LeetCode – 3536. Maximum Product of Two Digits](https://leetcode.com/problems/maximum-product-of-two-digits/)

---

## Problem Summary

You are given a positive integer `n`.

Return the maximum product that can be obtained by multiplying any two digits of `n`.

**Note:** The same digit may be used twice only if it appears at least twice in the number.

---

## Examples

### Example 1

**Input**

```text
n = 31
```

**Output**

```text
3
```

**Explanation**

The digits are `[3, 1]`.

Possible product:

```text
3 × 1 = 3
```

---

### Example 2

**Input**

```text
n = 22
```

**Output**

```text
4
```

**Explanation**

The digits are `[2, 2]`.

Possible product:

```text
2 × 2 = 4
```

---

### Example 3

**Input**

```text
n = 124
```

**Output**

```text
8
```

**Explanation**

Possible products:

```text
1 × 2 = 2
1 × 4 = 4
2 × 4 = 8
```

Maximum product = **8**.

---

## Intuition

Since an integer contains at most **10 digits**, we can simply extract every digit and compare every pair.

Trying all pairs is fast enough and guarantees finding the maximum product.

---

## Approach

1. Extract every digit of `n` into a vector.
2. Iterate through all pairs of digits.
3. Compute their product.
4. Keep track of the maximum product found.
5. Return the maximum.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(d²)` where `d` is the number of digits (`d ≤ 10`) |
| **Space** | `O(d)` |

Since `d ≤ 10`, this effectively runs in constant time.

---

## Code (C++)

```cpp
class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                ans = max(ans, digits[i] * digits[j]);
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Extract the digits of the number using modulo and division.
- Enumerate every pair of digits and compute their product.
- Since an integer has at most **10 digits**, a brute-force comparison is completely efficient.
- The algorithm is simple, easy to implement, and runs in effectively constant time.