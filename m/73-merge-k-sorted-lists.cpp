/*

https://www.lintcode.com/problem/merge-k-sorted-lists/description
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * ret = NULL;
        
        auto cmp = [](ListNode * lhs, ListNode *rhs) {
             return lhs->val > rhs->val;
        };
        
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> queue(cmp);
        
        for (auto elem: lists) {
            if (elem != NULL) queue.push(elem);
        }
        
        if (queue.size() == 0) return ret;
        
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        
        while (!queue.empty()) {
            ListNode *s = queue.top();
            queue.pop();
            
            cur->next = s;
            cur = cur->next;
            
            if (s->next != NULL) {
                queue.push(s->next);
            }
        }
        
        ret = dummy->next;
        delete dummy;
        
        return ret;
    }
    
private:
    struct my_cmp {
        bool operator()(ListNode * lhs, ListNode *rhs) {
             return lhs->val > rhs->val;
        };
    };
};


