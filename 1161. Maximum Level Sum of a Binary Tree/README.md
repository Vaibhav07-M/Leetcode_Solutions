# 1161. Maximum Level Sum of a Binary Tree

**Difficulty:** `Medium`  
**Tags:** `Tree`, `Breadth-First Search`, `Binary Tree`

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

[LeetCode — 1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

---

## Problem Summary

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest level x** such that the sum of all the values of nodes at level x is **maximal**.

---

## Examples

### Example 1
```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
```
**Explanation:**
- Level 1 sum = 1
- Level 2 sum = 7 + 0 = 7
- Level 3 sum = 7 + (-8) = -1
- Maximum sum is at level 2, so return 2

### Example 2
```
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```
**Explanation:**
- Level 2 has the maximum sum

---

## Intuition

This is a classic **level-order traversal** problem that requires calculating the sum at each level and tracking which level has the maximum sum.

The natural approach is to use **Breadth-First Search (BFS)** to traverse the tree level by level:
1. Process all nodes at the current level
2. Calculate their sum
3. Compare with the maximum sum seen so far
4. Move to the next level

Key considerations:
- We need the **smallest level** with maximum sum (if there's a tie)
- Node values can be negative, so we initialize max sum to the smallest possible value
- We process nodes level by level using a queue

---

## Approach

1. **Initialize BFS**:
   - Create a queue and push the root node
   - Initialize `currentLevel = 1`, `answerLevel = 1`, and `maxSum = LLONG_MIN`

2. **Level-Order Traversal**:
   - For each level:
     - Get the number of nodes at this level (`levelSize = queue.size()`)
     - Initialize `levelSum = 0`
     - Process all nodes at this level:
       - Add node value to `levelSum`
       - Enqueue left and right children (if they exist)
     - After processing the level:
       - If `levelSum > maxSum`:
         - Update `maxSum = levelSum`
         - Update `answerLevel = currentLevel`
     - Increment `currentLevel`

3. **Return Result**:
   - Return `answerLevel` (the level with maximum sum)

**Note**: We only update `answerLevel` when `levelSum > maxSum` (not `>=`), which ensures we get the **smallest** level in case of ties.

---

## Complexity

- **Time Complexity**: `O(n)` where n is the number of nodes in the tree.  
  We visit each node exactly once during the BFS traversal.

- **Space Complexity**: `O(w)` where w is the maximum width of the tree.  
  The queue stores nodes at each level, and in the worst case (complete binary tree), the maximum width is n/2.

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        int currentLevel = 1;
        int answerLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            long long levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                levelSum += currentNode->val;

                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                answerLevel = currentLevel;
            }

            currentLevel++;
        }

        return answerLevel;
    }
};
```

---

## Key Takeaways

- **BFS for Level Processing**: Level-order traversal using a queue is perfect for problems requiring level-by-level analysis.
- **Level Size Tracking**: Capturing `queue.size()` before processing ensures we only process nodes at the current level.
- **Tie-Breaking Logic**: Using `>` instead of `>=` ensures we return the smallest level when multiple levels have the same maximum sum.
- **Negative Values**: Initializing `maxSum` to `LLONG_MIN` handles trees with all negative values correctly.
- **Queue Pattern**: The standard BFS pattern with queue is a fundamental tree traversal technique.
- **Space-Time Tradeoff**: BFS uses more space than DFS but provides natural level-by-level processing.
