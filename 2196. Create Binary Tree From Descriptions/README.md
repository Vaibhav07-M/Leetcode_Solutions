# 2196. Create Binary Tree From Descriptions

**Difficulty:** `Medium`  
**Tags:** `Tree`, `Hash Table`

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

[LeetCode — 2196. Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

---

## Problem Summary

You are given a 2D integer array `descriptions` where `descriptions[i] = [parenti, childi, isLefti]`. Construct and return the binary tree described by `descriptions` and return its root. The input guarantees a valid binary tree.

---

## Examples

### Example 1
**Input:** `descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]`  
**Output:** `[50,20,80,15,17,19]`

### Example 2
**Input:** `descriptions = [[1,2,1],[2,3,0],[3,4,1]]`  
**Output:** `[1,2,null,null,3,4]`

---

## Intuition

Use a map from value → TreeNode to create nodes on demand and a set to track children; the root is the node that's never a child.

---

## Approach

1. Create a hashmap `nodes` mapping value → TreeNode*.
2. For each triple `(p,c,isLeft)`:
   - Ensure `nodes[p]` and `nodes[c]` exist.
   - Attach `nodes[c]` as left or right child of `nodes[p]` based on `isLeft`.
   - Record `c` in a `children` set.
3. After processing all descriptions, find the node whose value is not in `children` — that's the root.

This runs in O(n) time and O(n) space.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (auto &d : descriptions) {
            int p = d[0], c = d[1], isLeft = d[2];
            if (!nodes.count(p)) nodes[p] = new TreeNode(p);
            if (!nodes.count(c)) nodes[c] = new TreeNode(c);
            if (isLeft) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];
            children.insert(c);
        }
        for (auto &kv : nodes) if (!children.count(kv.first)) return kv.second;
        return nullptr;
    }
};
```

---

## Key Takeaways

- Build nodes lazily and track child nodes to find the root.
- Hash maps and sets make construction straightforward and linear-time.
