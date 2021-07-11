class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n = a.size();
        sort(a.begin() , a.end());
        // for(auto &i : a) cout << i << " "; cout << endl;
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            // take this element
            dp[i] = a[i-1];
            for(int j = i-1; j > 0; --j) 
                if(a[j-1] != a[i-1]-1 && a[j-1]!=a[i-1]+1 )
                    dp[i] = max(dp[i] , a[i-1] + dp[j]);
            ans = max(ans , dp[i]);
        }
        // for(auto &i : dp) cout << i << " "; cout << endl;
        return ans;
    }
};
