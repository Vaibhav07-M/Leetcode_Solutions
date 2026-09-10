# 2265. Count Nodes Equal to Average of Subtree

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

[LeetCode — 2265. Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)

---

## Problem Summary

The problem requires counting the number of nodes in a binary tree where the node's value is equal to the average of all values in its subtree. The average is calculated as the sum of subtree values divided by the number of nodes, rounded down to the nearest integer.

---

## Examples

### Example 1
**Input:** `root = [4,8,5,0,1,null,6]`  
**Output:** `5`  
**Explanation:**
- For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
- For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
- For the node with value 0: The average of its subtree is 0 / 1 = 0.
- For the node with value 1: The average of its subtree is 1 / 1 = 1.
- For the node with value 6: The average of its subtree is 6 / 1 = 6.

### Example 2
**Input:** `root = [1]`  
**Output:** `1`  
**Explanation:**
- For the node with value 1: The average of its subtree is 1 / 1 = 1.

---

## Intuition

To determine if a node's value matches the average of its subtree, we need to compute the total sum and the total count of nodes for that subtree. This is efficiently done using a recursive depth-first search (DFS) approach, where each function call returns a pair containing the sum and count of the current subtree. The root node's value is then compared against the calculated average to update the count of matching nodes.

---

## Approach

1. Define a recursive function `dfs` that takes a tree node as input and returns a pair of integers: the sum of the subtree's values and the count of nodes in the subtree.
2. In the `dfs` function, if the current node is `nullptr`, return a pair with values 0 and 0, indicating an empty subtree.
3. Recursively call `dfs` on the left and right children to obtain their respective sums and counts.
4. Calculate the total sum of the current subtree by adding the left child's sum, the right child's sum, and the current node's value.
5. Calculate the total count of the current subtree by adding the left child's count, the right child's count, and 1 (for the current node).
6. Check if the current node's value is equal to the integer division of the total sum by the total count. If true, increment the global counter `ans`.
7. Return the calculated sum and count for the current subtree.
8. In the main function `averageOfSubtree`, initialize `ans` to 0, call `dfs` on the root node, and return the final count of matching nodes.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The time complexity is linear because the algorithm performs a single depth-first traversal of the binary tree. Each node is visited once, and constant-time operations (addition and comparison) are performed at each node, resulting in a total runtime proportional to the number of nodes in the tree. |
| **Space** | `O(h)` — The space complexity is determined by the maximum depth of the recursion stack, which corresponds to the height of the binary tree (`h`). In the worst case of a skewed tree, this could be O(n), but for a balanced tree, it is typically O(log n). The recursive calls store the state of the traversal, including the return values for sum and count. |

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
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

---

## Key Takeaways

- This problem demonstrates the power of recursive DFS in tree traversal, allowing for the efficient collection of aggregate data (sum and count) from subtrees.
- The use of a pair as the return type for the recursive function is a standard technique for passing multiple values up the call stack in tree algorithms.
- The solution highlights the importance of understanding integer division and rounding behavior when working with averages in algorithmic contexts.
