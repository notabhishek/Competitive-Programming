class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i , int j, vector<int> &a, vector<int> &b) {
        if(i < 0 || j < 0)
            return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        if(a[i] == b[j]) return ret = 1 + lcs(i-1, j-1, a, b);
        return ret = max(lcs(i-1, j, a, b), lcs(i, j-1, a, b));
    }
    //ans is LCS of vectors 
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        dp.resize(n , vector<int> (m, -1));
        int ans =lcs(n-1, m-1, a, b);
        return ans;
    }
};
