class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i , int j, vector<int> &a) {
        if(i > j)
            return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        ret = max(a[i] - rec(i+1, j, a) , a[j]  - rec(i, j-1, a));
        return ret;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n , vector<int>(n, -1));
        int ans = rec(0, n-1, piles);
        return ans > 0;
    }
};
