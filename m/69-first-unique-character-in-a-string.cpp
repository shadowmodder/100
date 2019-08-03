/*
Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

Example
For "abaccdeff", return 'b'.

https://www.lintcode.com/problem/first-unique-character-in-a-string/
*/

class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        unordered_map<char, int> map;
        
        for (int i = 0; i < str.length(); i++) {
                map[str.at(i)]++;
        }
        
        for (int i = 0; i < str.length(); i++) {
            if (map[str.at(i)] == 1) return str.at(i);
        }
        
        return ' ';
    }
};