# 1722. Minimize Hamming Distance After Swap Operations

**Difficulty:** `Medium`  
**Tags:** `Array`, `Union Find`

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

[LeetCode — 1722. Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)

---

## Problem Summary

You are given two integer arrays `source` and `target`, both of length `n`.  
You are also given an array `allowedSwaps` where each `allowedSwaps[i] = [ai, bi]` indicates that you can swap elements at indices `ai` and `bi` in the `source` array.  
You can perform any number of swaps.

The **Hamming distance** is the number of positions where `source[i] != target[i]`.

Return the **minimum Hamming distance** after performing any number of allowed swaps.

---

## Examples

### Example 1
**Input:** `source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]`  
**Output:** `1`  
**Explanation:**
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
- Hamming distance is 1 (only index 3 differs)

### Example 2
**Input:** `source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []`  
**Output:** `2`  
**Explanation:**
- No swaps allowed, positions 1 and 2 differ

### Example 3
**Input:** `source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]`  
**Output:** `0`  
**Explanation:**
- All positions can be rearranged to match target

---

## Intuition

The key insight is that **indices connected by swap operations can be rearranged freely among themselves**.  
We can think of allowed swaps as edges in a graph—indices in the same connected component can exchange values freely.

For each connected component:
1. Collect all values from `source` at those indices.
2. Collect all target values needed at those indices.
3. Match as many source values to target values as possible.
4. Count mismatches as Hamming distance contribution.

This is a **Union-Find (DSU)** problem where we group indices, then greedily match values.

---

## Approach

1. **Build connected components** using Union-Find:
   - For each allowed swap `[a, b]`, unite indices `a` and `b`.
   - Group all indices by their root parent.

2. **For each group of connected indices:**
   - Collect frequencies of source values at those indices.
   - Iterate through target values at those indices.
   - If a target value exists in source frequencies, match it (decrement frequency).
   - Otherwise, count as a mismatch.

3. **Sum all mismatches** and return as minimum Hamming distance.

**Time Complexity:** O(n α(n) + m α(n)) where α is inverse Ackermann function  
**Space Complexity:** O(n) for parent array and hash maps

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + m)` where n = array length, m = number of swaps |
| **Space** | `O(n + m)` for DSU and grouping structures |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        
        // Step 1: DSU - Build connected components
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }
        
        // Step 2: Group indices by their root
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }
        
        int ans = 0;
        
        // Step 3: For each group, match source values to target values
        for(auto &p : groups) {
            unordered_map<int, int> freq;
            
            // Count source value frequencies in this group
            for(int idx : p.second) {
                freq[source[idx]]++;
            }
            
            // Try to match with target values
            for(int idx : p.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++; // Mismatch
                }
            }
        }
        
        return ans;
    }
};
```

---

## Key Takeaways

- **Union-Find** elegantly solves connectivity problems where you need to group elements by allowed relationships.
- **Greedy matching** within groups: if a target value exists in available source values, always match it.
- Processing in groups ensures we only count unmatched positions as Hamming distance.
- Path compression in DSU makes multiple finds nearly O(1) amortized.
