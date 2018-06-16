/*
https://www.lintcode.com/en/problem/two-sum-ii-input-array-is-sorted/
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
*/

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        if (nums.size() < 2) return ans;

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if      (sum < target) lo++;
            else if (sum > target) hi--;
            else {
                ans.push_back(lo + 1);
                ans.push_back(hi + 1);
                break;
            }
        }
        return ans;
    }
};