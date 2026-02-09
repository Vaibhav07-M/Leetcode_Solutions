# 1382. Balance a Binary Search Tree

**Difficulty:** `Medium`  
**Tags:** `Tree`, `DFS`, `Binary Search Tree`, `Binary Tree`, `Greedy`, `Divide and Conquer`

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

[LeetCode — 1382. Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

---

## Problem Summary

Given the `root` of a binary search tree, return a **balanced** binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than 1.

**Constraints:**
- The number of nodes in the tree is in the range `[1, 10^4]`
- `1 <= Node.val <= 10^5`

---

## Examples

### Example 1
**Input:** `root = [1,null,2,null,3,null,4,null,null]`
```
    1
     \
      2
       \
        3
         \
          4
```
**Output:** `[2,1,3,null,null,null,4]`
```
      2
     / \
    1   3
         \
          4
```
**Explanation:** This is not the only correct answer, `[3,1,4,null,2]` is also correct.

### Example 2
**Input:** `root = [2,1,3]`
```
    2
   / \
  1   3
```
**Output:** `[2,1,3]`  
**Explanation:** The tree is already balanced.

---

## Intuition

The key insight is leveraging the **BST property**: an inorder traversal of a BST produces values in sorted order.

The problem breaks down into two steps:
1. **Extract sorted values**: Perform inorder traversal to get all nodes in sorted order
2. **Build balanced BST**: Construct a balanced BST from the sorted array

**Why this works:**
- Inorder traversal of BST gives sorted array in O(n) time
- Building a balanced BST from sorted array: pick middle element as root recursively
- Middle element ensures left and right subtrees have equal (or differ by 1) number of nodes
- This guarantees height-balanced property at every node

**Key observations:**
1. We don't need to modify existing nodes; we can reuse them or create new ones
2. A balanced BST from sorted array has height ≈ log(n)
3. Choosing the middle element as root is a greedy choice that ensures balance
4. The process is similar to building a balanced BST (like in AVL tree construction)

---

## Approach

### Method 1: Inorder Traversal + Build from Sorted Array (Optimal)

**Algorithm:**
1. **Inorder Traversal**:
   - Traverse the BST in inorder (left → root → right)
   - Store all nodes (or values) in an array
   - Result: sorted array of nodes
   
2. **Build Balanced BST**:
   - Use divide and conquer on the sorted array
   - Pick middle element as root
   - Recursively build left subtree from left half
   - Recursively build right subtree from right half
   - This ensures balanced height at each level

**Implementation details:**
```
buildBalanced(arr, left, right):
    if left > right: return null
    
    mid = left + (right - left) / 2
    root = arr[mid]
    
    root.left = buildBalanced(arr, left, mid - 1)
    root.right = buildBalanced(arr, mid + 1, right)
    
    return root
```

**Why middle element?**
- Ensures left and right subtrees have equal nodes (±1)
- Guarantees height difference ≤ 1 at every level
- Produces the most balanced tree possible

### Method 2: Day-Stout-Warren (DSW) Algorithm

An in-place algorithm that balances BST without extra space:
1. Convert BST to right-skewed tree (vine)
2. Apply rotations to convert vine to balanced tree

**Pros**: O(1) space  
**Cons**: More complex, requires tree rotations

### Method 3: AVL Tree Rotations

Apply AVL tree rotations to rebalance:
- Calculate balance factor at each node
- Apply appropriate rotations (LL, LR, RR, RL)

**Cons**: More complex, may require multiple rotations per node

---

## Complexity

### Method 1: Inorder + Build (Optimal for Simplicity)
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — O(n) for inorder traversal + O(n) for building tree |
| **Space** | `O(n)` — array to store nodes + O(log n) recursion stack |

### Method 2: DSW Algorithm
| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — linear rotations |
| **Space** | `O(1)` — in-place rotations |

---

## Code (C++)

### Solution 1: Inorder Traversal + Build Balanced BST (Recommended)

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
    vector<TreeNode*> nodes;
    
    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Inorder traversal to get sorted nodes
        inorder(root);
        
        // Step 2: Build balanced BST from sorted array
        return build(0, nodes.size() - 1);
    }
    
private:
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        
        inorder(node->left);
        nodes.push_back(node);  // Store the node itself
        inorder(node->right);
    }
    
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        
        // Pick middle element as root
        int mid = left + (right - left) / 2;
        TreeNode* root = nodes[mid];
        
        // Recursively build left and right subtrees
        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);
        
        return root;
    }
};
```

### Solution 2: Store Values Instead of Nodes

```cpp
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        return buildBalanced(values, 0, values.size() - 1);
    }
    
private:
    void inorder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
    
    TreeNode* buildBalanced(vector<int>& values, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        
        root->left = buildBalanced(values, left, mid - 1);
        root->right = buildBalanced(values, mid + 1, right);
        
        return root;
    }
};
```

### Solution 3: Iterative Inorder with Stack

```cpp
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        // Iterative inorder traversal
        vector<TreeNode*> nodes;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            nodes.push_back(curr);
            curr = curr->right;
        }
        
        return buildBalanced(nodes, 0, nodes.size() - 1);
    }
    
private:
    TreeNode* buildBalanced(vector<TreeNode*>& nodes, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = nodes[mid];
        
        root->left = buildBalanced(nodes, left, mid - 1);
        root->right = buildBalanced(nodes, mid + 1, right);
        
        return root;
    }
};
```

### Solution 4: Compact Version

```cpp
class Solution {
public:
    vector<TreeNode*> nodes;
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
    
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        nodes.push_back(node);
        inorder(node->right);
    }
    
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* root = nodes[m];
        root->left = build(l, m - 1);
        root->right = build(m + 1, r);
        return root;
    }
};
```

---

## Key Takeaways

- **BST Property**: Inorder traversal of BST produces sorted sequence
- **Balanced Construction**: Building from sorted array with middle element as root ensures balance
- **Two-Phase Approach**: Extract sorted values → Build balanced tree
- **Divide and Conquer**: Recursively split array in half mirrors binary search structure
- **Greedy Choice**: Picking middle element is locally and globally optimal for balance
- **Reuse Nodes**: Can reuse existing nodes instead of creating new ones (saves allocation)
- **Height Guarantee**: Resulting tree has height ≈ log(n), ensuring O(log n) operations
- **AVL Connection**: This technique is fundamental to AVL tree construction
- **Multiple Solutions**: Any balanced BST with same values is valid (middle element choice may vary)
- **Space-Time Tradeoff**: O(n) space for simplicity vs O(1) space with DSW (more complex)
- **Similar to Problem 108**: Convert Sorted Array to Binary Search Tree (reverse problem)
- **Practical Use**: Real BST implementations (like AVL, Red-Black) use similar rebalancing concepts

