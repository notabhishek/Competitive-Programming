class Solution {
public:
    int spaceOptimizedLCS(string &a , string &b) {
        int m = a.length();
        int n = b.length();
        
        vector<vector<int>> dp (2 , vector<int> (n+1 , 0));
        int ind;
        for(int i = 0 ; i <= m; ++i) {
            ind = i % 2;
            for(int j = 0 ; j <= n; ++j) {
                if(i == 0 || j == 0) {
                    dp[ ind ][ j ] = 0;
                    continue;
                }
                if(a[i -1 ] == b[ j - 1]) 
                    dp[ ind ][j] = dp[ 1 - ind][j-1] + 1;
                else 
                    dp[ ind ][j] = max( dp[ind][j-1] , dp[1 - ind][j]);
            }
        }
        return dp[ind][ n ];
    }
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin() , b.end());
        return spaceOptimizedLCS(s , b);
    }
};
