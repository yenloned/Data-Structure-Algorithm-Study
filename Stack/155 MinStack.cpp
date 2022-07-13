/*
https://leetcode.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

class MinStack {
    //Another Stack Solution, push(), pop() and top() operations in stack will be Time Complexity of O(1)
private:
    stack<int> stk1;    //the normal stack
    stack<int> stk2;    //the stack used for return the minimum element
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk1.push(val);
        if(stk2.empty() || val <= stk2.top()){  //make sure the top element of stk2 will be the minimum element
            stk2.push(val);
        }
    }
    
    void pop() {
        if(stk1.top() == stk2.top()){   //if the popped element is not the minimum, keep it in stk2
            stk2.pop();
        }
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};