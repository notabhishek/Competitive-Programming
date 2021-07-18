// Egg dropping in NKlogN
class Solution {
public:
    const int INF = 1e7;
    vector<vector<int>> dp;
    int rec(int n ,  int k ) {
        int &ret = dp[n][k];
        if(ret != -1)
            return ret;
        if(k == 1 || n <= 1) return ret = n;
        ret = INF;
        int lo = 1, hi = n;
        // Instead of dropping from every floor O(N*N*K), 
        // we can find the best floor for dropping 
        while(lo <= hi ){
            int mid = (lo + hi)/2;
            // throw from mid floor
            int breaks = 1 + rec(mid-1, k-1);
            int notBreaks = 1 + rec(n - mid, k);
            ret = min(ret, max(breaks, notBreaks));
            if(breaks == notBreaks) break;
            if(breaks < notBreaks) {
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ret;
    }
    int superEggDrop(int k, int n) {
        dp.resize(n+1, vector<int>(k+1, -1));
        int ans = rec(n , k);
        return ans;
    }
};
