class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        if(!mat.size() || !mat[0].size()) 
                return 0;
        int n = mat.size();
        int m = mat[0].size();
        int dp[n + 1][m + 1];
        memset(dp , 0 , sizeof dp);
        for(int i = 1; i <=n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = (mat[i-1][j-1]=='1') + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }
        int area , sum;
        for(int len = min(m , n); len > 0; --len) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                    int x = i + len -1;
                    int y = j + len -1;
                    if(x > n || y > m) continue;
                    sum = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1];
                    area = len * len;
                    if(sum == area)
                        return area;
                }
            }
        }
        
        return 0;
    }
};