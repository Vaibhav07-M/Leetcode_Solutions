# 2833. Furthest Point From Origin

**Difficulty:** `Easy`  
**Tags:** `String`, `Math`

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

[LeetCode — 2833. Furthest Point From Origin](https://leetcode.com/problems/furthest-point-from-origin/)

---

## Problem Summary

You start at position `0` on a number line and are given a string `moves`:
- `'L'` means move left by 1
- `'R'` means move right by 1
- `'_'` means you can choose either left or right

Return the maximum possible distance from origin after performing all moves.

---

## Examples

### Example 1
**Input:** `moves = "L_RL__R"`  
**Output:** `3`

### Example 2
**Input:** `moves = "_R__LL_"`  
**Output:** `5`

### Example 3
**Input:** `moves = "_______"`  
**Output:** `7`

---

## Intuition

Fixed moves (`L` and `R`) create a base displacement of `R - L`.
Each blank (`_`) can be used in the direction that increases the absolute value of final displacement.
So every blank contributes `+1` to the maximum possible distance from origin.

That gives:

`maxDistance = |R - L| + blanks`

---

## Approach

1. Count how many `'L'`, `'R'`, and `'_'` appear in `moves`.
2. Compute base displacement magnitude: `abs(R - L)`.
3. Add the number of blanks because each can be assigned to increase distance.
4. Return `abs(R - L) + blank`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;
        
        for(char c : moves) {
            if(c == 'L') L++;
            else if(c == 'R') R++;
            else blank++;
        }
        
        return abs(R - L) + blank;
    }
};
```

---

## Key Takeaways

- Separate fixed effect (`L` vs `R`) from flexible effect (`_`).
- Blanks are always best used in one direction to maximize absolute distance.
- A counting-based formula avoids any simulation branching.
