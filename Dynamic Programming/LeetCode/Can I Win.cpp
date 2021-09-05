class Solution {
public:
    vector<int> dp;
    int bit;
    bool rec(int n, int mask) {
        if(n <= 0) return false;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 0; i < bit; ++i) {
            if((mask & (1<<i)) && !rec(n-i-1, mask^(1<<i)))
                return dp[mask] = true;
        }
        return dp[mask] = false;
    }
    bool canIWin(int N, int K) {
        if(K == 0) return true;
        if(((N*(N+1))/2) < K) return false; //1st player cannot force a win
        bit = N;
        dp.assign((1<<N), -1);
        bool ans = rec(K, (1<<(N)) - 1 );
        return ans;
    }
};
