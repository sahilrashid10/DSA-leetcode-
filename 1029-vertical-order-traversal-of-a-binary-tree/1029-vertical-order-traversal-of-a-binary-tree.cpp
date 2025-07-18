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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>>result;
        map<int, map<int, multiset<int>>>m;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> cur = q.front();
            q.pop();

            TreeNode* curNode = cur.first;
            int hd = cur.second.first;
            int lvl = cur.second.second;
            m[hd][lvl].insert(curNode->val);

            if(curNode->left)
                q.push({curNode->left, {hd-1, lvl+1}});
            if(curNode->right)
                q.push({curNode->right, {hd+1, lvl+1}});
        }
        for(auto &i:m){
            vector<int>col;
            for(auto &j:i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};