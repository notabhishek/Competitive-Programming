class Solution {
public:
    int numSquares(int n) {
        if(n==0)
            return 0;
        vector<int> dp(n+1 ,  n+1);
        dp[0] = 0;
        for(int i = 1; i*i <= n; ++i) {
            for(int j = i*i ; j<=n; ++j) 
                dp[j] = min( dp[j-i*i] + 1 , dp[j]);
        }
        return dp[n];
    }
};
