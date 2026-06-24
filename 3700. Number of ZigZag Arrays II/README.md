# 3700. Number of ZigZag Arrays II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Matrix Exponentiation`, `Graph`

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

[LeetCode — 3700. Number of ZigZag Arrays II](https://leetcode.com/problems/number-of-zigzag-arrays-ii/)

---

## Problem Summary

You are given three integers:

```cpp
n, l, r
```

A ZigZag array of length `n` must satisfy:

- Every element lies in the range `[l, r]`.
- No two adjacent elements are equal.
- No three consecutive elements form a strictly increasing sequence.
- No three consecutive elements form a strictly decreasing sequence.

Return the total number of valid ZigZag arrays modulo:

```cpp
10^9 + 7
```

Unlike Part I, here:

```cpp
n ≤ 10^9
```

so a linear DP solution is not feasible. :contentReference[oaicite:0]{index=0} :contentReference[oaicite:1]{index=1}

---

## Examples

### Example 1

**Input:**

```cpp
n = 3, l = 4, r = 5
```

**Output:**

```cpp
2
```

**Explanation:**

Valid arrays:

```text
[4,5,4]
[5,4,5]
```

:contentReference[oaicite:2]{index=2}

---

### Example 2

**Input:**

```cpp
n = 3, l = 1, r = 3
```

**Output:**

```cpp
10
```

**Explanation:**

There are 10 valid ZigZag arrays satisfying all conditions. :contentReference[oaicite:3]{index=3}

---

## Intuition

The DP solution from Part I tracks:

- Arrays ending with an **upward** move.
- Arrays ending with a **downward** move.

For each possible ending value, these become states.

Since:

```cpp
n ≤ 10^9
```

we cannot perform transitions one length at a time.

Instead:

- Model DP transitions as a matrix.
- Raise the transition matrix to the power:

```cpp
n - 2
```

using fast exponentiation.

This transforms an `O(n)` DP into an `O(log n)` process.

---

## Approach

### 1. Define States

Let:

```cpp
m = r - l + 1
```

There are:

```cpp
2 * m
```

states:

- `up[x]` → arrays ending at value `x` with last move upward.
- `down[x]` → arrays ending at value `x` with last move downward.

---

### 2. Build Transition Matrix

Create a matrix:

```cpp
T
```

of size:

```cpp
(2m × 2m)
```

Transitions:

#### Down → Up

To end at value `x` with an upward move:

```cpp
previous value < x
```

Therefore:

```cpp
T[x][m + y] = 1
```

for every:

```cpp
y < x
```

---

#### Up → Down

To end at value `x` with a downward move:

```cpp
previous value > x
```

Therefore:

```cpp
T[m + x][y] = 1
```

for every:

```cpp
y > x
```

---

### 3. Build Base State

Length-2 arrays are initialized exactly as in Part I.

For each value:

```cpp
base[x] = x;
```

counts valid upward endings.

And:

```cpp
base[m + x] = m - 1 - x;
```

counts valid downward endings.

---

### 4. Matrix Exponentiation

Each multiplication by `T` extends the array length by one.

Therefore:

```cpp
state(n) = T^(n-2) × base
```

Compute:

```cpp
T^(n-2)
```

using binary exponentiation.

---

### 5. Compute Answer

Multiply the powered matrix by the base state and sum all resulting states.

Return the answer modulo:

```cpp
10^9 + 7
```

---

## Complexity

Let:

```cpp
S = 2 * (r - l + 1)
```

| Metric | Complexity |
|----------|----------|
| **Time** | `O(S³ log n)` |
| **Space** | `O(S²)` |

Since:

```cpp
r - l ≤ 75
```

the matrix size remains small enough for fast exponentiation.

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();

        Matrix C(sz, vector<long long>(sz, 0));

        for(int i = 0; i < sz; i++) {
            for(int k = 0; k < sz; k++) {

                if(A[i][k] == 0) continue;

                for(int j = 0; j < sz; j++) {

                    if(B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] +
                        A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {

        int sz = base.size();

        Matrix res(sz, vector<long long>(sz, 0));

        for(int i = 0; i < sz; i++)
            res[i][i] = 1;

        while(exp) {

            if(exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for(int x = 0; x < m; x++) {

            for(int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            for(int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<long long> base(S);

        for(int x = 0; x < m; x++) {
            base[x] = x;
            base[m + x] = m - 1 - x;
        }

        if(n == 2) {
            long long ans = 0;

            for(long long v : base)
                ans = (ans + v) % MOD;

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<long long> state(S, 0);

        for(int i = 0; i < S; i++) {
            for(int j = 0; j < S; j++) {

                state[i] =
                    (state[i] +
                     P[i][j] * base[j]) % MOD;
            }
        }

        long long ans = 0;

        for(long long v : state)
            ans = (ans + v) % MOD;

        return (int)ans;
    }
};
```

---

## Key Takeaways

- Part II extends Part I by allowing `n` up to `10^9`.
- DP transitions can be represented as a matrix.
- Matrix exponentiation reduces repeated transitions from `O(n)` to `O(log n)`.
- States represent ending value and last movement direction.
- Fast exponentiation is a common optimization when DP transitions are linear.
- The solution efficiently handles extremely large values of `n`.