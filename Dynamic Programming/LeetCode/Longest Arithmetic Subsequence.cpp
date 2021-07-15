class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        int dmax = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
        int dp[n][dmax + 1][2]; // dp[last index][ diff ][ pos/neg ] = length
        memset(dp, 0, sizeof dp);
        int ans = 0;
        cout << dp[0][0][0] << endl;
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                int d = a[i] - a[j];
                if(d >= 0) {
                    dp[i][d][0] = max(dp[i][d][0], 1 + dp[j][d][0]);
                    ans = max(ans, dp[i][d][0]);
                }
                else {
                    dp[i][-d][1] = max(dp[i][-d][1], 1 + dp[j][-d][1]);
                    ans = max(ans, dp[i][-d][1]);
                }
            }
        } 
        return ans + 1;
    }
};
