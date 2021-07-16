class Solution {
public:
    int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp) {
        if(i == s1.length() || j == s2.length()) {
            int t = 0;
            for(int k = i; k < s1.length(); ++k) t+= s1[k];
            for(int k = j; k < s2.length(); ++k) t+= s2[k];
            return t;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        if(s1[i] == s2[j] ) 
            dp[i][j] = solve(i+1 , j+1 , s1 , s2 , dp);
        else 
            dp[i][j] = min( s1[i] + solve(i+1 , j , s1 , s2 , dp) ,s2[j] + solve(i , j+1 , s1,s2,dp) );
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
       vector<vector<int>> dp(s1.length()  , vector<int> (s2.length() , -1)); 
        return solve(0 , 0 , s1 , s2 , dp);
    }
};
