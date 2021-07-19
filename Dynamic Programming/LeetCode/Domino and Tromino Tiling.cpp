class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
       vector<long long> dp[3];
        dp[0].resize(n + 1, 0);
        dp[2] = dp[1] = dp[0];
        dp[0][0] = 1;
        /*
        possible endings after tiling till i
        dp0   dp1 dp2
        0     0   1   
        0     1   0
        */
        for(int i = 1; i <= n; ++i) {
            //fill dp0
            dp[0][i] = dp[0][i-1] + (i>=2 ? dp[0][i-2] : 0) + dp[1][i-1] + dp[2][i-1];
            
            //fill dp1
            dp[1][i] = (i>=2 ? dp[0][i-2] : 0) + dp[2][i-1]; // use trinomial or horizontal
            
            //fill dp2
            dp[2][i] = (i>=2 ? dp[0][i-2] : 0) + dp[1][i-1];
            // cout << i << " " << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << "\n";  
            for(int j = 0; j < 3; ++j) dp[j][i] %= MOD;
        }
        return dp[0][n];
    }
};
