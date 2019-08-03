/*
Given a string, find all permutations of it without duplicates.
Example
Given "abb", return ["abb", "bab", "bba"].
Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].

NOT verified.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> permuteUnique(string &str) {
        vector<string>  results;
        if (str.length() <= 1) {
            results.push_back(str);
            return results;
        }

        sort(str.begin(), str.end());
        string result = "";
        vector<bool> visisted(str.length(), false);
        getPermutation(str, visisted, result, results);

        return results;
    }

private:
    void getPermutation(string &str,
                        vector<bool> &visisted,
                        string &result,
                        vector<string> &results) {
        if (result.length() == str.length()) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < str.size(); i++) {
            if (visisted[i]) continue;
            if (i > 0 && str.at(i) == str.at(i - 1) && !visisted[i-1]) continue;

            result += str.at(i);
            visisted[i] = true;
            getPermutation(str, visisted, result, results);
            result.pop_back();
            visisted[i] = false;
        }

    }
};

int main() {
    string str = "aabb";
    Solution * s = new Solution();
    vector<string> ans = s->permuteUnique(str);
    for (auto & e: ans) {
        cout << e << " ";
    }
    cout << endl;
}