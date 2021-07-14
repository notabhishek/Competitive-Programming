class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        //sort by ending 
        sort(a.begin(), a.end(), [](vector<int>p, vector<int> q) -> bool {
            if(p[1] == q[1])
                return p[0] < q[0];
            return p[1] < q[1];
        });
        int n = a.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(a[i][0] > a[j][1])
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};
