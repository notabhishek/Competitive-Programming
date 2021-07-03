class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin() , a.end());
        reverse(a.begin() , a.end());
        int n = a.size();
        vector<int> dp(n, 1);
        vector<int> par(n , 1);
        for(int i = 0; i < n; ++i) 
            par[i] = i;
        
        int ans = 1 , idx = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j>=0; --j) 
                if( (a[j] % a[i] == 0) && (dp[i] < dp[j]+1)) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            if(dp[i] > ans) {
                ans = dp[i];
                idx = i;
            }
        }
        vector<int>res;
        while(par[idx] != idx) {
            res.push_back(a[idx]);
            idx = par[idx];
        }
        res.push_back(a[idx]);
        sort(res.begin(), res.end());
        return res;
    }
};
