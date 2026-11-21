# 3331. Find Subtree Sizes After Changes

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `String`, `Tree`, `Depth-First Search`

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

[LeetCode — 3331. Find Subtree Sizes After Changes](https://leetcode.com/problems/find-subtree-sizes-after-changes/)

---

## Problem Summary

The problem involves a tree where nodes are labeled with characters. The goal is to update the tree structure by re-parenting nodes to their nearest ancestor with the same character label, and then calculate the size of each resulting subtree. The solution uses a depth-first search (DFS) to traverse the tree, update parent links, and compute subtree sizes simultaneously.

---

## Examples

_No examples provided._

---

## Intuition

The core insight is to use a DFS to traverse the tree and keep track of the 'last seen' node for each character label. As we visit a node, we check if there is a closer ancestor with the same label. If so, we update the parent link of the current node to point to that ancestor. This effectively 'jumps' the node up the tree to the nearest matching label. The subtree size is then updated by adding the current node's size to the new parent's size.

---

## Approach

1. Build an adjacency list representation of the tree from the parent array.
2. Initialize an array 'last' to store the index of the last seen node for each character (0-25), starting with -1.
3. Perform a DFS starting from the root (node 0).
4. For each node visited, update the 'last' array with the current node's index.
5. Recursively visit all child nodes.
6. After returning from children, restore the 'last' array value to what it was before visiting this node (to maintain the correct ancestor tracking for siblings).
7. If the current node is not the root, check if a closer ancestor with the same label exists. If so, update the parent link and the subtree size of the new parent.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` — The DFS visits each node exactly once, and the operations within the loop (updating arrays, checking parents) are constant time. Thus, the total time complexity is linear with respect to the number of nodes. |
| **Space** | `O(n)` — The space complexity is dominated by the storage for the adjacency list and the result arrays. The 'last' array is small (size 26), so the overall space is linear relative to the number of nodes. |

---

## Code (C++)

```cpp
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currNode, string& s, vector<int>& parent) {
        int c = s[currNode] - 'a';

        int nearestAncestor = last[c];

        last[c] = currNode;
        for(int child : adj[currNode]) {
            dfs(child, s, parent);
        }

        //back to currNode
        last[c] = nearestAncestor;

        //if currNode is root, it has no ancestor
        if(currNode != 0) {
            int newParent = parent[currNode]; //old parent

            if(nearestAncestor != -1) {
                newParent = nearestAncestor;
            }

            parent[currNode] = newParent;

            resultSize[newParent] += resultSize[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        //parent[i] = node
        //node is the parent of ith node
        //node ---> i

        for(int i = 1; i < n; i++) {
            int u = parent[i]; //u is the parent
            int v = i;
            adj[u].push_back(v); //u --> v
        }

        resultSize.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return resultSize;
    }
};
```

---

## Key Takeaways

- This solution demonstrates a clever use of a single DFS pass to both update the tree structure and compute subtree sizes.
- The 'last' array acts as a cache to efficiently find the nearest ancestor with a specific property (same character label) during the traversal.
- The approach effectively simulates the 'jumping' of nodes to their new parents while maintaining the integrity of the subtree size calculations.
