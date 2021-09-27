#define  bpc __builtin_popcount
class Solution {
public:
    vector<int> dp;
    bool palin(int mask, string &s) {
        if(dp[mask] != -1) return dp[mask];
        if((mask & -mask) == mask) return dp[mask] = 1;
        int lsb = log2(mask & -mask);
        int msb = log2(mask);
        return dp[mask] = (s[lsb] == s[msb]) && palin(mask - (1<<lsb) - (1<<msb), s);
    }
    int maxProduct(string s) {
        int n = s.length();
        dp.assign(1<<n, -1);
        int ans = 0;
        for(int mask1 = (1<<n)-1; mask1 > 0; --mask1) {
            if(!palin(mask1, s)) continue;
            int x = ((1<<n)-1) ^ mask1;
            int c1 =bpc(mask1);
            for(int mask2 = x; mask2 > 0; mask2 = (mask2-1) & x) {
                if(palin(mask2, s)) ans = max(ans, c1 * bpc(mask2));
            }
        }
        return ans;
    }
};
