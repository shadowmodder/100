/*
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route.
Return -1 if knight can not reached.
https://www.lintcode.com/problem/knight-shortest-path/description

*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
     /*
     Note: make sure only put the points into queue once
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        const int STEPS = 8;
        int nextStep[][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bool> marked(rows * cols, false);
        int path = 0;
        
        queue<Point> queue;
        queue.push(source);
        marked[source.x * cols + source.y] = true;

        while (!queue.empty()) {
            int sz = queue.size();
            for (int t = 0; t < sz; t++) {
                Point p = queue.front();
                queue.pop();
                
                if (p.x == destination.x && p.y == destination.y) {
                    return path;
                }
            
                for (int i = 0; i < STEPS; i++) {
                    int nx = p.x + nextStep[i][0];
                    int ny = p.y + nextStep[i][1];
                    
                    if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                    if (marked[nx * cols + ny] || grid[nx][ny] == 1) continue;
                
                    queue.push(Point(nx, ny));
                    marked[nx * cols + ny] = true;
                }
            }
            path++;
        }
        return -1;
    }
};