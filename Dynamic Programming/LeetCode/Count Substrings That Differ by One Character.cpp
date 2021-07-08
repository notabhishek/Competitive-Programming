class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        int dp[ min(n , m ) + 1][ n+1 ][ m+1 ];
        memset(dp , 0 , sizeof dp);
        int ans = 0;
        for(int l = 1; l <= min(n , m); ++l) {
            for(int i = 0; i+l <= n; ++i) {
                for(int j=0; j+l <=m; ++j) {
                    dp[l][i][j] = dp[l-1][i][j] + (s[i + l-1] == t[j + l-1] ? 0 : 1);
                    if(dp[l][i][j] == 1) {
                        ++ans;
                        // cout << s.substr(i , l) << " " << t.substr(j , l) << endl;
                    }
                }
            }
        }
        return ans;
    }
};
