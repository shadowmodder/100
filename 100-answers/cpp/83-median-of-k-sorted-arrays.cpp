/*
https://www.lintcode.com/en/problem/median-of-k-sorted-arrays/ 

time: O(klogn)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double findMedianSortedArray(vector<vector<int>> &nums) {
        double result;
        if (nums.size() == 0) return result;
        
        auto cmp = [](Elem &lhs, Elem &rhs) {
            return lhs.val > rhs.val;
        };

        int totalLen = 0;
        int cnt = 0;
        priority_queue<Elem, vector<Elem>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums.size(); i++) {
            totalLen += nums[i].size();
            if (nums[i].size() > 0)
                pq.push(Elem(nums[i][0], i, 0));
        }

        while (!pq.empty()) {
            Elem e = pq.top();
            pq.pop();
            cnt++;

            if (cnt == totalLen / 2) {
                result = e.val;
                if (totalLen % 2 != 0) break;
            } else if (cnt == totalLen / 2 + 1) {
                result = (result + e.val) / 2.0;
                break;
            }

            if (e.col + 1 < nums[e.row].size()) {
                pq.push(Elem(nums[e.row][e.col+1], e.row, e.col+1));
            }
        }

        return result;
    }

private:
    struct Elem{
        int val;
        int row;
        int col;
        Elem(int val, int row, int col):
            val(val), row(row), col(col) {};
    };
};

int main() {
    vector<vector<int>> nums = {{1, 4, 5, 6},
                                {2, 9},
                                {3, 8}};
    Solution *s = new Solution();

    cout << s->findMedianSortedArray(nums) << endl;

    return 0;
}