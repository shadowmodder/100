/*
https://www.lintcode.com/en/problem/3sum/
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        vector<vector<int>> ans;
        
        int n = numbers.size();
        if (n < 3) return ans;
        
        sort(numbers.begin(), numbers.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && numbers[i] == numbers[i-1]) continue;
            
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                if (lo > i +1 && numbers[lo] == numbers[lo - 1]) {
                    lo++;
                    continue;
                }
                
                if (hi < n - 1 && numbers[hi] == numbers[hi + 1]) {
                    hi--;
                    continue;
                }
                
                int sum = numbers[i] + numbers[lo] + numbers[hi];
                if      (sum < 0) lo++;
                else if (sum > 0) hi--;
                else {
                    vector<int> oneAns {numbers[i],
                                        numbers[lo], 
                                        numbers[hi]};
                    ans.push_back(oneAns);
                    lo++;
                    hi--;
                }
            }
        }
        return ans;
    }
};