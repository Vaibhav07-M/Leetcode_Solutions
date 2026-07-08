# 3756. Concatenate Non-Zero Digits and Multiply by Sum II

**Difficulty:** `Medium`  
**Tags:** `String`, `Prefix Sum`, `Binary Search`

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

[LeetCode — 3756. Concatenate Non-Zero Digits and Multiply by Sum II](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/)

---

## Problem Summary

You are given:

- A string `s` consisting of digits.
- A list of queries `queries`, where each query is:

```cpp
[li, ri]
```

For every query:

1. Extract the substring:

```cpp
s[li...ri]
```

2. Form a new integer `x` by concatenating all **non-zero digits** while preserving their order.
3. Compute the sum of digits in `x`.
4. Return:

```text
x × sum
```

Since the answer may be very large, return every answer modulo:

```text
10^9 + 7
```

If the substring contains no non-zero digits, the answer is `0`. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
s = "10203004"
queries = [[0,7],[1,3],[4,6]]
```

**Output:**

```cpp
[12340,4,9]
```

---

### Example 2

**Input:**

```cpp
s = "1000"
queries = [[0,3],[1,1]]
```

**Output:**

```cpp
[1,0]
```

---

### Example 3

**Input:**

```cpp
s = "9876543210"
queries = [[0,9]]
```

**Output:**

```cpp
[444444137]
```

---

## Intuition

Processing every query independently would require scanning each substring, leading to an `O(n × q)` solution.

Instead:

- Store the positions of all non-zero digits.
- Build prefix sums of digit values.
- Build prefix values representing the concatenated number modulo `10^9 + 7`.

Using binary search, we can quickly locate the non-zero digits inside each queried range and answer every query efficiently.

---

## Approach

### 1. Store Non-Zero Digits

Traverse the string once.

For every non-zero digit, store:

- Its original position.
- Its numeric value.

---

### 2. Precompute Prefix Information

Build:

- `pow10[i]` → powers of 10 modulo `MOD`
- `prefVal[i]` → concatenated value of the first `i` non-zero digits
- `prefSum[i]` → sum of the first `i` non-zero digits

These allow constant-time computation of any concatenated number.

---

### 3. Process Each Query

Use binary search:

```cpp
lower_bound()
upper_bound()
```

to find all non-zero digits inside `[l, r]`.

If none exist, return `0`.

Otherwise:

- Compute the concatenated value using prefix values.
- Compute the digit sum using prefix sums.
- Multiply both values modulo `10^9 + 7`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + q) log n)` |
| **Space** | `O(n)` |

Where:

- `n` = length of the string
- `q` = number of queries

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefVal(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long x = (prefVal[R] - prefVal[L] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[R] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Store only the non-zero digits to simplify query processing.
- Prefix sums allow constant-time digit sum computation.
- Prefix concatenated values combined with powers of 10 reconstruct any queried number efficiently.
- Binary search quickly identifies the relevant non-zero digits for each query.
- The solution answers all queries in `O((n + q) log n)` time.
```