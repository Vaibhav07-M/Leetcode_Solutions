# 486. Predict the Winner

**Difficulty:** `Medium`  
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
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode – 486. Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

---

## Problem Summary

Two players take turns choosing a number from either end of an array. Each chosen number is added to the player's score.

Both players play optimally.

Return **true** if Player 1 can obtain a score **greater than or equal to** Player 2's score; otherwise, return **false**. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
nums = [1,5,2]
```

**Output**

```text
false
```

**Explanation**

No matter whether Player 1 picks `1` or `2`, Player 2 can take `5`, resulting in Player 1 losing.

---

### Example 2

**Input**

```text
nums = [1,5,233,7]
```

**Output**

```text
true
```

**Explanation**

Player 1 can force taking `233`, guaranteeing a higher final score.

---

## Intuition

Instead of tracking the absolute scores of both players, we track the **maximum score difference** the current player can achieve over the opponent.

For any subarray:

- Picking the left number gives:

  ```text
  nums[i] - opponent's best difference
  ```

- Picking the right number gives:

  ```text
  nums[j] - opponent's best difference
  ```

The current player chooses whichever option yields the larger score difference.

If the final score difference is non-negative, Player 1 can win (or tie).

---

## Approach

1. Let `dp[i][j]` represent the maximum score difference the current player can obtain from the subarray `nums[i...j]`.
2. Base case:
   - `dp[i][i] = nums[i]`.
3. Process subarrays in increasing order of length.
4. Transition:

```text
dp[i][j] =
max(
    nums[i] - dp[i+1][j],
    nums[j] - dp[i][j-1]
)
```

5. Return whether `dp[0][n-1] >= 0`.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n²)` |
| **Space** | `O(n²)` |

where `n` is the number of elements.

---

## Code (C++)

```cpp
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
```

---

## Key Takeaways

- Model the game using **score difference**, not individual scores.
- `dp[i][j]` stores the maximum advantage the current player can secure from the subarray.
- Each choice subtracts the opponent's optimal advantage because turns alternate.
- Filling the DP table by increasing subarray length ensures required states are already computed.
- If the final score difference is **non-negative**, Player 1 can guarantee at least a tie, which counts as a win.