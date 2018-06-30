/*
https://www.lintcode.com/problem/course-schedule-ii/
*/
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);
      
        vector<bool> marked(numCourses, false);
        vector<int>  result;
        vector<bool> onStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!marked[i]) {
                if (!DFS(g, i, marked, onStack, result)) {
                    result.clear();
                    return result;
                }
            }
        }
        
        return result;
    }
    
private:

    bool DFS(vector<vector<int>> &g, int v, 
             vector<bool> &marked,
             vector<bool> &onStack,
             vector<int>  &result) {
                 
        onStack[v] = true;
        marked[v]  = true;
        for (auto w: g[v]) {
            if (!marked[w]) {
                if (!DFS(g, w, marked, onStack, result)) return false;
            } else if (onStack[w]) {
                return false;
            }
        }
        onStack[v] = false;
        result.push_back(v);
        
        return true;
    }
    
    vector<vector<int>> buildGraph(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto elem: prerequisites) {
            g[elem.first].push_back(elem.second);
        }
        return g;
    }
};