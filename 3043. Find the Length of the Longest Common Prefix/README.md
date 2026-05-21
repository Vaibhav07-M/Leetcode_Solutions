# 3043. Find the Length of the Longest Common Prefix

**Difficulty:** `Medium`  
**Tags:** `Trie`

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

[LeetCode — 3043. Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/)

---

## Problem Summary

You are given two arrays with positive integers `arr1` and `arr2`.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, `123` is a prefix of the integer `12345`, while `234` is not.

A common prefix of two integers `a` and `b` is an integer `c`, such that `c` is a prefix of both `a` and `b`.

Return the length of the longest common prefix among all pairs `(x, y)` where `x` belongs to `arr1` and `y` belongs to `arr2`. If no common prefix exists, return `0`.

---

## Examples

### Example 1
**Input:** `arr1 = [1,10,100], arr2 = [1000]`  
**Output:** `3`  
**Explanation:** The longest common prefix among pairs is `100` (length 3).

### Example 2
**Input:** `arr1 = [1,2,3], arr2 = [4,4,4]`  
**Output:** `0`  
**Explanation:** No common prefix across any pair.

---

## Intuition

Treat each number as a string of digits. All prefixes of numbers in `arr1` can be collected into a set. Then, for every number in `arr2`, generate its prefixes and check membership in the set to find the longest matching prefix.

This avoids comparing every pair directly and is efficient because the maximum number length (digits) is small (≤ 9 for constraints). 

---

## Approach

1. Convert each number in `arr1` to a string and insert every its digit-prefix into an `unordered_set<string>`.
2. For each number in `arr2`, convert to string and iterate its prefixes; if a prefix exists in the set, update the answer with the prefix length.
3. Return the maximum prefix length found.

This is simple, robust, and fast given the small digit-length bound.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + m) * L^2)` worst-case where `L` is max digits (small, ≤9). Practically `O(n + m)` for fixed small `L`. |
| **Space** | `O(P * L)` where `P` is number of prefixes stored (≤ `n * L`). |

---

## Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        prefixes.reserve(arr1.size() * 3);

        for (int x : arr1) {
            string s = to_string(x);
            string p;
            p.reserve(s.size());
            for (char c : s) {
                p.push_back(c);
                prefixes.insert(p);
            }
        }

        int ans = 0;
        for (int y : arr2) {
            string s = to_string(y);
            string p;
            p.reserve(s.size());
            for (char c : s) {
                p.push_back(c);
                if (prefixes.find(p) != prefixes.end()) ans = max(ans, (int)p.size());
            }
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Convert numbers to digit-strings to reason about prefixes easily.
- Storing prefixes from one array and checking against the other is efficient because digit-length is bounded.
- This approach generalizes to other prefix-based matching problems.
