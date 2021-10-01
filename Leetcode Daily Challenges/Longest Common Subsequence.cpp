class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i, int j, string &a, string &b) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + lcs(i-1,j-1,a,b);
        return dp[i][j] = max(lcs(i-1,j,a,b), lcs(i,j-1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int>(text2.size(),-1));
        return lcs(text1.size()-1, text2.size()-1, text1, text2);
    }
};
