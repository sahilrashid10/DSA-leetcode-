/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string data = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int lvlSize = q.size();
            for (int i = 0; i < lvlSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node == nullptr)
                    data.append("#,");
                else {
                    data.append(to_string(node->val) + ',');
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        string str;
        stringstream s(data);
        getline(s, str, ',');  // str = "1", s = "1,2,#,#,3,4,5"

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while (!q.empty()) {
            int lvlSize = q.size();

            for (int i = 0; i < lvlSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Left child
                getline(s, str, ',');
                if (str == "#")
                    node->left = nullptr;
                else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }

                // Right child
                getline(s, str, ',');
                if (str == "#")
                    node->right = nullptr;
                else {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));