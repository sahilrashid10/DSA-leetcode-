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
 //USING ONE STACK
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        stack<TreeNode*>s;
        TreeNode* curr = root;
        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = s.top()->right;
                if(temp == NULL){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && s.top()->right == temp){
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
//USING 2 STACKS
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         if(!root)
//             return ans;
//         stack<TreeNode*>s;
//         stack<int>s1;
//         s.push(root);
//         while(!s.empty()){
//             TreeNode* curr = s.top();
//             s.pop();
//             s1.push(curr->val);
//             if(curr->left)
//                 s.push(curr->left);
//             if(curr->right)
//                 s.push(curr->right);
//             }
//             while(!s1.empty()){
//                 ans.push_back(s1.top());
//                 s1.pop();
//             }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int>ans;
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(!root)
//             return ans;
//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         ans.push_back(root->val);
//         return ans;
//     }
// };