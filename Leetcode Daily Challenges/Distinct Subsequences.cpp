class Solution {
public:
    int lcs(int i , int j , string &s , string &t , vector<vector<int>> &dp) {
        if(j==0) {
            return 1;
        }
        if(i==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        if(t[j-1] == s[i-1])
            ans+= lcs(i-1 , j-1 , s , t , dp); 
        ans+= lcs(i-1 , j , s, t , dp);
        dp[i][j] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1 , vector<int> (t.length()+1 , -1));
        return lcs(s.length() , t.length() , s ,t  , dp);
    }
};
