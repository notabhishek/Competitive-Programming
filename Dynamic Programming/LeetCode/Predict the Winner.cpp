class Solution {
public:
    const int INF = 1e9;
    vector<vector<bool>> f; // to check if dp has been calc or not
    vector<vector<int>> dp;
    int rec(int i, int j, vector<int> &a) {
        int &ret = dp[i][j];
        if(f[i][j])
            return ret;
        ret = max(ret, max(a[i] - rec(i+1, j , a) , a[j]-rec(i, j-1, a)));
        f[i][j] = 1;
        return ret;
    }
    bool PredictTheWinner(vector<int>& a) {
        int n = a.size();
        dp.resize(n , vector<int> (n, -INF));
        f.resize(n , vector<bool> (n, 0));
        for(int i = 0; i < n; ++i) {
            f[i][i] = 1;
            dp[i][i] = a[i];
        }
        int ans = rec(0, n-1, a);
        for(auto &i : dp) {
            for(auto &j : i ) cout << j << " "; cout << endl;
        }
        return ans >= 0;
    }
};
