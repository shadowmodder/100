/*

https://www.lintcode.com/problem/serialize-and-deserialize-binary-tree/description
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        string ret = "";
        if (root == nullptr) return ret;
        
        TreeNode* dummy= new TreeNode(-1);
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode * q = queue.front();
            queue.pop();
            if (q == dummy) {
                ret += "#,";
            } else {
                ret = ret + to_string(q->val) + ",";
                TreeNode *left = (q->left != nullptr) ? q->left: dummy;
                queue.push(left);
                
                TreeNode *right = (q->right != nullptr) ? q->right: dummy;
                queue.push(right);
            }
        }
        
        return ret;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        vector<string> values;
        TreeNode * root = nullptr;
        
        while (true) {
            int index = data.find_first_of(',');
            if (index <= 0) break;
            values.push_back(data.substr(0, index));
            data = data.substr(index + 1);
        }
        if (values.size() == 0) return root;
        
        root = new TreeNode(stoi(values[0]));
        queue<TreeNode *> queue;
        queue.push(root);
        
        int i = 1;
        while (!queue.empty() && i < values.size()) {
            TreeNode * node = queue.front();
            queue.pop();
            
            if (values[i].compare("#") != 0) {
                node->left = new TreeNode(stoi(values[i]));
                queue.push(node->left);
            }
            if (values[i].compare("#") != 0) {
                node->right = new TreeNode(stoi(values[i]));
                 queue.push(node->right);
            }
            i += 2;
        }
        
        return root;
    }
};