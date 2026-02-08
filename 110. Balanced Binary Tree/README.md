# 110. Balanced Binary Tree

**Difficulty:** `Easy`  
**Tags:** `Tree`, `DFS`, `Binary Tree`

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

[LeetCode — 110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

---

## Problem Summary

Given a binary tree, determine if it is **height-balanced**.

A **height-balanced** binary tree is defined as: a binary tree in which the left and right subtrees of **every** node differ in height by no more than 1.

**Constraints:**
- The number of nodes in the tree is in the range `[0, 5000]`
- `-10^4 <= Node.val <= 10^4`

---

## Examples

### Example 1
**Input:** `root = [3,9,20,null,null,15,7]`
```
      3
     / \
    9  20
      /  \
     15   7
```
**Output:** `true`  
**Explanation:**
- Left subtree (9) has height 0
- Right subtree (20) has height 1
- Difference = 1 (≤ 1, balanced)
- All subtrees are also balanced

### Example 2
**Input:** `root = [1,2,2,3,3,null,null,4,4]`
```
        1
       / \
      2   2
     / \
    3   3
   / \
  4   4
```
**Output:** `false`  
**Explanation:**
- At node 2 (left child of root):
  - Left subtree (3) has height 2
  - Right subtree (3) has height 2
  - But node 3's left subtree (4) has height 1, right has height 1
- At node 1 (root):
  - Left subtree has height 3
  - Right subtree has height 0
  - Difference = 3 (> 1, not balanced)

### Example 3
**Input:** `root = []`  
**Output:** `true`  
**Explanation:**
An empty tree is considered balanced.

---

## Intuition

A binary tree is height-balanced if **at every node**, the heights of the left and right subtrees differ by at most 1. This must hold for all nodes in the tree, not just the root.

Key observations:
1. **Recursive definition**: A tree is balanced if:
   - Its left subtree is balanced
   - Its right subtree is balanced
   - The height difference between left and right subtrees is at most 1

2. **Height calculation**: We need to compute the height of each subtree
   - Height of a node = 1 + max(height of left, height of right)
   - Height of null node = -1 (or 0, depending on convention)

3. **Bottom-up approach**: We can check balance while computing height in a single DFS traversal

4. **Early termination**: If we find any unbalanced subtree, we can immediately return false

---

## Approach

### Method 1: Bottom-Up DFS (Optimal)

Combine height calculation and balance checking in one pass:

1. **Recursive function** that returns:
   - The height of the subtree if it's balanced
   - A sentinel value (e.g., -1) if the subtree is unbalanced

2. **Base case**: 
   - If node is null, return height 0

3. **Recursive case**:
   - Get height of left subtree
   - If left is unbalanced (-1), propagate immediately
   - Get height of right subtree
   - If right is unbalanced (-1), propagate immediately
   - Check if |leftHeight - rightHeight| ≤ 1
   - If yes: return 1 + max(leftHeight, rightHeight)
   - If no: return -1 (unbalanced)

4. **Final check**: Tree is balanced if the returned height ≠ -1

**Time complexity**: O(n) — visit each node once  
**Space complexity**: O(h) — recursion stack, where h is tree height

### Method 2: Top-Down DFS (Naive)

Separate height calculation and balance checking:

1. **Helper function** to calculate height of a subtree
2. **Balance function** that:
   - Checks if current node is balanced (height difference ≤ 1)
   - Recursively checks if left and right subtrees are balanced

**Problem**: This recalculates heights multiple times  
**Time complexity**: O(n²) — for each node, we recalculate subtree heights  
**Space complexity**: O(h) — recursion stack

### Method 3: Using Pair/Struct

Return a struct containing both height and balance status:
- `struct Info { int height; bool isBalanced; }`
- More explicit but similar to Method 1

---

## Complexity

### Method 1: Bottom-Up DFS (Optimal)
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — visit each node exactly once |
| **Space** | `O(h)` — recursion stack depth (h = height of tree) |

### Method 2: Top-Down DFS
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n²)` — recalculate heights for each node |
| **Space** | `O(h)` — recursion stack depth |

---

## Code (C++)

### Solution 1: Bottom-Up DFS (Optimal)

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
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
private:
    // Returns height if balanced, -1 if unbalanced
    int checkHeight(TreeNode* node) {
        // Base case: empty tree has height 0
        if (node == nullptr) {
            return 0;
        }
        
        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1;  // Left subtree is unbalanced
        }
        
        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1;  // Right subtree is unbalanced
        }
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Current node is unbalanced
        }
        
        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }
};
```

### Solution 2: Top-Down DFS (Naive)

```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Empty tree is balanced
        if (root == nullptr) {
            return true;
        }
        
        // Check if current node is balanced
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        
        // Recursively check subtrees
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
};
```

### Solution 3: Using Struct for Clarity

```cpp
class Solution {
public:
    struct Info {
        int height;
        bool isBalanced;
    };
    
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).isBalanced;
    }
    
private:
    Info checkBalance(TreeNode* node) {
        // Base case: empty tree
        if (node == nullptr) {
            return {0, true};
        }
        
        // Check left subtree
        Info left = checkBalance(node->left);
        if (!left.isBalanced) {
            return {0, false};  // Height doesn't matter if unbalanced
        }
        
        // Check right subtree
        Info right = checkBalance(node->right);
        if (!right.isBalanced) {
            return {0, false};
        }
        
        // Check current node
        int heightDiff = abs(left.height - right.height);
        bool balanced = (heightDiff <= 1);
        int height = 1 + max(left.height, right.height);
        
        return {height, balanced};
    }
};
```

### Solution 4: Compact Bottom-Up

```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int left = dfs(node->left);
        if (left == -1) return -1;
        
        int right = dfs(node->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        
        return 1 + max(left, right);
    }
};
```

---

## Key Takeaways

- **Height-Balanced Definition**: Height difference between left and right subtrees ≤ 1 at **every** node
- **Bottom-Up Optimization**: Combine height calculation and balance checking in one pass for O(n) time
- **Sentinel Value Pattern**: Use -1 to indicate unbalanced state while returning height for balanced
- **Early Termination**: Propagate unbalanced status immediately to avoid unnecessary computation
- **Top-Down Inefficiency**: Recalculating heights at each node leads to O(n²) time complexity
- **Recursion Stack**: Space complexity is O(h) where h is tree height (O(log n) for balanced, O(n) for skewed)
- **Empty Tree**: An empty tree (null root) is considered balanced by definition
- **Common Mistake**: Forgetting to check balance at every node, not just the root
- **AVL Tree Connection**: This problem is fundamental to understanding AVL tree maintenance
- **DFS Pattern**: Post-order traversal naturally fits this problem (process children before parent)

