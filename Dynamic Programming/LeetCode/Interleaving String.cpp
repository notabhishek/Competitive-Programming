class Solution {
public:
    bool helper(string &s1 , string &s2 ,string &s3 ,  int i, int j , int k , vector<vector<int>> &dp) {
        if(k==0) {
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans1 = false;
        bool ans2 = false;
        dp[i][j] = 0;
        if(i>0 && s3[k-1] == s1[i-1] )
            ans1 = helper(s1 , s2 , s3, i-1 , j , k-1 , dp);
        dp[i][j] = dp[i][j] || ans1;
        if(ans1) 
            return true;
        if(j>0 && s3[k-1] == s2[j-1])
            ans2 = helper(s1 , s2 , s3 , i , j-1 , k-1 , dp);
         dp[i][j] = dp[i][j] || ans2;
        if(ans2)
            return true;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length()!=s3.length())
            return false;
        vector<vector<int>> dp(s1.length()+1 , vector<int> (s2.length()+1,-1));
        return helper(s1 , s2 , s3 , s1.length() , s2.length(), s3.length() , dp);
    }
};
