# 865. Smallest Subtree with all the Deepest Nodes

**Difficulty:** `Medium`  
**Tags:** `Tree`, `Depth-First Search`, `Binary Tree`

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

[LeetCode — 865. Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)

---

## Problem Summary

Given the `root` of a binary tree, the depth of each node is the shortest distance to the root.

Return the **smallest subtree** such that it contains **all the deepest nodes** in the original tree.

- A node is called the **deepest** if it has the largest depth possible among any node in the entire tree.
- The **subtree** of a node is a tree consisting of that node, plus the set of all descendants of that node.

**Note:** This question is the same as Problem 1123: Lowest Common Ancestor of Deepest Leaves.

---

## Examples

### Example 1
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
```
**Explanation:**
- Nodes 7 and 4 are the deepest nodes (depth 4)
- Node 2 is the smallest subtree that contains both deepest nodes
- Although nodes 5 and 3 also contain the deepest nodes, node 2 is the smallest subtree

### Example 2
```
Input: root = [1]
Output: [1]
```
**Explanation:**
- The root is the deepest node in the tree
- The entire tree is the smallest subtree

### Example 3
```
Input: root = [0,1,3,null,2]
Output: [2]
```
**Explanation:**
- The deepest node is 2 (depth 3)
- The subtree of node 2 is the smallest

---

## Intuition

This problem is essentially finding the **Lowest Common Ancestor (LCA)** of all the deepest nodes.

Key observations:
1. If all deepest nodes are in the left subtree, the answer is in the left subtree
2. If all deepest nodes are in the right subtree, the answer is in the right subtree
3. If deepest nodes are split between left and right subtrees with equal depth, the current node is the LCA (answer)

We can solve this using **DFS** with a clever approach:
- For each node, calculate the maximum depth of its left and right subtrees
- If left and right have the same max depth, this node is the LCA of deepest nodes
- Otherwise, recurse into the subtree with greater depth

We need to return two pieces of information from each recursive call:
1. The deepest node(s) in this subtree
2. The maximum depth of this subtree

---

## Approach

1. **Define Helper Function**:
   - Create a DFS function that returns a pair: `{node, depth}`
   - `node` = the root of the smallest subtree containing all deepest nodes
   - `depth` = the maximum depth of this subtree

2. **Base Case**:
   - If node is null, return `{nullptr, 0}`

3. **Recursive Case**:
   - Get `{leftNode, leftDepth}` from left subtree
   - Get `{rightNode, rightDepth}` from right subtree
   
4. **Decision Logic**:
   - If `leftDepth > rightDepth`: Answer is in left subtree
     - Return `{leftNode, leftDepth + 1}`
   - If `rightDepth > leftDepth`: Answer is in right subtree
     - Return `{rightNode, rightDepth + 1}`
   - If `leftDepth == rightDepth`: Current node is the LCA
     - Return `{currentNode, leftDepth + 1}`

5. **Return Result**:
   - Return the node from the root call

---

## Complexity

- **Time Complexity**: `O(n)` where n is the number of nodes.  
  We visit each node exactly once during the DFS traversal.

- **Space Complexity**: `O(h)` where h is the height of the tree.  
  Recursive call stack depth equals tree height. In worst case (skewed tree), this is O(n).

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
    // Returns {node, depth} where node is the root of smallest subtree 
    // containing all deepest nodes at this depth
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) {
            return {nullptr, 0};
        }
        
        // Get results from left and right subtrees
        auto [leftNode, leftDepth] = dfs(node->left);
        auto [rightNode, rightDepth] = dfs(node->right);
        
        // If left subtree is deeper, answer is in left
        if (leftDepth > rightDepth) {
            return {leftNode, leftDepth + 1};
        }
        
        // If right subtree is deeper, answer is in right
        if (rightDepth > leftDepth) {
            return {rightNode, rightDepth + 1};
        }
        
        // If both subtrees have same depth, current node is the LCA
        return {node, leftDepth + 1};
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
```

---

## Key Takeaways

- **LCA Pattern**: This is a variant of the Lowest Common Ancestor problem applied to deepest nodes.
- **Depth Tracking**: We track depth alongside the result node to make informed decisions at each level.
- **Three-Way Decision**: At each node, we choose left subtree, right subtree, or current node based on depth comparison.
- **Elegant Recursion**: Using structured bindings (C++17) makes the code clean and readable.
- **Single Pass**: We solve the problem in one DFS traversal without needing to first find all deepest nodes.
- **Depth vs Height**: We're essentially tracking the height of subtrees to find where all deepest leaves converge.
