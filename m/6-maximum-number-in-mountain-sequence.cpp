/*
Given a mountain sequence of n integers which increase firstly and
 then decrease, find the mountain top.

Example
Given nums = [1, 2, 4, 8, 6, 3] return 8
Given nums = [10, 9, 8, 7], return 10

This question can be solved using binary search. When mid is bigger than start, there is two situation:

1. The number is increasing, and the mid is located before top.

2. The number is decreasing, the mid is located after top.

When mid is smaller than start, there is only one situation, top is in the left half.
*/
#include <iostream>
#include <vector>
using namespace std;

int mountainSequence(int nums[], int len) {
    int lo = 0;
    int hi = len - 1;

    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid - 1]) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return (nums[lo] < nums[hi]) ? nums[hi] : nums[lo];
}

int main(int argc, char *argv[]) {
    int a[] = { 8, 16};
    vector<int> A(a, a + sizeof(a));
    int ans = mountainSequence(a, sizeof(a) / sizeof(int));
    cout << "Top is: " << ans << endl;

    return 0;
}