/*
https://www.lintcode.com/problem/merge-k-sorted-arrays/description 

Merge k sorted arrays | Set 1
Given k sorted arrays of size n each, merge them and print the sorted output.

Example:

Input:
k = 3, n =  4
arr[][] = { {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11}} ;

Output: 0 1 2 3 4 5 6 7 8 9 10 11
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        vector<int> result;
        if (arrays.size() == 0) return result;
        
        auto cmp = [](Elem &lhs, Elem &rhs) {
            return lhs.val > rhs.val;
        };

        priority_queue<Elem, vector<Elem>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i].size() > 0)
                pq.push(Elem(arrays[i][0], i, 0));
        }

        while (!pq.empty()) {
            Elem e = pq.top();
            pq.pop();
            result.push_back(e.val);
            if (e.col + 1 < arrays[e.row].size()) {
                pq.push(Elem(arrays[e.row][e.col+1], e.row, e.col+1));
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
    Solution *s = new Solution();
    vector<vector<int>> arrays = { {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11},
            {-5, 9, 10, 20}} ;
    vector<int> result = s->mergekSortedArrays(arrays);
    for (auto e: result) cout << e << " " << endl;

    return 0;
}