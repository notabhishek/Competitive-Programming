class Solution {
public:
    int rows , cols;
    int fill(int r , int c1 , int c2 , vector<vector<int>> &grid ,vector<vector<vector<int>>> &dp) {
        if( r == rows)
            return 0;
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        dp[r][c1][c2] = 0;
        for(auto x : {c1-1 , c1 , c1+ 1}) {
            if(x >=0 && x < cols) {
                for(auto y : {c2-1, c2 ,c2 + 1 }) {
                    if(y>=0 && y < cols ) {
                        if(x!=y) 
                            dp[r][c1][c2] = max(dp[r][c1][c2] , grid[r][c1] + grid[r][c2] + fill(r+1 , x , y , grid , dp)); 
                    }
                }
            }
        }
        return dp[r][c1][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows , vector<vector<int>> (cols , vector<int> (cols , -1)));
        //max cal dp[rows][ robot1 ][robot2 ]
        return fill( 0 , 0 , cols-1 , grid , dp );
    }
};
