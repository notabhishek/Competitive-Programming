class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[ n + 1 ][ m + 1];
        auto &a = matrix;
        memset(dp , 0 , sizeof dp);
        for(int i = 0; i < n; ++i) {
            for(int j = 0 ;j < m; ++j) {
                dp[i + 1][j + 1] = a[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            }
        }
        int ans = 0;
        map< int,  int > freq[n + 1];
        for(int r = 1; r <= n; ++r) {
            for(int c = 1; c <= m; ++c) {
                freq[r][ dp[r][c] ]++;
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int x = i; x <= n; ++x ) {
                    for(int y = j;y <= m; ++y) {
                        ans += (target == (dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1]));
                    }
                } 
            }
        }
        return ans;
    } 
};