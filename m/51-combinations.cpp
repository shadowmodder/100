/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

https://www.lintcode.com/problem/combinations/description
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> result;

        if (n < k) {
            results.push_back(result);
            return results;
        }
        
        DFS(n, k, 1, result, results);
        
        return results;
    }
    
private:
    void DFS(int n, int k, int start, vector<int> &result,
             vector<vector<int>> & results) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }         
        
        for (int i = start; i <= n; i++) {
            result.push_back(i);
            DFS(n, k, i + 1, result, results);
            result.pop_back();
        }
    }
};