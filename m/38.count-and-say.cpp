/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.40%)
 * Total Accepted:    256.8K
 * Total Submissions: 651.7K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string temp = "";
            for (int i = 0, cnt = 1; i < ans.length(); i++) {
                if (i + 1 == ans.length() || ans[i + 1] != ans[i]) {
                    temp += to_string(cnt) + ans[i];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            ans = temp;
        }

        return ans;
    }
};
