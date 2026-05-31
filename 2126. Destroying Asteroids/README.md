# 2126. Destroying Asteroids

**Difficulty:** `Medium`  
**Tags:** `Greedy`, `Sorting`

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

[LeetCode — 2126. Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/)

---

## Problem Summary

You are given an integer `mass`, which represents the original mass of a planet. You are further given an integer array `asteroids`, where `asteroids[i]` is the mass of the `i-th` asteroid.

You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return `true` if all asteroids can be destroyed. Otherwise, return `false`.

---

## Examples

### Example 1
**Input:** `mass = 10, asteroids = [3,9,19,5,21]`  
**Output:** `true`  
**Explanation:** One valid order is `[9,19,5,3,21]`. The planet absorbs each asteroid in turn and ends up with larger mass.

### Example 2
**Input:** `mass = 5, asteroids = [4,9,23,4]`  
**Output:** `false`  
**Explanation:** The planet cannot gain enough mass to destroy the asteroid with mass `23`.

---

## Intuition

To maximize chances of destroying all asteroids, collide with the smallest asteroids first so the planet can grow incrementally and absorb larger ones later. Sorting the `asteroids` array in non-decreasing order achieves this.

---

## Approach

1. Sort `asteroids` in ascending order.
2. Iterate through the sorted list; for each asteroid `a`:
   - If `mass >= a`, set `mass += a` and continue.
   - Otherwise, return `false`.
3. If all asteroids are absorbed, return `true`.

This greedy strategy is optimal because absorbing smaller asteroids earlier never reduces future absorption options.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n)` — sorting dominates |
| **Space** | `O(1)` extra space (in-place sort) |

---

## Code (C++)

```cpp
class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for (long long a : asteroids) {
            if (mass < a) return false;
            mass += a;
        }
        return true;
    }
};
```

---

## Key Takeaways

- Greedy: absorb smallest asteroids first to grow mass gradually.
- Sorting then linear scan yields a simple, correct solution.
- Watch integer size: `mass` can grow beyond 32-bit, use 64-bit where appropriate.
