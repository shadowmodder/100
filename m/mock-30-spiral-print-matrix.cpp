/*
1  2  3  4
5  6  7  8
9 10 11 12
Print: 1 2 3 4 8 12 11 10 9 5 6 7
*/

/*
Using a array to remember which element is visited. It takes O(mn) space.

Another way to to print the matrix layer by layer. But how to define the layer?
Using r1 r2 and c1, c2 to keep record the bounder of each layer. 
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Solution {
public:
    vector<T> printSpiralMatrix(vector<vector<T>> &nums) {
        vector<T> result;
        if (nums.size() == 0 || nums[0].size() == 0)
            return result;
        
        int r1 = 0, r2 = nums.size() - 1;
        int c1 = 0, c2 = nums[0].size() - 1;

        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) 
                result.push_back(nums[r1][c]); 

            for (int r = r1 + 1; r <= r2; r++) 
                result.push_back(nums[r][c2]);

            if (r1 < r2 && c1 < c2) {
                for (int c = c2 -1; c >= c1; c--) 
                    result.push_back(nums[r2][c]);
                for (int r = r2 - 1; r > r1; r--)
                    result.push_back(nums[r][c1]);
            }
            r1++; r2--;
            c1++; c2--;
        }

        return result;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9,10,11,12}
            };
    
    Solution<int> *s = new Solution<int>();
    auto result = s->printSpiralMatrix(nums);
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}