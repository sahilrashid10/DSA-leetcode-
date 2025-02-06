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
        void makeTree(vector<int>& p, TreeNode* root, int &i, int upper_bound){
            if(!root || i == p.size())
                return;
            if(root->val > p[i]){
                root->left = new TreeNode(p[i]);;
                makeTree(p, root->left, ++i, root->val);
            }
            if(i<p.size() && upper_bound > p[i]){
                root->right = new TreeNode(p[i]);;
                makeTree(p, root->right, ++i, upper_bound);
            }
        }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i=1;
        makeTree(preorder,root, i, INT_MAX);
        return root;

    }
};