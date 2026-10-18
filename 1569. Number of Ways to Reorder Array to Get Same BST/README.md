# 1569. Number of Ways to Reorder Array to Get Same BST

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Divide and Conquer`, `Dynamic Programming`, `Tree`, `Union-Find`, `Binary Search Tree`, `Memoization`, `Combinatorics`, `Binary Tree`, `Fermat's Little Theorem`

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

[LeetCode — 1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

---

## Problem Summary

The problem asks for the number of ways to reorder an array of integers such that the resulting binary search tree (BST) is identical to the one formed by the original array. The solution uses a recursive divide-and-conquer approach, breaking the problem into subproblems for the left and right subtrees, and then combining the results using a pre-computed Pascal's Triangle-like table to account for the number of ways to distribute elements between the two sides.

---

## Examples

### Example 1
**Input:** `nums = [2,1,3]`  
**Output:** `1`  
**Explanation:**
- We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

### Example 2
**Input:** `nums = [3,4,5,1,2]`  
**Output:** `5`  
**Explanation:**
- The following 5 arrays will yield the same BST:
- [3,1,2,4,5]
- [3,1,4,2,5]
- [3,1,4,5,2]
- [3,4,1,2,5]
- [3,4,1,5,2]

### Example 3
**Input:** `nums = [1,2,3]`  
**Output:** `0`  
**Explanation:**
- There are no other orderings of nums that will yield the same BST.

---

## Intuition

The core insight is that the structure of the BST is determined by the relative ordering of the elements, not their absolute values. By recursively solving for the number of valid permutations for the left and right subtrees, we can determine the total number of ways to arrange the elements while preserving the tree's shape. The 'PT' table is used to calculate the binomial coefficient (or similar combinatorial factor) that tells us how many ways we can split the remaining elements between the left and right branches.

---

## Approach

1. Initialize a 2D vector 'PT' to store combinatorial values, effectively acting as a Pascal's Triangle for calculating binomial coefficients up to the size of the input array.
2. Define a recursive function 'solve' that takes a subarray of integers. If the subarray has fewer than 3 elements, return 1 (as there is only one way to arrange 1 or 2 elements into a BST without changing the structure).
3. In the 'solve' function, identify the root element (the first element of the current subarray).
4. Partition the remaining elements into two vectors: 'left' for elements smaller than the root, and 'right' for elements larger than the root.
5. Recursively call 'solve' on the 'left' and 'right' vectors to find the number of valid permutations for each subtree.
6. Calculate the total number of ways by multiplying the results of the left and right subproblems, and then multiplying by the value from the 'PT' table that corresponds to the total number of elements and the number of elements in the left subtree. This accounts for the different ways the elements could have been distributed between the left and right branches.
7. The main function 'numOfWays' calls 'solve' on the original array and subtracts 1 from the result (likely to exclude the trivial case where the array is already in the correct order, or to adjust for the initial condition), returning the final answer modulo 10^9 + 7.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — The time complexity is dominated by the initialization of the 'PT' table, which requires filling a 2D array of size approximately n x n, resulting in a quadratic time complexity. The recursive calls themselves are efficient because the problem is divided into smaller subproblems, but the pre-computation step is the bottleneck. |
| **Space** | `O(n^2)` — The space complexity is also O(n^2) due to the storage of the 'PT' table. While the recursive stack depth is limited by the height of the tree (log n), the large 2D array used for combinatorial calculations consumes the most memory. |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    
    vector<vector<ll>> PT;
    
    int solve(vector<int>& nums) {
        int m = nums.size();
        
        if(m < 3)
            return 1;
        
        vector<int> left, right;
        
        int root = nums[0];
        for(int i = 1; i < m; i++) {
            
            if(nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
            
        }
        
        ll leftways  = solve(left)  % MOD;
        ll rightways = solve(right) % MOD;
        
        return (((leftways * rightways)%MOD) * PT[m-1][left.size()]) % MOD;
        
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        
        PT.resize(n+1);
        
        for(int i = 0; i <= n; i++) {
            
            PT[i] = vector<long long>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }
        
        
        return (solve(nums)-1) % MOD;
    }
};
```

---

## Key Takeaways

- The solution demonstrates a classic divide-and-conquer strategy applied to a combinatorial problem, breaking down the BST construction into smaller, manageable sub-problems.
- The use of a pre-computed table (PT) to store binomial-like coefficients is a key optimization that allows for efficient calculation of the number of ways to distribute elements between subtrees.
- The problem highlights the importance of understanding the relationship between array permutations and the resulting tree structure, specifically that the relative order of elements defines the BST, not their absolute values.
