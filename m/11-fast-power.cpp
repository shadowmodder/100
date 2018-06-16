/*
https://www.lintcode.com/en/problem/fast-power/
Calculate the an % b where a, b and n are all 32bit integers.

Example
For 231 % 3 = 2
For 1001000 % 1000 = 0
Challenge
O(logn)
*/

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if (n == 0) return 1 % b;
        if (n == 1) return a % b;
        
        long long t = fastPower(a, b, n/2);
        t = ((t % b) * (t % b)) % b;
        if (n % 2 != 0) {
            t = t * (a % b);
        }
        return (int) (t % b);
    }
};

