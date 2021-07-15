class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 1 , i3 = 1 , i5 = 1;
        int dp[n+1];
        dp[1] = 1;
        for(int i=2; i <=n; ++i) {
            int v2 = 2 * dp[i2];
            int v3 = 3 * dp[i3];
            int v5 = 5 * dp[i5];
            dp[i] = min( v2 , min(v3  , v5));
            if(dp[i] == v2) ++i2;
            if(dp[i] == v3) ++i3;
            if(dp[i] == v5) ++i5;
        }
        return dp[n];
    }
};
