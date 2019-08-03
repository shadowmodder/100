/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
https://www.lintcode.com/problem/subsets-ii/description
*/

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<int> result;
        vector<vector<int>> results;
        if (nums.size() == 0) {
            results.push_back(result);
            return results;
        }
        
        vector<bool> selected(nums.size(), false);
        sort(nums.begin(), nums.end());
        DFS(nums, 0, selected, result, results);
        
        return results;
    }
    
private:
    void DFS(vector<int> & nums, int start, vector<bool> &selected,
             vector<int> &result,
             vector<vector<int>> &results) {
        if (start == nums.size()) {
            results.push_back(result);
            return;
        }         
   
        DFS(nums, start + 1, selected, result, results);

        // node: how to remove duplicates?
        if(!(start > 0 && nums[start] == nums[start - 1] &&
           !selected[start - 1])) {
            result.push_back(nums[start]);
            selected[start] = true;
            DFS(nums, start + 1, selected, result, results);
            result.pop_back();
            selected[start] = false;
        }
            
                 
    }
};