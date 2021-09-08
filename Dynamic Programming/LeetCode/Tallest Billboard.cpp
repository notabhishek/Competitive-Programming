class Solution {
public:
    const int INF = 1e7;
    vector<vector<int>> dp;
    int rec(int i, int diff, vector<int> &r) {
        if(i < 0) return diff == 0 ? 0 : -INF;
        if(dp[i][diff] != -1) return dp[i][diff];
        int &ret = dp[i][diff];
        ret = rec(i-1, diff, r); 
        ret = max(ret, r[i] + rec(i-1, diff + r[i] , r));
        ret = max(ret, r[i] + rec(i-1, abs(diff - r[i]), r));
        return ret;
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        dp.resize(n, vector<int> (5001, -1));
        int ans = rec(n-1, 0, rods);
        return ans/2;
    }
};
