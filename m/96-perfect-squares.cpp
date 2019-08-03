/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 https://www.lintcode.com/problem/perfect-squares/description
 */

 class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        /*
        13 : 1 + 12
           : 4 + 9
           : 9 + 4
           : 16  return
        */
        vector<int> dp (n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s*s <= i; s++) {
                dp[i] = min(dp[i], dp[i - s*s] + 1);
            }
        }
        
        return dp[n];
    }
};
