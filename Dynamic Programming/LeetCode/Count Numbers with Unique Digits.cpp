class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n == 0) 
            return 1;
        int dp[9] ={0};
        dp[0] = 1;
        for(int i = 1 ; i < 9; ++i) {
            int c = 9;
            for(int j = 1; j < i; ++j)
                c*= 10-j;
            dp[i] = dp[i-1] + c;        
        }
        return dp[ n ];
    }
};
