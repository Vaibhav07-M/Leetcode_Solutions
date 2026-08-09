# 1140. Stone Game II

**Difficulty:** `Medium`  
**Tags:** `Array`, `Dynamic Programming`, `Game Theory`, `Minimax`

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

[LeetCode — 1140. Stone Game II](https://leetcode.com/problems/stone-game-ii/)

---

## Problem Summary

Alice and Bob play a game with piles of stones arranged in a row. Each pile has a positive integer number of stones `piles[i]`. The objective is to end with the most stones.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take all the stones in the first `X` remaining piles, where `1 <= X <= 2M`. Then, we set `M = max(M, X)`. Initially, `M = 1`.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

---

## Examples

### Example 1
**Input:** `piles = [2,7,9,4,4]`  
**Output:** `10`  
**Explanation:**
- If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
- If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
- So we return 10 since it's larger.

### Example 2
**Input:** `piles = [1,2,3,4,5,100]`  
**Output:** `104`

---

## Intuition

This is a two-player zero-sum game where both players play optimally. The key insight is that at any state, the current player wants to maximize their own stones, which is equivalent to minimizing the opponent's stones from the remaining piles.

We can use **Dynamic Programming with memoization** where the state is defined by:
- Current index `i` (which pile we're at)
- Current value of `M`

The total stones from index `i` to the end is fixed (suffix sum). If the current player takes `X` piles, they get `suffix[i] - solve(i + X, max(M, X))` stones, because the opponent will then play optimally from the remaining piles.

---

## Approach

1. **Compute suffix sums** — `suffix[i]` stores the total stones from pile `i` to the end. This allows O(1) calculation of stones taken in any move.

2. **Define DP state** — `dp[i][M]` = maximum stones the current player can get starting from index `i` with parameter `M`.

3. **Base cases:**
   - If `i >= n`: no piles left, return 0.
   - If `2 * M >= n - i`: current player can take all remaining piles, return `suffix[i]`.

4. **Transition:** For each valid `X` from 1 to `2*M`:
   - `nextM = max(M, X)`
   - Current player gets `suffix[i] - solve(i + X, nextM)` (total remaining minus what opponent gets)
   - Take the maximum over all valid `X`.

5. **Memoize** results to avoid recomputation.

6. Return `solve(0, 1)` — Alice's optimal score starting from the beginning with `M = 1`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n³)` — `n` states for `i`, `n` states for `M`, and up to `2M` transitions per state |
| **Space** | `O(n²)` — DP table of size `n × (n+1)` |

Given `n <= 100`, this is efficient enough.

---

## Code (C++)

```cpp
class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // Take all remaining piles
        if (i >= n)
            return 0;

        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int nextM = max(M, X);

            int current = suffix[i] - solve(i + X, nextM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Suffix sum
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // M can go up to n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};
```

---

## Key Takeaways

- Two-player optimal games can often be solved with minimax DP: `current_player_score = total_remaining - opponent_optimal_score`.
- Suffix sums enable O(1) range sum queries, critical for performance.
- State space is `(index, M)` where `M` grows up to `n`, giving `O(n²)` states.
- The constraint `X <= 2M` creates a natural bound on branching factor.