/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Example
Given root = {1}, target = 4.428571, return 1.

https://www.lintcode.com/problem/closest-binary-search-tree-value/
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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        TreeNode* ans = DFS(root, target); 
        return ans->val;
    }
    
private:
    TreeNode* DFS(TreeNode * root, double target) {
        if (root == NULL) return NULL;
        
        int diff = doubleCompare(root->val, target);
        if (diff == 0) {
            return root;
        } else if (diff > 0) {
            TreeNode * left  = DFS(root->left, target);
            if (left == NULL) return root;
            int cmp = doubleCompare(abs(root->val - target), abs(left->val - target));
            return (cmp <= 0) ? root : left;
        } else {
            TreeNode * right = DFS(root->right, target);
            if (right == NULL) return root;
            int cmp = doubleCompare(abs(root->val - target), abs(right->val - target));
            return (cmp <= 0) ? root : right;
        }
  
    }
    
    const double EPSILON = 0.0001;
    int doubleCompare(double a, double b) {
        if (abs(a - b) < EPSILON) {
            return 0;
        } else if (a < b) {
            return -1;
        } else {
            return 1;
        }
    }
};