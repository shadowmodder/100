#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(const string &src, const string &target) {
        if (src.length() < target.length()) return false;

        int t = 0;
        for (int s = 0; s < src.length() &&
                               t < target.length(); s++) {
            if (src.at(s) == target.at(t)) {
                t++;
            } 
        }

        if (t == target.length()) return true;
        return false;
/*
        int s = 0, t = 0;
        while (t < target.length()) {
            while (s < src.length() && src.at(s) != target.at(t)) {
                s++;
            }
            if (s == src.length()) return false;
            t++;
        }
        return true;*/
    }
};

int main()
{
    Solution s;

    cout << s.isSubsequence("hello word", "lwo") << endl;

    return 0;
}