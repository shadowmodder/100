/*

https://www.lintcode.com/problem/minimum-subtree/
Description
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Notice
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.


Example
Given a binary tree:

      1
    /   \
 -5      2
 / \     /  \
0   2  -4    -5
return the node 1.
*/

#include <iostream>

using namespace std;

class TreeNode {
   public:
       int val;
       TreeNode *left, *right;
       TreeNode(int val) {
           this->val = val;
           this->left = this->right = NULL;
       }
};
 
class Solution {
public:
     TreeNode* findSubtree(TreeNode* root) {
         ResultType ret = getSubTree(root);
         return ret.node;
     }

private:
    struct ResultType {
        int sum;
        TreeNode* node;
        ResultType(int sum, TreeNode* node) {
            this->sum = sum;
            this->node = node;
        }
    };

    ResultType getSubTree(TreeNode * root) {
        if(root == NULL) return ResultType(INT_MAX, NULL);

        ResultType left = getSubTree(root->left);
        ResultType right = getSubTree(root->right);

        int currentSum = left.sum + right.sum + root->val;
        
        ResultType ret(currentSum, root);
        ret.sum  = (left.sum < right.sum) ? left.sum : right.sum;
        ret.node = (left.sum < right.sum) ? left.node : right.node;

        if (ret.sum > currentSum) {
            ret.sum = currentSum;
            ret.node = root; 
        }

        return ret;
    }
};


int main()
{
    // Let us create binary tree given in the above example
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(-5);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(-4);
    root->right->right = new TreeNode(-5);

    Solution * s= new Solution();

    TreeNode *n =  s->findSubtree(root);
    if (n != NULL)
       cout << "root of min subtree = " << n->val << endl;
    else
       cout << "node is null " << endl;

    return 0;
}