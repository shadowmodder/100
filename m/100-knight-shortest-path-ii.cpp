/*
Knight Shortest Path II
Given a knight in a chessboard n * m (
a binary matrix with 0 as empty and 1 as barrier). the knight 
initial position is (0, 0) and he wants to reach position (n - 1, m - 1).
Find the shortest path to the destination position, 
return the length of the route. Return -1 if knight can not reached.

 
Clarification
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x - 1, y + 2)
(x + 2, y + 1)
(x - 2, y + 1

https://www.lintcode.com/problem/knight-shortest-path-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestPath2(vector<vector<bool>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> path(rows, vector<int>(cols, INT_MAX));

        path[0][0] = 0;
        for (int c = 0; c < cols; c++)
            for (int r = 0; r < rows; r++) {
                if (!grid[r][c]) {
                    int minVal = INT_MAX;
                    for (int i = 0; i < 4; i++) {
                        int nr = r + neighbors[i][0];
                        int nc = c + neighbors[i][1];
                        
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                        if (path[nr][nc] < minVal) minVal = path[nr][nc];
                    }
                    if (minVal < INT_MAX) {
                        path[r][c] = minVal + 1;
                        cout << "(" <<r << "," << c << "): " << path[r][c] << endl;
                    }
                }
            }
        
        return (path[rows-1][cols-1] == INT_MAX) ? -1: path[rows-1][cols-1];
    }
private:
    int neighbors[4][2]  = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}};
};

int main()
{
    vector<vector<bool>> grid_1 {{0,0,0,0}, {0,0,0,0},
                                 {0,1,0,0}};
    vector<vector<bool>> grid_2 {{0,0,0,0}, {0,0,0,0},
                                 {0,0,0,0}};

    Solution * s = new Solution();

    cout << s->shortestPath2(grid_1) << endl;                           

    return 0;
}