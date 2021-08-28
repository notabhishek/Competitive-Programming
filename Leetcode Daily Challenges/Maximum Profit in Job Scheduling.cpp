class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pr) {
        vector<array<int,3>> a;
        int n = st.size();
        for(int i = 0; i < n; ++i) {
            a.push_back({et[i], st[i], pr[i]});
        }
        sort(a.begin(), a.end());
        vector<int> dp(n+1, 0);
        int ans = 0;
        // projects cses standard dp
        for(int i = 1; i <= n; ++i) {
            int lo = 1, hi = i-1, idx = 0;
            while(lo <= hi) {
                int mid = (lo+hi)/2;
                if(a[mid-1][0] <= a[i-1][1])
                    lo = mid+1;
                else 
                    hi = mid - 1;
            }
            dp[i] = a[i-1][2] + dp[lo-1];
            dp[i] = max(dp[i], dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
