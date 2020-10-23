class Solution {
public:
    void fill(int i ,char p , string cur, map<string , int >&m , map< int , string> &rev) {
        if(i == 4) {
            if(cur.size() == 3) {
                m[ cur ] = m.size();
                rev[ m.size() - 1] = cur;
            }
            return;
        }
        string col = "RGB";
        for(auto &cc : col) 
            if(p !=cc ) {
                string temp = cur;
                temp+= cc;
                fill(i+1 , cc ,temp, m , rev);
            }
    }
    bool can(int i, int j ,map<int , string>&rev){
        string &s = rev[i];
        string &t = rev[j];
        for(int k = 0 ; k < 3; ++k) 
            if(s[k] == t[k])
                return false;
        return true;
    }
    int numOfWays(int n) {
        int dp[n + 1][13];
        memset(dp , 0 , sizeof dp);
        for(int i = 0 ; i < 13; ++i) dp[1][i] = 1;
        map < string , int > m;
        map < int , string > rev;
        fill(1 , 'X' , "" , m , rev);
        const int MOD = 1e9 + 7;
        for(int row = 2; row <= n; ++row) {
            for(int c = 0; c < rev.size(); ++c) {
                for(int p = 0; p < rev.size(); ++p) {
                    if(can(c , p , rev)) {
                        dp[row][c] += dp[row-1][p];
                        dp[row][c] %= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rev.size(); ++i) 
            ans = (ans + dp[n][i]) % MOD;
        return ans;
    }
};