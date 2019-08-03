/*
https://www.lintcode.com/problem/longest-increasing-subsequence/description
Given a sequence of integers, find the longest increasing subsequence (LIS).
*/

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int ans = 0;
        
        vector<int> path(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    path[i] = max(path[i], path[j] + 1);
                }
            }
            ans = max(ans, path[i]);
        }
        
        return ans;
    }
};