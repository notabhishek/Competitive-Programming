class Solution {
public:
    
    const int MOD = 1e9 + 7;
    int sum(long long int n) {
        return ( ( (n+1) * n )/2) % MOD; 
    }
    int countOrders(int n) {
        vector< long long int > dp(n + 1 , 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] * sum(2 * i - 1) ) % MOD;
        }
        return (int)dp[n];
    }
};
