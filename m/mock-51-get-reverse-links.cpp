#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getReverseLinks(vector<int> &nums) {
        if (nums.size() <= 1) return 0;

        int ans = 0;
        TreeNode *root = NULL;
        for (int i = 0; i < nums.size(); i++) {
            ans += getReverseNums(root, nums[i]);
            cout << nums[i] << " " << getReverseNums(root, nums[i]) << endl;
            root = insert(root, nums[i]);
        }
        return ans;
    }

    int verify(vector<int> & nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] <= nums[i]) ans++;
            }

        return ans;
    }
private:
    struct TreeNode {
        int val;
        int cnt;
        TreeNode *left, *right;
        TreeNode(int val, int cnt) {
            this->val = val;
            this->cnt = cnt;
            left = NULL;
            right = NULL;
        }
    };

    TreeNode* insert(TreeNode *root, int val) {
        if (root == NULL) {
            return new TreeNode(val, 1);
        }

        if (val > root->val) {
            root->right = insert(root->right, val);
            root->cnt++;
        } else if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->cnt++;
        }
        return root;
    }

    int getReverseNums(TreeNode * root, int val) {
        if (root == NULL) {
            return 0;
        }

        if (val > root->val) {
            return getReverseNums(root->right, val);
        } else if (val < root->val) {
            return root->cnt + getReverseNums(root->left, val);
        } else {
            return root->cnt;
        }
    }

};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {2, 1, 3, 3, 4, 6, 7, 9, 0, 3};
    cout << s.getReverseLinks(nums) << endl;
    cout << s.verify(nums) << endl;
    return 0;
}