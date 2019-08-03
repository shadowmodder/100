#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostForPostage(vector<int> & stamps, int postage) {
        if (postage == 0) return 0;

        int min = INT_MAX, max = 0;
        for (int i = 0; i < stamps.size(); i++) {
            if (stamps[i] < min) min = stamps[i];
            if (stamps[i] > max) max = stamps[i];
        }

        if (min == 1) return postage;

        vector<bool> dp(postage + max + 1, false);
        dp[0] = true;
        for (int i = 0; i < postage; i++) {
            if (dp[i]) {
                for (auto c: stamps) {
                    dp[i+c] = true;
                }
            }
        }
        
        for (int i = postage; i < dp.size(); i++) {
            if (dp[i]) return i;
        }

        return -1;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> stamps {3, 11};
    for (int target = 21; target <= 21; target++) {
        if (s->minCostForPostage(stamps, target) != target)
        cout << "("<< target << ", "<< s->minCostForPostage(stamps, target) <<  ")  ";
    }
    delete s;
    return 0;
}