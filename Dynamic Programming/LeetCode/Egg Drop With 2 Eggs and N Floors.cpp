class Solution {
public:
    const int INF = 1e3;
    vector<vector<int>> dp;
    int rec(int n , int k) {
        if(n <=2 ) return n;
        if(k == 1) return n;
        int &ret = dp[k][n];
        if(ret != -1)
            return ret;
        ret = n;
        for(int i = 1; i <= n; ++i)
            ret = min(ret ,1 + max(rec(i-1,k-1) , rec(n-i, k )));
        return ret;
    }
    int twoEggDrop(int n) {
        int k = 2;
        dp.resize(k+1 , vector<int>( n+1 , -1));
        dp[1][1] = 0;
        int ans = rec(n, k);
        return ans;
    }
};
