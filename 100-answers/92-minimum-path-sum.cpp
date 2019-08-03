/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
https://www.lintcode.com/problem/minimum-path-sum/description
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        
        int cols = grid[0].size();
        if (cols == 0) return 0;
        
        vector<vector<int>> path(rows, vector<int>(cols, 0));
        
        path[0][0] = grid[0][0];
        for (int r = 1; r < rows; r++) {
            path[r][0] = grid[r][0] + path[r-1][0];
        }
        for (int c = 1; c < cols; c++) {
            path[0][c] = grid[0][c] + path[0][c-1];
        }
        
        for (int r = 1; r < rows; r++)
            for (int c = 1; c < cols; c++) {
                path[r][c] = min(path[r-1][c], path[r][c-1]) + grid[r][c];
            }
            
        return path[rows-1][cols-1];
    }
};

