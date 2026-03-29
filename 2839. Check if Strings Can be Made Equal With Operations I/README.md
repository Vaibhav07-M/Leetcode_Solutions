# 2839. Check if Strings Can be Made Equal With Operations I

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

[LeetCode — 2839. Check if Strings Can be Made Equal With Operations I](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)

---

## Problem Summary

You are given two strings `s1` and `s2`, both of length 4, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:
- Choose any two indices `i` and `j` such that `j - i = 2`, then swap the two characters at those indices in the string.

Return `true` if you can make the strings `s1` and `s2` equal, and `false` otherwise.

---

## Examples

### Example 1
**Input:** `s1 = "abcd", s2 = "cdab"`  
**Output:** `true`  
**Explanation:**
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.

### Example 2
**Input:** `s1 = "abcd", s2 = "dacb"`  
**Output:** `false`  
**Explanation:** It is not possible to make the two strings equal.

---

## Intuition

The key insight is recognizing that with the operation constraint `j - i = 2`, we can only swap characters at positions that are exactly 2 apart.

In a string of length 4, we have two groups:
- **Group 1:** Indices 0 and 2
- **Group 2:** Indices 1 and 3

Since we can perform unlimited swaps within each group, characters within the same group can be rearranged freely, but characters cannot move between groups.

Therefore, we just need to check if both strings have the same multiset of characters in each group.

---

## Approach

1. Extract the characters at indices 0 and 2 from both strings (Group 1).
2. Extract the characters at indices 1 and 3 from both strings (Group 2).
3. Sort each group separately to get canonical representations.
4. Check if Group 1 from `s1` matches Group 1 from `s2` AND Group 2 from `s1` matches Group 2 from `s2`.

This greedy approach guarantees correctness because each group is independent.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(1)` — fixed size strings of length 4, sorting is constant |
| **Space** | `O(1)` — only using fixed-size vectors |

---

## Code (C++)

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Group 1: index 0, 2
        vector<char> a = {s1[0], s1[2]};
        vector<char> b = {s2[0], s2[2]};
        
        // Group 2: index 1, 3
        vector<char> c = {s1[1], s1[3]};
        vector<char> d = {s2[1], s2[3]};
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        
        return (a == b && c == d);
    }
};
```

---

## Key Takeaways

1. **Group Independence:** When swaps are restricted to specific positions, it creates independent groups. Recognize this pattern to simplify the problem.
2. **Sorting for Comparison:** Sorting small collections makes it trivial to check if they contain the same elements regardless of order.
3. **Fixed Constraints:** With a fixed string length and operation constraints, the solution becomes deterministic and simple.
4. **Avoid Over-Complication:** Despite the operation description, the actual solution is straightforward once the group pattern is identified.
