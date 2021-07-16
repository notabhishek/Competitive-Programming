class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        vector<int> dp[2];
        dp[0].resize(n , 1);
        dp[1] = dp[0];
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(a[i] > a[j])
                    dp[0][i] = max(dp[0][i] , 1 + dp[1][j]);
                if(a[i] < a[j])
                    dp[1][i] = max(dp[1][i] , 1 + dp[0][j]);
            }
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        return ans;
    }
};
