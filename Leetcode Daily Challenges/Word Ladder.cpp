class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        w.push_back(b);
        int n = w.size(), m = b.length();
        int st = n-1, en = -1;
        vector<vector<int>> g(n);
        for(int i = 0; i < n; ++i) {
            if(en == -1 && w[i] == e) en = i;
            for(int j = i+1; j < n; ++j) {
                int d = 0;
                for(int k = 0; k < m; ++k) {
                    if(w[i][k] == w[j][k]) continue;
                    else if(d == 0) ++d;
                    else {
                        ++d; break;
                    }
                }
                if(d == 1)
                    g[i].push_back(j), g[j].push_back(i);
            }
        }
        if(en == -1) return 0;
        // bfs
        const int INF = 1e7;
        vector<int> dist(n, INF);
        dist[st] = 0;
        queue<int> q; 
        q.push(st);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(dist[v] == INF) {
                    dist[v] = dist[u]+1;
                    if(v == en) return dist[v] + 1;
                    q.push(v);
                }
            } 
        }
        return 0;
    }
};
