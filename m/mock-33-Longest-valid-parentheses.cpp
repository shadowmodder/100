/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string &s) {
        int maxlen = 0;
        /* brute froce */
        /*
        for (int i = 0; i < s.length(); i++)
            for (int j = i + 1; j < s.length(); j++) {
                if (isValidParentheses(s, i, j)) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        */

        /* dynamic program */
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s.at(i) == ')') {
                if (s.at(i-1) == '(')
                    dp[i] = dp[i-2] + 2;
                else {
                    if ((i > dp[i-1])&& s.at(i - dp[i-1]- 1) == '(')
                        dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2];
                }     
            }
            maxlen = max(maxlen, dp[i]);
        }

        return maxlen;
    }
private:
    bool isValidParentheses(string &str, int lo, int hi) {
        stack<char> s;
        for (int i = lo; i <= hi; i++) {
            if (str.at(i) == '(')                  s.push('(');
            else if (!s.empty() && s.top() == '(') s.pop();
            else                                   return false;
        }
        return true;
    }

};

int main() {
    string str = ")()())";
    
    Solution *s = new Solution();
    int result = s->longestValidParentheses(str);
    
    cout << result << endl;

    return 0;
}