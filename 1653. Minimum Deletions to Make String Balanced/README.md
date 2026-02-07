# 1653. Minimum Deletions to Make String Balanced

**Difficulty:** `Medium`  
**Tags:** `String`, `Dynamic Programming`, `Stack`

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

[LeetCode — 1653. Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

---

## Problem Summary

You are given a string `s` consisting only of characters `'a'` and `'b'`.

You can delete any number of characters in `s` to make `s` **balanced**. `s` is balanced if there is no pair of indices `(i, j)` such that `i < j` and `s[i] = 'b'` and `s[j] = 'a'`.

In other words, a balanced string has all `'a'`s before all `'b'`s (or contains only `'a'`s, only `'b'`s, or is empty).

Return the **minimum number of deletions** needed to make `s` balanced.

**Constraints:**
- `1 <= s.length <= 10^5`
- `s[i]` is `'a'` or `'b'`

---

## Examples

### Example 1
**Input:** `s = "aababbab"`  
**Output:** `2`  
**Explanation:**
You can either:
- Delete the characters at 0-indexed positions 2 and 6 (`"aababbab"` → `"aaabbb"`), or
- Delete the characters at 0-indexed positions 3 and 6 (`"aababbab"` → `"aabbbb"`)

### Example 2
**Input:** `s = "bbaaaaabb"`  
**Output:** `2`  
**Explanation:**
The only solution is to delete the first two characters.

---

## Intuition

A balanced string must follow the pattern: **all 'a's come before all 'b's**.

Key observations:
1. **Invalid pattern**: Any `'b'` followed by an `'a'` violates the balance condition
2. **Goal**: Remove minimum characters to ensure no `'b'` appears before any `'a'`
3. **Final form**: The result should be like `"aaa...abbb...b"` (some 'a's followed by some 'b's)

When we encounter a `'b'` followed by an `'a'`, we have two choices:
- Delete the `'b'` (or some previous `'b'`s)
- Delete the `'a'` (or current and future `'a'`s)

The key insight is that at each position, we can decide a "split point" where everything before should be `'a'` and everything after should be `'b'`. We want to minimize deletions to achieve this.

**Greedy approach**: Track the number of `'b'`s seen so far. When we encounter an `'a'`:
- We can delete this `'a'` (deletions + 1)
- Or delete all previous `'b'`s (countB deletions)
- Choose the minimum: `deletions = min(deletions + 1, countB)`

---

## Approach

### Method 1: Dynamic Programming (Single Pass Greedy)

**State tracking:**
- `countB`: Number of `'b'`s encountered so far
- `deletions`: Minimum deletions needed up to current position

**Algorithm:**
1. Iterate through each character in the string
2. If we see `'b'`: Increment `countB` (no deletion needed yet)
3. If we see `'a'`: We have a conflict with previous `'b'`s
   - Either delete this `'a'`: cost = `deletions + 1`
   - Or delete all previous `'b'`s: cost = `countB`
   - Take minimum: `deletions = min(deletions + 1, countB)`
4. Return `deletions`

**Why this works:**
At each `'a'`, we decide optimally whether to keep it (delete previous `'b'`s) or delete it. The greedy choice is optimal because:
- If we keep the `'a'`, we must delete all previous `'b'`s
- If we delete the `'a'`, we preserve the ability to keep future `'a'`s

### Method 2: Prefix/Suffix Count

For each possible split point `i`:
- Delete all `'b'`s before position `i`
- Delete all `'a'`s after position `i`
- Result: `prefix_b[i] + suffix_a[i+1]`

Try all split points and find minimum.

### Method 3: Stack-Based Approach

Use a stack to build the balanced string:
- Push characters onto stack
- When we want to push `'a'` but stack top is `'b'`, we have a conflict
- Remove `'b'` from stack (deletion) or skip `'a'` (deletion)
- Choose based on which minimizes total deletions

### Method 4: Dynamic Programming with Explicit States

Define `dp[i][0]` = min deletions to make `s[0..i-1]` balanced ending with last kept char as `'a'` (or empty)
Define `dp[i][1]` = min deletions to make `s[0..i-1]` balanced ending with last kept char as `'b'`

Transitions at position `i`:
- If `s[i] == 'a'`:
  - Keep: `dp[i+1][0] = dp[i][0]`
  - Delete: both states increase by 1
- If `s[i] == 'b'`:
  - Keep: `dp[i+1][1] = min(dp[i][0], dp[i][1])`
  - Delete: both states increase by 1

---

## Complexity

### Method 1: Greedy Single Pass
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass through the string |
| **Space** | `O(1)` — only two variables |

### Method 2: Prefix/Suffix Count
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — three passes (prefix, suffix, find min) |
| **Space** | `O(n)` — arrays for prefix and suffix counts |

### Method 3: Stack-Based
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass |
| **Space** | `O(n)` — stack storage |

### Method 4: DP with States
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — single pass |
| **Space** | `O(1)` — only tracking two states |

---

## Code (C++)

### Solution 1: Greedy Single Pass (Optimal)

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;      // Number of 'b's seen so far
        int deletions = 0;   // Minimum deletions needed
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                countB++;  // Just track, no deletion yet
            } else {  // s[i] == 'a'
                // Option 1: Delete this 'a' (cost: deletions + 1)
                // Option 2: Delete all previous 'b's (cost: countB)
                deletions = min(deletions + 1, countB);
            }
        }
        
        return deletions;
    }
};
```

### Solution 2: Prefix/Suffix Count

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        // Count 'a's to the right of each position
        vector<int> suffixA(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixA[i] = suffixA[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        
        int minDeletions = n;  // Worst case: delete everything
        int prefixB = 0;       // Count of 'b's to the left
        
        // Try each split point
        for (int i = 0; i <= n; i++) {
            // Delete all 'b's before i and all 'a's after i
            minDeletions = min(minDeletions, prefixB + suffixA[i]);
            
            if (i < n && s[i] == 'b') {
                prefixB++;
            }
        }
        
        return minDeletions;
    }
};
```

### Solution 3: Stack-Based Approach

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int deletions = 0;
        
        for (char c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                // Conflict: 'b' before 'a'
                // Delete the 'b' from stack
                st.pop();
                deletions++;
            } else {
                // No conflict, push current character
                st.push(c);
            }
        }
        
        return deletions;
    }
};
```

### Solution 4: DP with Two States

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        // dp0: min deletions ending with 'a' or empty
        // dp1: min deletions ending with 'b'
        int dp0 = 0, dp1 = 0;
        
        for (char c : s) {
            if (c == 'a') {
                // Keep 'a': dp0 stays same
                // Delete 'a': both increase by 1
                dp1 = min(dp1 + 1, dp0 + 1);  // Can't end with 'b' after keeping 'a'
                // dp0 = dp0  (keeping 'a' maintains dp0)
            } else {  // c == 'b'
                // Keep 'b': can come from either dp0 or dp1
                // Delete 'b': stays same + 1
                int newDp1 = min(dp0, dp1);
                int newDp0 = dp0 + 1;  // If we delete 'b', dp0 increases
                dp0 = newDp0;
                dp1 = newDp1;
            }
        }
        
        return min(dp0, dp1);
    }
};
```

### Solution 5: Compact Greedy Version

```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0, deletions = 0;
        for (char c : s) {
            if (c == 'b') b_count++;
            else deletions = min(deletions + 1, b_count);
        }
        return deletions;
    }
};
```

---

## Key Takeaways

- **Balanced String Pattern**: All 'a's must come before all 'b's (form: `aaa...bbb...`)
- **Problem Transformation**: Minimize deletions = Find optimal split point between 'a' region and 'b' region
- **Greedy Choice**: At each 'a', decide whether to delete it or delete all previous 'b's
- **Optimal Substructure**: Decision at each position depends only on current state (count of 'b's and deletions so far)
- **Single Pass Solution**: O(n) time with O(1) space is achievable
- **Stack Approach**: Natural representation where conflicts are resolved by popping 'b' when 'a' arrives
- **DP Perspective**: Can model as states representing last character type kept
- **No Backtracking Needed**: Greedy local optimum leads to global optimum
- **Related Patterns**: Similar to problems involving monotonic sequences or partition optimization
- **Edge Cases**: All 'a's (0 deletions), all 'b's (0 deletions), already balanced (0 deletions)

