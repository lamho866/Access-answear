/*

It needs one stack to save the stack element
It needs another to save the current miuimum element the stack , which use for speed up

Example :
stk : 5 2 2 3
minstk : 2 2

push(1)

stk : 5 2 2 3 1
minstk : 2 2 1

pop()

stk : 5 2 2 3
minstk : 2 2

pop()

stk : 5 2 2
minstk : 2 2

pop() <=  if we don't push the same minimum element, it will happens error

stk : 5 2
minstk : 2 

*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push_back(x);
         //case 1: if minStk doesn't have any element, then push it
         //case 2: if x is minimum element or equal push it in minStk
        if(minStk.empty() || x <= minStk.back())
            minStk.push_back(x);
    }
    
    void pop() {
        //update the minimum element
        if(stk.back() == minStk.back())
             minStk.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return  minStk.back();
    }
    
private:
    vector<int> stk; // save the stack value
    vector<int> minStk;// save the current minimum value on the stack
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
