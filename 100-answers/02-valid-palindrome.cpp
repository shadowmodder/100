/*
https://www.lintcode.com/problem/valid-palindrome/
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
O(n) without extra memory
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        int lo = 0, hi = s.length() - 1;
        
        while (lo < hi) {
            if (!isAlphaNum(s.at(lo))) {
                lo++;
            } else if (!isAlphaNum(s.at(hi))) {
                hi--;
            } else if (equals(s.at(lo), s.at(hi))) {
                lo++;
                hi--;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }
    
    bool equals(char u, char w) {
        if (u >= 'a' && u <= 'z')
             u = u - 'a' + 'A';
        if (w >= 'a' && w <= 'z')
             w = w - 'a' + 'A';
             
        return (u == w);
    }
};
