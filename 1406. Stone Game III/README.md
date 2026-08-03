# 1406. Stone Game III

**Difficulty:** `Hard`  
**Tags:** `Dynamic Programming`, `Game Theory`, `Minimax`

---

## Table of Contents

- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Why This Works](#why-this-works)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

https://leetcode.com/problems/stone-game-iii/

---

## Problem Summary

Alice and Bob play a game on an array of stone values.

- Alice starts first.
- On each turn, a player can take **1, 2, or 3** stones from the beginning of the remaining array.
- Each player adds the values of the stones they take to their score.
- Both players play optimally.

Return:

- `"Alice"` if Alice wins.
- `"Bob"` if Bob wins.
- `"Tie"` if both end with the same score. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
stoneValue = [1,2,3,7]
```

**Output**

```text
Bob
```

---

### Example 2

**Input**

```text
stoneValue = [1,2,3,-9]
```

**Output**

```text
Alice
```

---

### Example 3

**Input**

```text
stoneValue = [1,2,3,6]
```

**Output**

```text
Tie
```

---

## Intuition

At every position, the current player has three choices:

- Take 1 stone.
- Take 2 stones.
- Take 3 stones.

Since the opponent also plays optimally, we store the **maximum score difference** the current player can achieve from every index.

If:

```
dp[i] > 0
```

the current player can finish with more points.

If:

```
dp[i] < 0
```

the opponent eventually wins.

---

## Approach

Let:

```
dp[i]
```

be the maximum score difference (current player − opponent) starting from index `i`.

Transition:

For every index:

- Take 1 stone
- Take 2 stones
- Take 3 stones

Suppose the current collected sum is:

```
sum
```

After taking those stones, the opponent starts from:

```
i + k + 1
```

The opponent can achieve:

```
dp[i+k+1]
```

So the current player's net advantage becomes:

```
sum - dp[i+k+1]
```

Take the maximum among all valid choices.

Finally,

- `dp[0] > 0` → Alice
- `dp[0] < 0` → Bob
- `dp[0] == 0` → Tie

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};
```

---

## Why This Works

Suppose

```text
stoneValue = [1,2,3,7]
```

Work backwards.

```
dp[4] = 0
```

Index 3:

```
Take 7

dp[3] = 7
```

Index 2:

```
Take 3

3 - dp[3]
```

or

```
Take 3+7

10
```

Choose the larger value.

Continue similarly until index 0.

The DP always represents the best possible score difference assuming both players make optimal moves.

---

## Key Takeaways

- This is a classic **game DP** problem.
- `dp[i]` stores the maximum score difference from index `i`.
- At every step, try taking 1, 2, or 3 stones.
- Subtract the opponent's optimal result because turns alternate.
- The sign of `dp[0]` directly determines the winner.
- Time Complexity is **O(n)** with **O(n)** extra space.