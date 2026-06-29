# 1967. Number of Strings That Appear as Substrings in Word

**Difficulty:** `Easy`  
**Tags:** `String`

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

[LeetCode — 1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)

---

## Problem Summary

You are given:

- An array of strings `patterns`.
- A string `word`.

Return the number of strings in `patterns` that appear as a **substring** of `word`.

A substring is a contiguous sequence of characters within a string. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input:**

```cpp
patterns = ["a","abc","bc","d"]
word = "abc"
```

**Output:**

```cpp
3
```

**Explanation:**

The substrings `"a"`, `"abc"`, and `"bc"` are present in `"abc"`, while `"d"` is not.

---

### Example 2

**Input:**

```cpp
patterns = ["a","b","c"]
word = "aaaaabbbbb"
```

**Output:**

```cpp
2
```

**Explanation:**

Only `"a"` and `"b"` appear as substrings.

---

### Example 3

**Input:**

```cpp
patterns = ["a","a","a"]
word = "ab"
```

**Output:**

```cpp
3
```

**Explanation:**

Each occurrence in `patterns` is counted separately, and every `"a"` appears as a substring of `"ab"`.

---

## Intuition

The C++ string function:

```cpp
find()
```

can directly determine whether one string exists as a substring of another.

For every string in `patterns`, we simply check whether it occurs inside `word`.

If it does, increment the answer.

---

## Approach

1. Initialize the answer as `0`.
2. Traverse every string in `patterns`.
3. For each pattern:
   - Use:
     ```cpp
     word.find(pattern)
     ```
   - If the returned value is not:
     ```cpp
     string::npos
     ```
     then the pattern exists as a substring.
4. Increment the answer for every matching pattern.
5. Return the final count.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n × m × k)` in the worst case, where `n` is the number of patterns, `m` is the length of `word`, and `k` is the average pattern length |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &s : patterns) {
            if (word.find(s) != string::npos)
                ans++;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Use the built-in `find()` function to check whether a substring exists.
- Count every pattern independently, including duplicates.
- `string::npos` indicates that the substring was not found.
- The solution is straightforward and requires only a single pass through the `patterns` array.