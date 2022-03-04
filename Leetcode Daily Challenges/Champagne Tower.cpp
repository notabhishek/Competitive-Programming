class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(query_row == 0) {
            return min(poured , 1);
        }
        vector< vector< double>> dp(105 , vector<double> (105,0));
        dp[0][0] = poured;
        for(int row = 1; row <= 100; ++row) {
            for(int i = 0 ; i < row; ++i) {
                if(dp[row-1][i] > 1 ) {
                    dp[row][i] += (dp[row-1][i] - 1)/2.0;
                    dp[row][i+1] += (dp[row-1][i] - 1)/2.0;
                }
            }
        }
        double &res = dp[query_row][query_glass];
        if(res > 1 ) res = 1;
        return res;
    }
};
