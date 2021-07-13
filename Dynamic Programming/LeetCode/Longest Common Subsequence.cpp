class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i , int j, string &s, string &t) {
        if(i < 0 || j < 0) 
            return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        if(s[i] == t[j]) return ret = 1 + lcs(i-1, j-1, s, t);
        return ret = max( lcs(i-1, j , s, t) , lcs(i, j-1, s, t));
    }
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        dp.resize(n , vector<int> (m,-1));
        int ans = lcs(n-1, m-1, s, t);
        return ans;
    }
};
