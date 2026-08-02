# 877. Stone Game

**Difficulty:** `Medium`  
**Tags:** `Dynamic Programming`, `Game Theory`, `Minimax`, `Math`

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

[LeetCode – 877. Stone Game](https://leetcode.com/problems/stone-game/)

---

## Problem Summary

Alice and Bob take turns picking an entire pile of stones from either the beginning or the end of the row.

- Alice always moves first.
- Both players play optimally.
- The number of piles is even.
- The total number of stones is odd, so a tie is impossible.

Return **true** if Alice wins; otherwise, return **false**. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
piles = [5,3,4,5]
```

**Output**

```text
true
```

---

### Example 2

**Input**

```text
piles = [3,7,2,3]
```

**Output**

```text
true
```

---

## Intuition

Unlike the general "Predict the Winner" problem, this problem has a special property:

- The number of piles is **even**.
- Alice moves first.

Before the game starts, Alice can decide to always take either:

- the piles originally at **even indices**, or
- the piles originally at **odd indices**.

Since one of these two groups has a larger total number of stones (the total sum is odd), Alice chooses that group and can always force Bob into leaving those piles available.

Therefore, Alice always has a winning strategy.

---

## Approach

Simply return `true`.

No simulation, dynamic programming, or recursion is needed because the mathematical property guarantees Alice's victory.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(1)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

---

## Why This Works

Suppose the piles are:

```text
a b c d e f
```

Alice observes two groups:

- Even-indexed piles → `a + c + e`
- Odd-indexed piles → `b + d + f`

One group must contain more stones because the total sum is odd.

On her first move, Alice picks from the end that lets her commit to that group. After every move Bob makes, Alice can always continue taking from her chosen parity.

Thus Alice guarantees collecting the larger-sum group and therefore always wins.

---

## Key Takeaways

- This is a special case of a two-player game.
- Although it appears to require DP or Minimax, the constraints make the answer much simpler.
- Alice can always force herself to collect either all even-indexed or all odd-indexed piles.
- Since the total number of stones is odd, one parity must have a strictly larger sum.
- Therefore, Alice always wins, so the solution is simply `return true;`.