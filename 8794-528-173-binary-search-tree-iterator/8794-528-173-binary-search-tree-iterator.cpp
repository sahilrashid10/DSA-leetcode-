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
class BSTIterator {
public:
    stack<TreeNode*> nodeStack;

    BSTIterator(TreeNode* root) {
        pushLeftSubtree(root);
    }

    int next() {
        TreeNode* cur = nodeStack.top();
        nodeStack.pop();
        int result = cur->val;

        // Push all left children of the right subtree
        if (cur->right) {
            pushLeftSubtree(cur->right);
        }

        return result;
    }

    bool hasNext() {
        return !nodeStack.empty();
    }

private:
    void pushLeftSubtree(TreeNode* node) {
        while (node) {
            nodeStack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
