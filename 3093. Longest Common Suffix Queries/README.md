# 3093. Longest Common Suffix Queries

**Difficulty:** `Hard`  
**Tags:** `Trie`, `String`, `Suffix`

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

[LeetCode — 3093. Longest Common Suffix Queries](https://leetcode.com/problems/longest-common-suffix-queries/)

---

## Problem Summary

Given two arrays of strings `wordsContainer` and `wordsQuery`, for each `wordsQuery[i]` find the index of a string in `wordsContainer` that has the longest common suffix with `wordsQuery[i]`.
Tie-breakers:
- If multiple strings share the same longest common suffix, choose the shortest string.
- If still tied, choose the one that occurred earlier in `wordsContainer`.

Return the array of indices for all queries.

---

## Examples

### Example 1
**Input:** wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]  
**Output:** [1,1,1]

### Example 2
**Input:** wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]  
**Output:** [2,0,2]

---

## Intuition

Longest common suffix can be found by reversing strings and matching prefixes. Build a trie of reversed `wordsContainer` strings; at each trie node store the best candidate index according to tie-break rules (shortest length, then earliest index).

---

## Approach

1. Reverse every string in `wordsContainer` and insert into a trie. At each node maintain the best index among words passing through that node using the tie-break criteria.
2. For each query, traverse the trie following the reversed query as far as possible — the deepest node reached holds the longest common suffix; return its stored best index.

This yields O(sum lengths) build time and O(length of query) per query.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(S + Q)` where `S` is total characters in `wordsContainer` and `Q` is total characters in queries |
| **Space** | `O(S)` for the trie |

---

## Code (C++)

```cpp
struct TrieNode {
    int bestIndex = -1; // best candidate index for this node
    int bestLen = INT_MAX; // length of that candidate
    TrieNode* next[26] = {nullptr};
};

class Solution {
public:
    void insert(TrieNode* root, const string &s, int idx) {
        TrieNode* cur = root;
        // update root candidate as empty suffix (shared by all)
        updateCandidate(cur, idx, s.size());
        for (char ch : s) {
            int c = ch - 'a';
            if (!cur->next[c]) cur->next[c] = new TrieNode();
            cur = cur->next[c];
            updateCandidate(cur, idx, s.size());
        }
    }

    void updateCandidate(TrieNode* node, int idx, int len) {
        if (node->bestIndex == -1 || len < node->bestLen || (len == node->bestLen && idx < node->bestIndex)) {
            node->bestIndex = idx;
            node->bestLen = len;
        }
    }

    int query(TrieNode* root, const string &s) {
        TrieNode* cur = root;
        int ans = cur->bestIndex; // empty suffix candidate
        for (char ch : s) {
            int c = ch - 'a';
            if (!cur->next[c]) break;
            cur = cur->next[c];
            if (cur->bestIndex != -1) ans = cur->bestIndex;
        }
        return ans;
    }

    vector<int> longestCommonSuffixQueries(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < (int)wordsContainer.size(); ++i) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(root, rev, i);
        }
        vector<int> res;
        for (auto &q : wordsQuery) {
            string rev = q;
            reverse(rev.begin(), rev.end());
            res.push_back(query(root, rev));
        }
        return res;
    }
};
```

---

## Key Takeaways

- Reverse strings to convert suffix queries into prefix queries and use a trie.
- Store tie-break best candidate at each trie node while building.
- Queries are answered by walking as deep as possible and returning the stored index.
