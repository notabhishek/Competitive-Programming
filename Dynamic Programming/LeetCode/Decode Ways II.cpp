class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int> (10, 0));

        dp[0] = vector<int> (10, 1);
        if(s[0] == '*') dp[1] = vector<int> (10, 1);
        else dp[1][s[0]-'0'] = 1;
        dp[1][0] = 0;
        
        for(int i = 2; i <= n; ++i) {
            // take s[i-1] alone
            int sum = 0; // sum dp[i-1][0..9]
            for(int k = 0; k < 10; ++k) sum = (sum + dp[i-1][k])%MOD;
            
            if(s[i-1] == '*') {
                for(int j = 1; j <= 9; ++j) {
                    // dp[i][j] += dp[i-1][k] // for all k
                    dp[i][j] = (dp[i][j] + sum)%MOD;
                }
            } else if(s[i-1] != '0') dp[i][s[i-1]-'0'] = (dp[i][s[i-1]-'0'] + sum)%MOD;
            
            // take s[i-1] with last char
            int sum2 = 0;
            if(i == 2) sum2 = 1;
            else for(int k = 0; k < 10; ++k) sum2 = (sum2 + dp[i-2][k])%MOD;
            
            if(s[i-1] == '*') {
                for(int j = 1; j < 10; ++j) {
                    if(s[i-2]=='1' || s[i-2] == '*') dp[i][j] = (dp[i][j] + sum2) % MOD;
                    if(j <= 6 && (s[i-2]=='2' || s[i-2] == '*'))
                        dp[i][j] = (dp[i][j] + sum2) % MOD;
                }
            } else  {
                int j = s[i-1] - '0'; 
                if(s[i-2]=='1' || s[i-2] == '*') dp[i][j] = (dp[i][j] + sum2) % MOD;
                if(j <= 6 && (s[i-2]=='2' || s[i-2] == '*'))
                    dp[i][j] = (dp[i][j] + sum2) % MOD;
            }
        }
        int res = 0;
        for(int j = 0; j < 10; ++j) res = (res + dp[n][j]) % MOD;
        return res;
    }
};
