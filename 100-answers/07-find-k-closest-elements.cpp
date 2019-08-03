/*
https://www.lintcode.com/problem/find-k-closest-elements/description
Given a target number, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

Example
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

Challenge
O(logn + k) time complexity.
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        vector<int> ret;
        if (A.size() < k) return ret;
        
        int lo = 0;
        int hi = A.size() - 1;
        int mid;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if      (target < A[mid]) hi = mid - 1;
            else if (target > A[mid]) lo = mid + 1;
            else                      break;
        }
        mid = A[mid] < target ? mid + 1 : mid;

        lo = mid - 1;
        hi = mid;
        while (ret.size() < k) {
            if (hi >= A.size() ||
                (lo >= 0 && (target - A[lo] <= A[hi] - target))) {
                ret.push_back(A[lo]);
                lo--;
            } else {
                ret.push_back(A[hi]);
                hi++;
            }
        }
      
        return ret;
    }
    
    
};
