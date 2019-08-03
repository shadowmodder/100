/*
https://www.lintcode.com/problem/implement-stack-by-two-queues/description
implement stack by two queue
*/

#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }

        int v = top();
        queue1.pop();
        
        return v;
    }
    
    /** Get the top element. */
    int top() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }

        if (queue1.empty()) {
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }
        
        while (queue1.size() > 1) {
          queue2.push(queue1.front());
          queue1.pop();
        }

        return queue1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
    
private:
    queue<int> queue1; // pop
    queue<int> queue2; // push
};


int main() {
    MyStack *s = new MyStack();
    s->push(1);
    s->push(2);
    cout << s->top() << endl;
    s->push(3);
    s->push(4);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    s->top();
    return 0;
}