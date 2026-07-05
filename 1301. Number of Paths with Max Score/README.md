# 1301. Number of Paths with Max Score

**Difficulty:** `Hard`  
**Tags:** `Dynamic Programming`, `Matrix`

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

[LeetCode — 1301. Number of Paths with Max Score](https://leetcode.com/problems/number-of-paths-with-max-score/)

---

## Problem Summary

You are given an `n × n` board consisting of:

- `E` (starting destination)
- `S` (starting position)
- Digits `1`–`9`
- Obstacles `X`

Starting from `S` (bottom-right), you may move:

- Up
- Left
- Up-left (diagonally)

Your goal is to reach `E` (top-left).

Return:

- The **maximum score** obtainable by collecting numeric cells.
- The **number of paths** achieving this maximum score modulo `10⁹ + 7`.

If no valid path exists, return:

```text
[0, 0]
```

:contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
board = ["E23","2X2","12S"]
```

**Output:**

```cpp
[7,1]
```

---

### Example 2

**Input:**

```cpp
board = ["E12","1X1","21S"]
```

**Output:**

```cpp
[4,2]
```

---

### Example 3

**Input:**

```cpp
board = ["E11","XXX","11S"]
```

**Output:**

```cpp
[0,0]
```

---

## Intuition

Since movement is only upward, leftward, or diagonally upward-left, we can process the board **from bottom-right to top-left**.

For every cell, we maintain:

- The maximum score obtainable from that cell to `S`.
- The number of ways to achieve that maximum score.

When multiple neighboring cells provide the same maximum score, we add their path counts.

This naturally leads to a Dynamic Programming solution.

---

## Approach

### 1. Initialize DP Tables

Maintain two matrices:

- `dp[i][j]` → maximum score from `(i, j)` to `S`
- `ways[i][j]` → number of optimal paths

Initialize:

```cpp
dp[n-1][n-1] = 0;
ways[n-1][n-1] = 1;
```

---

### 2. Process Cells in Reverse Order

Traverse from bottom-right toward top-left.

Skip:

- Obstacles (`X`)
- The starting cell (`S`)

For every cell, consider the three possible previous positions:

- Down
- Right
- Down-right

Among all reachable neighbors:

- Choose the largest DP value.
- Sum the number of ways for neighbors having that same value.

---

### 3. Add Current Cell Value

If the current cell contains a digit:

```cpp
dp[i][j] += digit
```

The cell `E` contributes `0`.

---

### 4. Return the Answer

If the destination is unreachable:

```cpp
return {0, 0};
```

Otherwise return:

```cpp
{dp[0][0], ways[0][0]}
```

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n²)` |
| **Space** | `O(n²)` |

---

## Code (C++)

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                long long cnt = 0;

                vector<pair<int,int>> prev = {
                    {i + 1, j},
                    {i, j + 1},
                    {i + 1, j + 1}
                };

                for (auto [x, y] : prev) {
                    if (x >= n || y >= n) continue;
                    if (dp[x][y] == -1) continue;

                    if (dp[x][y] > best) {
                        best = dp[x][y];
                        cnt = ways[x][y];
                    } else if (dp[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                if (best == -1) continue;

                int val = 0;
                if (board[i][j] != 'E')
                    val = board[i][j] - '0';

                dp[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if (dp[0][0] == -1)
            return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};
```

---

## Key Takeaways

- Use Dynamic Programming to compute the maximum score from every cell.
- Maintain a second DP table to count the number of optimal paths.
- Process the board in reverse because moves are restricted to up, left, and diagonal.
- When multiple neighbors have the same maximum score, sum their path counts modulo `10⁹ + 7`.
- If the destination cannot be reached, return `[0, 0]`.