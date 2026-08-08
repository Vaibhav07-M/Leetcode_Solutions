# 3302. Find the Lexicographically Smallest Valid Sequence

**Difficulty:** `Medium`  
**Tags:** `String`, `Greedy`, `Two Pointers`

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

[LeetCode — 3302. Find the Lexicographically Smallest Valid Sequence](https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/)

---

## Problem Summary

You are given two strings `word1` and `word2`.

A string `x` is called **almost equal** to `y` if you can change **at most one character** in `x` to make it identical to `y`.

A sequence of indices `seq` is called **valid** if:

1. The indices are sorted in ascending order.
2. Concatenating the characters at these indices in `word1` in the same order results in a string that is **almost equal** to `word2`.

Return an array of size `word2.length` representing the **lexicographically smallest valid sequence** of indices. If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest **array**, not the corresponding string formed by those indices.

---

## Examples

### Example 1
**Input:** `word1 = "vbcca", word2 = "abc"`  
**Output:** `[0,1,2]`  
**Explanation:**
The lexicographically smallest valid sequence of indices is `[0, 1, 2]`:
- Change `word1[0]` to `'a'`.
- `word1[1]` is already `'b'`.
- `word1[2]` is already `'c'`.

### Example 2
**Input:** `word1 = "bacdc", word2 = "abc"`  
**Output:** `[1,2,4]`  
**Explanation:**
The lexicographically smallest valid sequence of indices is `[1, 2, 4]`:
- `word1[1]` is already `'a'`.
- Change `word1[2]` to `'b'`.
- `word1[4]` is already `'c'`.

### Example 3
**Input:** `word1 = "aaaaaa", word2 = "aaabc"`  
**Output:** `[]`  
**Explanation:**
There is no valid sequence of indices.

### Example 4
**Input:** `word1 = "abc", word2 = "ab"`  
**Output:** `[0,1]`

---

## Intuition

We need to find a subsequence of indices in `word1` that matches `word2` with at most one character change. To get the **lexicographically smallest** sequence of indices, we should greedily pick the earliest possible index for each character in `word2`.

The key insight is to precompute how many characters from the end of `word2` can be matched from each position in `word1` (going right-to-left). This allows us to know, at any position `i` in `word1`, whether we can afford to "use" our one character change here and still complete the rest of `word2` from the remaining characters.

---

## Approach

1. **Precompute suffix matches** — Traverse `word1` from right to left, tracking how many characters of `word2` (from the end) can be matched. Store this in `rightHandSideMatchLength[i]` = number of characters of `word2` suffix that can be matched starting from `word1[i]`.

2. **Greedy left-to-right construction** — Traverse `word1` from left to right, building the answer sequence:
   - If `word1[i] == word2[j]`, take this index (no change needed).
   - Else if we still have our "change power" (haven't used the one allowed change) AND the remaining suffix of `word1` (from `i+1`) can match the remaining suffix of `word2` (from `j+1`), then use the change here: take index `i`, consume the change power, and move to next character in `word2`.
   - Otherwise, skip this index in `word1`.

3. If we successfully match all characters of `word2`, return the sequence; otherwise return empty array.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` — single pass right-to-left + single pass left-to-right |
| **Space** | `O(n)` — for the `rightHandSideMatchLength` array |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandSideMatchLength(n, 0);

        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }

            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool changePower = true; //can change only one character

        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};
```

---

## Key Takeaways

- Precomputing suffix match information enables greedy decisions from the left.
- The "change power" concept cleanly models the "at most one character change" constraint.
- Lexicographically smallest index sequence is achieved by always taking the earliest valid index.
- Two-pointer technique with precomputed suffix data is a powerful pattern for subsequence matching problems.