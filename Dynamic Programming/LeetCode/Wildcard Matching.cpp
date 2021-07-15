class Solution {
public:
    bool wildcard(int i , int j , string &s , string &p , vector<vector<int>> &dp){
        if(i<0 || j<0){
            return false;
        }
        if(i==0 && j==0)
                return true;
        if(i==0 || j==0) {
            if(i==0) 
                return p[j-1] =='*' && wildcard(i , j-1 , s , p , dp);
            return false;
        }
        if(dp[i-1][j-1]!=-1)
            return dp[i-1][j-1];
        if(p[j-1]!='?' && p[j-1]!='*' && s[i-1]!=p[j-1]) {
            dp[i-1][j-1] = false;
            return false;
        }
        if(s[i-1] == p[j-1] || p[j-1]=='?') {
            dp[i-1][j-1] =  wildcard(i-1 , j-1 , s , p , dp);
            return dp[i-1][j-1];
        }
        dp[i-1][j-1] = 0;
        if(p[j-1] == '*') {
            //cout << "Match "<< i << " " << j << endl;
            for(int k = i; k>=0; --k) {
                if(wildcard( k , j-1 , s , p , dp )) {
                    //cout << i <<" to "<< k <<" matched " <<endl;
                    dp[i-1][j-1] = 1;
                    return true;
                }
                //cout << "Tried " << k << " " << j-1 << endl;
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() , vector<int> (p.length() , -1));
        return wildcard(s.length() , p.length() , s , p , dp);
    }
};
