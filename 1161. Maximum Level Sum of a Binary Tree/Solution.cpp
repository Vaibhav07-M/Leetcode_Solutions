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

                if (currentNode->left)
                    nodeQueue.push(currentNode->left);
                if (currentNode->right)
                    nodeQueue.push(currentNode->right);
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
