class Solution {
public:
    int sum(int r1, int c1, int r2, int c2, vector<vector<int>> &dp){
        return dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
    }
    int largest1BorderedSquare(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = g[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for(int l = 1; l <= min(m,n); ++l) {
            for(int i = 1; i+l-1 <= n; ++i) {
                for(int j = 1; j+l-1 <= m; ++j) {
                    int x = i + l-1;
                    int y = j + l-1;
                    if(l <= 2) {
                        if(sum(i,j, x,y,dp) == l*l) ans = max(ans, l);
                    } else {
                        if((sum(i,j,x,y,dp) - sum(i+1,j+1, x-1,y-1,dp)) == (4*(l-1)))
                            ans = max(ans, l);
                    }
                }
            }
        }
        return ans * ans;
    }
};
