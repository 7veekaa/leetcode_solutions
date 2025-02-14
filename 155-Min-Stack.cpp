#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stackk;        
    stack<int> minStack; 

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stackk.push(val); 
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (stackk.top() == minStack.top()) {
            minStack.pop();
        }
        stackk.pop();
    }
    
    int top() {
        return stackk.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */