/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 https://www.lintcode.com/problem/climbing-stairs/description
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n == 0) return 0;
        
        vector<int> path(n + 1, 0);
        
        path[0] = 1;
        path[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            path[i] = path[i-2] + path[i-1];
        }
        
        return path[n];
    }
};