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
    TreeNode* makeTree(vector<int>& preorder, int s, int e){
       if(s > e) return nullptr;

       TreeNode* root = new TreeNode(preorder[s]);
       int newEnd = s+1;
       while(newEnd <= e && root->val > preorder[newEnd])
                newEnd++;
        root->left = makeTree(preorder, s+1, newEnd-1);
        root->right = makeTree(preorder, newEnd, e);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return makeTree(preorder, 0, n-1);
    }
};