#define vt vector
class Solution {
public:
    const int INF = 1e6;
    int work(int i , int j,vt<int>&a, int d, vt<vt<vt<int>>>&dp) {
        int &ret = dp[i][j][d-1];
        if(ret != -1)
            return ret;
        if(d == 1) {
            ret = INT_MIN;
            for(int k = i; k<=j; ++k ) ret = max(ret , a[k]);
            return ret;
        }
        if(i == j) {
            return ret = INF;
        }
        ret = INF;
        for(int k = i; k < j; ++k) {
            ret = min(ret , work(i , k,a,1,dp) + work(k+1,j,a,d-1,dp));
        }
        return ret;
    }
    int minDifficulty(vector<int>& a, int d) {
        int n = a.size();
        vt<vt<vt<int>>> dp(n , vt<vt<int>>(n ,vt<int>(d ,-1)));
        int ans = work(0 , n-1 , a, d, dp);
        if(ans >= INF) 
            ans = -1;
        return ans;
    }
};