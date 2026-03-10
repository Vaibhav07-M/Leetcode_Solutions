# 3130. Find All Possible Stable Binary Arrays II

**Difficulty:** `Hard`  
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

[LeetCode — 3130. Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)

---

## Problem Summary

You are given three positive integers `zero`, `one`, and `limit`. A binary array `arr` is considered **stable** if:
1. It contains exactly `zero` 0s.
2. It contains exactly `one` 1s.
3. No contiguous subarray of `arr` with a size strictly greater than `limit` consists of identical elements.

Return the total number of stable binary arrays. Since the answer may be very large, return it modulo $10^9 + 7$.

**Constraints:**
- `1 <= zero, one, limit <= 1000`

> **Note:** This is the exact same problem as *3129. Find All Possible Stable Binary Arrays I*, but with significantly larger constraints (`limit` goes up from 200 to 1000). A simple 3D or 4D dynamic programming state that iterates through the `limit` size will Result in **Time Limit Exceeded** ($O(N^3) \approx 10^9$ operations). An $O(zero \times one)$ transition strategy is necessary.

---

## Examples

### Example 1
**Input:** `zero = 1, one = 1, limit = 2`  
**Output:** `2`  
**Explanation:**  
The two possible stable binary arrays are `[1, 0]` and `[0, 1]`.

### Example 2
**Input:** `zero = 1, one = 2, limit = 1`  
**Output:** `1`  
**Explanation:**  
The only possible stable binary array is `[1, 0, 1]`.

### Example 3
**Input:** `zero = 3, one = 3, limit = 2`  
**Output:** `14`  

---

## Intuition

In the previous version of the problem, we maintained the consecutive *count* of the last digit within the DP state. To optimize from $O(zero \cdot one \cdot limit)$ to $O(zero \cdot one)$, we need to drop the `count` state parameter altogether and calculate valid transitions mathematically using the inclusion-exclusion principle.

Let `t[i][j][k]` represent the number of stable valid configurations utilizing exactly `i` zeros and `j` ones, such that the sequence optimally ends with the digit `k` (where $k \in \{0, 1\}$).

If we want to append a `1` at the end (transitioning to `t[i][j][1]`), it can follow:
- Any sequence ending in `0` (`t[i][j-1][0]`).
- Any sequence ending in `1` (`t[i][j-1][1]`).

So trivially, `t[i][j][1] = t[i][j-1][0] + t[i][j-1][1]`.
However, this unconditionally adds a `1`, which might inadvertently construct a sequence ending with `limit + 1` continuous ones!

To fix this efficiently, we must subtract the *invalid* sequences. An invalid sequence ending in exactly `limit + 1` ones corresponds to a valid sequence that ended in a `0` beforehand, followed strictly by `limit + 1` ones. That distinct "prefix" state is exactly `t[i][j - 1 - limit][0]`.

By subtracting this specific state, we perfectly remove the offending configurations in $O(1)$ transition time!

---

## Approach

1. Initialize a 3D DP array: `t[zero + 1][one + 1][2]`.
2. **Base Cases:**
   - Arrays with all `0`s (and $0 \le i \le limit$) have exactly 1 valid array: `t[i][0][0] = 1`.
   - Arrays with all `1`s (and $0 \le j \le limit$) have exactly 1 valid array: `t[0][j][1] = 1`.
3. Loop through `i` from $0$ to `zero` and `j` from $0$ to `one`.
4. Skip when either `i == 0` or `j == 0` (handled by base cases).
5. Calculate transitions:
   - For strings ending in `1`:
     ```cpp
     t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % MOD;
     if (j - 1 >= limit) {
         t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + MOD) % MOD;
     }
     ```
   - For strings ending in `0`:
     ```cpp
     t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % MOD;
     if (i - 1 >= limit) {
         t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + MOD) % MOD;
     }
     ```
6. Return `(t[zero][one][0] + t[zero][one][1]) % MOD`.

> *Always remember to add `MOD` before taking the modulo when performing subtraction to prevent intermediate negative values.*

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | $\mathcal{O}(zero \times one)$. For each $i$ and $j$, the transition formulas calculate the values in $\mathcal{O}(1)$ time. Computations drastically step down from the billions context block to roughly $10^6$ ops. |
| **Space** | $\mathcal{O}(zero \times one)$. We construct a 3D table `t` of size $(zero + 1) \times (one + 1) \times 2$. *(This space could technically be optimized to $\mathcal{O}(\text{limit} \times one)$ via a rolling window, but this bound is quite sufficient and fits in memory.)* |

---

## Code (C++)

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // t[zero+1][one+1][2] 
        vector<vector<vector<int>>> t(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

        for(int i = 0; i <= min(zero, limit); i++)
            t[i][0][0] = 1;
        
        for(int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) { // i = # 0s
            for(int j = 0; j <= one; j++) { // j = # 1s

                if(i == 0 || j == 0)
                    continue;

                // Add 1 to previous states
                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
                
                // Remove invalid sequences exceeding limit
                if(j - 1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + M) % M;
                }

                // Add 0 to previous states
                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
                
                // Remove invalid sequences exceeding limit
                if(i - 1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + M) % M;
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};
```

---

## Key Takeaways

- To reduce dimensionality from dynamic programming states handling streaks or frequencies, consider tracking the generalized accumulated sequence and cleanly subtracting the boundary violation prefix sequences. 
- Negative modulo operations in C++ result in negative bounds, so ALWAYS structure subtractions identically to `(a - b + mod) % mod`.
