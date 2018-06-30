/*
https://www.lintcode.com/problem/subsets/description
*/
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
       vector<int> result;
       vector<vector<int>> results;
       if (nums.size() == 0) {
           results.push_back(result);
           return results;
       }
       
       sort(nums.begin(), nums.end());
       DFS(nums, 0, result, results);
       
       return results;
    }
    
private:
    void DFS(vector<int> &nums, int start, vector<int> &result,
             vector<vector<int>>& results) {
        if (start == nums.size()) {
            results.push_back(result);
            return;
        }
        
        DFS(nums, start + 1, result, results);
        
        result.push_back(nums[start]);
        DFS(nums, start + 1, result, results);
        result.pop_back();
                
    }

};