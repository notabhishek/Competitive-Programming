class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        int dp[n][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        dp[0][ a[0] % 3] = a[0];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 3; ++j) {
                dp[i][j] = dp[i-1][j];
                if( dp[i-1][(j - (a[i]%3) + 3) % 3] == 0 ) {
                    if(dp[i][ a[i] % 3 ] == 0) 
                        dp[i][a[i] % 3] = a[i];
                } else {
                    dp[i][j] = max(dp[i-1][j ] ,a[i] + dp[i-1][(j - (a[i]%3) + 3) % 3]);
                }
            }
        }
        return max(0 , dp[n-1][0]);
    }
};