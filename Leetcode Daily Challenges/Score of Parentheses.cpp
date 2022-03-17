class Solution {
public:
    int scoreOfParentheses(string a) {
        int ans = 0, cur = 0;
        stack<int> s;
        for(char c : a) {
            if(c == '(') {
                s.push(cur);
                cur = 0;
            }
            else {
                cur = s.top() + max(2*cur, 1);
                s.pop();
            }
        }
        return cur;
    }
};
