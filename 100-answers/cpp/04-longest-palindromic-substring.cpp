/*
https://www.lintcode.com/problem/longest-palindromic-substring/
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
try O(n)
*/
class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int max = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int lo = i - 1;
            int hi = i + 1;
            int len = 1;
            // i is the palindrome center
            while (lo >= 0 && hi < s.length()) {
                if (s[lo] == s[hi]) {
                    lo--;
                    hi++;
                    len = len + 2;
                } else {
                    break;
                }
            }
            if (max < len) {
                max = len;
                start = i - len / 2;
            }
            // i is the right center, abbc
            if(i > 0 && s[i] == s[i-1]) {
                lo = i - 2;
                hi = i + 1;
                len = 2;
                while (lo >= 0 && hi < s.length()) {
                    if (s[lo] == s[hi]) {
                        lo--;
                        hi++;
                        len = len + 2;
                    } else {
                       break;
                    }
                }
                if (max < len) {
                    max = len;
                    start = i - len / 2;
                }
            }
        }
        return s.substr(start, max);
    }
};
