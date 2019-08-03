/*
https://www.lintcode.com/en/problem/binary-tree-level-order-traversal/
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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> oneLevel;
            
            for (int i = 0; i < size; i++) {
                TreeNode * v = q.front();
                q.pop();
                oneLevel.push_back(v->val);
                if (v->left != NULL)  q.push(v->left);
                if (v->right != NULL) q.push(v->right);
            }
            
            ret.push_back(oneLevel);
        }
        
        return ret;
    }
};