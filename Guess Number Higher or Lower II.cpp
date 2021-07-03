class Solution {
public:
    vector<vector<int>> dp;
    int F(int l , int r){
        if(r < l)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        if(l == r-1)
            return dp[l][r] = l;
        dp[l][r] = INT_MAX;
        for(int i = l+1; i < r; ++i) {
            dp[l][r] = min(dp[l][r] , i + max(F(l,i-1) , F(i+1, r)));
        }
        dp[l][r] = min(dp[l][r] , l + F(l+1, r));
        dp[l][r] = min(dp[l][r] , r + F(l, r-1));
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        for(int i = 0; i <= n; ++i) 
            dp[i][i] = 0;
        return F(1 , n);
    }
};
