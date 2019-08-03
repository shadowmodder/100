/*
remove a node from BST
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        if (root == nullptr) return nullptr;
        
        if (root->val == value) {
            if (root->right == nullptr) {
                TreeNode *ret = root->left;
                delete root;
                return ret;
            } else if (root->left == nullptr) {
                TreeNode *ret = root->right;
                delete root;
                return ret;
            } else {
                TreeNode * leftmax = root->left;
                while (leftmax->right != nullptr)
                    leftmax = leftmax->right;
                root->val = leftmax->val;
                root->left = removeNode(root->left, leftmax->val);
                return root;
            }

        }
        
        if (root->val < value) {
            root->right = removeNode(root->right, value);
        } else {
            root->left = removeNode(root->left, value);
        }
        
        return root;
    }
    
private:
struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
};
};