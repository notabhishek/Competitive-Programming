class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int tz = count(s.begin() , s.end(), '0');
        int n = s.length();
        int to = n - tz;
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + (s[i-1]=='1');
        int ans = tz; // make all ones
        // all zeros < i and 1 > i
        for(int i = 1; i <= n; ++i) {
            // req = ones <i + zeros >= i
            int cur = pre[i] + (n-i - (pre[n] - pre[i]));
            ans = min(ans, cur);
        }
        return ans;
    }
};
