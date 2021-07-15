class Solution {
public:
    int ways(int i , string &s , vector<int> &dp) {
        if(i==0)
            return 1;
        if(dp[i-1]!=-1)
            return dp[i-1];
        dp[i-1] = 0;
        if(s[i-1]!='0')
            dp[i-1]+= ways(i-1 , s , dp);
        if((i-1)> 0) {
            if(s[i-2]=='1') dp[i-1] += ways(i-2 , s , dp);
            if(s[i-2]=='2' && s[i-1]<='6') dp[i-1]+=ways(i-2 , s , dp);
        }
        return dp[i-1];
    }
    int numDecodings(string s) {
        vector<int> dp(s.length() , -1);
        return ways(s.length() , s , dp);
    }
};
