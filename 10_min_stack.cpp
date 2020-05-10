/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> min;
    stack<int> minStack;

    MinStack() {

    }

    void push(int x) {
        if(min.empty() || x <= min.back())
            min.push_back(x);
        minStack.push(x);
    }

    void pop() {
        if(!minStack.empty()) {
            int popped = minStack.top();
            if(popped == min.back())
                min.pop_back();
            minStack.pop();
        }
    }

    int top() {
        if(minStack.empty())
            return -1;
        int stack_top = minStack.top();
        return stack_top;
    }

    int getMin() {
        if(min.empty())
            return -1;
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
