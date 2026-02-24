# 1022. Sum of Root To Leaf Binary Numbers

**Difficulty:** `Easy`  
**Tags:** `Tree, Depth-First Search, Binary Tree`

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

[LeetCode — 1022. Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)

---

## Problem Summary

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the **most significant bit**.

For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the **sum of these numbers**.

The test cases are generated so that the answer fits in a 32-bit integer.

---

## Examples

### Example 1
**Input:** `root = [1,0,1,0,1,0,1]`  
**Output:** `22`  
**Explanation:**  
```
        1
       / \
      0   1
     / \ / \
    0  1 0  1
```
- Path `1 -> 0 -> 0` = `100` (binary) = 4
- Path `1 -> 0 -> 1` = `101` (binary) = 5
- Path `1 -> 1 -> 0` = `110` (binary) = 6
- Path `1 -> 1 -> 1` = `111` (binary) = 7
- Sum = 4 + 5 + 6 + 7 = **22**

### Example 2
**Input:** `root = [0]`  
**Output:** `0`  
**Explanation:**  
There is just one path (the root), which represents `0` in binary.

---

## Intuition

We need to traverse the binary tree and compute the decimal value of each root-to-leaf path.

**Key observations:**
- Each path from root to leaf forms a binary number (MSB first)
- We need to visit all leaf nodes and accumulate their path values
- As we traverse from parent to child, we build the binary number by shifting left and adding the current bit
- Binary number construction: if current value is `val`, and we visit child with bit `b`, new value = `val * 2 + b` (or `(val << 1) | b`)

**Approach:**
1. Use DFS (recursion or iterative with stack)
2. Pass the current accumulated value down the tree
3. At each node, update value: `newVal = currentVal * 2 + node->val`
4. When we reach a leaf, add the accumulated value to the result
5. Sum all leaf values

---

## Approach

### Solution 1: Recursive DFS

1. **Base case**: If node is null, return 0
2. **Update current value**: `val = val * 2 + node->val` (or `(val << 1) | node->val`)
3. **Leaf node check**: If both left and right are null, return the accumulated value
4. **Recursive case**: Return sum of left subtree + right subtree
5. **Initial call**: Start with `dfs(root, 0)`

### Solution 2: Iterative DFS with Stack

1. **Initialize**: Stack with pairs of `(node, currentValue)`
2. **Process**: Pop from stack, update value
3. **Leaf check**: If it's a leaf, add to result
4. **Push children**: Push left and right children with updated value
5. **Return** accumulated sum

### Solution 3: Morris Traversal (Space Optimized)

Can be done with O(1) space using Morris traversal, but more complex for this problem.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — visit each node exactly once |
| **Space** | `O(h)` for recursion stack, where h is tree height (O(log n) for balanced, O(n) for skewed) |

**Note:** Iterative solution has O(h) space for the stack.

---

## Code (C++)

### Solution 1: Recursive DFS

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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int val) {
        if(!node) return 0;
        
        val = (val << 1) | node->val;  // or val * 2 + node->val
        
        // Leaf node
        if(!node->left && !node->right) {
            return val;
        }
        
        return dfs(node->left, val) + dfs(node->right, val);
    }
};
```

### Solution 2: Cleaner Recursive Version

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if(!root) return 0;
        
        val = val * 2 + root->val;
        
        if(!root->left && !root->right) {
            return val;
        }
        
        return sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};
```

### Solution 3: Iterative DFS with Stack

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        int ans = 0;
        
        while(!st.empty()) {
            auto [node, val] = st.top();
            st.pop();
            
            val = (val << 1) | node->val;
            
            // Leaf node
            if(!node->left && !node->right) {
                ans += val;
            }
            
            if(node->right) st.push({node->right, val});
            if(node->left)  st.push({node->left, val});
        }
        
        return ans;
    }
};
```

### Solution 4: Helper Function Approach

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
private:
    void helper(TreeNode* node, int val, int& sum) {
        if(!node) return;
        
        val = (val << 1) | node->val;
        
        if(!node->left && !node->right) {
            sum += val;
            return;
        }
        
        helper(node->left, val, sum);
        helper(node->right, val, sum);
    }
};
```

### Solution 5: Compact One-Liner Style

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if(!root) return 0;
        val = (val << 1) | root->val;
        return (root->left || root->right) ? 
               sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val) : val;
    }
};
```

---

## Key Takeaways

- **Tree traversal**: DFS (recursive or iterative) is natural for path-based problems
- **Path accumulation**: Pass accumulated value down the tree as parameter
- **Binary number building**:
  - Formula: `newVal = oldVal * 2 + currentBit`
  - Bit manipulation: `newVal = (oldVal << 1) | currentBit`
  - Left shift multiplies by 2, OR adds the new bit
- **Leaf detection**: Node is a leaf when both `left` and `right` are null
- **Result accumulation**: Sum all leaf values at the end
- **Base case**: Null node returns 0 (contributes nothing to sum)
- **Parameter passing**: Pass current accumulated value as function parameter
- **Alternative styles**:
  - Return sum directly from recursive function
  - Use reference parameter to accumulate sum
  - Use global/class member variable
- **Bit shifting advantage**: `val << 1` is equivalent to `val * 2` but often faster
- **Operator precedence**: OR operator has lower precedence, use parentheses: `(val << 1) | bit`
- **MSB first**: Most significant bit is at the root, so we build from left to right
- **Tree structure**: No need to track the actual path, just the accumulated value
- **Iterative advantage**: Avoids recursion stack, explicit stack control
- **Stack order**: Push right before left so left is processed first (though order doesn't matter for sum)
- **Edge cases**:
  - Single node (root only): Returns root value (0 or 1)
  - Tree with only left children: Works as linear path
  - Perfect binary tree: All paths same length
- **Optimization**: Early termination not applicable since we need all paths
- **Space considerations**:
  - Recursive: O(h) call stack where h is height
  - Iterative: O(h) explicit stack
  - Morris traversal: O(1) but complex for this problem
- **Number range**: With max 1000 nodes and height ≤ 1000, max value is 2^1000 but constraint says answer fits in 32-bit
- **Path representation**: Don't need to store the path, just accumulate the value
- **DFS vs BFS**: DFS is more natural since we're tracking path values from root to leaf

