//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
 
class Solution {
public:
    bool ans = true;
    void check(TreeNode*l, TreeNode*r){
        if(!l && !r)
            return;
        if ((!l && r) || (l && !r) || (l->val != r->val)) {
            ans = false;
            return;
        }
        
        check(l->left, r->right);
        check(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode *l, *r;
        check(root, root);
        return ans;
    }
};