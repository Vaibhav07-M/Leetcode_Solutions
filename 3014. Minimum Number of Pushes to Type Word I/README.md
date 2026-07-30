# 3014. Minimum Number of Pushes to Type Word I

**Difficulty:** `Easy`  
**Tags:** `Greedy`, `Math`, `String`

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

[LeetCode – 3014. Minimum Number of Pushes to Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/)

---

## Problem Summary

You are given a string `word` consisting of **distinct lowercase English letters**.

You may remap the letters onto the **8 telephone keys (2–9)** in any way. The first letter assigned to a key requires **1 push**, the second requires **2 pushes**, and so on.

Return the minimum total number of key presses required to type the word.

---

## Examples

### Example 1

**Input**

```text
word = "abcde"
```

**Output**

```text
5
```

**Explanation**

Each of the five letters can occupy the first position on a different key, requiring only one push each.

---

### Example 2

**Input**

```text
word = "xycdefghij"
```

**Output**

```text
12
```

**Explanation**

The first eight letters occupy the first position on the eight keys.

The remaining two letters occupy the second position, requiring two pushes each.

```text
8 × 1 + 2 × 2 = 12
```

---

## Intuition

There are **8 available keys**.

To minimize the total number of pushes:

- Put the first **8 letters** in position **1**.
- The next **8 letters** in position **2**.
- The next **8 letters** in position **3**, and so on.

Since every character appears exactly once, only the number of assigned positions matters.

---

## Approach

1. Let `n` be the number of distinct letters.
2. Iterate through each letter index.
3. Every group of eight letters has the same push count.
4. The push cost for index `i` is:

```text
(i / 8) + 1
```

5. Sum these costs and return the answer.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n)` |
| **Space** | `O(1)` |

where `n` is the length of `word`.

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += i / 8 + 1;
        }

        return ans;
    }
};
```

---

## Key Takeaways

- There are exactly **8 keys** available for letter assignments.
- Every group of **8 letters** shares the same push count.
- The push cost for the `i`-th assigned letter is `(i / 8) + 1`.
- Since all letters are distinct, no frequency counting is required.
- The greedy assignment yields the minimum total pushes in **O(n)** time.