/*
https://www.lintcode.com/en/problem/lowest-common-ancestor-ii/
Description
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.
*/
/*
NOT verified.
*/
#include <iostream>
using namespace std;

class TreeNode {
   public:
       int val;
       TreeNode *left, *right, *parent;
       TreeNode(int val) {
           this->val = val;
           this->left = nullptr;
           this->right = nullptr;
           this->parent = nullptr;
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
        int depthOfA = getDepth(A);
        int depthOfB = getDepth(B);

        cout << depthOfA << " " << depthOfB << endl;
        if (depthOfA - depthOfB > 0) {
            int stepDiff = depthOfA - depthOfB;
            while(stepDiff-- > 0) {
                A = A->parent;
            }
        } else {
            int stepDiff = depthOfB - depthOfA;
            while(stepDiff-- > 0) {
                B = B->parent;
            }
        }

        while (A != NULL && B != NULL && A != B) {
            A = A->parent;
            B = B->parent;
        }

        if (A == NULL || B == NULL) return nullptr;

        return A;
    }

private:
    int getDepth(TreeNode * target) {
        int depth = 0;
        while (target != NULL && target->parent != NULL) {
            target = target->parent;
            depth++;
        }
        return depth;
    }
};


int main()
{
    // Let us create binary tree given in the above example
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->parent = root;
    root->right = new TreeNode(3);
    root->right->parent = root;
    root->left->left = new TreeNode(4);
    root->left->left->parent = root->left;
    root->left->right = new TreeNode(5);
    root->left->right->parent = root->left;
    root->right->left = new TreeNode(6);
    root->right->left->parent = root->right;
    root->right->right = new TreeNode(7);
    root->right->right->parent = root->right;

    Solution * s= new Solution();

    TreeNode *lca =  s->lowestCommonAncestor(root, root->left, 
                                                  root->left->right);
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