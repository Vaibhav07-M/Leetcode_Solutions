# 3129. Find All Possible Stable Binary Arrays I

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`

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

[LeetCode — 3129. Find All Possible Stable Binary Arrays I](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)

---

## Problem Summary

You are given three positive integers `zero`, `one`, and `limit`. A binary array `arr` is considered **stable** if:
1. It contains exactly `zero` 0s.
2. It contains exactly `one` 1s.
3. No contiguous subarray of `arr` with a size strictly greater than `limit` consists of identical elements. (i.e., you cannot have more than `limit` consecutive 0s or `limit` consecutive 1s).

Your task is to calculate the total number of stable binary arrays. Since the answer can be large, return it modulo $10^9 + 7$.

**Constraints:**
- `1 <= zero, one, limit <= 200`

---

## Examples

### Example 1
**Input:** `zero = 1, one = 1, limit = 2`  
**Output:** `2`  
**Explanation:**  
The two possible stable binary arrays are `[1, 0]` and `[0, 1]`. Both arrays have a single 0 and a single 1, and no consecutive sequence of the same element exceeds a length of 2.

### Example 2
**Input:** `zero = 1, one = 2, limit = 1`  
**Output:** `1`  
**Explanation:**  
The only possible stable binary array is `[1, 0, 1]`. The arrays `[1, 1, 0]` and `[0, 1, 1]` have subarrays of length 2 containing identical elements, which violates the `limit = 1` constraint.

### Example 3
**Input:** `zero = 3, one = 3, limit = 2`  
**Output:** `14`  

---

## Intuition

Since we need to build an array sequentially while counting valid configurations and keeping track of constraints, this inherently reduces to a **Dynamic Programming** problem. We have overlapping subproblems and optimal substructure where our choices at index `i` only depend on the most recent elements we have appended.

Specifically, at any given step during array construction, we only care about:
1. How many `0`s are remaining? (`z`)
2. How many `1`s are remaining? (`o`)
3. What was the *last digit* we appended? (`last`)
4. How many consecutive *identical* digits have we currently placed at the end? (`cnt`)

If `cnt` reaches the `limit` for current digit, we are *forced* to switch to the other digit.

---

## Approach

We can design a Top-Down DP with Memoization.
Let our recursive state be `solve(z, o, last, cnt, limit)`, which returns the number of valid stable arrangements given the remaining elements and current sequence count.

**Transitions:**
- We can try appending a `0` if `z > 0`:
  - If the previous digit `last` was `0`, appending another `0` increases the consecutive streak `cnt`. This is only allowed if `cnt < limit`. If valid, we recurse to `solve(z - 1, o, 0, cnt + 1, limit)`.
  - If the previous digit `last` was `1`, appending a `0` breaks the consecutive 1s streak and starts a new 0s streak. We recurse to `solve(z - 1, o, 0, 1, limit)`.
- We can try appending a `1` if `o > 0`:
  - If `last == 1`, similar to above, we check `cnt < limit` and recurse to `solve(z, o - 1, 1, cnt + 1, limit)`.
  - If `last == 0`, we switch the digit and recurse to `solve(z, o - 1, 1, 1, limit)`.

**Base cases:**
- If `z == 0` and `o == 0`, we have successfully formed a valid binary array, so we return `1`.

**Memoization:**
- The state limits are $z \le 200$, $o \le 200$, $last \in \{0, 1\}$, and $cnt \le limit \le 200$. 
- We can utilize a 4D array `memo[201][201][2][201]` initialized with `-1` to cache already computed states.

To start the recursion, we initiate it from an empty array by trying to place both `0` (if `zero > 0`) and `1` (if `one > 0`) as the very first element and sum those outcomes together.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | $\mathcal{O}(zero \times one \times limit)$. The number of unique states in memo cache is roughly $(200 \times 200 \times 2 \times 200) \approx 1.6 \times 10^7$. State transition takes $\mathcal{O}(1)$ time. |
| **Space** | $\mathcal{O}(zero \times one \times limit)$ for the 4D memoization table. Additionally, an $\mathcal{O}(zero + one)$ recursion stack depth space margin. |

---

## Code (C++)

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;
    int memo[201][201][2][201];

    int solve(int z, int o, int last, int cnt, int limit) {
        if(z == 0 && o == 0) return 1;

        if(memo[z][o][last][cnt] != -1)
            return memo[z][o][last][cnt];

        long long ans = 0;

        if(z > 0) {
            if(last == 0) {
                if(cnt < limit)
                    ans += solve(z - 1, o, 0, cnt + 1, limit);
            } 
            else {
                ans += solve(z - 1, o, 0, 1, limit);
            }
        }

        if(o > 0) {
            if(last == 1) {
                if(cnt < limit)
                    ans += solve(z, o - 1, 1, cnt + 1, limit);
            } 
            else {
                ans += solve(z, o - 1, 1, 1, limit);
            }
        }

        return memo[z][o][last][cnt] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo, -1, sizeof(memo));

        long long ans = 0;

        if(zero > 0)
            ans += solve(zero - 1, one, 0, 1, limit);

        if(one > 0)
            ans += solve(zero, one - 1, 1, 1, limit);

        return ans % MOD;
    }
};
```

---

## Key Takeaways

- Combinatorial counting sequences with "maximum consecutive" constraints strongly hint at representing `current element length` in DP state.
- Always apply modulo $10^9 + 7$ appropriately, even at the intermediary steps returning from state calls to avoid `long long` overflows in larger variations.
