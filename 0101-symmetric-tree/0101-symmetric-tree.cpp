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
    bool checkSymmetry(TreeNode* leftRoot, TreeNode* rightRoot){
        if(!leftRoot && !rightRoot) return true;

        if((!leftRoot || !rightRoot) || leftRoot->val != rightRoot->val)
            return false;

        bool left = checkSymmetry(leftRoot->left, rightRoot->right);
        bool right = checkSymmetry(leftRoot->right, rightRoot->left);

        return left && right;
    }
    bool isSymmetric(TreeNode* root) {

    
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;

        return checkSymmetry(root->left, root->right);
    }
};