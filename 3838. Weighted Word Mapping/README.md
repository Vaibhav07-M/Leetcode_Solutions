# 3838. Weighted Word Mapping

**Difficulty:** `Easy`  
**Tags:** `Array`, `String`, `Math`

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

[LeetCode — 3838. Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/)

---

## Problem Summary

You are given an array of strings `words`, where each string consists of lowercase English letters.  
You are also given an integer array `weights` of length 26, where `weights[i]` represents the weight of the `i-th` lowercase English letter.

The **weight of a word** is defined as the sum of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using **reverse alphabetical order**:
- 0 → 'z'
- 1 → 'y'
- ...
- 25 → 'a'

Return a string formed by concatenating the mapped characters for all words in order.

---

## Examples

### Example 1
**Input:** `words = ["abcd","def","xyz"]`, `weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]`  
**Output:** `"rij"`  
**Explanation:**
- Weight of "abcd" = 5+3+12+14 = 34 → 34 % 26 = 8 → 'z' - 8 = 'r'
- Weight of "def" = 14+1+2 = 17 → 17 % 26 = 17 → 'z' - 17 = 'i'
- Weight of "xyz" = 7+7+2 = 16 → 16 % 26 = 16 → 'z' - 16 = 'j'
- Result: "rij"

### Example 2
**Input:** `words = ["a","b","c"]`, `weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]`  
**Output:** `"yyy"`  
**Explanation:**
- Each word has weight 1 → 1 % 26 = 1 → 'z' - 1 = 'y'
- Result: "yyy"

---

## Intuition

For each word, we need to:
1. Compute the sum of weights of all its characters
2. Take that sum modulo 26
3. Map the result to a letter using reverse alphabetical order

The mapping formula is straightforward: if `rem` is the remainder, the corresponding letter is `'z' - rem`. This is because:
- rem = 0 → 'z'
- rem = 1 → 'y'
- ...
- rem = 25 → 'a'

---

## Approach

1. **Iterate through each word** in the input array.
2. **For each word**, compute the sum of weights of all characters by looking up each character's weight in the `weights` array using `weights[ch - 'a']`.
3. **Take the sum modulo 26** to get the remainder.
4. **Map to letter** using `'z' - rem` (reverse alphabetical order).
5. **Append the mapped character** to the result string.
6. **Return the result** after processing all words.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n * m)` — where n = number of words, m = average length of words |
| **Space** | `O(1)` extra space (excluding output string) |

---

## Code (C++)

```cpp
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans;

        for (string &word : words) {
            long long sum = 0;
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int rem = sum % 26;

            ans.push_back('z' - rem);
        }


        return ans;
    }
};
```

---


## Key Takeaways

- Character weight lookup is O(1) using array indexing.
- The reverse alphabetical mapping is simple: `'z' - rem`.
- This is a straightforward simulation problem — just follow the steps defined in the problem.
