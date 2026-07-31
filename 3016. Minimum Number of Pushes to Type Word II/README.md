# 3016. Minimum Number of Pushes to Type Word II

**Difficulty:** `Medium`  
**Tags:** `Greedy`, `Hash Table`, `Sorting`, `String`

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

[LeetCode – 3016. Minimum Number of Pushes to Type Word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/)

---

## Problem Summary

You are given a string `word` consisting of lowercase English letters.

You may freely remap the letters onto the **8 telephone keys (2–9)**. Unlike Part I, letters may appear multiple times.

Return the **minimum total number of key presses** required to type the entire word after choosing the optimal mapping. :contentReference[oaicite:0]{index=0}

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

---

### Example 2

**Input**

```text
word = "xyzxyzxyzxyz"
```

**Output**

```text
12
```

---

### Example 3

**Input**

```text
word = "aabbccddeeffgghhiiiiii"
```

**Output**

```text
24
```

---

## Intuition

Since some letters appear more frequently than others, the most frequent letters should require the fewest key presses.

Therefore:

- Count the frequency of every character.
- Sort the frequencies in descending order.
- Assign:
  - the first **8** most frequent letters a cost of **1**,
  - the next **8** a cost of **2**,
  - the remaining letters a cost of **3**, and so on.

This greedy assignment minimizes the total number of pushes.

---

## Approach

1. Count the occurrences of every lowercase letter.
2. Sort the frequency array in descending order.
3. Traverse the sorted frequencies.
4. For the `i`-th most frequent character:
   - its push cost is `(i / 8) + 1`.
5. Multiply the frequency by its push cost and add it to the answer.
6. Stop once all remaining frequencies are zero.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Time** | `O(n + 26 log 26)` ≈ `O(n)` |
| **Space** | `O(26)` ≈ `O(1)` |

where `n` is the length of `word`.

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};
```

---

## Key Takeaways

- Assign the smallest push counts to the most frequently used letters.
- Frequency sorting makes the greedy assignment straightforward.
- Every block of **8** letters shares the same push cost.
- The cost for the `i`-th most frequent letter is `(i / 8) + 1`.
- Since the alphabet size is fixed (26 letters), sorting is effectively constant time, giving an overall **O(n)** solution.