class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> idx;
    string s;
    int rec(int i, int j) {
        if(i > j) return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        if(i == j) return ret = 1;
        if(i == j-1) return ret = 2;
        
        auto it1 = upper_bound(idx[s[i]-'a'].begin(), idx[s[i]-'a'].end(), i);
        auto it2 = lower_bound(idx[s[j]-'a'].begin(), idx[s[j]-'a'].end(), j);
        
        if(s[i] != s[j]) { 
            ret = ((rec(i+1, j) + rec(i, j-1)-rec(i+1,j-1))%MOD + MOD)%MOD;
        } else {
            // this is the first time this char came 
            if(*it1 == j)
                ret = (2 * rec(i+1, j-1) + 2) % MOD;
            else if( *prev(it2) == *it1 ) // this char came 1 time in middle
                ret = (2 * rec(i+1, j-1) + 1) % MOD;
            else // this char came >= 2 times 
                ret = ((2*rec(i+1, j-1)  - rec(*it1 + 1, *prev(it2) - 1))%MOD + MOD)%MOD;
        }
        ret %= MOD;
        return ret;
    }
    int countPalindromicSubsequences(string a) {
        s = a;
        int n = s.size();
        dp.assign(n, vector<int> (n, -1));
        idx.resize(26);
        for(int i = 0; i < n; ++i) {
            idx[s[i]-'a'].push_back(i);
        }
        // cout << idx;
        int ans = rec(0, n-1);
        return ans;
    }
};
