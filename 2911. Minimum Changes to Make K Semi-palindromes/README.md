# 2911. Minimum Changes to Make K Semi-palindromes

**Difficulty:** `Hard`  
**Tags:** `Two Pointers`, `String`, `Dynamic Programming`

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

[LeetCode — 2911. Minimum Changes to Make K Semi-palindromes](https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/)

---

## Problem Summary

Given a string s and an integer k, partition s into k substrings such that the letter changes needed to make each substring a semi-palindrome are minimized.  
Return the minimum number of letter changes required.

---

## Examples

_No examples provided._

---

## Intuition

The problem revolves around two pointers, string, dynamic programming. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    int n;
    string str;

    vector<vector<int>> costMemo;
    vector<vector<int>> memo;

    int getCost(int i, int j) {
        int len = j - i + 1;

        if(costMemo[i][j] != -1) {
            return costMemo[i][j];
        }

        int minCost = INT_MAX;

        for(int d = 1; d < len; d++) {
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int group = 0; group < d; group++) { //for d, we will have d groups
                int l = i + group;
                int r = l + (len/d - 1) * d;

                while(l < r) {
                    if(str[l] != str[r])
                        cost++;
                    
                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return costMemo[i][j] = minCost;
    }

    int solve(int start, int k) {
        if(k == 0) {
            if(start == n)
                return 0;
            
            return INT_MAX;
        }

        //early return
        if(start + 2*k > n)
            return INT_MAX;

        if(memo[start][k] != -1) {
            return memo[start][k];
        }
        
        int result = INT_MAX;

        for(int end = start+1; end < n; end++) {
            //start...end -> 1 piece
            int remainingCost = solve(end+1, k-1);

            if(remainingCost == INT_MAX) {
                continue;
            }

            result = min(result, getCost(start, end) + remainingCost);
        }

        return memo[start][k] = result;
    }

    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;

        costMemo.assign(n+1, vector<int>(n+1, -1)); //n*n
        memo.assign(n+1, vector<int>(k+1, -1));

        return solve(0, k);
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Two Pointers, String, Dynamic Programming patterns often reduce an apparently complex problem to a few simple rules.
