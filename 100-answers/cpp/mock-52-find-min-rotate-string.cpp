#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string findMinString(string &str) {
        int index = 0;
        for (int i = 1; i < str.length(); i++) {
            if (less(str, i, index)) {
                index = i;
            }
        }
        return str.substr(index) + str.substr(0, index);
    }
private:
    bool less(string& str, int p0, int p1) {
        int len = str.length();
        while (str.at(p0 % len) == str.at(p1 % len)) {
            p0++;
            p1++;
        }
        return str.at(p0 % len) < str.at(p1 % len);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    if (argc < 2) return -1;
    string str(argv[1]);
    cout << s.findMinString(str) << endl;
    return 0;
}