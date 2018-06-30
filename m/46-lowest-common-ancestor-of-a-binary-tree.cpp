/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
https://www.lintcode.com/problem/lowest-common-ancestor-of-a-binary-tree/
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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (root == NULL) return NULL;
        
        if (root->val == A->val || root->val == B->val) return root;
        
        TreeNode * left  = lowestCommonAncestor(root->left,  A, B);
        TreeNode * right = lowestCommonAncestor(root->right, A, B);
        
        if (left != NULL && right != NULL) return root;
        
        return (left != NULL) ? left: right;
    }
    
};