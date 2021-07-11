class Solution {
public:
    const int INF = 1e8;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int dp[ n ][ n ][ n ]; // [stops][u][v]
        memset(dp, INF, sizeof(dp));   
        for(int i = 0 ; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int kk = 0; kk < n ; ++kk) 
                    dp[i][j][kk]  = INF;
            }
        }
        for(auto &f : flights) {
            dp[0][ f[0] ][ f[1] ] = min(f[2],dp[0][ f[0] ][ f[1] ]) ;
        }
        
        for(int stops = 1; stops < n; ++stops) {
            for(int u = 0; u < n; ++u)
                for(int v = 0; v < n; ++v) 
                    for(int k = 0; k < n; ++k) 
                        dp[stops][u][v] = min( dp[stops][u][v] , dp[stops-1][u][k]  + dp[0][k][v]);
        }
        int ans = INF;
        for(int u = 0; u  <= k; ++u) ans = min(ans , dp[u][src][dst]);
        if(ans >= INF) ans = -1;
        return ans;
    }
};
