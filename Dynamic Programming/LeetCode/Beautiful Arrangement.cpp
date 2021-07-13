class Solution {
public:
    int N;
    vector< vector<int>> dp;
    int cnt(int n, int mask) {
        if(mask == 0) 
            return 1;
        if(dp[n][mask] != -1)
            return dp[n][mask];
        dp[n][mask] = 0;
        for(int i = 0 ; i < N; ++i) {
            if( (mask & (1<<i) ) && ( n%(i+1)==0 || (i+1)%n==0)) {
                dp[n][mask] += cnt( n-1, mask ^ (1<<i));
            }
        }
        return dp[n][mask];
    }
    int countArrangement(int n) {
        dp.resize( n + 1 , vector<int> ( 1<<n , -1));
        N = n;
        dp[0][0] = 1;
        int ans = cnt( n , (1<<n) - 1);
        return ans;
    }
};
