# 3629. Minimum Jumps to Reach End via Prime Teleportation

**Difficulty:** `Medium`  
**Tags:** `Array`, `BFS`, `Graph`, `Math`

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

[LeetCode — 3629. Minimum Jumps to Reach End via Prime Teleportation](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/)

---

## Problem Summary

Given an integer array `nums` of length `n`, start at index `0` and reach index `n-1`.
You may:
- Take an adjacent step to `i+1` or `i-1` (if within bounds).
- If `nums[i]` is prime `p`, teleport to any index `j != i` where `nums[j] % p == 0`.

Return the minimum number of jumps required to reach `n-1`.

---

## Examples

### Example 1
**Input:** `nums = [1,2,4,6]`  
**Output:** `2`

### Example 2
**Input:** `nums = [2,3,4,7,9]`  
**Output:** `2`

### Example 3
**Input:** `nums = [4,6,5,8]`  
**Output:** `3`

---

## Intuition

Teleportation connects indices sharing divisibility by a prime value. Treat indices as nodes in a graph where edges are:
- Bidirectional edges between adjacent indices.
- From an index with prime value `p`, edges to all indices whose values are multiples of `p`.

Shortest path (minimum jumps) is a classic BFS on this graph. To avoid O(n^2) teleport checks, group indices by prime factors or by primes present in `nums` and only traverse each prime-group once.

---

## Approach

1. Precompute primes up to max(nums) with a sieve to identify primes quickly.
2. Build a map from prime p -> list of indices i where `nums[i] % p == 0`.
   - For each index i where `nums[i]` is prime p, teleport options are the list `map[p]` (excluding i).
3. Run BFS from 0 over indices:
   - Expand adjacent neighbors i-1 and i+1 if not visited.
   - If `nums[i]` is prime `p`, iterate over `map[p]` and enqueue those indices (then clear `map[p]` to avoid reprocessing).
4. Stop when reaching `n-1`; return distance.

This ensures each index and each prime group is processed a bounded number of times.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n + P + total_multiples)` where `P` is sieve cost up to max(nums); practical runtime near `O(n log log M + n)` |
| **Space** | `O(n + P)` for maps and sieve |

---

## Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

static vector<int> sievePrimes(int M) {
    vector<char> isPrime(M+1, true);
    isPrime.assign(M+1, true);
    isPrime[0]=isPrime[1]=false;
    for (int p=2;p*p<=M;++p) if (isPrime[p]) for (int x=p*p;x<=M;x+=p) isPrime[x]=false;
    vector<int> primes;
    for (int i=2;i<=M;++i) if (isPrime[i]) primes.push_back(i);
    return primes;
}

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int M = *max_element(nums.begin(), nums.end());
        // mark primes quickly
        vector<char> isPrime(M+1, false);
        if (M >= 2) {
            vector<char> isp(M+1, true);
            isp[0]=isp[1]=false;
            for (int p=2;p*p<=M;++p) if (isp[p]) for (int x=p*p;x<=M;x+=p) isp[x]=false;
            isPrime = move(isp);
        }
        unordered_map<int, vector<int>> primesToIndices;
        for (int i = 0; i < n; ++i) {
            if (isPrime[nums[i]]) {
                int p = nums[i];
                // we'll use this map to find teleport targets (nums[j] % p == 0)
                // fill map later by scanning all indices for divisibility
                // to be efficient, we populate for primes that actually appear in nums
                primesToIndices[p];
            }
        }
        // For each prime p that appears, collect indices j where nums[j] % p == 0
        for (auto &kv : primesToIndices) {
            int p = kv.first;
            for (int j = 0; j < n; ++j) if (nums[j] % p == 0) kv.second.push_back(j);
        }

        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0; q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == n-1) return dist[u];
            int d = dist[u] + 1;
            // neighbors
            if (u-1 >= 0 && dist[u-1] == -1) { dist[u-1] = d; q.push(u-1); }
            if (u+1 < n && dist[u+1] == -1) { dist[u+1] = d; q.push(u+1); }
            // teleport
            if (isPrime[nums[u]]) {
                int p = nums[u];
                auto &targets = primesToIndices[p];
                for (int v: targets) if (dist[v] == -1) { dist[v] = d; q.push(v); }
                targets.clear(); // avoid reprocessing this prime group
            }
        }
        return -1; // unreachable in valid inputs
    }
};
```

---

## Key Takeaways

- Model teleportation as grouped edges by prime divisors.
- Use BFS for shortest path; ensure each prime-group is traversed only once to keep complexity low.
- Sieve primes up to max(nums) to detect prime-valued indices.
