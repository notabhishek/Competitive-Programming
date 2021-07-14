class Solution {
public:
    const int MOD = 1e9 + 7;
    // dp[n][k] = number of arrays [1..n] having k inversions
    vector<vector<int>> dp;
    // sum[n][k] = dp[n][k] + dp[n][k-1] + .. . dp[n][0]
    vector<vector<int>> sum;
    int srec(int n , int k) {
        if(n < 0 || k < 0) return 0;
        
        int &ret = sum[n][k];
        if(ret != -1)
            return ret;
        
        if(k == 0)
            return ret = 1;
        
        ret = (rec(n, k) + srec(n, k-1) ) % MOD;
        
        return ret;
    }
    int rec(int n , int k) {
        if(n < 0 || k < 0) return 0;
        int &ret = dp[n][k];
        if(ret != -1)
            return ret;
        
        if(k == 0)
            return ret = 1;
        // _ _ _ _ _ _  push N at any position in already built array of N-1 , inversions ill be numbers on right
        // Constant O(N * K)
        ret = (srec(n-1, k) - srec(n-1 , k-1-(n-1)))%MOD;
        if( ret < 0) 
            ret += MOD;
        // linear O(N * N * K) 
        // for(int i = 1; i <= n-1; ++i) {
            // ret = (ret + rec(n-1, k - i)) % MOD;
        // }
        return ret;
    }
    int kInversePairs(int n, int k) {
        dp.resize(n + 1, vector<int>(k+1, -1));
        sum.resize(n+1, vector<int>(k+1, -1));
        int ans = rec(n , k);
        
        // cout <<"dp\n";
        // for(auto &i : dp) {
        //     for(auto &j : i ) cout << j << " "; cout << "\n";
        // }
        // cout <<"sum\n";
        // for(auto &i : sum) {
        //     for(auto &j : i ) cout << j << " "; cout << "\n";
        // }
        
        return ans;
    }
};
