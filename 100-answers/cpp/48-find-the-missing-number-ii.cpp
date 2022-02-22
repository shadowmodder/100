
/*
Giving a string with number from 1-n in random order, but miss 1 number.Find that number.
https://www.lintcode.com/problem/find-the-missing-number-ii/description
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        unordered_set<int> set;
        
        DFS(n, str, 0, set);
        
        for (int i = 1; i <= n; i++) {
            if (find(set.begin(), set.end(), i) == set.end()) {
                return i;
            }
        }
        
        return -1;
    }
 
private:
    bool DFS(int n, string &str, int start, unordered_set<int>& set) {
        if (start == str.length()) return true;
        
        int i = 1;
        while(start + i <= str.length()) {
            int val = stoi(str.substr(start, i));
            
            if (val > n) break;

            if (val == 0) return false;
            
            if (count(set.begin(), set.end(), val) == 0) {
                set.insert(val);
                if(DFS(n, str, start + i, set)) return true;
                set.erase(val);
            } 
            
            i++;
        }

        return false;
    }
};
