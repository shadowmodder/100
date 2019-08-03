/*
https://www.lintcode.com/problem/number-of-islands/
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.
*/
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int cnt  = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        /* BFS
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c]) {
                    BFS(grid, r, c);
                    cnt++;
                }
            }
        */
        
        /* DFS
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c]) {
                    DFS(grid, r, c);
                    cnt++;
                }
            }
        */
        
        /* union find */
        cnt = unionfind(grid);
        
        return cnt;        
    }

private:
    int rows;
    int cols;
    int neighbors[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    void BFS(vector<vector<bool>> &grid, int r, int c) {
        queue<int> queue;
        queue.push(r * cols + c);
        
        while (!queue.empty()) {
            int index = queue.front();
            queue.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = index / cols + neighbors[i][0];
                int nc = index % cols + neighbors[i][1];
                
                if (!inBound(nr, nc)) {
                    continue;
                }
                
                if (grid[nr][nc]) {
                    queue.push(nr * cols + nc);
                    grid[nr][nc] = false;
                }
            }
        }
    }
    
    void DFS(vector<vector<bool>> &grid, int r, int c) {
        if (!inBound(r, c))  return;
        if (!grid[r][c])     return;

        for (int i = 0; i < 4; i++) {
            int nr = r + neighbors[i][0];
            int nc = c + neighbors[i][1];
            grid[r][c] = false;
            DFS(grid, nr, nc);
        }
    }
    
    bool inBound(int nr, int nc) {
        return (nr < rows && nr >= 0 && nc < cols && nc >= 0);
    }
    
    /* for union find */
    int unionfind(vector<vector<bool>> &grid) {
        int cnt   = rows * cols;
        int total = cnt + 1;
        vector<int> sets(total);
        for (int i = 0; i < total; i++) {
            sets[i] = i;
        }
        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                int p = r * cols + c;
                if (grid[r][c] == 0) {
                    merge(sets, p, total - 1);
                    cnt--;
                } else {
                    for (int i = 0; i < 4; i++) {
                        int nr = r + neighbors[i][0];
                        int nc = c + neighbors[i][1];
                
                        if (!inBound(nr, nc)) {
                            continue;
                        }
                        
                        int q = nr * cols + nc;
                        if (grid[nr][nc] && !isConnected(sets, p, q)) {
                            merge(sets, q, p);
                            cnt--;
                        }
                    }
                }
            }
            
        return cnt;
    }
    
    int root(vector<int> &sets, int id) {
        while (id != sets[id]) {
            sets[id] = sets[sets[id]];
            id = sets[id];
        }
        return id;
    }
    
    bool isConnected(vector<int> &sets, int p, int q) {
        return root(sets, p) == root(sets, q);    
    }
    
    void merge(vector<int> &sets, int p ,int q) {
        int pid = root(sets, p);
        int qid = root(sets, q);
        if (pid != qid) {
            sets[pid] = qid; // Note: set the root unioned
        }
    }
};
