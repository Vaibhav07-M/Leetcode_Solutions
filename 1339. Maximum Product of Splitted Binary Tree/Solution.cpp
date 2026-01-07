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
    static const int MOD = 1e9 + 7;
    long long maxProductValue = 0;
    long long totalTreeSum = 0;

    // First DFS: calculate total sum
    long long calculateTotalSum(TreeNode* node) {
        if (!node) return 0;
        return node->val +
               calculateTotalSum(node->left) +
               calculateTotalSum(node->right);
    }

    // Second DFS: compute subtree sums and maximize product
    long long computeSubtreeSum(TreeNode* node) {
        if (!node) return 0;

        long long leftSum = computeSubtreeSum(node->left);
        long long rightSum = computeSubtreeSum(node->right);

        long long currentSubtreeSum = node->val + leftSum + rightSum;

        long long product =
            currentSubtreeSum * (totalTreeSum - currentSubtreeSum);

        maxProductValue = max(maxProductValue, product);

        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalTreeSum = calculateTotalSum(root);
        computeSubtreeSum(root);
        return maxProductValue % MOD;
    }
};
