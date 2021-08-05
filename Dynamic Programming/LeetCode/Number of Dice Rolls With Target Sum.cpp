class Solution {
public:
    int ways(int d , int f , int target , vector<vector<int>> &dp) {
        const int MOD = 1e9 + 7;
        if(d == 0 ) 
            return target == 0;
        if(dp[target][d]!=-1)
            return dp[target][d];
        int w = 0;
        for(int  i = 1 ; i <= min(f , target); ++i) 
            w = (w +  ways(d-1 , f , target - i , dp)) % MOD;
        dp[target][d] = w%MOD;
        return dp[target][d];
    }
    int numRollsToTarget(int d, int f, int target) {
        if(target < d)
            return 0;
        vector<vector<int>> dp( target+1 , vector<int > (d+1 , -1));
        return ways(d  , f , target , dp);
    }
};
