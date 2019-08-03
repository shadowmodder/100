/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
https://www.lintcode.com/problem/largest-divisible-subset/description
*/

class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        vector<int> parent(nums.size(), -1);
        vector<int> pathLen(nums.size(), 1);
        int maxIndex = 0;

        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((pathLen[j] + 1 > pathLen[i]) && nums[i] % nums[j] == 0) {
                    parent[i] = j;
                    pathLen[i] = pathLen[j] + 1;
                }
            }

            if (pathLen[maxIndex] < pathLen[i]) {
                maxIndex = i;
            }
        }
        
        vector<int> ans;
        int index = maxIndex;
        while (index != -1) {
            ans.push_back(nums[index]);
            index = parent[index];
        }
        
        return ans;
    }
};
