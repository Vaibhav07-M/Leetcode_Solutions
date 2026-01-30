# 2977. Minimum Cost to Convert String II

**Difficulty:** `Hard`  
**Tags:** `String`, `Dynamic Programming`, `Graph`, `Shortest Path`, `Trie`

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

[LeetCode — 2977. Minimum Cost to Convert String II](https://leetcode.com/problems/minimum-cost-to-convert-string-ii/)

---

## Problem Summary

You are given two 0-indexed strings `source` and `target`, both of length `n` consisting of lowercase English characters. You are also given two 0-indexed string arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` represents the cost of converting the string `original[i]` to the string `changed[i]`.

You start with the string `source`. In one operation, you can pick a **substring** `x` from the string and change it to `y` at a cost of `z` if there exists any index `j` such that `cost[j] == z`, `original[j] == x`, and `changed[j] == y`.

You are allowed to do any number of operations, but any pair of operations must satisfy either:
1. The substrings picked are **disjoint** (indices don't overlap)
2. The substrings picked are **identical** (same indices)

Return the **minimum cost** to convert the string `source` to the string `target` using any number of operations. If it is impossible, return **-1**.

**Note**: There may exist indices `i, j` such that `original[j] == original[i]` and `changed[j] == changed[i]`.

---

## Examples

### Example 1
**Input:** `source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]`  
**Output:** `28`  
**Explanation:**
- Change substring source[1..1] from "b" to "c" at cost 5
- Change substring source[2..2] from "c" to "e" at cost 1
- Change substring source[2..2] from "e" to "b" at cost 2
- Change substring source[3..3] from "d" to "e" at cost 20
- Total: 5 + 1 + 2 + 20 = 28

### Example 2
**Input:** `source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]`  
**Output:** `9`  
**Explanation:**
- Change source[1..3] from "bcd" to "cde" at cost 1
- Change source[5..7] from "fgh" to "thh" at cost 3 (disjoint indices)
- Change source[5..7] from "thh" to "ghh" at cost 5 (identical indices with previous)
- Total: 1 + 3 + 5 = 9

### Example 3
**Input:** `source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]`  
**Output:** `-1`  
**Explanation:**
- Cannot convert because operations would require overlapping (non-identical) indices

---

## Intuition

This problem extends the single-character conversion problem (2976) to **substring conversions**. The key challenges are:

1. **Multiple substring lengths**: Unlike single characters, substrings can have varying lengths
2. **Overlapping constraints**: We can only apply transformations to disjoint or identical substrings
3. **Optimal substring selection**: At each position, we need to decide which substring to transform (or skip)

### Key Insights:

1. **Graph of substrings**: Build a graph where nodes are unique substrings from `original` and `changed` arrays, and edges represent transformations with costs

2. **Floyd-Warshall for shortest paths**: Pre-compute minimum cost to transform any substring to any other substring (handling transitive transformations like "abc" → "def" → "ghi")

3. **Dynamic Programming**: Use DP to find minimum cost to transform `source[0..i]` to `target[0..i]`, considering:
   - Skip position `i` if `source[i] == target[i]`
   - Try all possible substring transformations starting at position `i`

4. **Efficient substring matching**: Use hash maps or tries to quickly find which transformation substrings match at each position

---

## Approach

### Algorithm Steps:

1. **Build Substring Graph**:
   - Collect all unique substrings from `original` and `changed` arrays
   - Assign each unique substring an ID
   - Build adjacency matrix for transformation costs

2. **Floyd-Warshall All-Pairs Shortest Paths**:
   - Pre-compute minimum cost to transform any substring to any other
   - Handle transitive transformations (e.g., "a" → "b" → "c" might be cheaper than "a" → "c")

3. **Dynamic Programming**:
   - `dp[i]` = minimum cost to transform `source[0..i-1]` to `target[0..i-1]`
   - Base case: `dp[0] = 0` (empty strings match with cost 0)
   - Transition: For position `i`, try:
     - **No transformation**: If `source[i] == target[i]`, `dp[i+1] = dp[i]`
     - **Substring transformation**: For each length `len`:
       - Check if `source[i..i+len-1]` can be transformed to `target[i..i+len-1]`
       - Update `dp[i+len] = min(dp[i+len], dp[i] + transformation_cost)`

4. **Optimization - Substring Matching**:
   - Use hash maps to store which substrings from `original`/`changed` start at each position
   - Only check valid transformation candidates at each position

5. **Return Result**:
   - Return `dp[n]` if reachable, otherwise `-1`

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m³ + n × m × L)` — where m = number of unique substrings, L = max substring length, n = string length. Floyd-Warshall is O(m³), DP is O(n × m × L) |
| **Space** | `O(m² + n)` — distance matrix for m substrings, DP array of size n |

---

## Code (C++)

### Solution: Floyd-Warshall + Dynamic Programming

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, 
                          vector<string>& original, vector<string>& changed, 
                          vector<int>& cost) {
        int n = source.length();
        const long long INF = 1e18;
        
        // Map substrings to IDs
        unordered_map<string, int> stringToId;
        int idCounter = 0;
        
        auto getId = [&](const string& s) {
            if (!stringToId.count(s)) {
                stringToId[s] = idCounter++;
            }
            return stringToId[s];
        };
        
        // Build transformation graph
        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }
        
        int m = idCounter;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        
        // Initialize self-loops
        for (int i = 0; i < m; i++) {
            dist[i][i] = 0;
        }
        
        // Add transformation edges
        for (int i = 0; i < original.size(); i++) {
            int from = stringToId[original[i]];
            int to = stringToId[changed[i]];
            dist[from][to] = min(dist[from][to], (long long)cost[i]);
        }
        
        // Floyd-Warshall: find shortest paths between all substring pairs
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // DP: dp[i] = min cost to transform source[0..i-1] to target[0..i-1]
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            
            // Option 1: Characters already match, no transformation needed
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            
            // Option 2: Try substring transformations of various lengths
            for (int len = 1; len <= n - i; len++) {
                string srcSub = source.substr(i, len);
                string tgtSub = target.substr(i, len);
                
                // If substrings already match
                if (srcSub == tgtSub) {
                    dp[i + len] = min(dp[i + len], dp[i]);
                    continue;
                }
                
                // Check if transformation exists
                if (stringToId.count(srcSub) && stringToId.count(tgtSub)) {
                    int srcId = stringToId[srcSub];
                    int tgtId = stringToId[tgtSub];
                    
                    if (dist[srcId][tgtId] != INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[srcId][tgtId]);
                    }
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
```

### Solution 2: Optimized with Substring Position Caching

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, 
                          vector<string>& original, vector<string>& changed, 
                          vector<int>& cost) {
        int n = source.length();
        const long long INF = 1e18;
        
        // Map substrings to IDs
        map<string, int> strToId;
        int id = 0;
        
        for (const auto& s : original) {
            if (!strToId.count(s)) strToId[s] = id++;
        }
        for (const auto& s : changed) {
            if (!strToId.count(s)) strToId[s] = id++;
        }
        
        int m = id;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        
        for (int i = 0; i < m; i++) dist[i][i] = 0;
        
        for (int i = 0; i < original.size(); i++) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd-Warshall
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // Pre-compute valid transformation positions
        vector<vector<pair<int, long long>>> validTransforms(n);
        
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                string src = source.substr(i, len);
                string tgt = target.substr(i, len);
                
                if (src == tgt) {
                    validTransforms[i].push_back({len, 0});
                } else if (strToId.count(src) && strToId.count(tgt)) {
                    long long c = dist[strToId[src]][strToId[tgt]];
                    if (c != INF) {
                        validTransforms[i].push_back({len, c});
                    }
                }
            }
        }
        
        // DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            
            for (auto [len, cost] : validTransforms[i]) {
                dp[i + len] = min(dp[i + len], dp[i] + cost);
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
```

---

## Key Takeaways

1. **Substring graph modeling**: Extend character-based graph problems to substrings by treating each unique substring as a node.

2. **Floyd-Warshall for substring transformations**: Pre-compute all-pairs shortest paths to handle transitive substring transformations efficiently.

3. **Dynamic programming on strings**: Use `dp[i]` to represent the minimum cost to match the first `i` characters, considering all possible substring transformations.

4. **Greedy substring matching**: At each position, try all possible substring lengths and choose the transformation that minimizes total cost.

5. **Overlapping vs disjoint constraint**: The constraint that operations must be on disjoint or identical substrings is naturally handled by DP's left-to-right processing.

6. **Optimization through pre-computation**: Pre-computing valid transformations at each position reduces redundant substring matching during DP.

7. **String hashing for efficiency**: Using maps to assign IDs to substrings enables efficient graph representation and lookup.

8. **Problem decomposition**: Breaking the problem into (1) graph construction, (2) shortest paths, and (3) DP makes the complex problem manageable.

9. **Transitivity matters**: Just like in the single-character version (problem 2976), transitive transformations ("abc" → "def" → "ghi") may be cheaper than direct transformations.

10. **Similar to word break problems**: The DP approach is similar to word break problems where we decide whether to match/transform substrings at each position.

---
