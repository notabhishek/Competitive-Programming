class Solution {
public:
    vector< vector< int >> dp;
    int n;
    bool P(int i , int j , string &s) {
        if(i>j) 
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = (s[i] == s[j] && P(i+1 , j-1,s));
    }
    string longestPalindrome(string s) {
        n = s.size();
        if(n == 0)
            return "";
        dp.assign(n , vector<int> (n , -1));
        for(int i = 0; i < n; ++i) 
            dp[i][i] = 1; 
        
        for(int len = n; len > 0; --len) {
            for(int i = 0; i + len <= n; ++i) {
                int j = i + len-1;
                if(P(i,j,s))
                    return s.substr(i , len);
            }
        }
        return "";
    }
};
