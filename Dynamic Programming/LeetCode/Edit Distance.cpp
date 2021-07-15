class Solution {
public:
    int minD(int i  , int j , string &s , string &t , vector<vector<int>> &dp) {
        if(i==0 || j==0) {
            if(i==0 && j==0)
                return 0;
            return max(i , j);
        }
        if(dp[i-1][j-1]!=-1)
            return dp[i-1][j-1];
        if(s[i-1] == t[j-1]) {
            dp[i-1][j-1] = minD(i-1 , j-1 , s , t , dp);
        }else {
            int ans1 = minD(i-1 , j , s , t , dp);
            int ans2 = minD(i , j-1 , s , t , dp);
            int ans3 = minD(i-1 , j-1 , s, t , dp);
            dp[i-1][j-1] =1 + min(ans1 , min(ans2 , ans3));
        }
        return dp[i-1][j-1];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size() , -1));
        return minD(word1.size() , word2.size() , word1 , word2 , dp);
    }
};
