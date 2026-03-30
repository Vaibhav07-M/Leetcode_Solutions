# 2840. Check if Strings Can be Made Equal With Operations II

**Difficulty:** `Medium`  
**Tags:** `String`, `Hash Table`, `Counting`

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

[LeetCode - 2840. Check if Strings Can be Made Equal With Operations II](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)

---

## Problem Summary

You are given two strings `s1` and `s2` of equal length `n`.

You can perform this operation any number of times on either string:
- Pick indices `i < j` such that `(j - i)` is even, then swap `s[i]` and `s[j]`.

Return `true` if it is possible to make `s1` equal to `s2`, otherwise return `false`.

---

## Examples

### Example 1
**Input:** `s1 = "abcdba", s2 = "cabdab"`  
**Output:** `true`

### Example 2
**Input:** `s1 = "abe", s2 = "bea"`  
**Output:** `false`

---

## Intuition

If `(j - i)` is even, then `i` and `j` always have the same parity.
So swaps are only possible:
- among even indices
- among odd indices

That means characters can move freely inside their parity group, but never cross from even to odd or odd to even.

So the condition for equality is:
- even-index character multiset of `s1` must match even-index character multiset of `s2`
- odd-index character multiset of `s1` must match odd-index character multiset of `s2`

---

## Approach

1. Create four frequency arrays of size 26:
   - even positions in `s1`, even positions in `s2`
   - odd positions in `s1`, odd positions in `s2`
2. Traverse the strings once:
   - if index is even, update even frequency arrays
   - else, update odd frequency arrays
3. Compare:
   - `even1 == even2` and `odd1 == odd2`
4. Return the result.

This works because parity groups are independent under the allowed swap rule.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` extra space (fixed-size 26 arrays) |

---

## Code (C++)

```cpp
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even1(26, 0), even2(26, 0);
        vector<int> odd1(26, 0), odd2(26, 0);

        int n = s1.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        return (even1 == even2 && odd1 == odd2);
    }
};
```

---

## Key Takeaways

- Check what an operation preserves; here, index parity is invariant.
- Convert reachability-by-swaps problems into multiset matching.
- Frequency counting avoids sorting and keeps the solution linear.
