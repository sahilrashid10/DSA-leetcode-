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
    bool checkIsValid(TreeNode* root, long long &prev){
        if(!root) return true;

        bool left = checkIsValid(root->left, prev);
        if(prev >= root->val)
            return false;

        prev = root->val;

        if(!left) return false;

        bool right = checkIsValid(root->right, prev);

        return right && left;
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return checkIsValid(root, prev);
    }
};