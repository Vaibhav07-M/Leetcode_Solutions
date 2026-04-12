# 1320. Minimum Distance to Type a Word Using Two Fingers

**Difficulty:** `Hard`  
**Tags:** `String`, `Dynamic Programming`

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

[LeetCode - 1320. Minimum Distance to Type a Word Using Two Fingers](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)

---

## Problem Summary

Given a word of uppercase English letters, type it on the 6-column keyboard grid (`A` to `Z`) using two fingers.

- Moving a finger from `(x1, y1)` to `(x2, y2)` costs Manhattan distance:  
  `|x1 - x2| + |y1 - y2|`
- Initial placement of both fingers is free.

Return the minimum total movement cost to type the whole word.

---

## Examples

### Example 1
**Input:** `word = "CAKE"`  
**Output:** `3`

**Explanation:**
- Finger 1: `C -> A` costs `2`
- Finger 2: `K -> E` costs `1`
- Total = `3`

### Example 2
**Input:** `word = "HAPPY"`  
**Output:** `6`

**Explanation:**
- One optimal typing sequence gives total movement cost `6`.

---

## Intuition

At each character, we can type it with either finger.
That creates two choices per step, which suggests dynamic programming over states of both finger positions.

A state must capture:
- current index in `word`
- position of finger 1
- position of finger 2

Then try both transitions:
- move finger 1 to current letter
- move finger 2 to current letter

and take the minimum.

---

## Approach

1. Map each letter to grid coordinates with:
   - `row = (ch - 'A') / 6`
   - `col = (ch - 'A') % 6`
2. Use memoized recursion:
   - `solve(i, x1, y1, x2, y2)` = minimum cost to type from index `i` onward.
3. Base case:
   - if `i == word.size()`, return `0`.
4. For current character `word[i]` at `(x, y)`:
   - Option 1: type using finger 1 and pay distance from finger 1 (or `0` if unused).
   - Option 2: type using finger 2 and pay distance from finger 2 (or `0` if unused).
5. Cache and return the minimum of both options.

The provided implementation uses `-1, -1` as sentinel for an unused finger and offsets indices in the DP array by `+1`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * 27 * 27)` states in practice (bounded finger positions with sentinel), each with `O(1)` transitions |
| **Space** | `O(n * 27 * 27)` for memoization |

---

## Code (C++)

```cpp
class Solution {
public:

    int dp[301][7][7][7][7];

    pair<int, int> getCoordinate(char ch) {
        int pos = ch - 'A';
        return {pos / 6, pos % 6};
    }

    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int x1, int y1, int x2, int y2) {
        if (i == word.size())
            return 0;

        if (dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1)
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];

        auto [x, y] = getCoordinate(word[i]);

        // Case 1: first character, both fingers unused.
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = solve(word, i + 1, x, y, x2, y2);
        }

        // Case 2: second finger still unused.
        if (x2 == -1 && y2 == -1) {
            int moveF2 = solve(word, i + 1, x1, y1, x, y);

            int moveF1 = solve(word, i + 1, x, y, x2, y2)
                             + getDistance(x1, y1, x, y);

            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
        }

        // Case 3: both fingers already placed.
        int moveF1 = solve(word, i + 1, x, y, x2, y2)
                     + getDistance(x1, y1, x, y);

        int moveF2 = solve(word, i + 1, x1, y1, x, y)
                     + getDistance(x2, y2, x, y);

        return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1, -1, -1);
    }
};
```

---

## Key Takeaways

- This is a classic two-pointer-choice DP over typing sequence.
- Sentinel states let us model free initial finger placement cleanly.
- Memoization turns exponential branching into manageable state exploration.