/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& postorder, int start, int end, int& index,
                unordered_map<int, int>& inorderMap) {
                    
        if (start > end || index<0)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[index]);
        int i = inorderMap[postorder[index]];
        index--;
        root->right = helper(postorder, i + 1, end, index, inorderMap);
        root->left = helper(postorder, start, i - 1, index, inorderMap);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;

        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        int index = postorder.size() - 1;
        return helper(postorder, 0, inorder.size() - 1, index, inorderMap);
    }
};