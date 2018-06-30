/*
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.
https://www.lintcode.com/en/problem/flatten-binary-tree-to-linked-list/
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        //flat(root);
        helper(root);
    }
    
private:

    void flat(TreeNode * root) {
        if (root == NULL) return;
        
        TreeNode* r = root->right;
        TreeNode* l = root->left;
        
        flat(l);
        flat(r);
        
        if (l != NULL) {        
            root->right = l;
            while(l->right != NULL) l = l->right;
            l->right = r;
            root->left = NULL;
        }
    }

    TreeNode* helper(TreeNode * r) {
        if (r == NULL) return NULL;
        
        TreeNode * leftLast  = helper(r->left);
        TreeNode * rightLast = helper(r->right);
        
        if (leftLast != NULL) {
            leftLast->right = r->right; 
            r->right = r->left;
            r->left = NULL;
        }
        
        if (rightLast != NULL) {
            return rightLast;
        }
        
        if (leftLast != NULL) {
            return leftLast;
        }
 
        return r;
    }

};
