/*
Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

https://www.lintcode.com/problem/ugly-number-ii/description
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        vector<int> results;
        results.push(1);
        
        int p1 = 0, p2 = 0, p3 = 0;
        
        while (results.size() < n) {
            results[p1] * 2 
        }
        int num = 1;
        
        while (n > 1) {
            num++;
            if (isUglyNumber(num)) n--;
        }
        
        return num;
    }
    
private:
    bool isUglyNumber(int num) {
        int last = INT_MAX;
        
        while (num < last) {
            last = num;
            if (num % 2 == 0) num /= 2;
            if (num % 3 == 0) num /= 3;
            if (num % 5 == 0) num /= 5;
        }
        
        return num == 1;
    }
};