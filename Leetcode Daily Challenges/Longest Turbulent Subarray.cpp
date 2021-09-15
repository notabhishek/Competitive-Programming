class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size();
        vector< int > dp[2]; // dp[0][i] // prev element was smaller , dp[0][1] => prev element was larger
        
        dp[0].resize(n , 1);
        dp[1] = dp[0];
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            if(a[i] > a[i-1])
                dp[0][i] = 1 + dp[1][i-1];
            if(a[i] < a[i-1])
                dp[1][i] = 1 + dp[0][i-1];
            ans = max(ans, max(dp[0][i] , dp[1][i]));
        }
        return ans;
    }
};
