/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int elem = obj->top();
 * int min_elem = obj->getMin();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int mn;
    MinStack() {
    }
    
    void push(int x) {
        if(st.empty()) {
        	mn = x;
            st.push(x);
            return;
        }
    	if(x >= mn) {
        	st.push(x);
        } else {
        	st.push(2*x - mn);
            mn = x;
        }
    }
    
    void pop() {
        if(mn >= st.top()) {
        	st.pop();
        } else {
        	mn = 2*mn - st.top();
            st.pop();
        }
    }
    
    int top() {
       if(mn > st.top()) {
        	return mn;
        } else {
        	return st.top();
        }
    }
    
    int getMin() {
       return mn;
    }
};
