/*
Find the last position of a target number in a sorted array. 
Return -1 if target does not exist.
Example, given [1, 2, 2, 4, 5, 5]. For target = 2, return 2.
*/

#include <iostream>
#include <vector>

using namespace std;


    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int lastPosition(vector<int>& A, int target) {
        // 1 2 2  3 3 4
        int lo = 0, hi = A.size() - 1;
        int targetIndex = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == target) {
                targetIndex = mid;
                //if (lo == hi) break;
                lo = mid + 1;
                //hi = mid - 1;
            } else if (A[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return targetIndex;
    }

int main(int argc, char *argv[]) {
    int a[] = {1, 2, 2, 3, 3, 3, 4};
    vector<int> A(a, a + sizeof(a));
    int t = 0;
    cin >> t;
    int ans = lastPosition(A, t);
    cout << t << " pos is: " << ans << endl;

    return 0;
}