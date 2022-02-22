/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Example
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

https://www.lintcode.com/problem/remove-invalid-parentheses/description
*/
class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &s) {
        vector<string> results;
        
        int l = 0, r = 0;
        for (const char ch: s) {
            l += (ch == '(') ? 1: 0;
            if (l == 0) {
                r += (ch == ')') ? 1: 0;
            } else {
                l -= (ch == ')') ? 1: 0;
            }
        }
        DFS(s, 0, l, r, results);
        
        return results;
    }
    
private:
    void DFS(const string &s, int start, int l, int r, vector<string> &results) {
        if (l == 0 && r == 0) {
            if(isValid(s)) {
                results.push_back(s);
            }
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (s.at(i) == '(' || s.at(i) == ')') {
                if (i > start && s.at(i) == s.at(i - 1)) continue;
                
                string str = s.substr(0, i) + s.substr(i+1);
                if(r > 0 && s.at(i) == ')') {
                    DFS(str, i, l, r - 1, results);
                } else if (l > 0) {
                    DFS(str, i, l - 1, r, results);
                }
            }
        }
    }
    
    bool isValid(const string &s) {
        int count = 0;
        for (const char c: s) {
            if (c == '(') count++;
            if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};

/*
reference: 
http://zxi.mytechroad.com/blog/string/leetcode-301-remove-invalid-parentheses/
*/