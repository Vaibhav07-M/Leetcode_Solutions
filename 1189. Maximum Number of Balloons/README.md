# 1189. Maximum Number of Balloons

**Difficulty:** `Easy`  
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

[LeetCode — 1189. Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)

---

## Problem Summary

Given a string `text`, determine the maximum number of times the word:

```text
"balloon"
```

can be formed using the characters of `text`.

Each character in `text` can be used at most once.

Return the maximum number of complete instances of `"balloon"` that can be constructed.

---

## Examples

### Example 1

**Input:**

```cpp
text = "nlaebolko"
```

**Output:**

```cpp
1
```

**Explanation:**

The characters can form exactly one `"balloon"`.

---

### Example 2

**Input:**

```cpp
text = "loonbalxballpoon"
```

**Output:**

```cpp
2
```

**Explanation:**

The characters can form `"balloon"` two times.

---

### Example 3

**Input:**

```cpp
text = "leetcode"
```

**Output:**

```cpp
0
```

**Explanation:**

The required characters are insufficient to form `"balloon"`.

---

## Intuition

To build the word:

```text
balloon
```

we need:

```text
b → 1
a → 1
l → 2
o → 2
n → 1
```

The maximum number of balloons that can be formed depends on the character with the smallest available count relative to its requirement.

So we simply count the frequency of each character and compute how many complete `"balloon"` words can be made.

---

## Approach

### 1. Count Character Frequencies

Create a frequency array:

```cpp
cnt[26]
```

and count the occurrences of every character in `text`.

---

### 2. Check Required Characters

For the word:

```text
balloon
```

the required frequencies are:

```cpp
b = 1
a = 1
l = 2
o = 2
n = 1
```

Since `l` and `o` appear twice, divide their counts by `2`.

---

### 3. Find the Limiting Character

The answer is the minimum among:

```cpp
cnt['b']
cnt['a']
cnt['l'] / 2
cnt['o'] / 2
cnt['n']
```

because the least available required character determines how many complete words can be formed.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

Where `n` is the length of `text`.

---

## Code (C++)

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> cnt(26, 0);

        for(char c : text)
            cnt[c - 'a']++;

        return min({
            cnt['b' - 'a'],
            cnt['a' - 'a'],
            cnt['l' - 'a'] / 2,
            cnt['o' - 'a'] / 2,
            cnt['n' - 'a']
        });
    }
};
```

---

## Key Takeaways

- Count the frequency of all characters.
- Focus only on characters required for `"balloon"`.
- Characters `'l'` and `'o'` are needed twice, so divide their counts by `2`.
- The limiting character determines the answer.
- The solution runs in `O(n)` time with `O(1)` extra space.