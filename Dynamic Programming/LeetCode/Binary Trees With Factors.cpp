using ll = long long;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& a) {
        sort(a.begin() , a.end());
        map<int , ll> dp;
        ll ans = 0 , n = a.size();
        for(int i = 0; i < n; ++i) {
            ll cur = 1;
            for(int j = 0; j < i; ++j) {
                if(a[i] % a[j] == 0 && dp.count(a[i]/a[j]))
                    cur = (cur + (dp[ a[j] ] * dp[a[i]/a[j]])%MOD)%MOD;
            }
            dp[a[i]] = cur;
            ans = (ans + cur) % MOD;
        }
        return ans;
    }
};
