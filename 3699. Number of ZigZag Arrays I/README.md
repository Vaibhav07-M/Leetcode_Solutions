# 3699. Number of ZigZag Arrays I

**Difficulty:** `Hard`  
**Tags:** `Array`, `Dynamic Programming`, `Prefix Sum`

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

[LeetCode — 3699. Number of ZigZag Arrays I](https://leetcode.com/problems/number-of-zigzag-arrays-i/)

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

:contentReference[oaicite:0]{index=0}

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
[4, 5, 4]
[5, 4, 5]
```

:contentReference[oaicite:1]{index=1}

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

There are 10 valid ZigZag arrays satisfying all conditions. :contentReference[oaicite:2]{index=2}

---

## Intuition

For every position, only the relationship with the previous element matters:

- The sequence can currently be moving **up**.
- The sequence can currently be moving **down**.

Let:

```cpp
up[i]
```

represent the number of valid arrays ending with value `i` where the last move was upward.

Similarly:

```cpp
down[i]
```

represents the number of valid arrays ending with value `i` where the last move was downward.

To maintain a ZigZag pattern:

- An upward move must come after a downward move.
- A downward move must come after an upward move.

Using prefix sums allows these transitions to be computed efficiently.

---

## Approach

### 1. Compress the Value Range

Let:

```cpp
m = r - l + 1
```

represent the number of available values.

Each index corresponds to a value in the interval `[l, r]`.

---

### 2. Initialize Length 2 Arrays

For arrays of length `2`:

```cpp
up[i] = number of smaller values before i
```

which equals:

```cpp
i
```

Similarly:

```cpp
down[i] = number of larger values before i
```

which equals:

```cpp
m - 1 - i
```

---

### 3. Build Longer Arrays

For every length from:

```cpp
3 → n
```

compute prefix sums of `up` and `down`.

#### Transition to Up

To end with an upward move at value `i`:

```cpp
previous value < i
```

and the previous state must be `down`.

Therefore:

```cpp
newUp[i] = prefDown[i];
```

---

#### Transition to Down

To end with a downward move at value `i`:

```cpp
previous value > i
```

and the previous state must be `up`.

Therefore:

```cpp
newDown[i] =
    totalUp - prefUp[i + 1];
```

---

### 4. Update DP

After computing the new states:

```cpp
swap(up, newUp);
swap(down, newDown);
```

---

### 5. Compute Answer

The final answer is:

```cpp
sum(up[i]) + sum(down[i])
```

for all possible ending values.

Return the result modulo:

```cpp
10^9 + 7
```

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n × m)` |
| **Space** | `O(m)` |

Where:

```cpp
m = r - l + 1
```

---

## Code (C++)

```cpp
class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<int> up(m), down(m);
        vector<int> newUp(m), newDown(m);
        vector<int> prefUp(m + 1), prefDown(m + 1);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] =
                    (prefUp[i] + up[i]) % MOD;

                prefDown[i + 1] =
                    (prefDown[i] + down[i]) % MOD;
            }

            int totalUp = prefUp[m];

            for (int i = 0; i < m; i++) {

                newUp[i] = prefDown[i];

                newDown[i] =
                    (totalUp - prefUp[i + 1] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
        }

        return ans % MOD;
    }
};
```

---

## Key Takeaways

- Track whether the last step was increasing or decreasing.
- ZigZag sequences must alternate between upward and downward moves.
- Prefix sums reduce transition complexity from `O(m²)` to `O(m)`.
- Only the previous direction and ending value are needed.
- The solution runs in `O(n × m)` time and `O(m)` space.