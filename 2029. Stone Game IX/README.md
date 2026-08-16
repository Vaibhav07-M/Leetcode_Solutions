# 2029. Stone Game IX

**Difficulty:** `Medium`  
**Tags:** `Array`, `Math`, `Greedy`, `Counting`, `Game Theory`

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

[LeetCode — 2029. Stone Game IX](https://leetcode.com/problems/stone-game-ix/)

---

## Problem Summary

Alice and Bob take turns removing stones from a row, with Alice starting first.  
On each turn, a player may remove **any** stone. The player who removes a stone loses if the **sum of all removed stones so far** becomes divisible by `3`.  
If all stones are removed without this happening, Bob wins automatically.

Given the array `stones`, return `true` if Alice wins assuming both players play optimally.

---

## Examples

### Example 1
**Input:** `stones = [2,1]`  
**Output:** `true`  
**Explanation:**
- Turn 1: Alice removes either stone.
- Turn 2: Bob removes the remaining stone.
- The sum of removed stones is 1 + 2 = 3, divisible by 3, so Bob loses and Alice wins.

### Example 2
**Input:** `stones = [2]`  
**Output:** `false`  
**Explanation:**
- Alice removes the only stone; the sum is 2, not divisible by 3.
- All stones are gone, so Bob wins automatically.

### Example 3
**Input:** `stones = [5,1,2,4,3]`  
**Output:** `false`  
**Explanation:**
- Bob can always force the final sum to be divisible by 3 on Alice's turn, so Bob wins.

---

## Intuition

Only each stone's value **modulo 3** matters, since losing depends on the running sum being divisible by `3`.

- A stone with `value % 3 == 0` never changes the running sum mod 3 — it only **passes the turn** to the other player.
- Stones with remainder `1` and `2` change the running sum, and players must avoid making it hit `0 (mod 3)`.

So the whole game reduces to three counts: `count[0]`, `count[1]`, `count[2]`.

---

## Approach

1. **Count stones by remainder**: `count[r]` = number of stones with `stone % 3 == r`.
2. **Case 1 — `count[0]` is even**:
   - The "turn-passing" stones cancel out in pairs, so they don't change who is forced to lose.
   - Alice wins only if she can start a safe sequence, which requires **at least one stone of remainder 1 and one of remainder 2**.
   - Result: `min(count[1], count[2]) > 0`.
3. **Case 2 — `count[0]` is odd**:
   - The single unpaired `0`-stone flips the turn advantage once, shifting who gets forced into the losing move.
   - Alice wins only if one remainder type outnumbers the other by **more than 2**, giving her enough "safe" moves to outlast Bob.
   - Result: `abs(count[1] - count[2]) > 2`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass to count remainders |
| **Space** | `O(1)` — only three counters |

---

## Code (C++)

```cpp
class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    vector<int> count(3);

    for (const int stone : stones)
      ++count[stone % 3];

    if (count[0] % 2 == 0)
      return min(count[1], count[2]) > 0;
    return abs(count[1] - count[2]) > 2;
  }
};
```

---

## Key Takeaways

- In modulo-based games, reduce every value by its remainder — the actual magnitudes rarely matter.
- Stones divisible by 3 act as pure turn-passers; only their parity affects the outcome.
- Many game problems collapse to simple count comparisons once the losing pattern is identified.
