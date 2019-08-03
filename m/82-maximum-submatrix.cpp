/*
Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.

https://www.lintcode.com/en/problem/maximum-submatrix/
*/


class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
     
     /*
     1. generate prefix column sum
     2. compress matrix to one row array
     3. use one dimension array to calculate max sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int maxsum = INT_MIN;
        
        vector<vector<int>> prefixColSum(matrix.size(),
                                         vector<int>(matrix[0].size(), 0));
        genPrefixColSum(matrix, prefixColSum);

        for (int up = 0; up < matrix.size(); up++) {
            for (int dn = up; dn < matrix.size(); dn++) {
                vector<int> compressedArr(prefixColSum[dn].begin(), 
                                          prefixColSum[dn].end());
                                          
                for (int c = 0; dn != up && c < matrix[0].size(); c++) {
                    compressedArr[c] -= prefixColSum[up][c]; 
                }
                
                maxsum = max(maxsum, findMaxArray(compressedArr));
            }
        }
        
        return maxsum;
    }
    
private:
    void genPrefixColSum(vector<vector<int>> &matrix,
                         vector<vector<int>> &prefixColSum) {
        for (int r = 0; r < matrix.size(); r++)
            for (int c = 0; c < matrix[0].size(); c++) {
                prefixColSum[r][c] = matrix[r][c];
                if (r > 0) {
                    prefixColSum[r][c] += prefixColSum[r-1][c];
                }
            }
    }
    
    int findMaxArray(vector<int> &arr) {
        int maxsum = INT_MIN;
        for (int i = 0, sum = 0; i < arr.size(); i++) {
            sum += arr[i];
            sum = max(sum, arr[i]);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};