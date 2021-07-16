class Solution {
public:
    const int MOD = 1e9 + 7;
    int knightDialer(int n) {
        vector<pair<int, int>> pos = { {3,1} , {0,0}, {0,1}, {0,2}, {1, 0}, {1,1}, {1,2}, {2,0} , {2,1}, {2,2}};
        vector<vector<int>> dp(n+1, vector<int> (10, 0));
        dp[1].assign(10 , 1);
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 10; ++j) {
                for(int k = 0; k < 10; ++k) {
                    int x = abs(pos[j].first - pos[k].first);
                    int y = abs(pos[j].second - pos[k].second);
                    if((x==1 && y==2) || (x==2 && y==1)) {
                        dp[i][j] =(dp[i][j] + dp[i-1][k])%MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 10; ++i) ans = (ans + dp[n][i]) % MOD;
        return ans;
    }
};
