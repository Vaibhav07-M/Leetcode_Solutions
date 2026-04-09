# 3655. XOR After Range Multiplication Queries II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Simulation`, `Square Root Decomposition`

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

[LeetCode - 3655. XOR After Range Multiplication Queries II](https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/)

---

## Problem Summary

You are given an integer array `nums` and a list of queries `queries`, where each query is `[l, r, k, v]`.

For every query, start at index `l` and keep moving by `k` while the index is at most `r`. For each visited index, multiply the current value by `v` and take the result modulo `1e9 + 7`.

After all queries are processed, return the bitwise XOR of the final array.

---

## Examples

### Example 1
**Input:** `nums = [1,1,1], queries = [[0,2,1,4]]`  
**Output:** `4`

**Explanation:**
- Indices `0, 1, 2` are all multiplied by `4`
- Final array becomes `[4, 4, 4]`
- XOR is `4 ^ 4 ^ 4 = 4`

### Example 2
**Input:** `nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]`  
**Output:** `31`

**Explanation:**
- Query `[1,4,2,3]` updates indices `1` and `3`
- Query `[0,2,1,2]` updates indices `0, 1, 2`
- Final array is `[4, 18, 2, 15, 4]`
- XOR is `4 ^ 18 ^ 2 ^ 15 ^ 4 = 31`

---

## Intuition

The key challenge is that `q` and `n` are both large, so simulating every query naively can be too slow when `k` is small.

There are two different regimes:
- When `k` is large, each query touches only a few indices, so direct simulation is cheap.
- When `k` is small, many indices belong to the same arithmetic progression, so we can batch queries with the same `k` using a multiplicative difference array.

That split is the reason square root decomposition works well here.

---

## Approach

1. Set a threshold `blockSize = ceil(sqrt(n))`.
2. For each query `[l, r, k, v]`:
   - If `k >= blockSize`, update `nums[l], nums[l + k], ...` directly.
   - Otherwise, store the query in a bucket keyed by `k`.
3. For each small `k` bucket:
   - Build a multiplicative difference array initialized to `1`.
   - For every query in the bucket:
     - Multiply `diff[l]` by `v`.
     - Multiply the first index after the last affected position by `v^-1` modulo `M`.
   - Propagate the products along steps of size `k`.
   - Apply the resulting multiplier array to `nums`.
4. XOR all numbers in `nums` and return the result.

The modular inverse is computed with Fermat's little theorem because `M = 1e9 + 7` is prime.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + q) * sqrt(n))` in the worst case |
| **Space** | `O(n + q)` |

---

## Code (C++)

```cpp
class Solution {
public:
    int M = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0) {
            return 1;
        }

        long long half = power(a, b / 2);
        long long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> bravexuneth = nums;
        int blockSize = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> smallKMap;

        for (auto &query : queries) {
            int L = query[0];
            int R = query[1];
            int K = query[2];
            int V = query[3];

            if (K >= blockSize) {
                for (int i = L; i <= R; i += K) {
                    nums[i] = (1LL * nums[i] * V) % M;
                }
            } else {
                smallKMap[K].push_back(query);
            }
        }

        for (auto &[K, allQueries] : smallKMap) {
            vector<long long> diff(n, 1);

            for (auto &query : allQueries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L) / K;
                int next = L + (steps + 1) * K;

                if (next < n) {
                    diff[next] = (diff[next] * power(V, M - 2)) % M;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i - K >= 0) {
                    diff[i] = (diff[i] * diff[i - K]) % M;
                }
            }

            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % M;
            }
        }

        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};
```

---

## Key Takeaways

- Large-step queries are cheap to simulate directly.
- Small-step queries benefit from grouping by step size.
- Multiplicative difference arrays are a natural fit when updates follow arithmetic progressions.