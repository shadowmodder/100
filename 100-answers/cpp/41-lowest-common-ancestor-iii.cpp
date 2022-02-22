/*
https://www.lintcode.com/en/problem/lowest-common-ancestor-iii/ 
Description
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Notice
node A or node B may not exist in tree.
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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {

        ResultLCA res = findLCA(root, A, B);
        
        return (res.v1 && res.v2) ? res.node : NULL;
    }

private:
    struct ResultLCA {
        bool v1;
        bool v2;
        TreeNode * node;
        ResultLCA(TreeNode * n, bool v1, bool v2) {
            this->v1 = v1;
            this->v2 = v2;
            this->node = n;
        }
    };

    ResultLCA findLCA(TreeNode * root, TreeNode* A, TreeNode *B) {
        if (root == NULL) {
            return ResultLCA(root, false, false);
        }

        if (root == A) {
            return ResultLCA(root, true, findNode(A, B));
        }

        if (root == B) {
            return ResultLCA(root, findNode(B, A), true);
        }

        ResultLCA left  = findLCA(root->left,  A, B);
        ResultLCA right = findLCA(root->right, A, B);

        if (left.node != NULL && right.node != NULL) {
            return ResultLCA(root, true, true);
        }

        if (left.node != NULL) {
           return ResultLCA(left.node, left.v1, left.v2);
        }

        if (right.node != NULL) {
           return ResultLCA(right.node, right.v1, right.v2);
        }


        return ResultLCA(NULL, false, false);
    }

    bool findNode(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false;
        if (s == t) return true;

        return findNode(s->left, t) || findNode(s->right, t);
    }
};

int main()
{
    // Let us create binary tree given in the above example
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution * s= new Solution();

    TreeNode *lca =  s->lowestCommonAncestor(root, root->left, 
                                                  root->right->right);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->val << endl;
    else
       cout << "Keys are not present " << endl;
 
    TreeNode * ten = new TreeNode(10);
    lca =  s->lowestCommonAncestor(root, root->left->left, ten);
    if (lca != NULL)
       cout << "LCA(4, 10) = " << lca->val << endl;
    else
       cout << "Keys are not present " << endl;
 
    return 0;
}