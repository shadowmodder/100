/*
https://www.lintcode.com/problem/implement-queue-by-two-stacks/description
*/
class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        pushStack.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        
        int val = top();
        popStack.pop();
        
        return val;
    }

    /*
     * @return: An integer
     */
    int top() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        
        if (popStack.empty()) return -1;
        
        return popStack.top();
    }
private:
    stack<int> pushStack;
    stack<int> popStack;
};