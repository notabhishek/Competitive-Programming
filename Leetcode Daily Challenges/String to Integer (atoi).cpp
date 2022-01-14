class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        long long ans = 0;
        int i = 0, n = s.length();
        
        while(i < n && s[i] == ' ') ++i;
        if(s[i] == '+' || s[i] == '-') {
            neg = (s[i] == '-');
            ++i;
        } 
        
        while(i<n) {
            if(s[i] < '0' || s[i] > '9') break;
            ans = 10*ans + (neg?-1:1) * (s[i]-'0');
            ans = min(ans, (long long)INT_MAX);
            ans = max(ans, (long long)INT_MIN);
            i++;
        }
        
        return ans;
    }
};
