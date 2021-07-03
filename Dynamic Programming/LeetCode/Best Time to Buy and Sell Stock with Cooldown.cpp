class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int dp[n+1][2];
        // dp[i][0] = max profit after selling on ith day
        // dp[i][1] = max profit not necessarily selling on ith day
        dp[0][0] = dp[0][1] = 0;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = dp[i][1] = 0;
            for(int j = i-1; j >= 1; --j) {
                dp[i][0] = max(dp[i][0] , a[i-1]-a[j-1] + (j>1 ? dp[j-2][1] : 0));
            }
            dp[i][1] = max(dp[i-1][1] , dp[i][0]);
        }
        return dp[n][1];
    }
};
