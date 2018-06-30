/*
https://www.lintcode.com/problem/course-schedule/
*/
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
     /*
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj = buildGraph(numCourses, prerequisites);
       
        vector<bool> marked(numCourses, false);
        vector<bool> onStack(numCourses, false);;
        
        for (int i = 0; i < numCourses; i++) {
            if (!marked[i]) {
                if (!DFS(adj, i, marked, onStack))
                    return false;
            }
        }
        return true;
    }
    */
    
    /* Indegree method */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj = buildGraph(numCourses, prerequisites);
        vector<int> degree(numCourses, 0);
        queue<int> queue;

        for (const auto &elem : prerequisites) {
            degree[elem.second]++;
        }

        int count = numCourses;        
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                queue.push(i);
                count--;
            }
        }

        while (!queue.empty()) {
            int v = queue.front();
            queue.pop();
            
            for (auto w: adj[v]) {
                degree[w]--;
                if (degree[w] == 0) {
                    queue.push(w);
                    count--;
                }
            }
        }

        return count == 0;
    }    
    
private:
    bool DFS(vector<vector<int>> &adj, int v,
             vector<bool> &marked, vector<bool> &onStack) {

        onStack[v] = true;
        marked[v]  = true;
        for (auto w: adj[v]) {
            if (!marked[w]) {
                if(!DFS(adj, w, marked, onStack))
                    return false;
            } else if (onStack[w]) {
                return false;
            }
        }
        onStack[v] = false;
        return true;
    }
    
    vector<vector<int>> buildGraph (int numCourses, vector<pair<int, int>>&                             prerequisites) {
        vector<vector<int>> G (numCourses, vector<int>());
        
        for (const auto &elem : prerequisites) {
            G[elem.first].push_back(elem.second);
        }
        
        return G;
    }
};