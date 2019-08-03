/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.61%)
 * Total Accepted:    295.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        bool largestNegative = false;
        if (n < 0) {
            if (n == INT_MIN) {
                largestNegative = true;
                n += 1;
            }
            n = -n;
            x = 1/x;
        }

        double res = 1;
        for (double i = x; n > 0; n /= 2, i = i * i) {
            if (n % 2 != 0) res = i * res;
        }

        if (largestNegative) res *= x;
        return res;
    }
};

