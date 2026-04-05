# 657. Robot Return to Origin

**Difficulty:** `Easy`  
**Tags:** `String`, `Simulation`

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

[LeetCode - 657. Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/)

---

## Problem Summary

A robot starts at the origin `(0, 0)` on a 2D plane.
You are given a string `moves` where each character is one move:
- `U` -> up
- `D` -> down
- `L` -> left
- `R` -> right

Return `true` if the robot ends at the origin after all moves, else return `false`.

---

## Examples

### Example 1
**Input:** `moves = "UD"`  
**Output:** `true`  
**Explanation:** One up and one down cancel out.

### Example 2
**Input:** `moves = "LL"`  
**Output:** `false`  
**Explanation:** Two left moves do not return to origin.

---

## Intuition

To return to origin:
- number of `U` moves must equal number of `D` moves
- number of `L` moves must equal number of `R` moves

If both balances hold, the final displacement on both axes is zero.

---

## Approach

1. Count occurrences of `U`, `D`, `L`, and `R` in the string.
2. Check if `U == D` and `L == R`.
3. Return the result.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` where `n = moves.length` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, D = 0, L = 0, R = 0;
        
        for(char c : moves) {
            if(c == 'U') U++;
            else if(c == 'D') D++;
            else if(c == 'L') L++;
            else if(c == 'R') R++;
        }
        
        return (U == D && L == R);
    }
};
```

---

## Key Takeaways

- Break 2D movement into independent axis balances.
- Equal opposite moves imply zero net displacement.
- A single linear scan is enough for this problem.
