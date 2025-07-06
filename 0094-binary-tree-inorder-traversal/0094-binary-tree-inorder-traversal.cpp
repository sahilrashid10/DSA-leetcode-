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

//Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        while(root){
            if(root->left){
                TreeNode* temp = root->left;
                while(temp->right && temp->right != root)
                    temp = temp->right;
                if(temp->right == root){
                    inorder.push_back(root->val);
                    temp->right = nullptr;
                    root = root->right;
                }
                else{
                    temp->right = root;
                    root = root->left;
                    
                }
            }else{
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        return inorder;
    }
};


//RECURSION
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& inorder){
//         if(!root)  return;
//         inorder(root->left, inorder);
//         inorder.push_back(root->val);
//         inorder(root->right, inorder);

//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> inorder;
//         inorder(root, inorder);
//         return inorder;
//     }
// };