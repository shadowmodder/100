/*
https://www.lintcode.com/problem/clone-graph/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        UndirectedGraphNode* ans = nullptr;
        if (node == nullptr) return ans;
        
        unordered_map<int, bool> visited;
        unordered_map<int, UndirectedGraphNode*> targetMap;
        
        queue<UndirectedGraphNode *> sQueue;
        sQueue.push(node);
        visited[node->label] = true;
        queue<UndirectedGraphNode *> tQueue;
        ans = new UndirectedGraphNode(node->label);
        tQueue.push(ans);
        targetMap[ans->label] = ans;
        
        while (!sQueue.empty()) {
            UndirectedGraphNode * s = sQueue.front();
            sQueue.pop();
            UndirectedGraphNode * t = tQueue.front();
            tQueue.pop();
            
            cout << s->neighbors.size() << endl;
            for (int i = 0; i < s->neighbors.size(); i++) {
                UndirectedGraphNode* sNode  = (s->neighbors)[i];
                if (!visited[sNode->label]) {
                    UndirectedGraphNode * tNode = new UndirectedGraphNode(sNode->label);
                    (t->neighbors).push_back(tNode);
                    targetMap[tNode->label] = tNode;
                    sQueue.push(sNode);
                    tQueue.push(tNode);
                    visited[sNode->label] = true;
                } else {
                    (t->neighbors).push_back(targetMap[sNode->label]);
                }
            }
        }
        return ans;
    }
};