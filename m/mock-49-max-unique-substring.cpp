#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getMaxUniqueSubstring(string & src) {
        if (src.length() <= 1) return src.length();

        int start = 0, end = 0;
        unordered_set<char> letters;
        int ans = 0;
        
        while (end < src.length()) {
            while (end < src.length() && letters.count(src.at(end)) == 0) {
                letters.insert(src.at(end));
                end++;
            }

            ans = max(ans, end - start);
            
            while (start <= end && src.at(start) != src.at(end)) {
                letters.erase(src.at(start));
                start++;
            }
            start++;
            end++;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    string src(argv[1]);
    cout << s.getMaxUniqueSubstring(src) << endl;
    return 0;
}