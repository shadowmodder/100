/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.
https://www.lintcode.com/problem/merge-sorted-array/description
*/

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        
        int index = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] < B[j]) {
                A[index--] = B[j--];
            } else {
                A[index--] = A[i--];
            }
        }
        
        while (i >= 0) A[index--] = A[i--];
        while (j >= 0) A[index--] = B[j--];
    }
};