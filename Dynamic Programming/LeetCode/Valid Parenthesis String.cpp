class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool> pre(n+1, false); 
        pre[0] = true;
        for(int i = 0; i < n; ++i) {
            vector<bool> cur(n+1, false);
            if(s[i] == ')' || s[i] == '*') {
                for(int j = 0; j < n; ++j)
                    cur[j] = cur[j] || pre[j+1];
            } 
            if(s[i] == '(' || s[i] == '*') {
                for(int j = 1; j <= n; ++j) 
                    cur[j] = cur[j] || pre[j-1];
            }
            if(s[i] == '*') {
                for(int j = 0; j <= n; ++j) 
                    cur[j] = cur[j] || pre[j];
            }
            
            pre = cur;
        }
        return pre[0];
    }
};
