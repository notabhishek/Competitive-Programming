class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1][2];
        dp[0][0] = 0; // Not Robbed 0th house
        dp[0][1] = 0; // Robbed 0th house
        for(int i = 1; i <= n; ++i ) {
            dp[i][1] = nums[i-1] + dp[i-1][0];
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1]);
        }
        return max(dp[n][0] , dp[n][1]);
    }
};