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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
            
        stack<TreeNode*>s;
        TreeNode* temp=root;
        while(!s.empty() || temp != NULL){
            while(temp != NULL){
                s.push(temp);
                temp=temp->left;
            }
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int>ans;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root)
//             return ans;
//         inorderTraversal(root->left);
//         ans.push_back(root->val);
//         inorderTraversal(root->right);
//         return ans;
//     }
// };