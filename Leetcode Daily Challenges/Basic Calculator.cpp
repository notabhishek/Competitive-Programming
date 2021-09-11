class Solution {
public:
    int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        if(op == '^') return 3;
        return 0;
    }
    string Postfix(string s) {
        string postfix  = "";
        stack<char> st;
        for(auto &i : s) {
            if(isalnum(i)) postfix += i;
            else if(i == ' ') continue;
            else if(i == '(') st.push(i);
            else if(i == ')') {
                while(st.top() != '(') {
                    postfix += st.top(); st.pop();
                }
                st.pop();
            } else {
                int curp = precedence(i);
                while(!st.empty() && precedence(st.top()) >= curp) {
                    postfix += st.top(); st.pop();
                }
                postfix += ' ';
                st.push(i);
            }
         }
        while(!st.empty()) {
            postfix += st.top(); st.pop();
        }
        return postfix;
    }
    
    bool isop(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    int operate(int a, int b, char op) {
        switch(op) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            case '^' : return pow(a,  b);
        }
        return 0;
    }
    int evalPostfix(string postfix) {
        int i = 0, n = postfix.length();
        stack<int> s;
        while(i < n) {
            if(postfix[i] == ' ') {++i; continue;}
            if(isop(postfix[i])) {
                int a = s.top(); s.pop();
                int b = 0; if(!s.empty()) {b = s.top(); s.pop();}
                s.push(operate(b, a, postfix[i]));
                ++i;   
            } else {
                int num = 0;
                while(i < n && postfix[i] >= '0' && postfix[i] <= '9') {
                    num = num * 10 + (postfix[i] - '0'); ++i;
                }
                s.push(num);
            }
        }
        return s.top();
    }
    int calculate(string s) {
        int cur = 0;
        int i = 0, n = s.length();
        return evalPostfix(Postfix(s));
    }
};
