class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        int pre[n+1][26];
        memset(pre, 0, sizeof pre);
        for(int i = 1 ; i <= n; ++i) {
            for(int j = 0; j < 26; ++j) pre[i][j] = pre[i-1][j];
            pre[i][ s[i-1]-'a' ]++;
        }
        int ans = 0;
        for(int i = 0; i < n-1; ++i){
            // a = [0..i]
            // b = [i+1 ... n-1]
            int d1 = 0, d2 = 0;
            for(int j = 0; j < 26; ++j) {
                if(pre[i+1][j]) ++d1;
                if(pre[n][j] - pre[i+1][j]) ++d2;
            }
            // cout << i << " "<< d1 << " "<< d2 << endl;
            ans += d1 == d2;
        }
        return ans;
    }
};
