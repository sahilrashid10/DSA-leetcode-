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
    void getKthSmallest(TreeNode* root, int &k, int &ans){
        if(!root || k == 0) return;

        getKthSmallest(root->left, k, ans);
        if(k == 0) return;
        ans = root->val;
        k -= 1;
        getKthSmallest(root->right, k, ans);        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        getKthSmallest(root, k, ans);
        return ans;

    }
};