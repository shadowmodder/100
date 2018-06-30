/*
https://www.lintcode.com/en/problem/word-ladder/
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
*/
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        if (start.compare(end) == 0) return 0;
        if (start.length() != end.length()) return -1;
        
        int level = 1;
        unordered_map<string, bool> marked;
        queue<string> queue;
        queue.push(start);
        marked[start] = true;
       
        while (!queue.empty()) {
            int sz = queue.size();
            
            for (int i = 0; i < sz; i++) {
                string& s = queue.front();
                queue.pop();
                
                if (isEdge(end, s)) return ++level;
                //for (string m: getNextString(s, dict, marked)) {
                for (string m: dict) {
                    if (marked[m] || !isEdge(s, m)) continue;
                    queue.push(m);
                    marked[m] = true;
                }
            }
            level++;
        }
        
       return -1;
    }
    
private:
    vector<string> getNextString(string &s, unordered_set<string> &dict,
                                 unordered_map<string, bool> &marked) {
        vector<string> ret;
        
        for (int i = 0; i < s.length(); i++) {
            string n = s;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s.at(i)) {
                    n.at(i) = c;
                    if (dict.find(n) != dict.end() && !marked[n]) {
                        ret.push_back(n);
                    }
                }
            }
        }
        
        return ret;
    }
    bool isEdge(string& s, string& t) {
        if (s.length() != t.length()) return false;
        
        for (int i = 0, cnt = 0; i < s.length(); i++) {
            if (s.at(i) != t.at(i)) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }
};