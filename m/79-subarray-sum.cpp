/*
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
https://www.lintcode.com/problem/subarray-sum/description
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        vector<int> result;
        
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.count(sum) > 0) {
                result.push_back(m[sum] + 1);
                result.push_back(i);
                break;
            } else {
                m[sum] = i;
            }
        }
        
        /*
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int j = i;
            while (j < nums.size()) {
                sum += nums[j];
                if (sum == 0) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
                j++;
            }
        }*/
        
        return result;
    }
};
