/*
 https://www.lintcode.com/en/problem/first-bad-version/
 The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.

*/


class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        int mid;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                hi = mid;
                if (lo == hi) break;
            } else {
                lo = mid + 1;
            }
        }
        return mid;
    }
};

