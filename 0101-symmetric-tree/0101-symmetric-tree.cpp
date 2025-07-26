class Solution {
private:
    /**
     * Recursively checks if two subtrees are mirror images of each other.
     */
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode && !rightNode) return true;
        if (!leftNode || !rightNode) return false;
        if (leftNode->val != rightNode->val) return false;

        // Compare outer pair and inner pair
        return isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }

public:
    /**
     * Returns true if the tree is symmetric (mirror image of itself).
     */
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
