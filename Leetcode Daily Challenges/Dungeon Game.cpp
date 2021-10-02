class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        const int inf = 1e16;
        vector<vector<int>> dp( n , vector<int> (m , inf));
        dp[n-1][m-1] = 1;
        if(dungeon[n-1][m-1] < 0) {
            dp[n-1][m-1] -= dungeon[n-1][m-1];
        }
        for(int i = n-1; i>=0 ; --i)
            for(int j = m-1; j>=0; --j) {
                if(i<n-1){
                    dp[i][j] = min(dp[i][j], dp[i+1][j]);
                }
                if(j<m-1){
                    dp[i][j] = min(dp[i][j], dp[i][j+1]);
                }
                if(i!=n-1 || j!=m-1){
                    dp[i][j]-=dungeon[i][j];
                    if(dp[i][j]<=0){
                        dp[i][j] = 1;
                    }
                }
            }
        return dp[0][0];
    }
};
