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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        vector<int>temp;
        deque<TreeNode*>q;
        q.push_back(root);
        q.push_back(NULL);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop_front();
            if(curr == NULL){
                ans.push_back(temp);
                temp = {};
                if(!q.empty())
                    q.push_back(NULL);
            }else{
                temp.push_back(curr->val);
                if(curr->left)
                    q.push_back(curr->left);
                if(curr->right)
                    q.push_back(curr->right);
            }
        }
        return ans;
    }
};