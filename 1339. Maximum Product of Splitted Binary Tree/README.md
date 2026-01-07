# 1339. Maximum Product of Splitted Binary Tree

**Difficulty:** `Medium`  
**Tags:** `Tree`, `Depth-First Search`, `Binary Tree`, `Dynamic Programming`

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

[LeetCode — 1339. Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

---

## Problem Summary

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the **product of the sums** of the subtrees is **maximized**.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it **modulo 10^9 + 7**.

**Note:** You need to maximize the answer before taking the mod, not after.

---

## Examples

### Example 1
```
Input: root = [1,2,3,4,5,6]
Output: 110
```
**Explanation:**
- Remove the edge connecting nodes to get two trees
- Tree 1 sum = 11, Tree 2 sum = 10
- Product = 11 × 10 = 110

### Example 2
```
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
```
**Explanation:**
- Remove an edge to get two trees
- Tree 1 sum = 15, Tree 2 sum = 6
- Product = 15 × 6 = 90

---

## Intuition

The key insight is that when we remove an edge, we split the tree into two parts:
1. One subtree (the part below the removed edge)
2. The remaining tree (total sum minus the subtree sum)

To maximize the product, we need to:
1. **Calculate the total sum** of all nodes in the tree
2. **Try removing each edge** (conceptually) and calculate the product
3. For each subtree with sum `S`, the other part has sum `(totalSum - S)`
4. The product would be `S × (totalSum - S)`
5. Track the maximum product

We can achieve this efficiently using **DFS**:
- First pass: Calculate the total sum of the tree
- Second pass: For each subtree, calculate its sum and compute the product with the remaining part

---

## Approach

1. **First DFS - Calculate Total Sum**:
   - Traverse the entire tree to compute `totalSum`
   - Use a simple recursive DFS that returns the sum of each subtree

2. **Second DFS - Find Maximum Product**:
   - For each node, calculate the subtree sum rooted at that node
   - If we "cut" the edge above this node, we get:
     - Subtree sum = `subtreeSum`
     - Remaining tree sum = `totalSum - subtreeSum`
     - Product = `subtreeSum × (totalSum - subtreeSum)`
   - Track the maximum product across all possible cuts

3. **Apply Modulo**:
   - After finding the maximum product, return it modulo `10^9 + 7`

4. **Implementation Details**:
   - Use `long long` to avoid overflow during multiplication
   - Store all subtree sums during first DFS, then compute products
   - Alternatively, compute products on the fly during second DFS

---

## Complexity

- **Time Complexity**: `O(n)` where n is the number of nodes.  
  We traverse the tree twice: once to calculate total sum, once to find maximum product.

- **Space Complexity**: `O(h)` where h is the height of the tree.  
  Recursive call stack depth equals tree height. In the worst case (skewed tree), this is O(n).

---

## Code (C++)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    long long totalSum = 0;
    long long maxProduct = 0;
    const int MOD = 1e9 + 7;
    
    // First DFS: Calculate total sum of the tree
    long long calculateSum(TreeNode* node) {
        if (!node) return 0;
        
        long long leftSum = calculateSum(node->left);
        long long rightSum = calculateSum(node->right);
        
        return node->val + leftSum + rightSum;
    }
    
    // Second DFS: Find maximum product by trying each edge
    long long findMaxProduct(TreeNode* node) {
        if (!node) return 0;
        
        long long leftSum = findMaxProduct(node->left);
        long long rightSum = findMaxProduct(node->right);
        long long subtreeSum = node->val + leftSum + rightSum;
        
        // Calculate product if we cut this subtree from the rest
        long long product = subtreeSum * (totalSum - subtreeSum);
        maxProduct = max(maxProduct, product);
        
        return subtreeSum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        // First pass: Get total sum
        totalSum = calculateSum(root);
        
        // Second pass: Find maximum product
        findMaxProduct(root);
        
        return maxProduct % MOD;
    }
};
```

---

## Key Takeaways

- **Two-Pass DFS**: First pass computes total sum, second pass finds optimal split point.
- **Product Formula**: For subtree sum S, product = S × (totalSum - S).
- **Optimization Insight**: We want to find S closest to totalSum/2 to maximize the product (similar to splitting a number into two parts).
- **Modulo Timing**: Apply modulo only at the end, after finding the maximum product.
- **Overflow Prevention**: Use `long long` since the product can exceed int range before applying modulo.
- **Tree Decomposition**: Each subtree sum represents a potential split point in the tree.
