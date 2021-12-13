class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cur = 1, p = '0';
        for(char &c : s) {
            if(c == p) ++cur;
            else {
                ans = max(ans, cur);
                cur = 1;
            }
            p = c;
        }
        ans = max(ans, cur);
        return ans;
    }
};
