# 3360. Stone Removal Game

**Difficulty:** `Easy`  
**Tags:** `Math`, `Simulation`

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

[LeetCode — 3360. Stone Removal Game](https://leetcode.com/problems/stone-removal-game/)

---

## Problem Summary

The problem involves a two-player game where Alice and Bob take turns removing stones from a pile. Alice starts by removing 10 stones, and each subsequent turn requires removing one fewer stone than the previous opponent. The goal is to determine if Alice can win the game, which depends on whether the total number of stones allows for a sufficient number of turns to reach a winning position.

---

## Examples

_No examples provided._

---

## Intuition

The key insight is that the game progresses in a specific pattern: Alice removes 10, then Bob removes 9, then Alice removes 8, and so on. This creates a sequence of decreasing removals. The outcome depends on whether the total number of stones (n) is sufficient to complete an odd or even number of these 'steps' before the pile is exhausted. Since Alice wins if she makes the last move, we need to check if the number of steps taken is odd (meaning Alice ends the game).

---

## Approach

1. Initialize a variable 'take' to 10 (the number of stones Alice removes on her first turn) and 'steps' to 0.
2. Enter a while loop that continues as long as the number of stones 'n' is greater than or equal to the current 'take' value.
3. Inside the loop, subtract the current 'take' value from 'n', decrement 'take' by 1 (to prepare for the next turn), and increment 'steps' by 1.
4. After the loop ends, check if the number of steps is odd ('steps % 2 == 1'). If it is, Alice wins because she made the last move; if it is even, Bob wins.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(sqrt(n))` — The loop iterates while 'take' is greater than 0. Since 'take' starts at 10 and decreases by 1 each iteration, the number of iterations is approximately proportional to the square root of the total number of stones, as the sum of the first k integers is roughly k^2 / 2. |
| **Space** | `O(1)` — The solution uses only a few integer variables ('take', 'steps', and 'n') and does not require any additional data structures or arrays, making the space complexity constant. |

---

## Code (C++)

```cpp
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};
```

---

## Key Takeaways

- The game outcome is determined by the parity of the number of turns completed, not the absolute number of stones removed.
- The decreasing removal pattern creates a specific rhythm where the winner is the player who completes the last full cycle of the pattern.
- The time complexity is bounded by the square root of the input size due to the geometric nature of the stone removal sequence.
