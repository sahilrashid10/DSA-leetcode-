class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;

        // Map each value to its index in the inorder traversal
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildSubtree(
            postorder, 
            0, postorder.size() - 1, 
            inorder, 
            0, inorder.size() - 1, 
            inorderIndexMap
        );
    }

private:
    TreeNode* buildSubtree(
        const vector<int>& postorder, int postStart, int postEnd,
        const vector<int>& inorder, int inStart, int inEnd,
        unordered_map<int, int>& inorderIndexMap
    ) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        // The last element in postorder is the root
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder traversal
        int rootIndexInInorder = inorderIndexMap[rootVal];
        int leftSubtreeSize = rootIndexInInorder - inStart;

        // Recursively build left and right subtrees
        root->left = buildSubtree(
            postorder,
            postStart,
            postStart + leftSubtreeSize - 1,
            inorder,
            inStart,
            rootIndexInInorder - 1,
            inorderIndexMap
        );

        root->right = buildSubtree(
            postorder,
            postStart + leftSubtreeSize,
            postEnd - 1,
            inorder,
            rootIndexInInorder + 1,
            inEnd,
            inorderIndexMap
        );

        return root;
    }
};
