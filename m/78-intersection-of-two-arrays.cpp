/*
Given two arrays, write a function to compute their intersection.
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
https://www.lintcode.com/problem/intersection-of-two-arrays/description
*/

class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        vector<int> results;
        
        if (nums1.size() == 0 || nums2.size() == 0) return results;
        
        //sortAndMerge(nums1, nums2, results);
        
        searchAndCheck(nums1, nums2, results);
        
        return results;
    }
    
private:
    void searchAndCheck(vector<int> &nums1, vector<int> &nums2,
                      vector<int> &results) {
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end());
        
        for (int i = 0; i < nums2.size(); i++) {
            if (i > 0 && nums2[i] == nums2[i - 1]) continue;
            
            if (binarySearch(nums1, nums2[i])) {
                results.push_back(nums2[i]);
            }
        }
    }
    
    void sortAndMerge(vector<int> &nums1, vector<int> &nums2,
                      vector<int> &results) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (results.size() == 0 || results.back() != nums1[i]) {
                    results.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) { 
                i++;
            } else {
                j++;
            }
        }
    }
    
    bool binarySearch(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if      (target < nums[mid]) hi = mid - 1;
            else if (target > nums[mid]) lo = mid + 1;
            else                         return true;
        }
        
        return false;
    }
};