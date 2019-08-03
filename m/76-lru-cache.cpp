/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

https://www.lintcode.com/problem/lru-cache/description
*/

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->dummy = new Node(0, 0);
        this->tail  = dummy;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (map.count(key) == 0) return -1;
        
        Node * pre = map[key];

        // move it to back
        Node * cur = pre->next;
        if (cur != tail) {
            pre->next = cur->next;
            map[cur->next->key] = pre;
            
            tail->next = cur;
            map[cur->key] = tail;
            tail = cur;
        }

        return tail->val;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (get(key) != -1) {
            tail->val = value;
            return;
        }
        
        if (size == capacity) {
            Node *first = dummy->next;
            map.erase(first->key);
            dummy->next = first->next;
            if (dummy->next != NULL)
                map[dummy->next->key] = dummy;
            else
                tail = dummy;
            delete first;
            size--;
        }
        
        Node * n = new Node(key, value);
        map[key] = tail;
        tail->next = n;
        tail = n;
        size++;
    }
    
private:
    struct Node {
        int key;
        int val;
        Node * next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
        }
    };
    
    unordered_map<int, Node*> map;
    Node *dummy;
    Node *tail;
    int capacity;
    int size;
    
    void moveNextNodeToFirst(Node *pre) {
        if (pre->next != NULL) {
            pre->next = pre->next->next;
        }
    }
};