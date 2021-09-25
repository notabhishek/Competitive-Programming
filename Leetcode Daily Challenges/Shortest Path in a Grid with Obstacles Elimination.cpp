class Solution {
public:
    const int r4[4] = {1, -1, 0, 0};
    const int c4[4] = {0, 0, 1, -1};
    int shortestPath(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        const int INF = 1e8;
        vector<vector<vector<int>>> dist(k+1, vector<vector<int>>(n, vector<int> (m, INF)));
        
        // dijkstra 
        priority_queue<array<int,4>, vector<array<int,4>>, greater<array<int,4>>> pq;
        dist[a[0][0]][0][0] = 0;
        pq.push({0, 0, 0, a[0][0]}); // {distance, row, col, obstacles removed}
        
        while(!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int d = tp[0], r = tp[1], c = tp[2], prevk = tp[3];
            if(dist[prevk][r][c] != d) continue;
            
            for(int i = 0; i < 4; ++i) {
                int tr = r + r4[i];
                int tc = c + c4[i];
                if(tr>=0 && tr<n && tc>=0 && tc<m) {
                    int newd = d + 1, newk = prevk + a[tr][tc];
                    if(newk <= k && newd < dist[newk][tr][tc]) {
                        dist[newk][tr][tc] = newd;
                        pq.push({newd, tr, tc, newk});
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 0; i <= k; ++i) {
            ans = min(ans, dist[i][n-1][m-1]);
        }             
        if(ans == INF) ans = -1;
        return ans;
    }
};
