/*
 https://www.lintcode.com/problem/partition-array/
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.

Challenge
Can you partition the array in-place and in O(n)?

*/

/*
After exchange the value, need change two pointers together.
if (lo < hi) {
    exch(nums, lo, hi);
    lo++;
    hi--;
}
*/

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
     /*
    int partitionArray(vector<int> &nums, int k) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                exch(nums, i, index);
                index++;
            }
        }
        return index;
    }*/

    int partitionArray(vector<int> &nums, int k) {
        if (nums.size() == 0) return 0;
        
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            while (lo <= hi && nums[lo] < k) lo++;
            while (lo <= hi && nums[hi] >= k) hi--;
            
            if (lo < hi) {
                exch(nums, lo, hi);
                lo++;
                hi--;
            }
        }
        return lo;
    }
    
private:
    void exch(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};