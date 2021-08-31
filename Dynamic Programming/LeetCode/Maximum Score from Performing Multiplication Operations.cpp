const int INF = 2e9;
class Solution {
public:
    vector<vector<int>> dp;
    inline int rec(int idx, int l, int r, vector<int> &a, vector<int> &b) {
        if(idx == b.size()) return 0;
        if(dp[l][r] != -INF) return dp[l][r];
        return dp[l][r] = max(
                a[l]*b[idx] + rec(idx+1, l+1, r, a, b), 
                a[a.size()-1-r]*b[idx] + rec(idx+1, l, r+1, a, b) );
    }
    int maximumScore(vector<int>& a, vector<int>& b) {
        dp.resize(b.size() , vector<int> (b.size(), -INF));
        return rec(0, 0, 0, a, b);
    }
};
