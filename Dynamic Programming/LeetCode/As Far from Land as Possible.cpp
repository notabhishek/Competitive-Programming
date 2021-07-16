class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        const int INF = 1e7;
        int n = g.size();
        vector<vector<int>> d(n , vector<int> (n, INF));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n ; ++j) 
                if(g[i][j]) {
                    d[i][j] = 0;
                    q.push({i,j});
                }
        
        int r[4] = {1, -1, 0 , 0};
        int c[4] = {0 , 0, 1, -1};
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int tr = cur.first + r[i];
                int tc = cur.second + c[i];
                if(tr>=0 && tr< n && tc>=0 && tc<n && (d[tr][tc] > 1 + d[cur.first][cur.second])) {
                    d[tr][tc] = 1 + d[cur.first][cur.second];
                    q.push({tr,tc});
                }
            }
        }
        int ans = -1;
        for(auto &i : d)
            ans = max(ans, *max_element(i.begin(), i.end()));
        if(ans <= 0 || ans >= INF) ans = -1;
        return ans;
    }
};
