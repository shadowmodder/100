/**
 * https://www.lintcode.com/en/problem/kth-smallest-element-in-a-bst/
 * Given a binary search tree, write a function kthSmallest to find the
 * kth smallest element in it.
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        int cnt = 0;
        int ret;
        
        DFS(root, cnt, ret, k);
        
        return ret;
    }
private:
    void DFS(TreeNode * root, int& cnt, int& ret, int k) {
        if (root == NULL) return;
        
        DFS(root->left, cnt, ret, k);
        
        if (cnt > k) return;
        if (++cnt == k) {
            ret = root->val;
            return;
        }
        
        DFS(root->right, cnt, ret, k);
    }
};