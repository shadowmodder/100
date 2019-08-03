/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
3, 4, 1, 2, 0 -> 3 4 2 0 1
https://leetcode.com/problems/next-permutation/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, j = nums.size() - 1;

        /* find first decrease number */
        while (i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }

        /* if did not find one means it is the biggest number */
        if (i == 0) {
             reverse(nums.begin(), nums.end());
             return;
        }

        while (j > i && nums[j] <= nums[i - 1]) {
            j--;
        }

        swap(nums[i - 1], nums[j]);

        sort(nums.begin() + i, nums.end());
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> numsArray = {{1, 2, 1}, {3, 2, 1}, {1, 1, 5}, {3, 4, 1, 2, 0}};
    for (auto &nums: numsArray) {
        s->nextPermutation(nums);
        for (int item: nums) {
            cout << item << " ";
        }
        cout << endl;
    }
}

