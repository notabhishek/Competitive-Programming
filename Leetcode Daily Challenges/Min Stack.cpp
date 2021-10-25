class MinStack {
public:
    stack<long long> s;
    int mn;
    MinStack() {
        mn = 0;
    }
    
    void push(int val) {
        if(s.empty()) {
            mn = val;
            s.push(val);
        } else {
            if(val >= mn) {
                s.push(val);
            } else {
                s.push(2ll*val - mn);
                mn = val;
            }
        }
    }
    
    void pop() {
        if(s.top() >= mn) {
            s.pop();
        } else{
            mn = 2ll*mn - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top() >= mn) {
            return s.top();
        } 
        return mn;
    }
    
    int getMin() {
        return mn;
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
