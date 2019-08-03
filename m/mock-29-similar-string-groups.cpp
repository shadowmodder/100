/*
https://leetcode.com/articles/similar-string-groups/
*/

#include <iostream>
#include <vector>

using namespace std;

class UF {
public:
    UF(int sz) {
        root.resize(sz);
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
        cnt = sz;
    }

    void makeUnion(int p, int q) {
        int rp = find(p);
        int rq = find(q);
        if (rp != rq) {
            root[rp] = rq;
            cnt--;
        }
    }

    int find(int p) {
        while (p != root[p]) {
            root[p] = root[root[p]];
            p = root[p];
        }
        return p;
    }

    int getSets() {
        return cnt;
    }
private:
    vector<int> root;
    int cnt = 0;
};

class Solution {
public:
    int numSimilarGroups(vector<string> &A) {
        if (A.size() <= 1) return A.size();

        UF uf(A.size());

        for (int i = 0; i < A.size(); i++)
            for (int j = i + 1; j < A.size(); j++) {
                if (isSimilar(A[i], A[j])) {
                    uf.makeUnion(i, j);
                }
            }

        return uf.getSets();
    }
private:
    bool isSimilar(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        int cnt = 0, i = 0;
        while (i <= s1.size() && cnt <= 2) {
            if (s1[i] != s2[i]) cnt++;
            i++;
        }
        return cnt <= 2;
    }
};

int main() {
    vector<string> strs = {
            "tars","rats","arts","star"};
    
    Solution *s = new Solution();
    int result = s->numSimilarGroups(strs);
    
    cout << result << endl;

    return 0;
}