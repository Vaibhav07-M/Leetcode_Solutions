# 2452. Words Within Two Edits of Dictionary

**Difficulty:** `Medium`  
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

[LeetCode — 2452. Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary/)

---

## Problem Summary

You are given two arrays of equal-length lowercase words: `queries` and `dictionary`.
For each query word, determine whether it matches at least one dictionary word after changing at most two letters.

Return all query words that satisfy this condition, in their original order.

---

## Examples

### Example 1
**Input:** `queries = ["word","note","ants","wood"]`, `dictionary = ["wood","joke","moat"]`  
**Output:** `["word","note","wood"]`  
**Explanation:**
- `word` differs from `wood` by 1 letter.
- `note` differs from `joke` by 2 letters.
- `ants` differs from every dictionary word by more than 2 letters.
- `wood` matches exactly.

### Example 2
**Input:** `queries = ["yes"]`, `dictionary = ["not"]`  
**Output:** `[]`  
**Explanation:**
- `yes` cannot be transformed into `not` with at most 2 edits.

---

## Intuition

The words all have the same length, so the only thing that matters is how many character positions differ.
If a query word differs from any dictionary word in at most two positions, it is valid.

Because the constraints are small, a direct comparison between each query and each dictionary word is enough.
We can stop checking a pair early as soon as the difference count exceeds 2.

---

## Approach

1. Iterate over every word in `queries`.
2. For each query, compare it with every word in `dictionary`.
3. Count character mismatches between the two words.
4. If the mismatch count becomes greater than 2, stop early for that pair.
5. If any dictionary word has at most 2 mismatches, add the query word to the answer and move to the next query.

This is a simple brute-force string comparison solution with early exit.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(q * d * m)` where `q` is the number of queries, `d` is the number of dictionary words, and `m` is word length |
| **Space** | `O(1)` extra space |

---

## Code (C++)

```cpp
class Solution {
public:
    bool isValid(string &a, string &b) {
        int diff = 0;
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                diff++;
                if(diff > 2) return false; // early stop
            }
        }
        
        return true;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> ans;
        
        for(string &q : queries) {
            for(string &d : dictionary) {
                
                if(isValid(q, d)) {
                    ans.push_back(q);
                    break; // no need to check further
                }
            }
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

- Two words are close enough if they differ in at most two positions.
- Early exit keeps the nested comparison efficient in practice.
- A direct brute-force scan is sufficient when the input sizes are small.
