/*
https://www.lintcode.com/en/problem/longest-palindrome/
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
*/
class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        vector<int> letters(52, 0);
        int oneLetter = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            letters[index(s.at(i))]++;
        }
        
        for (int i = 0; i < letters.size(); i++) {
            maxLen += (letters[i] / 2) * 2;
            if (oneLetter == 0 && letters[i] % 2 == 1)
                oneLetter = 1;
        }
        
        return maxLen + oneLetter;
    }
    
    int index(char c) {
        int idx = 0;
        
        if(c >= 'a' && c <= 'z') {
            idx = c - 'a';
        } else if(c >= 'A' && c <= 'Z') {
            idx = c - 'A' + 26;
        }
        
        return idx;
    }
};
