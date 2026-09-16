# 1621. Number of Sets of K Non-Overlapping Line Segments

**Difficulty:** `Medium`  
**Tags:** `Math`, `Dynamic Programming`, `Combinatorics`, `Prefix Sum`

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

[LeetCode — 1621. Number of Sets of K Non-Overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

---

## Problem Summary

The problem asks for the number of ways to draw exactly K non-overlapping line segments on a 1-D plane with N points, where each segment must cover at least two points. The solution uses dynamic programming to count these configurations, returning the result modulo 10^9 + 7.

---

## Examples

### Example 1
**Input:** `n = 4, k = 2`  
**Output:** `5`  
**Explanation:**
- The two line segments are shown in red and blue.
- The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.

### Example 2
**Input:** `n = 3, k = 1`  
**Output:** `3`  
**Explanation:**
- The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.

### Example 3
**Input:** `n = 30, k = 7`  
**Output:** `796297179`  
**Explanation:**
- The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

---

## Intuition

The core insight is to build the solution iteratively. For each number of segments (k) and each starting point (i), we can either skip adding a new segment (keeping the count from the next point) or add a new segment. If we add a segment starting at i, we need to sum up the counts of valid configurations for the remaining points (from i+1 to n-1) with k-1 segments, which is efficiently computed using a prefix sum of the previous row's DP values.

---

## Approach

1. Initialize the DP table: dp[0][i] = 1 for i < n (no segments), 0 otherwise. This represents the base case where no segments are drawn.
2. For each number of segments k from 1 to K, iterate over the starting points i from n-1 down to 0.
3. Calculate the 'skip' option: dp[k][i] = dp[k][i+1], which counts the ways to draw k segments without using point i.
4. Calculate the 'take' option: Sum the DP values from the previous row (k-1) starting at i+1 up to n-1. This represents drawing a segment from i to some later point. Use a pre-computed prefix sum array to efficiently calculate this sum.
5. The final answer is the sum of the 'skip' and 'take' options, stored in dp[k][i].
6. Return the final value dp[K][0], which represents the total number of ways to draw K segments starting from the first point.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(N * K)` — The solution uses a double loop: one for the number of segments (K) and one for the starting point (N). Within the inner loop, operations are performed in constant time, leading to a total complexity of O(N * K). |
| **Space** | `O(N * K)` — The primary data structure is a 2D array dp of size (K+1) x (N+1) to store the intermediate results. Additionally, a 1D vector is used for prefix sums, which is linear in size. Thus, the space complexity is O(N * K). |

---

## Code (C++)

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};
```

---

## Key Takeaways

- The problem demonstrates the use of dynamic programming to solve a combinatorial counting problem involving overlapping constraints.
- The optimization of using a prefix sum (prevRowSum) to quickly calculate the sum of the previous row's values is a key technique for improving efficiency in such DP problems.
- The state transition logic clearly separates the 'skip' and 'take' decisions, making the recursive relationship easy to understand and implement.
