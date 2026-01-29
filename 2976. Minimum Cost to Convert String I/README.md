# 2976. Minimum Cost to Convert String I

**Difficulty:** `Medium`  
**Tags:** `Array`, `String`, `Graph`, `Shortest Path`

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

[LeetCode — 2976. Minimum Cost to Convert String I](https://leetcode.com/problems/minimum-cost-to-convert-string-i/)

---

## Problem Summary

You are given two 0-indexed strings `source` and `target`, both of length `n` consisting of lowercase English letters. You are also given two 0-indexed character arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` represents the cost of changing the character `original[i]` to the character `changed[i]`.

You start with the string `source`. In one operation, you can pick a character `x` from the string and change it to character `y` at a cost of `z` if there exists any index `j` such that `cost[j] == z`, `original[j] == x`, and `changed[j] == y`.

Return the **minimum cost** to convert the string `source` to the string `target` using any number of operations. If it is impossible to convert `source` to `target`, return **-1**.

**Note**: There may exist indices `i, j` such that `original[j] == original[i]` and `changed[j] == changed[i]`.

---

## Examples

### Example 1
**Input:** `source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]`  
**Output:** `28`  
**Explanation:**
- Change value at index 1 from 'b' to 'c' at a cost of 5
- Change value at index 2 from 'c' to 'e' at a cost of 1
- Change value at index 2 from 'e' to 'b' at a cost of 2
- Change value at index 3 from 'd' to 'e' at a cost of 20
- Total cost: 5 + 1 + 2 + 20 = 28

### Example 2
**Input:** `source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]`  
**Output:** `12`  
**Explanation:**
- To change 'a' to 'b': first change 'a' to 'c' (cost 1), then 'c' to 'b' (cost 2) = 3 per character
- Total cost: 3 × 4 = 12

### Example 3
**Input:** `source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]`  
**Output:** `-1`  
**Explanation:**
- Impossible to convert source to target because character at index 3 cannot be changed from 'd' to 'e'

---

## Intuition

The key insight is that this is a **graph shortest path problem** where:
- **Nodes** = 26 lowercase English letters ('a' to 'z')
- **Edges** = transformations from `original[i]` to `changed[i]` with weight `cost[i]`
- **Goal** = Find minimum cost to transform each character in `source` to corresponding character in `target`

Since we may need to transform the same character pair multiple times (e.g., multiple 'a' → 'b'), we should:
1. **Pre-compute shortest paths** between all pairs of characters
2. Use these pre-computed costs to quickly calculate the total transformation cost

This is a classic use case for **Floyd-Warshall algorithm**, which finds all-pairs shortest paths in O(V³) time, where V = 26 (number of letters).

For each position in the string:
- If `source[i] == target[i]`, no cost needed
- Otherwise, look up the pre-computed minimum cost to transform `source[i]` → `target[i]`
- If no path exists, return -1

---

## Approach

### Algorithm Steps:

1. **Initialize Distance Matrix**:
   - Create a 26×26 matrix `dist[i][j]` representing minimum cost to transform character `i` to character `j`
   - Initialize all distances to infinity (or a large value)
   - Set `dist[i][i] = 0` for all characters (no cost to transform a character to itself)

2. **Build Initial Edges**:
   - For each transformation in `original`, `changed`, and `cost` arrays:
     - `dist[original[i]][changed[i]] = min(dist[original[i]][changed[i]], cost[i])`
   - Handle multiple edges between same pair by keeping the minimum cost

3. **Floyd-Warshall All-Pairs Shortest Paths**:
   - For each intermediate character `k`:
     - For each source character `i`:
       - For each target character `j`:
         - `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
   - This finds the minimum cost path between all pairs of characters

4. **Calculate Total Transformation Cost**:
   - For each position in the strings:
     - If `source[i] == target[i]`, add 0
     - Else, add `dist[source[i]][target[i]]`
     - If any required transformation is impossible (distance = infinity), return -1

5. **Return Total Cost**

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(26³ + n + m)` = `O(n + m)` — where n = string length, m = number of transformations. Floyd-Warshall is O(26³) = O(17,576) which is constant |
| **Space** | `O(26²)` = `O(676)` = `O(1)` — constant space for 26×26 distance matrix |

---

## Code (C++)

### Solution 1: Floyd-Warshall Algorithm

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
                          vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        const int CHARS = 26;
        
        // Initialize distance matrix
        vector<vector<long long>> dist(CHARS, vector<long long>(CHARS, INF));
        
        // Distance from a character to itself is 0
        for (int i = 0; i < CHARS; i++) {
            dist[i][i] = 0;
        }
        
        // Build initial edges from transformations
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = min(dist[from][to], (long long)cost[i]);
        }
        
        // Floyd-Warshall: find all-pairs shortest paths
        for (int k = 0; k < CHARS; k++) {
            for (int i = 0; i < CHARS; i++) {
                for (int j = 0; j < CHARS; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Calculate total transformation cost
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) {
                continue; // No transformation needed
            }
            
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            
            if (dist[from][to] == INF) {
                return -1; // Impossible to transform
            }
            
            totalCost += dist[from][to];
        }
        
        return totalCost;
    }
};
```

### Solution 2: Dijkstra for Each Unique Character (Alternative)

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
                          vector<char>& changed, vector<int>& cost) {
        const int CHARS = 26;
        
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(CHARS);
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from].push_back({to, cost[i]});
        }
        
        // Dijkstra from each unique source character
        auto dijkstra = [&](int start) {
            vector<long long> dist(CHARS, LLONG_MAX);
            priority_queue<pair<long long, int>, 
                          vector<pair<long long, int>>, 
                          greater<>> pq;
            
            dist[start] = 0;
            pq.push({0, start});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > dist[u]) continue;
                
                for (auto [v, w] : graph[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist;
        };
        
        // Find unique characters in source
        set<char> uniqueChars(source.begin(), source.end());
        
        // Pre-compute shortest paths from each unique source character
        map<int, vector<long long>> shortestPaths;
        for (char c : uniqueChars) {
            shortestPaths[c - 'a'] = dijkstra(c - 'a');
        }
        
        // Calculate total cost
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) continue;
            
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            
            if (shortestPaths[from][to] == LLONG_MAX) {
                return -1;
            }
            
            totalCost += shortestPaths[from][to];
        }
        
        return totalCost;
    }
};
```

---

## Key Takeaways

1. **Character transformation as graph**: Model character conversions as a directed weighted graph where edges represent transformation costs.

2. **All-pairs shortest path**: When you need to perform multiple queries for shortest paths, pre-compute using Floyd-Warshall (O(V³)) rather than running Dijkstra for each query.

3. **Floyd-Warshall for small graphs**: With only 26 characters, Floyd-Warshall's O(26³) = O(17,576) is very efficient and simpler than alternative approaches.

4. **Handle multiple edges**: When multiple transformations exist between the same character pair, keep the minimum cost edge.

5. **Pre-computation optimization**: Computing all shortest paths once and querying in O(1) is more efficient than computing paths on-demand when multiple queries are needed.

6. **Impossible transformations**: Track when no path exists between characters using infinity values in the distance matrix.

7. **Character indexing**: Convert characters to indices (`char - 'a'`) for efficient array-based graph representation.

8. **Transitive transformations**: Character transformations can be chained (e.g., 'a'→'c'→'b' might be cheaper than direct 'a'→'b'), which Floyd-Warshall handles optimally.

---
