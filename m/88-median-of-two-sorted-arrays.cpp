/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

https://www.lintcode.com/problem/median-of-two-sorted-arrays/description
*/

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
     /*
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        if (A.size() == 0) return findMiedian(B);
        if (B.size() == 0) return findMiedian(A);
        
        double ret;
        int lo = 0, hi = A.size();
        int median = 0;
        
        int x, y;
        while (lo <= hi) {
            x = lo + (hi - lo) / 2;
            y = (A.size() + B.size() + 1) / 2 - x;
            
            if (x > 0 && y < B.size() && A[x - 1] > B[y]) {
                hi = x - 1;
            } else if (x < A.size() && y > 0 && A[x] < B[y - 1]) {
                lo = x + 1;
            } else {
                if (x == 0) {
                    median = B[y - 1];
                } else if (y == 0) {
                    median = A[x - 1];
                } else {
                    median = max(A[x - 1], B[y - 1]);
                }
                
                break;
            }
        }
        
        
        if ((A.size() + B.size()) % 2 == 1)  return (double) median;
        
        
        if (x == A.size())  return (median + B[y]) / 2.0;
        if (y == B.size())  return (median + A[x]) / 2.0;
        
        return (median + min(A[x], B[y])) / 2.0;;
    }
    
private:
    double findMiedian(vector<int> &B) {
        double ret;
        int mid = (B.size() - 1) / 2;
        if (B.size() % 2 == 0) {
            ret = (B[mid] + B[mid + 1]) / 2.0;
        } else {
            ret = B[mid];
        }
        return ret;
    }
};

*/

/* ref: https://www.geeksforgeeks.org/median-two-sorted-arrays-different-sizes-ologminn-m/ */

    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int mid = (A.size() + B.size() + 1) / 2;
        if ((A.size() + B.size()) % 2 != 0) {
            return findKth(A, 0, B, 0, mid);
        } else {
            return (findKth(A, 0, B, 0, mid + 1) + findKth(A, 0, B, 0, mid)) / 2.0;
        }
    }

    int findKth(vector<int> &A, int startA, vector<int> &B, int startB, int k) {
        int remainSizeA = A.size() - startA;
        int remainSizeB = B.size() - startB;
        
        if (remainSizeA > remainSizeB) {
            return findKth(B, startB, A, startA, k);
        } else if (remainSizeA == 0) {
            return B[startB + k - 1];
        }
        
        if (k == 1) return min(A[startA], B[startB]);
        
        int offset = min(k/2, remainSizeA);
        int x = startA + offset;
        int y = startB + k - offset;
        if (A[x - 1] < B[y - 1]) {
            return findKth(A, x, B, startB, k - offset);
        } else {
            return findKth(A, startA, B, y, offset);
        }
    }
};