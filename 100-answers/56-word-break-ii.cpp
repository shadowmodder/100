/*
https://www.lintcode.com/problem/word-break-ii/
*/

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        vector<string> results;
        if (s.size() == 0) return results;
        
        string result = "";
        DFS(s, 0, wordDict, result, results);
        
        return results;
    }
    
private:
    void DFS(string &s, int start, unordered_set<string> &wordDict,
            string& result, vector<string> &results) {
        if (start == s.length()) {
            results.push_back(result);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            string str = s.substr(start, i - start + 1);
            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {
                int len = result.length();
                if (len != 0) result += " ";
                result += str;
                DFS(s, i + 1, wordDict, result, results);
                result = result.substr(0, len);
            }
        }
                
    }
};