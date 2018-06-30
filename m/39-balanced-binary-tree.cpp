/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
https://www.lintcode.com/en/problem/balanced-binary-tree/
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        return helper(root) != -1;
    }
    
private:
    int helper(TreeNode * root) {
        if (root == NULL) return 0;
        
        int left = helper(root->left);
        if (left == -1) return -1;
        
        int right = helper(root->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
};
