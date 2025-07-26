class Solution {
private:
    /**
     * Recursively builds the subtree from:
     * - preorder[preStart..preEnd]
     * - inorder[inStart..inEnd]
     * Uses a hashmap to find root indices quickly in inorder array.
     */
    TreeNode* buildSubtree(const vector<int>& preorder, int preStart, int preEnd,
                           const vector<int>& inorder,  int inStart,  int inEnd,
                           unordered_map<int, int>& inorderIndexMap) {
        // Base case: invalid range
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element in preorder is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root index in inorder
        int rootInorderIndex = inorderIndexMap[rootVal];

        // Elements on the left of root in inorder are part of left subtree
        int leftSubtreeSize = rootInorderIndex - inStart;

        // Build left subtree
        root->left = buildSubtree(preorder, preStart + 1, preStart + leftSubtreeSize,
                                  inorder, inStart, rootInorderIndex - 1, inorderIndexMap);

        // Build right subtree
        root->right = buildSubtree(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                   inorder, rootInorderIndex + 1, inEnd, inorderIndexMap);

        return root;
    }

public:
    /**
     * Builds a binary tree from preorder and inorder traversal arrays.
     * Time: O(n), Space: O(n)
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;

        // Build a value-to-index map for quick lookup in inorder traversal
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < n; ++i)
            inorderIndexMap[inorder[i]] = i;

        return buildSubtree(preorder, 0, n - 1, inorder, 0, n - 1, inorderIndexMap);
    }
};
