# 2573. Find the String with LCP

**Difficulty:** `Hard`  
**Tags:** `String`, `Dynamic Programming`, `Matrix`

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

[LeetCode - 2573. Find the String with LCP](https://leetcode.com/problems/find-the-string-with-lcp/)

---

## Problem Summary

You are given an `n x n` matrix `lcp`, where `lcp[i][j]` is the length of the longest common prefix between suffixes `word[i..n-1]` and `word[j..n-1]`.

Return the lexicographically smallest lowercase string `word` that matches this matrix.  
If no valid string exists, return an empty string.

---

## Examples

### Example 1
**Input:** `lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]`  
**Output:** `"abab"`

### Example 2
**Input:** `lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]`  
**Output:** `"aaaa"`

### Example 3
**Input:** `lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]`  
**Output:** `""`

---

## Intuition

To get the lexicographically smallest answer, assign characters from left to right and keep each position as small as possible.

- If `lcp[j][i] > 0`, then positions `j` and `i` must have the same character.
- If `lcp[j][i] == 0`, then positions `j` and `i` must be different.

For each position, try to reuse an earlier required-equal character first. If none exists, pick the smallest letter that does not violate any required-inequality constraints.

Finally, validate the constructed string by recomputing its full LCP matrix and comparing with input.

---

## Approach

1. Build result string of length `n`, initially all `'a'`.
2. For each index `i` from left to right:
   - Track letters that cannot be used at `i` from all `j < i` where `lcp[j][i] == 0`.
   - If any `j < i` has `lcp[j][i] > 0`, set `result[i] = result[j]` (must match).
   - Otherwise choose the smallest available letter not forbidden by inequality constraints.
3. Recompute an LCP matrix from the built string using DP from bottom-right:
   - `lcp2[i][j] = 1 + lcp2[i+1][j+1]` if chars match, else `0`.
4. If `lcp2 == lcp`, return `result`; otherwise return `""`.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` |
| **Space** | `O(n^2)` |

---

## Code (C++)

```cpp
class Solution {
    vector<vector<int>> LongestCommonPrefixMatrix (string s) {
        int n = s.length();
        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0;
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }

        return result;
    }

public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string result (n, 'a');

        for (int i = 1; i < n; i ++) {
            vector<bool> not_equal(26, false);
            bool matched = false;

            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    not_equal[result[j] - 'a'] = true;
                    continue;
                }

                matched = true;
                result[i] = result[j];
                break;
            }

            if (matched) continue;
            for (int j = 0; j < 26; j ++) {
                if (not_equal[j]) continue;

                result[i] = (char)('a' + j);
                break;
            }
        }

        if (LongestCommonPrefixMatrix(result) == lcp) return result;
        return "";
    }
};
```

---

## Key Takeaways

- Construct greedily for lexicographically smallest candidate.
- Use local constraints (`== 0` vs `> 0`) while assigning each position.
- Always perform a final full-matrix verification to reject invalid constructions.
