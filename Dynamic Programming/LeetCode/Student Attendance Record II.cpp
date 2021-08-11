#define late 3
#define absent 2
class Solution {
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n) {
        int dp[absent][late]; // dp[i][j] = i days absent , j consecutive late 
        memset(dp, 0, sizeof dp);
        int cur[absent][late];
        memset(cur, 0, sizeof cur);
        dp[0][0] = 1;
        for(int day = 1; day <= n; ++day) {
            for(int a = 0; a < absent; ++a) {
                for(int l  = 0; l < late; ++l) {
                    // Case1 : don't be absent today
                        // case 1.1 : be late today
                            cur[a][l] = (cur[a][l] + (l>0? dp[a][l-1] : 0)) % MOD; 
                        // case 1.2 : don't be late today
                            cur[a][0] = (cur[a][0] + dp[a][l]) % MOD;
                    // Case2 : be absent today
                    if(a > 0) cur[a][0] = (cur[a][0] + dp[a-1][l])%MOD;
                }
            }
            for(int i = 0; i < absent; ++i) 
                for(int j = 0; j < late; ++j) {
                    dp[i][j] = cur[i][j];
                    cur[i][j] = 0;
                }
        }
        int ans = 0;
        for(int a = 0; a < absent; ++a){
            for(int l = 0; l < late; ++l) ans = (ans + dp[a][l]) % MOD;
        }
        return ans;
                
    }
};
