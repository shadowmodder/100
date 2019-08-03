/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
https://www.lintcode.com/problem/triangle/description
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) return 0;
        
        vector<int> path(triangle.back().begin(), triangle.back().end());

        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int c = 0; c < triangle[r].size(); c++) {
                path[c] = triangle[r][c] + min(path[c], path[c + 1]);
            }
        }
        
        return path[0];
    }
};