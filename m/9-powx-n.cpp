/*
https://www.lintcode.com/problem/powx-n/
implement pow(x, n).

*/
class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (abs(x) < 0.0001) return 0;
        
        double t = myPow(x, n/2);
        
        return (abs(n % 2) == 1) ? t * t * (n < 0 ? 1/x : x) : t * t;
    }
};
