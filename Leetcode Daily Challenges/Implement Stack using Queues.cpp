class MyStack {
public:
    vector<int> s;
    MyStack() {
        
    }
    
    void push(int x) {
        s.push_back(x);
    }
    
    int pop() {
        int v = s.back();
        s.pop_back();
        return v;
    }
    
    int top() {
        return s.back();
    }
    
    bool empty() {
        return s.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
