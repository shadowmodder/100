/*
https://www.lintcode.com/problem/remove-duplicate-numbers-in-array/
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int index = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 2) {
                if (nums[i] != nums[index]) {
                    nums[++index] = nums[i];
                    cnt = 1;
                }
            } else {
                if (nums[i] == nums[index]) {
                    cnt++;
                }
                nums[++index] = nums[i];
            }         
        }
        return index + 1;
    }

};
