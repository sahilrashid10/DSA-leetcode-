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
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* first = nullptr;
        TreeNode* last = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* prev = nullptr;

        while (cur) {
            if (!cur->left) {
                // Process current node
                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                        middle = cur;
                    } else {
                        last = cur;
                    }
                }
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode* temp = cur->left;

                while (temp->right && temp->right != cur)
                    temp = temp->right;

                if (temp->right == nullptr) {
                    // Create threaded link
                    temp->right = cur;
                    cur = cur->left;
                } else {
                    // Remove threaded link
                    temp->right = nullptr;

                    // Process current node
                    if (prev && prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                            middle = cur;
                        } else {
                            last = cur;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        // Correct the swapped nodes
        if (last) {
            swap(first->val, last->val);
        } else {
            swap(first->val, middle->val);
        }
    }
};
