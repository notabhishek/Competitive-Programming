class Solution {
public:
    int minC(int i , vector<int> &days , vector<int> &costs , vector<int> &dp) {
        if( i < 0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        dp[i] = costs[0] + minC(i-1 , days , costs, dp); 
        int j = i-1;
        while(j>=0 && (days[i-1] - days[j]) < 7) --j;
        dp[i] = min(dp[i] , costs[1] + minC(j+1 , days , costs , dp));
        j = i-1;
        while(j>=0 && (days[i-1] - days[j]) < 30) --j;
        dp[i] = min(dp[i] , costs[2] + minC(j+1 , days , costs , dp));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1 , -1);
        dp[0] = 0;
        return minC(days.size() , days , costs, dp );
    }
};
