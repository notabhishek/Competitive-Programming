class Solution {
public:
    
    int maxLength(vector<string>& a) {
        int n = a.size();
        int N = 1<<n;
        int ans = 0;
        
        vector<int> mask(N);
        vector<int> dp(N);
        
        for(int i = 0; i < n; ++i) {
            int cur = 0, f = 1, len = a[i].length();
            for(char c: a[i]) {
                if(cur & (1<<(c-'a'))) f = 0;
                cur ^= (1<<(c-'a'));
            }
    
            for(int m = 0; m < (1<<i); ++m) {
                int prev = mask[m];
                if(f && (prev^cur) == (prev | cur)) {
                    mask[m ^ (1<<i)] = prev ^ cur;
                    dp[m ^ (1<<i)] = max(dp[m ^ (1<<i)], len + dp[m]);
                    ans = max(ans, dp[m ^ (1<<i)]);
                } else {
                    mask[m ^ (1<<i)] = N - 1;
                    dp[m ^ (1<<i)] = 0;
                }
            }
        }
        
        return ans;
    }
};
