/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

https://www.lintcode.com/problem/combination-sum/description
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        vector<int> result;
        vector<vector<int>> results;
        if (candidates.size() == 0) {
            results.push_back(result);
            return results;
        }
        
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0, result, results);
        
        return results;
    }
    
private:
    void DFS(vector<int>& candidates, int res, int start,
            vector<int>& result, vector<vector<int>>& results) {
        if (res < 0) return;
        if (res == 0) {
            results.push_back(result);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            result.push_back(candidates[i]);
            // important: where for next start, here is i
            DFS(candidates, res - candidates[i], i, result, results);
            result.pop_back();
        }
    }
};
