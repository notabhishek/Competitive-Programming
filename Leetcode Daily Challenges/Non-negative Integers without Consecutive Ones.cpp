class Solution {
public:
    int findIntegers(int n) {
        const int NAX = 32;
        // dp[i] = cnt of intigers of i bits s.t no 2 ones are consecutive
        vector<int> dp(NAX);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < NAX; ++i)
            dp[i] = (dp[i-1] + dp[i-2]);
        
        int ans = 0;
        int pre = 0 , cur = 0;
        for(int i = NAX-1; i >= 0; --i) {
            if((n & (1<<i))) {
                // take zero at this place , ans += all numbers of length i
                ans += dp[i];
                
                // 2 consecutive ones, break
                if(pre == 1) {
                    --ans;
                    break;
                }
            }
            pre = (n & (1<<i))!=0;
            // take ith bit of n
        }
        return ans + 1;
    }
};
