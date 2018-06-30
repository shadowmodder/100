/**
 * https://www.lintcode.com/problem/validate-binary-search-tree/description
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 */

/*
 * The node value maybe INT_MAX or INT_MIN.
*/
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        ResultType ret = isBST(root);
        return ret.isBST;
    }
    
private:
    struct ResultType {
        bool isBST;
        int  min;
        int  max;
        ResultType(bool isBST, int min, int max) {
            this->isBST = isBST;
            this->min   = min;
            this->max   = max;
        };
    };
    
    ResultType isBST(TreeNode *root) {
        if (root == NULL) return ResultType(true, INT_MAX, INT_MIN);
        
        ResultType left  = isBST(root->left);
        
        ResultType right = isBST(root->right);
        
        if (!left.isBST || !right.isBST) {
            return ResultType(false, 0, 0);
        }
        
        
        if ((root->left  != NULL && left.max >= root->val) ||
            (root->right != NULL && right.min <= root->val)) {
            return ResultType(false, 0, 0); 
                              
        }
        
        return ResultType(true,
                          min(left.min, root->val), 
                          max(right.max, root->val));
    }
};