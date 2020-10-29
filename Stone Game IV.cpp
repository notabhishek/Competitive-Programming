class Solution {
public:
    bool win(int n , vector< int > &dp) {
        if(dp[n] != -1)
            return dp[n];
        for(int i = 1; i * i <= n; ++i) 
            if(win(n - i*i , dp) == false)
                return dp[n] = true;
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector< int > dp(n + 1 , -1);
        dp[1] = 1;
        return win(n , dp);
    }
};