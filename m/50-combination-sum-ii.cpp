/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

https://www.lintcode.com/problem/combination-sum-ii/description
*/

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> results;
        vector<int> result;
        
        if (num.size() == 0) return results;
        
        sort(num.begin(), num.end());
        DFS(num, 0, target, result, results);
        
        return results;
    }
    
private:
    void DFS(vector<int>& num, int start, int sum, vector<int> &result,
             vector<vector<int>> & results) {
        if (sum < 0) return;
        if (sum == 0) {
            results.push_back(result);
            return;
        }
        
        for (int i = start; i < num.size(); i++) {
            if (i > start && num[i] == num[i - 1]) continue;
            
            result.push_back(num[i]);
            DFS(num, i + 1, sum - num[i], result, results);
            result.pop_back();
        }
                 
    }
};