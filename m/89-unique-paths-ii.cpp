/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 https://www.lintcode.com/en/problem/unique-paths-ii/
 */

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows == 0) return 0;
        
        int cols = obstacleGrid[0].size();
        if (cols == 0) return 0;
        
        vector<vector<int>> path(rows, vector<int>(cols, 0));
        
        path[0][0] = obstacleGrid[0][0] == 1 ? 0: 1;
        
        for (int r = 1; r < rows; r++) {
            path[r][0] = (obstacleGrid[r][0] == 1) ? 0: path[r-1][0];
        }
        
        for (int c = 1; c < cols; c++) {
            path[0][c] = (obstacleGrid[0][c] == 1) ? 0: path[0][c-1];
        }
        
        for (int r = 1; r < rows; r++)
            for (int c = 1; c < cols; c++) {
                path[r][c] = path[r-1][c] + path[r][c-1];
                if (obstacleGrid[r][c] == 1) path[r][c] = 0;
            }
            
        return path[rows-1][cols-1];
    }
};