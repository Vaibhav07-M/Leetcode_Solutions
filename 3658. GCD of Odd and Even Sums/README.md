# 3658. GCD of Odd and Even Sums

**Difficulty:** `Easy`  
**Tags:** `Math`, `Number Theory`, `GCD`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Proof](#proof)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode — 3658. GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums/)

---

## Problem Summary

Given an integer `n`:

- `sumOdd` is the sum of the first `n` positive odd numbers.
- `sumEven` is the sum of the first `n` positive even numbers.

Return the greatest common divisor (GCD) of `sumOdd` and `sumEven`.

---

## Examples

### Example 1

**Input:** `n = 4`

**Output:** `4`

**Explanation:**

- `sumOdd = 1 + 3 + 5 + 7 = 16`
- `sumEven = 2 + 4 + 6 + 8 = 20`
- `GCD(16, 20) = 4`

---

### Example 2

**Input:** `n = 5`

**Output:** `5`

**Explanation:**

- `sumOdd = 25`
- `sumEven = 30`
- `GCD(25, 30) = 5`

---

## Intuition

The first `n` odd numbers always sum to:

```
n²
```

The first `n` even numbers sum to:

```
2 + 4 + ... + 2n = n(n + 1)
```

Therefore,

```
GCD(sumOdd, sumEven)
= GCD(n², n(n + 1))
```

Since consecutive integers are always coprime,

```
GCD(n, n + 1) = 1
```

we obtain

```
GCD(n², n(n + 1))
= n × GCD(n, n + 1)
= n
```

Hence the answer is simply **`n`**.

---

## Approach

1. Observe the mathematical formulas:
   - `sumOdd = n²`
   - `sumEven = n(n + 1)`
2. Use the GCD property:
   - `GCD(n², n(n+1)) = n`
3. Return `n`.

---

## Proof

```
sumOdd = n²

sumEven = n(n + 1)

GCD(sumOdd, sumEven)

= GCD(n², n(n + 1))

= n × GCD(n, n + 1)

Since consecutive integers are coprime,

GCD(n, n + 1) = 1

Therefore,

Answer = n
```

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(1)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
```

---

## Key Takeaways

- The sum of the first `n` odd numbers is `n²`.
- The sum of the first `n` even numbers is `n(n + 1)`.
- Consecutive integers are always coprime.
- A mathematical observation reduces the entire problem to returning `n`.
```