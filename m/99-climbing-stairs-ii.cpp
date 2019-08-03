/*
https://www.lintcode.com/en/problem/climbing-stairs-ii/

Climbing Stairs II
Description
A child is running up a staircase with n steps, and
can hop either 1 step, 2 steps, or 3 steps at a time.
Implement a method to count how many possible ways the
child can run up the stairs.

Example
n=3
1+1+1=2+1=1+2=3=3
return 4
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs2(int n) {
        if (n <= 1) return 1;
        
        vector<int> steps(n+1, 0);
        steps[0] = 1;
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i <= n; i++) {
            steps[i] = steps[i - 1] + steps[i - 2] + steps[i - 3];
        }

        return steps[n];
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->climbStairs2(5) << endl;
}