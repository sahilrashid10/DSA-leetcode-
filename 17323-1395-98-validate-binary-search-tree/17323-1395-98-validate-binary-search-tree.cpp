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
    bool inOrderModified(TreeNode* root,long long mini, long long maxi){
        if(!root)
            return true;
        if(root->val >= maxi || root->val <= mini)
            return false;
        return inOrderModified(root->left, mini, root->val) && inOrderModified(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return inOrderModified(root, LLONG_MIN, LLONG_MAX);
    }
};
// class Solution {
// public:

//     void inOrder(TreeNode* root, bool &ans, long long &flag){
//         if(!root)
//             return;

//         inOrder(root->left, ans, flag);
//         if(flag >= root->val){
//             ans = false;
//             return;
//         }
//         flag = root->val;
//         inOrder(root->right, ans, flag);
//     }
//     bool isValidBST(TreeNode* root) {
//         bool ans = true;
//         long long flag = LLONG_MIN;
//         inOrder(root, ans, flag);
//         return ans;
//     }
// };