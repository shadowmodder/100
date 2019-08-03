/*
https://www.lintcode.com/problem/topological-sorting/description
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> ret;
        unordered_map<int, bool> marked;
        unordered_map<int, bool> onStack;
        
        for (auto node :graph) {
            if (!marked[node->label]) {
                if (!DFS(graph, node, onStack, marked, ret)) {
                    ret.clear();
                    return ret;
                }
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    bool DFS(vector<DirectedGraphNode*>& graph, DirectedGraphNode* v,
             unordered_map<int, bool> &onStack,
             unordered_map<int, bool> &marked,
             vector<DirectedGraphNode*> &ret) {
                 
        marked [v->label]  = true;
        onStack[v->label]  = true;
        for (auto w: v->neighbors) {
            if (!marked[w->label]) {
                if (!DFS(graph, w, onStack, marked, ret)) return false;
            } else if(onStack[w->label]) {
                return false;
            }
        }
        onStack[v->label]  = false;
        ret.push_back(v);
        return true;
    }
};