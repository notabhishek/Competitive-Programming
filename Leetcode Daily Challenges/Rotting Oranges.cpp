class Solution {
public:
    const int r4[4] = {1, -1, 0, 0};
    const int c4[4] = {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        // multisource bfs
        const int INF = 1e9;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INF));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)  
                if(grid[i][j] == 2) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
        int maxTime = 0;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            maxTime = max(maxTime, dist[cur.first][cur.second]);
            
            for(int i = 0; i < 4; ++i) {
                int tr = cur.first + r4[i];
                int tc = cur.second + c4[i];
                if(tr>=0 && tr<n && tc>=0 && tc<m && grid[tr][tc] == 1 && dist[tr][tc]>1+dist[cur.first][cur.second]){
                    dist[tr][tc] = dist[cur.first][cur.second] + 1;
                    q.push({tr, tc});
                }
            }
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 1 && dist[i][j] == INF)
                    return -1;
        return maxTime;
    }
};
