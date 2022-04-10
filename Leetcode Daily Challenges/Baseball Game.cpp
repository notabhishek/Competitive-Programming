class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto &s : ops) {
            if(s == "D")
                st.push(2*st.top());
            else if(s == "+") {
                int x = st.top();st.pop();
                int y = x + st.top();
                st.push(x);
                st.push(y);
            } else if(s == "C") st.pop();
            else st.push(stoi(s));
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        return ans;
    }
};
