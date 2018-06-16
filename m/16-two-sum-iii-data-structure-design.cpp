/*
https://www.lintcode.com/problem/two-sum-iii-data-structure-design/description
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
*/
class TwoSum {
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        data.push_back(number);
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        int lo = 0, hi = data.size() - 1;
        sort(data.begin(), data.end());
        
        while (lo < hi) {
            int sum = data[lo] + data[hi];
            if      (sum > value) hi--;
            else if (sum < value) lo++;
            else    return true;
        }
        return false;
    }
private:
    vector<int> data;
};

