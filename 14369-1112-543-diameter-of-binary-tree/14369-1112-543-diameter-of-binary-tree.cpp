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
    int ans=0;
    int maxHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right); 
        if(root->left && root->right)
            ans =  max(ans, lh+rh);
        return 1+max(lh, rh); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int h = maxHeight(root);
      return max(ans, h-1);
    }
};