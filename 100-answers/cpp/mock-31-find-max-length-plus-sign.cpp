/*
Given an array with * and ., find a longest length of a cross. The length
of cross means the minimal and each edge.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findBiggestPlus(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> left(row, vector<int>(col, 0));
        vector<vector<int>> right(row, vector<int>(col, 0));
        vector<vector<int>> up(row, vector<int>(col, 0));
        vector<vector<int>> down(row, vector<int>(col, 0));
        
        // left and right
        for (int r = 0; r < row; r++) {
            left[r][0] = matrix[r][0];
            for (int c = 1; c < col; c++) {
                if (matrix[r][c] == 1)
                    left[r][c] = left[r][c - 1] + 1;
            }
            
            right[r][col - 1] = matrix[r][col - 1];
            for (int c = col - 2; c >= 0; c--) {
                if (matrix[r][c] == 1)
                    right[r][c] = right[r][c + 1] + 1;
            }
        }

        // up and down
        for (int c = 0; c < col; c++) {
            up[0][c] = matrix[0][c];
            for (int r = 1; r < row; r++) {
                if (matrix[r][c] == 1)
                    up[r][c] = up[r-1][c] + 1;
            }

            down[row-1][c] = matrix[row-1][c];
            for (int r = row - 2; r >= 0; r--) {
                if (matrix[r][c] == 1)
                    down[r][c] = down[r+1][c] + 1;
            }
        }

        // find min len and save max
        int maxlen = 0;
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++) {
               int len =  min(min(left[r][c], right[r][c]), min(up[r][c], down[r][c]));
               if (maxlen < len) {
                   maxlen = len;
                   cout << r << " " << c << endl;
               } 
            }
        
        return maxlen - 1; // remove the center
    }
};

int main()
{
	vector<vector<int>> m {
		{0, 0, 1, 0, 0, 1, 0}, 
		{1, 0, 1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};
    Solution *s = new Solution();
	cout << "max: " << s->findBiggestPlus(m) << endl;
}