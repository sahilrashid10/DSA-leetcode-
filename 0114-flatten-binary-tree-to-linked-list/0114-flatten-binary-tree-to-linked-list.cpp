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
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* temp = cur->left;

                while(temp->right){
                    temp = temp->right;
                }
                temp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;

                cur = cur->right;
                
            }else{
                cur = cur->right;
            }
        }
    }
};


/**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (!root) return;

//         // Step 1: Store nodes in preorder traversal
//         vector<TreeNode*> nodes;
//         preorder(root, nodes);

//         // Step 2: Re-link nodes
//         for (int i = 0; i < nodes.size() - 1; ++i) {
//             nodes[i]->left = nullptr;
//             nodes[i]->right = nodes[i + 1];
//         }
//     }

// private:
//     // Helper function to perform preorder traversal and store nodes
//     void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
//         if (!node) return;

//         nodes.push_back(node);
//         preorder(node->left, nodes);
//         preorder(node->right, nodes);
//     }
// };
