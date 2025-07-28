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

class BSTIterator{
    public:
    void pushNodes(TreeNode* root){
        while(root){
            nodeStack.push(root);
            if(reverseOrder)
                root = root->right;
            else
                root = root->left;
        }
    }
    BSTIterator(TreeNode* root, bool order){
        reverseOrder = order;
        pushNodes(root);
    }

    bool hasElement(){
        return !nodeStack.empty();
    }

    int next(){
        TreeNode *node = nodeStack.top();
        nodeStack.pop();

        if(reverseOrder)
            pushNodes(node->left);

        else
            pushNodes(node->right);

        return node->val;
    }
private:
    stack<TreeNode*> nodeStack;
    bool reverseOrder = true;
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int l = left.next(), r = right.next();
        while(l < r){
    
            if(l + r > k){
                r = right.next();
            }else if(l + r < k){
                l = left.next();
            }else return true;

        }
        return false;
    }
};