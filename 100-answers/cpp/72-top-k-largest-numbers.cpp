/*
Given an integer array, find the top k largest numbers in it.
https://www.lintcode.com/problem/top-k-largest-numbers/description
*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
     /*
    vector<int> topk(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
            if (queue.size() > k) {
                queue.pop();
            }
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = queue.top();
            queue.pop();
        }
        
        return result;
    }
    */
    vector<int> topk(vector<int> &nums, int k) {
        
        int low = 0, high = nums.size() - 1;
        
        int switchIndex;
        while (low < high) {
            int val = nums[high];
            switchIndex = low;
            for (int i = low; i < high; i++) {
                if (nums[i] > val) {
                    swap(nums, i, switchIndex);
                    switchIndex++;
                }
            }
            swap(nums, switchIndex, high);
            
            if (switchIndex + 1 == k) {
                break;
            } else if (switchIndex + 1 < k) {
                low = switchIndex + 1;
            } else {
                high = switchIndex - 1;
            }
        }
        
        vector<int> result(nums.begin(), nums.begin() + k);
        sort(result.begin(), result.end(), greater<int>());
        
        return result;
    }
    
private:
    void swap(vector<int> &nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};