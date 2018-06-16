/*
https://www.lintcode.com/problem/search-in-rotated-sorted-array/description

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.

*/

class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        /*
        if lo < target < hi 
            binary search
        
        else
           if mid == target
              targetIndex = mid
              break;
           if lo < hi 
              if target < mid
                 hi = mid - 1 
              else
                 lo = mid + 1
           if mid > lo and mid > hi
               if target > mid || target < lo
                  lo = mid + 1 
                else 
                  hi = mid - 1 
            else if mid < lo and mid < hi
               if target < mid || target > hi
                  hi = mid - 1
                else
                  lo = mid + 1
        
        */
        
        int targetIndex = -1;
        int lo = 0, hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == target) {
                targetIndex = mid;
                break;
            }
            
            if (A[lo] < A[hi]) {
                if (A[mid] < target) lo = mid + 1;
                else                 hi = mid - 1;
            } else if (A[mid] > A[lo] && A[mid] > A[hi]) {
                if (target > A[mid] || target < A[lo])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            } else {
                if (target < A[mid] || target > A[hi])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        
        return targetIndex;
    }
};