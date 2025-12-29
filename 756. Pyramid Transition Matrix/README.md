# 756. Pyramid Transition Matrix

**Difficulty:** `Medium`  
**Tags:** `Hash Table`, `String`, `Backtracking`, `Bit Manipulation`

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

[LeetCode — 756. Pyramid Transition Matrix](https://leetcode.com/problems/pyramid-transition-matrix/)

---

## Problem Summary

You are stacking blocks to form a pyramid where each row has one less block than the row beneath it.

**Rules:**
- Each block has a color (single letter)
- Blocks can only be stacked following specific triangular patterns
- A pattern is given as a 3-letter string: first two characters are left and right bottom blocks, third is the top block
- Example: "ABC" means 'C' can be placed on top of 'A' (left) and 'B' (right)

Given a `bottom` row string and a list of `allowed` patterns, return `true` if you can build the pyramid all the way to the top (single block), or `false` otherwise.

---

## Examples

### Example 1
**Input:** `bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]`  
**Output:** `true`  
**Explanation:**
- Level 3 (bottom): BCD
- Level 2: CE (using patterns BCC and CDE)
- Level 1: A (using pattern CEA)
- All patterns are allowed

### Example 2
**Input:** `bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]`  
**Output:** `false`  
**Explanation:**
- No matter which combinations are tried, it's impossible to build all the way to the top

---

## Intuition

This is a classic **backtracking** problem where we:
1. Try to build each level based on the level below
2. For each adjacent pair of blocks, check what blocks can go on top (from allowed patterns)
3. Recursively try all valid possibilities
4. Use **memoization** to avoid re-exploring failed configurations

The key insight is that for each level, we need to generate all possible next levels, and recursively check if any path leads to a complete pyramid.

---

## Approach

1. **Build Transition Map:**
   - Create a hash map where key = first two characters (bottom pair)
   - Value = list of possible top blocks for that pair
   - Example: "BCC" → map["BC"] = ['C']

2. **Recursive Backtracking:**
   - **Base case:** If current row has only 1 block, pyramid is complete → return `true`
   - **Memoization:** If we've already failed to build from this row → return `false`
   - Generate all possible next rows from current row
   - Recursively try to build from each possibility
   - If any path succeeds → return `true`
   - Otherwise, mark this row as failed and return `false`

3. **Generate Next Rows:**
   - For each adjacent pair in current row
   - Look up valid top blocks from transition map
   - Recursively build all possible combinations

4. **Memoization:**
   - Cache failed rows to avoid redundant computation
   - Critical for performance on larger inputs

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(7^n)` worst case, but pruned significantly by memoization |
| **Space** | `O(n^2)` for recursion stack and memoization |

**Note:** Since there are at most 6 letters and length ≤ 6, the actual search space is limited.

---

## Code (C++)

```cpp
class Solution {
public:
    unordered_map<string, vector<char>> transitionMap; 
    unordered_set<string> failedRows;

    bool canBuild(const string& baseRow) {
        // Base case: reached the top of pyramid
        if (baseRow.size() == 1) return true;
        
        // Memoization: already tried and failed from this row
        if (failedRows.count(baseRow)) return false;

        // Generate all possible next level rows
        vector<string> upperRows;
        generateNextRows(baseRow, 0, "", upperRows);

        // Try each possibility recursively
        for (const string& nextRow : upperRows)
            if (canBuild(nextRow)) return true;

        // Mark this row as failed
        failedRows.insert(baseRow);
        return false;
    }

    void generateNextRows(const string& baseRow, int idx, string formedRow, vector<string>& results) {
        // Built complete next level
        if (idx == baseRow.size() - 1) {
            results.push_back(formedRow);
            return;
        }

        // Get adjacent pair
        string pairKey = baseRow.substr(idx, 2);
        if (!transitionMap.count(pairKey)) return;

        // Try all valid blocks that can go on top of this pair
        for (char topBlock : transitionMap[pairKey])
            generateNextRows(baseRow, idx + 1, formedRow + topBlock, results);
    }

    bool pyramidTransition(string bottomRow, vector<string>& allowedPatterns) {
        // Build transition map from allowed patterns
        for (const string& pattern : allowedPatterns)
            transitionMap[pattern.substr(0, 2)].push_back(pattern[2]);
        
        return canBuild(bottomRow);
    }
};
```

---

## Key Takeaways

- Backtracking with memoization efficiently prunes the search space.
- Hash maps enable fast lookup of valid transitions.
- Caching failed states prevents redundant computation.
- Small constraint sizes make brute-force backtracking feasible.
