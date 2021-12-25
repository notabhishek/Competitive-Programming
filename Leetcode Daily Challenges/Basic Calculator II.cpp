class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int cur = 0, pre = 0, ans = 0;
        char sign = '+';
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                cur = (cur * 10) + (c - '0');
            }
            if (!isdigit(c) && !iswspace(c) || i == n - 1) {
                if (sign == '+' || sign == '-') {
                    ans += pre;
                    pre = (sign == '+') ? cur : -cur;
                } else if (sign == '*') {
                    pre = pre * cur;
                } else if (sign == '/') {
                    pre = pre / cur;
                }
                sign = c;
                cur = 0;
            }
        }
        ans += pre;
        return ans;  
    }
};
