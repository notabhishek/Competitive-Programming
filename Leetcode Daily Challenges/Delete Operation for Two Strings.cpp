class Solution {
public:
    // L1 + L2 - 2 * LCS
    vector< vector<int>> dp;
    int lcs(int i , int j , string &a, string &b) {
        if(i < 0 || j < 0)
            return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        
        if(a[i] == b[j]) return ret = 1 + lcs(i-1, j-1, a ,b);
        return ret = max(lcs(i-1, j , a , b), lcs(i, j-1, a, b));
    }
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        dp.resize(n , vector<int> (m, -1));
        return m + n - 2 * lcs(n-1, m-1, a, b);
    }
};
