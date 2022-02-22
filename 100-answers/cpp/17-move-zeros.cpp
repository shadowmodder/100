/*
https://www.lintcode.com/problem/move-zeroes/description


*/
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        for (int cur = 0, zeroIndex = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                exch(nums, cur, zeroIndex);
                zeroIndex++;
            }
        }
    }
private:
    void exch(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};