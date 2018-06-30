/*
https://www.lintcode.com/problem/sequence-reconstruction/
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.
*/
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        unordered_map<int, int> indegree;
        unordered_map<int, unordered_set<int>> adj;
        for (int i = 0; i < seqs.size(); i++) {
            for (int j = 0; j < seqs[i].size(); j++) {
                int v = seqs[i][j];
                unordered_set<int>& neighbor = adj[v];
                for (int k = j + 1; k < seqs[k].size(); k++) {
                    pair<unordered_set<int>::iterator, bool> ret = neighbor.insert(k);
                    if (ret.second) indegree[k]++;
                }
            }
        }
        
        
        vector<int>  unique(adj.size(), -1);
        while (true && unique.size() < adj.size()) {
            int cnt = 0;
            int index;
            
            for (int i = 0; i < indegree.size(); i++) {
                if (indegree[i] == 0) {
                    cnt++;
                    index = i;
                }
            }
            
            if  (cnt > 1) return false;
            
            for (auto it : adj[index]) 
                indegree[it]--;
                
            indegree[index]--;
            unique.push_back(index);
        }
        
        for (int i = 0; i < org.size(); i++) {
            if (unique[i] != org[i]) return false;
        }
        
        return true;
    }
};
