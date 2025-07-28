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
 //Optimal solution: idea: use stack instead of recursion for storing values and do the inorder
class BSTIterator {
public:
    // Constructor: initialize stack with the leftmost path from root
    BSTIterator(TreeNode* root) {
        pushLeftBranch(root);
    }

    // Returns the next smallest element in the BST
    int next() {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();

        // If the node has a right child, push its leftmost path
        if (node->right) {
            pushLeftBranch(node->right);
        }

        return node->val;
    }

    // Returns true if there are more elements in the BST
    bool hasNext() const {
        return !nodeStack.empty();
    }

private:
    stack<TreeNode*> nodeStack;

    // Helper function to push all left children of a subtree
    void pushLeftBranch(TreeNode* node) {
        while (node) {
            nodeStack.push(node);
            node = node->left;
        }
    }
};



// O(n) time and O(n) space brute force
// class BSTIterator {
// public:
//     void inorder(TreeNode* root){
//         if(!root) return;
//         inorder(root->left);
//         inorderValues.push_back(root->val);
//         inorder(root->right);
//     }
//     BSTIterator(TreeNode* root) {
//         inorder(root);
//         n = inorderValues.size();
//     }
    
//     int next() {
//         if(i>n) return NULL;

//         return inorderValues[i++];
//     }
    
//     bool hasNext() {
//         if(i<n) return true;
//         return false;
//     }
// private:
//     vector<int>inorderValues;
//     int n;
//     int i = 0;
// };


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */