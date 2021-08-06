class Solution {
public:
    vector<vector<vector<int>>> dp; // dp[i][j][previous color]
    int rec(int i, int j , int c, string &s){
        if(i > j) 
            return 0;
    
        int &ret = dp[i][j][c];
        if(ret != -1)
            return ret;
        ret = j-i+1;
        if(s[i]-'a' == c) return ret = rec(i+1, j , c, s);
    
        for(int k = i; k <= j; ++k) {
            // color [i..k] in s[i]
            ret =  min(ret , 1 + rec(i+1, k, s[i]-'a', s) +  rec(k+1, j , c, s));
        }
        return ret;
    }
    int strangePrinter(string s) {
        int n = s.length();
        dp.resize(n, vector<vector<int>>(n, vector<int>(27, -1)));
        int ans = rec(0, n-1, 26, s);
        return ans;
    }
};
