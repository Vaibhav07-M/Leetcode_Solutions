# 3723. Maximize Sum of Squares of Digits

**Difficulty:** `Medium`  
**Tags:** `Math`, `Greedy`

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

[LeetCode — 3723. Maximize Sum of Squares of Digits](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)

---

## Problem Summary

You are given two positive integers num and sum.  
A positive integer n is good if it satisfies both of the following:

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around math, greedy. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — each element/state processed once |
| **Space** | `O(1)` — only a few variables |

---

## Code (C++)

```cpp

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                ans += '9';
                sum -= 9;
            } else {
                ans += char('0' + sum);
                sum = 0;
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Math, Greedy patterns often reduce an apparently complex problem to a few simple rules.
