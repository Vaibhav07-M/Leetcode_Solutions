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
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) {
            return {0, nullptr};
        }

        auto leftResult = dfs(node->left);
        auto rightResult = dfs(node->right);

        int leftDepth = leftResult.first;
        int rightDepth = rightResult.first;

        if (leftDepth > rightDepth) {
            return {leftDepth + 1, leftResult.second};
        }
        if (rightDepth > leftDepth) {
            return {rightDepth + 1, rightResult.second};
        }

        // Both sides have same depth → current node is LCA of deepest nodes
        return {leftDepth + 1, node};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
