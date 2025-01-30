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
    void countGoodNodes(TreeNode* root, int maxVal, int &count) {
        if (!root) return;

        if (root->val >= maxVal) {
            count++;
            maxVal = root->val;  
        }

        countGoodNodes(root->left, maxVal, count);
        countGoodNodes(root->right, maxVal, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        countGoodNodes(root, root->val, count);
        return count;
    }
};
