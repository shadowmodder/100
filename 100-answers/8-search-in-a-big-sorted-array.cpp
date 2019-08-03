/* Given a big sorted array with positive integers 
sorted by ascending order.
 The array is so big so that you can not get the 
 length of the whole array directly, and 
 you can only access the kth number by 
 ArrayReader.get(k) (or ArrayReader->get(k) for C++). 
 Find the first index of a target number. 
 Your algorithm should be in O(log k), 
 where k is the first index of the target number.
Return -1, if the number doesn’t exist in the array.
*/

#include <iostream>
#include <vector>

using namespace std;
int a[] = {1, 2, 4, 5, 7, 8, 10, 12, 13, 14, 15};

int getK(int k) {
    return a[k];
}

int computerRange(int t) {
    if (getK(0) == t) return 0;
    if (getK(0) > t) return -1;
    
    int i = 1;
    while (getK(i) < t) {
        i = 2 * i;
    }
    // so it is in i / 2 to i
    int lo = i / 2, hi = i;
    int targetIndex = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (getK(mid) > t) {
            hi = mid - 1;
        } else if (getK(mid) < t) {
            lo = mid + 1;
        } else {
            targetIndex = mid;
            if (lo == hi) break;
            hi = mid - 1;
        }
    }
    return targetIndex;
}


int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    cout << "note: can not get the bigger part" << endl;

    int ans = computerRange(t);
    cout << "target index of k is: " << ans << endl;

    return 0;
}