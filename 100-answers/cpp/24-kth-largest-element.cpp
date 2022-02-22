/*
https://www.lintcode.com/problem/kth-largest-element/description
Find K-th largest element in an array.

Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Challenge
O(n) time, O(1) extra memory.
*/

/*
If the array is sorted, the kth largest must be in the position of
size - k. So using the partition way during qsort. But exit that when
find the target value.
Note: do not forget to exchange the pivot.
*/


class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        if (n > nums.size()) return -1;
        
        int index = partition(nums, 0, nums.size() - 1, n);
        return nums[index];
    }
    
private:
    int partition(vector<int>& nums, int start, int end, int k) {
        
        int lo = start, hi = end;
        while (lo <= end) {
            int pivot = lo;
            for (int i = lo; i < hi; i++) {
                if (nums[i] < nums[hi]) {
                    exch(nums, i, pivot);
                    pivot++;
                }
            }
            exch(nums, pivot, hi);
            
            if (pivot < nums.size() - k) {
                lo = pivot + 1;
            } else if (pivot > nums.size() - k) {
                hi = pivot - 1;
            } else {
                return pivot;
            }
        }
    }
    
    void exch(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};