/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.12%)
 * Total Accepted:    263.4K
 * Total Submissions: 625K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        stack<pair<int, int>> stk; // first -> value, second ->index
        int ans = 0;

        for (int i = 0; i < height.size(); i++) {
            int h = height[i];
            if (stk.empty() || stk.top().first > h) {
                stk.push({h, i});
            } else {
                int bars = 0;
                int lastIndex = 0;
                while (!stk.empty() && stk.top().first < h) {
                    bars += stk.top().first;
                    lastIndex = stk.top().second;
                    stk.pop();
                }
                if (!stk.empty()) {
                    lastIndex = stk.top().second;
                } else {
                    bars -= height[lastIndex];
                }
                ans += (i - lastIndex - 1) * min(height[lastIndex], h) - bars;
                stk.push({h, i});
            }
        }

        return ans;
    }
};

