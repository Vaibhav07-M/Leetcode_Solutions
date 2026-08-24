# 1872. Stone Game VIII

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Dynamic Programming`, `Minimax`, `Prefix Sum`, `Game Theory`, `Zero-Sum Game`

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

[LeetCode — 1872. Stone Game VIII](https://leetcode.com/problems/stone-game-viii/)

---

## Problem Summary

The problem is about a game where two players, Alice and Bob, take turns removing stones from a row and adding their values to their scores. The goal is to find the maximum score difference between Alice and Bob if they both play optimally. The game ends when only one stone is left in the row.

---

## Examples

### Example 1
**Input:** `stones = [-1,2,-3,4,-5]`  
**Output:** `5`  
**Explanation:**
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
- value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
- the left. stones = [-3].
- The difference between their scores is 2 - (-3) = 5.

### Example 2
**Input:** `stones = [7,-6,5,10,5,-2,-6]`  
**Output:** `13`  
**Explanation:**
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
- stone of value 13 on the left. stones = [13].
- The difference between their scores is 13 - 0 = 13.

### Example 3
**Input:** `stones = [-10,-12]`  
**Output:** `-22`  
**Explanation:**
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
- score and places a stone of value -22 on the left. stones = [-22].
- The difference between their scores is (-22) - 0 = -22.

---

## Intuition

The key insight is to use dynamic programming to solve the problem. The idea is to calculate the maximum score difference for each subproblem, where a subproblem is defined as the remaining stones from index i to the end. The maximum score difference for a subproblem is either the maximum score difference for the next subproblem (i+1) or the sum of the prefix sum up to index i minus the maximum score difference for the next subproblem (i+1).

---

## Approach

1. 1. Calculate the prefix sum of the stones array, where prefixSum[i] is the sum of stones from index 0 to i. 2. Initialize a dynamic programming array t, where t[i] is the maximum score difference for the subproblem from index i to the end. 3. Set the base case t[n-1] to prefixSum[n-1], which is the maximum score difference when there is only one stone left. 4. Iterate from index n-2 to 1, and for each index i, calculate the maximum score difference t[i] by taking the maximum of two options: taking the prefix sum up to index i minus t[i+1], or skipping the current stone and taking t[i+1]. 5. Return t[1], which is the maximum score difference for the entire game.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The time complexity is linear because we iterate through the stones array once to calculate the prefix sum, and then iterate through the dynamic programming array t once to calculate the maximum score differences. |
| **Space** | `O(n)` — The space complexity is linear because we use two arrays of size n: prefixSum and t. |

---

## Code (C++)

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> t(n);
        t[n - 1] = prefixSum[n - 1];                       // base case: solve(n-1)
        
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }

        return t[1]; // == solve(1)
    }
};
```

---

## Key Takeaways

- This solution demonstrates the use of dynamic programming to solve a game theory problem. The key takeaway is to identify the subproblems and calculate the maximum score difference for each subproblem. Another takeaway is the use of prefix sum to efficiently calculate the sum of stones up to a certain index.
