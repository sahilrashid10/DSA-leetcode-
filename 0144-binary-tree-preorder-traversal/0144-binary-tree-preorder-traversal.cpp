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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root && !root->left && !root->right)
            return {root->val};

        while(root){
            if(root->left){
                TreeNode* temp = root->left;

                while(temp->right && temp->right != root){
                    temp = temp->right;
                }
                if(temp->right == root){
                    temp->right = nullptr;
                    root = root->right;
                }else{
                    preOrder.push_back(root->val);
                    temp->right = root;
                    root = root->left;
                }
            }else{
                preOrder.push_back(root->val);
                root = root->right;
            }
        }
        return preOrder;
    }
};



//Recursion

// class Solution {
// public:
//     void preOrder(TreeNode* root, vector<int>& ans){
//         if(!root) return;

//         ans.push_back(root->val);
//         preOrder(root->left, ans);
//         preOrder(root->right, ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preOrder(root, ans);

//         return ans;
//     }
// };