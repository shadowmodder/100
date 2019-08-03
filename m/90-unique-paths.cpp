/*
A robot is located at the top-left corner of a m x n grid.

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?
https://www.lintcode.com/problem/unique-paths/
*/
class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) path[r][0] = 1;
        for (int c = 0; c < n; c++) path[0][c] = 1;
        
        for (int r = 1; r < m; r++)
            for (int c = 1; c < n; c++) {
                path[r][c] = path[r - 1][c] + path[r][c - 1];
            }
        
        return path[m-1][n-1];
    }
};
