class Solution {
public:
    int numPermsDISequence(string s) {
        //Can be optimized using prefix sum dp 
        // Same as  : https://github.com/becomeahacker/Competitive-Programming/blob/main/Dynamic%20Programming/Atcoder%20Educational%20DP%20Contest/dp_t.cpp
        
        const int M = 1e9 + 7;
        int n = s.length() + 1;
        int dp[n+1][n+1]; // Number of permutations of length i, ending in j
        memset(dp , 0 , sizeof dp);
        dp[1][1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(s[i-2] == 'I') {
                    // Increasing required
                    for(int k = 1; k < j; ++k) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= M;
                    }
                } else {
                    // Decreasing required
                    for(int k = j; k <= i; ++k ) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= M;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            ans = (ans + dp[n][i]) % M;
        return ans;
        
    }
};