/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root){
            if (root->val < p->val && root->val < q->val) 
                root = root->right;

            else if (root->val > p->val && root->val > q->val) 
                root = root->left;
            else
                return root;  
        }
        return nullptr;
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (!root) return nullptr;

        // if (root->val < p->val && root->val < q->val) 
        //     return lowestCommonAncestor(root->right, p, q);
        
        // else if (root->val > p->val && root->val > q->val) 
        //     return lowestCommonAncestor(root->left, p, q);
        
        // return root; 
//     }
// };


// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root) return nullptr;

//         if(root==p || root==q) return root;

//         TreeNode* left =  lowestCommonAncestor(root->left, p, q);
//         TreeNode* right =  lowestCommonAncestor(root->right, p, q);

//         if(!left) return right;
//         if(!right) return left;
//         return root;

//     }
// };