/*
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

https://www.lintcode.com/problem/split-string/
*/

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        vector<string> result;
        vector<vector<string>> results;
        
        if (s.length() == 0) {
            results.push_back(result);
            return results;
        }
        
        dfs(s, 0, result, results);
        
        //results.push_back(result); // push an empty for first
        //helper(s, 0, results);
        return results;
    }
    
private:

    void dfs(string& s, int index, vector<string> result, vector<vector<string>>& results) {
        if (index == s.length()) {
            results.push_back(result);
            return;
        }
        
        for (int i = 1; i <= 2 && index + i <= s.length(); i++) {
            result.push_back(s.substr(index, i));
            dfs(s, index + i, result, results);
            result.pop_back();
        }
    }
    
    void helper(string& s, int start, vector<vector<string>>& results) {
        
        if (start == s.length()) return;
        
        string c = s.substr(start, 1);
        int sz = results.size();
        for (int i = 0; i < sz; i++) {
            if (results[i].size() > 0) {
                string v = results[i].back();
                if (v.length() == 1) {
                    vector<string> newResult(results[i].begin(), results[i].end() - 1);
                    newResult.push_back(v + c);
                    results.push_back(newResult);
                }
            }
            
            results[i].push_back(c);
        }
        
        helper(s, start + 1, results);
    }
};