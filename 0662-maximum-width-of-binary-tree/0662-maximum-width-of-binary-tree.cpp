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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long result = 0;

        while (!q.empty()) {
            int mini = q.front().second;
            int levelSize = q.size();
            long long l, r;

            for (int i = 0; i < levelSize; i++) {
                auto [node, idx] = q.front();
                long long curIndex = idx - mini;
                q.pop();       

                if (i == 0) l = curIndex;
                if (i == levelSize - 1) r = curIndex;

                if (node->left)
                    q.push({node->left, 2 * curIndex + 1});
                if (node->right)
                    q.push({node->right, 2 * curIndex + 2});
            }

            result = max(result, r - l + 1);
        }
        return int(result);
    }
};