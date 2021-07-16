class Solution {
public:
    const int INF = 1e7;
    int minSideJumps(vector<int>& o) {
        int n = o.size();
        vector< vector<int>> dp(n+1, vector<int>(3, INF));
        dp[0][1] = 0;
        dp[0][0] = 1;
        dp[0][2] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(o[i-1] != j+1) 
                    dp[i][j] = dp[i-1][j];
            }
            for(int j = 0; j < 3; ++j) {
                if(o[i-1] != j+1)
                for(int k = 0; k < 3; ++k) 
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k]);
            }
         }
        return min(dp[n][0] , min(dp[n][1] , dp[n][2]));
    }
};
