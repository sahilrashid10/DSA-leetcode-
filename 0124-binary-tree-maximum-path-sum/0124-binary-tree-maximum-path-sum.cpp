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

    int findMaxPathSum(TreeNode* root, int &ans){
        if(!root) return 0;

        int left = findMaxPathSum(root->left, ans);
        int right = findMaxPathSum(root->right, ans);
        
        int val = root->val;
        int curVal = max(left + val, max(right + val, val));

        ans = max(ans, max(curVal, left + right + val));

        return curVal;

    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPathSum(root, ans);

        return ans;
    }
};