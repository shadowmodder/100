/*
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.

https://www.lintcode.com/problem/binary-search-tree-iterator/
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    BSTIterator(TreeNode * root) {
        cur = getMostLeftChild(root);
        s.push(cur);
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        if (cur->right != NULL) {
            cur = getMostLeftChild(cur->right);
        } else {
            if (s.size() > 0) {
                cur = s.top();
                s.pop();
            } else {
                cur = NULL;
            }
        }  
        
        return cur != NULL ? true : false;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        return cur;
    }
    
private:
    TreeNode* cur;
    stack<TreeNode *> s;
    
    TreeNode * getMostLeftChild(TreeNode * root) {
        if (root == NULL) return NULL;
        
        while (root->left != NULL) {
            s.push(root);
            root = root->left;
        }
        return root;
    }
};