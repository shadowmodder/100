/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
https://www.lintcode.com/problem/jump-game/
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        vector<bool> isPath(A.size(), false);
        
        isPath[A.size() - 1] = true;
        
        for (int i = A.size() - 1; i >= 0; i--) {
            for (int step = 1; step <= A[i] && i + step < A.size(); step++) {
                if (isPath[i + step]) isPath[i] = true;
            }
        }
        
        return isPath[0];
    }
};