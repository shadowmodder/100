/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
https://www.lintcode.com/problem/palindrome-partitioning/description
*/

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> results;
        vector<string> result;
        
        DFS(s, 0, result, results);
        
        return results;
    }
    
private:
    void DFS(string &s, int start, vector<string> &result, 
                                   vector<vector<string>> &results) {
        if (start == s.length()) {
            results.push_back(result);
            return;
        }
        
        // here the range of i, think with only one letter
        for (int i = 1; i <= s.length() - start; i++) {
            string str = s.substr(start, i);
            if (isPalindrome(str)) {
                result.push_back(str);
                DFS(s, start + i, result, results);
                result.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s) {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            if (s.at(lo++) != s.at(hi--)) return false;
        }
        return true;
    }
};
