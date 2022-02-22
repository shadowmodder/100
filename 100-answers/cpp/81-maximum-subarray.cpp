/*
Given an array of integers, find a contiguous subarray which has the largest sum.

https://www.lintcode.com/problem/maximum-subarray/description
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        int maxsum = INT_MIN;
        /* presum method
        int minpresum = 0;
        int presum = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            maxsum = max(maxsum, presum - minpresum);
            minpresum = min(presum, minpresum);
        } */
        
        int sum  = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxsum = max(maxsum, sum);
            sum = max(sum, nums[i]);
        }
 
        return maxsum;
    }
};