class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        
        vector<vector<int>> dp(n+1 , vector<int> (m , -1));
        if(m == 1) return dp[0];
        
        for(int i = 0; i < m; ++i) 
            dp[n][i] = i;

        for(int r = n-1; r >= 0; --r) {
            for(int i = 0; i < m; ++i) {
                if(g[r][i] == 1) {
                    if(i < m-1 && g[r][i+1] != -1) dp[r][i] = dp[r+1][i+1];
                } else {
                    if(i > 0 && g[r][i-1] != 1) dp[r][i] = dp[r+1][i-1];
                }
            }
        }
        
        return dp[0];
    }
};
