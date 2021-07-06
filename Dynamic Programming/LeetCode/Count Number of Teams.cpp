class Solution {
public:
    int cnt(vector<int> &a) {
      int n = a.size();
        vector<int> dp[3];
        for(int i = 0 ; i < 3; ++i) {
            dp[i].resize(n, 0);
            for(int j = 0; j < n; ++j) {
                if(i == 0)
                    dp[i][j] = 1;
                else {
                    for(int k = j-1; k >= 0; --k) {
                        dp[i][j] += (a[j] > a[k] ? dp[i-1][k] : 0);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)ans += dp[2][i];
        return ans;  
    }
    int numTeams(vector<int>& a) {
        int res = cnt(a);
        reverse(a.begin() , a.end());
        res += cnt(a);
        return res;
    }
};
