class Solution {
public:
    const int INF = 1e7;
    int findTheCity(int n, vector<vector<int>>& edges, int DT) {
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for(auto &e : edges){
            dp[e[0]][e[1]] = min(dp[e[0]][e[1]], e[2]);
            dp[e[1]][e[0]] = min(dp[e[1]][e[0]], e[2]);
        }
        for(int i = 0 ; i < n; ++i) dp[i][i] = 0;
        
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
                }
            }
        }
        // for(auto &i : dp) {
        //     for(auto &j : i) cout << j << " "; cout << endl;
        // }
        int city = -1, reach = INF;
        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = 0; j < n; ++j) 
                if(dp[i][j] <= DT)
                    ++cur;
            // cout <<"city " << i << " cur" << cur << endl;
            if(cur <= reach) {
                reach = cur;
                city = i;
            }
        } 
        return city;
    }
};
