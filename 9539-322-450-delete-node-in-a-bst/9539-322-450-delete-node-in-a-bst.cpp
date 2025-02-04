class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (!root) return nullptr;

        TreeNode *node = root, *parent = nullptr;

        // Search for the node to delete
        while (node && node->val != val) {
            parent = node;
            node = (val < node->val) ? node->left : node->right;
        }

        if (!node) return root; // Node not found

        // Case 1: Node has a left subtree
        if (node->left) {
            TreeNode* temp = node->left;
            while (temp->right) temp = temp->right;  // Find rightmost node in left subtree
            temp->right = node->right;  // Connect right subtree
            
            if (parent) {
                if (parent->right == node) parent->right = node->left;
                else parent->left = node->left;
            } else root = node->left; // Deleting the root node
        }
        // Case 2: Node has no left subtree, only right child or no child
        else {
            if (parent) {
                if (parent->right == node) parent->right = node->right;
                else parent->left = node->right;
            } else root = node->right; // Deleting the root node
        }

        delete node;
        return root;
    }
};
