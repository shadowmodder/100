/*
src = "tabcgcde", target = "abc"
ans is 3, index is [1, 3]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLeastSubstring(string &source, string &target) {
        if (source.length() < target.length()) return -1;

        unordered_map<char, int> map;
        for (auto letter: target) {
            map[letter]++;
        }
        int start = 0, end = 0, unMatchCnt = map.size();
        int ans = INT_MAX;

        while (end < source.length()) {
            while (end < source.length() && unMatchCnt != 0) {
                char ch = source.at(end);
                if (map.count(ch) > 0) {
                    map[ch]--;
                    if (map[ch] == 0) unMatchCnt--;
                }
                end++;
            }
            if (unMatchCnt != 0) break;

            while (start <= end && unMatchCnt == 0) {
                char ch = source.at(start);
                if (map.count(ch) > 0) {
                    map[ch]++;
                    if (map[ch] > 0) unMatchCnt++;
                }
                start++;
            }
            
            ans = min(ans, end - start + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    string src(argv[1]);
    string target(argv[2]);
    cout << s.findLeastSubstring(src, target) << endl;
    return 0;
}