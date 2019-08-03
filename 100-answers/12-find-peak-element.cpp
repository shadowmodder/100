/*
https://www.lintcode.com/problem/find-peak-element/description
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].

*/

class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        int lo = 0 ;
        int hi = A.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid == 0) mid = hi;

            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid] < A[mid - 1]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};