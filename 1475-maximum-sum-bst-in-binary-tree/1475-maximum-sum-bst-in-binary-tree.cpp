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

struct Info {
    int sum;     // Sum of the BST subtree
    int minVal;  // Minimum value in subtree
    int maxVal;  // Maximum value in subtree

    Info(int s, int mn, int mx) : sum(s), minVal(mn), maxVal(mx) {}
};

class Solution {
private:
    int maxSum = 0;

    Info postorder(TreeNode* node) {
        if (!node)
            return Info(0, INT_MAX, INT_MIN);  // Base case: null node

        Info left = postorder(node->left);
        Info right = postorder(node->right);

        // Check if current subtree is a BST
        if (left.maxVal < node->val && node->val < right.minVal) {
            int currentSum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, currentSum);

            int subtreeMin = min(left.minVal, node->val);
            int subtreeMax = max(right.maxVal, node->val);

            return Info(currentSum, subtreeMin, subtreeMax);
        }

        // Not a BST: return invalid range to signal parent
        return Info(0, INT_MIN, INT_MAX);
    }

public:
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum;
    }
};
