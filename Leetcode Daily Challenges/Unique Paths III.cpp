class Solution {
public:
    const int r4[4] = {1, -1, 0, 0};
    const int c4[4] = {0, 0, 1, -1};
    int walks(int r, int c, int left, vector<vector<int>> &grid) {
        --left;
        if(grid[r][c] == 2) 
            return left == 0;
        int t = grid[r][c];
        grid[r][c] = -1;
        int ans = 0;
        for(int i = 0; i < 4; ++i) {
            int tr = r + r4[i];
            int tc = c + c4[i];
            if(tr >= 0 && tr < grid.size() && tc >= 0 && tc < grid[0].size() && grid[tr][tc] != -1){
                ans += walks(tr, tc, left, grid);
            }
        }
        grid[r][c] = t;
        return ans;
    } 
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc;
        int cnt = (int)grid.size() * (int)grid[0].size();
        for(int i = 0; i < grid.size(); ++i) 
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 1) {
                    sr = i; sc = j;
                } else if(grid[i][j] == -1) --cnt;
        int ans = walks(sr, sc, cnt, grid);
        return ans;
    }
};
