class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char c : num) {
            if(s.empty() || c >= s.top()) 
                s.push(c);
            else {
                while(k > 0 && !s.empty() && s.top() > c) {
                    s.pop();
                    k--;
                }
                s.push(c);
            }
        }
        num = "";
        while(!s.empty()) {
            if(k == 0)
                num += s.top();
            else k--;
            s.pop();
        }
        reverse(num.begin(), num.end());
        int z = 0; 
        for(char c : num) if(c == '0') ++z; else break;
        num = num.substr(z);
        return num == "" ? "0" : num;
    }
};
