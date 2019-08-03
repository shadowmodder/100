/*
Given two Sparse Matrix A and B, return the result of AB.

https://www.lintcode.com/problem/sparse-matrix-multiplication/description
*/

class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
      
        vector<vector<int>> results;
        
        vector<unordered_map<int, int>> matrix(B[0].size(), unordered_map<int, int>());
        generateSparse(B, matrix);
        
        for (int r = 0; r < A.size(); r++) {
            vector<int> row;
            for (int c = 0; c < B[0].size(); c++) {
                int sum = 0;
                for (auto& p: matrix[c]) {
                    sum += A[r][p.first] * p.second;
                }
                row.push_back(sum);
            }
            results.push_back(row);
        }
        /*
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size()));
        bruteforce(A, B, ans);
        */
        return results;
    }
    
private:
    void generateSparse(vector<vector<int>> &A, vector<unordered_map<int, int>> & matrix) {
        for (int c = 0; c < A[0].size(); c++) {
            for (int r = 0; r < A.size(); r++) {
                if (A[r][c] != 0) {
                    matrix[c].insert(make_pair(r, A[r][c]));
                }
            }
        }
    }
    
    void bruteforce(vector<vector<int>> &A, vector<vector<int>> &B,
                    vector<vector<int>> &C) {
        int row   = A.size();
        int col   = B[0].size();
        int col_A = A[0].size();
        
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++) {
                for (int k = 0; k < col_A; k++) {
                    C[r][c] += A[r][k] * B[k][c];
                    if (A[r][k] == 0) continue;
                }        
        }
    }
};