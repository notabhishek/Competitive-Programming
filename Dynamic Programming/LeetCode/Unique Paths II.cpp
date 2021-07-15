class Solution {
public:
    int move(int i , int j  , int n , int m , vector<vector<int>> &ways, vector<vector<int>>& grid) {
        if(ways[i][j]!=-1)
            return ways[i][j];
        ways[i][j] = 0;
        if(i < n-1 && grid[i+1][j] == 0) 
            ways[i][j] += move(i+1 , j , n , m , ways, grid);
        if(j < m-1 && grid[i][j+1] == 0)
            ways[i][j] += move(i , j+1 , n , m , ways , grid);
        return ways[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        vector<vector<int>> ways(n , vector<int> (m , -1));
        for(int i = 0 ; i < obstacleGrid.size(); ++i) {
            for(int j = 0 ; j < obstacleGrid[i].size(); ++j) 
                if(obstacleGrid[i][j]) ways[i][j] = 0;
        }
        ways[n-1][m-1] = obstacleGrid[n-1][m-1] == 0;
        return move( 0, 0 , n , m , ways , obstacleGrid);
    }
};
