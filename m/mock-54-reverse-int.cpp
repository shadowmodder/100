#include <iostream>
#include <vector>

using namespace std;

int reverse(int num) {
    int sign = num > 0 ? 1: -1;
    long ret = 0;
    num = abs(num);
    while (num > 0) {
        ret = ret * 10 + num % 10;
        num = num / 10;
    }
    ret *= sign;
    if (ret < INT_MIN || ret > INT_MAX) {
        cout << "out of range: ";
        return -1;
    }
    return (int) ret;
}

int main() {
    vector<int> nums = {INT_MIN, -199, -100, 0, 100, 199, INT_MAX};

    for (auto num: nums) {
        cout << reverse(num) << endl;
    }
    return 0;
}