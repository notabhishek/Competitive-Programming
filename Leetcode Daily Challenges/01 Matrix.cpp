class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int x[4] = {1, -1, 0 , 0};
        int y[4] = {0 , 0 , 1, -1};
        queue<pair<int,int>> q;
        int n = a.size();
        int m = a[0].size();
        const int INF = 1e9;
        vector< vector<int>> d(n , vector<int> (m, INF));
        for(int i = 0 ; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == 0) {
                    d[i][j] = 0;
                    q.push({i , j});
                }
            } 
        }
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int r = cur.first + x[i];
                int c = cur.second + y[i];
                if(r>=0 && r<n &&  c>=0 && c<m && d[r][c] == INF) {
                    d[r][c] = 1 + d[cur.first][cur.second];
                    q.push({r, c});
                }
            }
        }
        return d;
    }
};
