class Solution {
public:
    bool win(int N , vector< int > &dp) {
        if(dp[N] != -1)
            return dp[N];
        for(int i = 2; i * i <= N; ++i ) {
            if( N % i == 0 ) {
                if(!win(N - i , dp) || !win(N - N/i , dp))
                    return dp[N] = true;
            }
        }
        if(!win(N-1 , dp))
            return dp[N] = true;
        return dp[N] = false;
    }
    bool divisorGame(int N) {
        const int MXN = 1e3 + 5;
        vector< int > dp( MXN , -1 );
        dp[1] = 0;
        return win(N , dp);
    }
};