/*
Given a binary tree, return all root-to-leaf paths.
https://www.lintcode.com/en/problem/binary-tree-paths/
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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> ans;
        if (root == NULL) return ans;
        
        /*
        vector<int> path;
        vector<vector<int>> paths;
        DFS(root, path, paths);
        
        for (int i = 0; i < paths.size(); i++) {
            string p;
            for (int j = 0; j < paths[i].size(); j++) {
                if (p.length() != 0) p += "->";
                p += to_string(paths[i][j]);
            }
            ans.push_back(p);
        }
        */
        
        /* traverse */
        string path = to_string(root->val);
        helper(root, path, ans);
        
        /* devide and conquer */
        ans = getPaths(root);
        
        return ans;
    }
    
private:
    void DFS(TreeNode * r, vector<int> & path, vector<vector<int>> &paths) {
        if (r == NULL) return;
        
        path.push_back(r->val);
        if (r->left == NULL && r->right == NULL) {
            paths.push_back(path);
            path.pop_back(); // need to pop out last one after inserting
            return;
        }
        
        DFS(r->left, path, paths);
        DFS(r->right, path, paths);
        
        path.pop_back();

        return;
    }
    
    void helper(TreeNode *r, string path, vector<string> &paths) {
        if (r == NULL) return;
        
        if (r->left == NULL && r->right == NULL) {
            paths.push_back(path);
            return;
        }
        
        if (r->left != NULL) {
            helper(r->left, path + "->" + to_string(r->left->val), paths);
        }
        if (r->right != NULL) {
            helper(r->right, path + "->" + to_string(r->right->val), paths);
        }
        
    }
    
    vector<string> getPaths(TreeNode *r) {
        vector<string> paths;
        if (r == NULL) return paths;
        
        vector<string> left  = getPaths(r->left);
        vector<string> right = getPaths(r->right);
        
        for (auto s: left) {
            paths.push_back(to_string(r->val) + "->" + s);
        }
        for (auto s: right) {
            paths.push_back(to_string(r->val) + "->" + s);
        }
        
        if (paths.size() == 0) paths.push_back(to_string(r->val));
        
        return paths;
    }
};