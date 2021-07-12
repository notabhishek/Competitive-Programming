class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int rec(int sum ,int c, vector<int>& coins) {
        if(c< 0)
            return sum == 0;
        int &ret = dp[sum][c];
        if(ret != -1)
            return ret;
        ret = rec(sum , c-1, coins);
        if(sum >= coins[c])
            ret += rec(sum - coins[c], c, coins);
        // ret %= MOD;
        return ret;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(amount + 1 ,vector<int>(n + 1, -1));
        int ans = rec(amount, n-1, coins);
        return ans;
    }
};
