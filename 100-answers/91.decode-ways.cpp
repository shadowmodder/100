/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.08%)
 * Total Accepted:    249.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int prev_prev = 1;
        int prev  = s.at(0) != '0' ? 1: 0;

        for (int i = 1; i < n; i++) {
            int cur = 0;
            int index = stoi(s.substr(i-1, 2));
            if (s.at(i-1) != '0' && index >= 1 && index <= 26) {
                cur = prev_prev;
            }

            char ch = s.at(i);
            if (ch >= '1' && ch <= '9') {
                cur += prev;
            }

            prev_prev = prev;
            prev = cur;
        }

        return prev;
    }
};

