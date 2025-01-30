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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start,
                     int end, int& index, unordered_map<int, int> &preorderMap) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int i = preorderMap[preorder[index]];
        index++;
        root->left = helper(preorder, inorder, start, i - 1, index, preorderMap);
        root->right = helper(preorder, inorder, i + 1, end, index, preorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        int index = 0;
        unordered_map<int, int> preorderMap;
        for (int i = 0; i < inorder.size(); i++)
            preorderMap[inorder[i]] = i;
        return helper(preorder, inorder, 0, preorder.size() - 1, index,
                      preorderMap);
    }
};