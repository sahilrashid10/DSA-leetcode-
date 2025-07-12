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
    // 1.level order traversal
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({0, {0, root}});
        map<int, map<int, multiset<int>>> mp;
        while(!q.empty()){
            int level = q.size();

            for(int i=0; i<level; i++){
                auto[vert_dist, temp] = q.front();
                q.pop();

                TreeNode* curNode = temp.second;
                int curLvl = temp.first;
                
                mp[vert_dist][curLvl].insert(curNode->val);
                if(curNode->left)
                    q.push({vert_dist - 1, {curLvl+1, curNode->left}});

                if(curNode->right)
                    q.push({vert_dist + 1, {curLvl+1, curNode->right}});
    
            }
        }

        for (auto& [x, level_map] : mp) {
            vector<int> col;
            for (auto& [y, nodes] : level_map) {
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            result.push_back(col);
        }

        return result;
        
    }
};