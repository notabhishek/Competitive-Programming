class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) 
            return 0;
        int cols = grid[0].size();
        if(cols == 0)
            return 0;
        for(int c = 1; c < cols; ++c) 
            grid[0][c]+=grid[0][c-1];
        for(int r = 1; r < rows; ++r)
            grid[r][0]+= grid[r-1][0];
        for(int r = 1 ; r < rows; ++r)
            for(int c = 1; c < cols; ++c) 
                grid[r][c]+= min(grid[r-1][c] , grid[r][c-1]);
        return grid[rows-1][cols-1];
    }
};
