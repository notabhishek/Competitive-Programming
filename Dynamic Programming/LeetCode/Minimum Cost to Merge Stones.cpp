class Solution {
public:
    const int INF = 1e7;
    // dp[i][j][k] = cost for merging i..j by merging k tiles
    vector< vector< vector<int>>> dp;
    int K;
    int rec(int i, int j, int k, int sum, vector<int> &a){
        if(i > j) 
            return k == 0 ? 0 : INF;
        if(k <= 0)
            return INF;
        
        int &ret = dp[i][j][k];
        if(ret != -1) 
            return ret;
        
        if(i == j) {
            return ret = (k == K || k == 1? 0 : INF);
        }
        if(k == 1) {
            return ret = rec(i, j, K, sum, a);
        }
        ret = INF;
        int lsum = 0 , rsum = sum;
        for(int p = i; p < j; ++p) {
            lsum += a[p];
            rsum -= a[p];
            int cur = (k==K ? sum : 0) + rec(i, p, K, lsum, a) + rec(p+1, j , k-1, rsum, a);
            ret = min(ret, cur);
        }
        return ret;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        K = k;
        dp.resize(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int ans = rec(0, n-1, K, sum, stones);

        if(ans >= INF) ans = -1;
        return ans;
    }
};
