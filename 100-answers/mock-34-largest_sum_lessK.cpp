/*
Given an array, find a subarry which sum is largest but less than k.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findLargestLessThanK(vector<int> &nums, int k) {
        int presum = 0;
        int ans = INT_MIN;
        set<int> sets;

        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            auto it = sets.lower_bound(presum - k);
            if (it != sets.end()) {
                ans = max(ans, presum - *it);
            }
            if (presum <= k) ans = max(ans, presum);
            sets.insert(presum);
        }
        return ans;
    }
};

int main() {
    vector<int> nums {10, -1, 3, -2, 3};
    Solution *s = new Solution();
    cout << s->findLargestLessThanK(nums, -20) << endl;
    return 0;
}