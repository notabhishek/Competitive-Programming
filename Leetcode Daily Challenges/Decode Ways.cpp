class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i] = 0;
            if(s[i-1] >= '1' && s[i-1] <= '9')
                dp[i] = dp[i-1]; // this digit as single
            if(i >= 2) {
                string pre = ""; pre+= s[i-2]; pre+= s[i-1];
                if(stoi(pre) >= 1  && stoi(pre) <= 26 && s[i-2] > '0')
                    dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
