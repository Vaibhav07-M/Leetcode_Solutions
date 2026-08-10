# 1510. Stone Game IV

**Difficulty:** `Medium`  
**Tags:** `Dynamic Programming`, `Game Theory`, `Math`

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

[LeetCode — 1510. Stone Game IV](https://leetcode.com/problems/stone-game-iv/)

---

## Problem Summary

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are `n` stones in a pile. On each player's turn, that player makes a move consisting of removing **any non-zero square number of stones** from the pile (i.e., 1, 4, 9, 16, ...). If a player cannot make a move, they lose the game.

Given `n`, return `true` if and only if Alice wins the game assuming both players play optimally.

---

## Examples

### Example 1
**Input:** `n = 1`  
**Output:** `true`  
**Explanation:** Alice removes 1 stone and wins.

### Example 2
**Input:** `n = 2`  
**Output:** `false`  
**Explanation:** Alice can only remove 1 stone. Then Bob removes 1 stone and wins.

### Example 3
**Input:** `n = 4`  
**Output:** `true`  
**Explanation:** Alice removes 4 stones and wins.

### Example 4
**Input:** `n = 7`  
**Output:** `false`  
**Explanation:** Alice's options:
- Remove 1 → Bob faces 6 (winning for Bob)
- Remove 4 → Bob faces 3 (winning for Bob)
All moves lead to Bob winning.

---

## Intuition

This is a classic impartial combinatorial game. For each number of stones `i`, we want to determine if the current player can force a win. The key insight is that a position is **winning** if there exists at least one move to a **losing** position for the opponent.

We can use **Dynamic Programming** where `dp[i]` represents whether the current player can win starting with `i` stones. The base case is `dp[0] = false` (no stones = current player loses).

---

## Approach

1. **DP State**: `dp[i]` = `true` if the current player can win with `i` stones, `false` otherwise.

2. **Base Case**: `dp[0] = false` — if no stones are left, the current player cannot move and loses.

3. **Transition**: For each `i` from 1 to `n`, try all possible square numbers `j*j` where `j*j <= i`:
   - If `dp[i - j*j] == false`, then the current player can move to a losing position for the opponent.
   - In that case, set `dp[i] = true` and break (no need to check further squares).

4. Return `dp[n]`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * sqrt(n))` — for each `i` up to `n`, we check squares up to `sqrt(i)` |
| **Space** | `O(n)` — DP array of size `n+1` |

Given `n <= 10^5`, this is efficient enough.

---

## Code (C++)

```cpp
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[0] = false;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
```

---

## Key Takeaways

- This is a standard **Win/Lose DP** (also called "game DP" or "combinatorial game DP").
- State: `dp[i]` = can current player force a win with `i` stones?
- Transition: try all valid moves (square numbers); if any move leads to opponent losing (`dp[i - move] == false`), current position is winning.
- The square number constraint makes this a variant of the "take-away game" with restricted moves.
- Time complexity `O(n * sqrt(n))` is acceptable for `n <= 10^5`.