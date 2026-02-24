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
        if(root == nullptr) return 0;

        int ans = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            auto [node, val] = st.top();
            st.pop();

            val = (val << 1) | node->val;

            if(node->left == nullptr && node->right == nullptr) {
                ans += val;
            }
            if(node->right) st.push({node->right, val});
            if(node->left)  st.push({node->left, val});
        }
        return ans;
    }
};