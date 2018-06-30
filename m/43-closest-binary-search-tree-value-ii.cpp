/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
https://www.lintcode.com/problem/closest-binary-search-tree-value-ii/description

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
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        vector<int> ans;
        priority_queue<double, vector<double>, Compare>  pq;
        
        inOrderTraversal(root, target, pq, k);
        
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top() + target);
            pq.pop();
        }
        
        return ans;
    }

    struct Compare {
        bool operator()(double lhs, double rhs) {
            return abs(lhs) < abs(rhs);
        }
    };

    
private:
    
    void inOrderTraversal(TreeNode * root, double target,
              priority_queue<double, vector<double>, Compare>  &pq, int k) {
                  
        if (root == NULL) return;
        
        inOrderTraversal(root->left, target, pq, k);
        
        double diff = root->val - target;
        if (pq.size() == k && abs(diff) > abs(pq.top())) return;
        
        pq.push(diff);
        if (pq.size() == k + 1) {
            pq.pop();
        } 
        
        inOrderTraversal(root->right, target, pq, k);
    }

};
