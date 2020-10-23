class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int M = 1e9 + 7;
        const int MXN = 51;
        const int MXM = 101;
        const int MXK = 51;
        int dp[MXN][MXM][MXK]; // [prefix][max value till now][comparisons]
        memset(dp , 0 , sizeof dp);
        for(int mxv = 1; mxv <= m; ++ mxv)
            dp[1][mxv][1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int putt = 1; putt <= m; ++putt ) {
                for(int cmx = 1; cmx <= m; ++cmx) {
                        for(int j = 1; j <= k; ++j ) {
                            if( putt > cmx ) {
                                dp[i][putt][j] += dp[i-1][cmx][j-1];
                                 dp[i][putt][j] %= M;
                            } else {
                                dp[i][cmx][j] += dp[i-1][cmx][j];
                                dp[i][cmx][j] %= M;
                            }
                    }
                }
            }
        }
        int ans = 0;
        for(int mxv = 1; mxv <= m; ++mxv) {
            ans += dp[n][mxv][k];
            ans %= M;
        }
        return ans;
        
    }
};