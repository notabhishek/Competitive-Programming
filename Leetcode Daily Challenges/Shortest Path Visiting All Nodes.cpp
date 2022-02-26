template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {
    os << "[ ";
    for(T u : v) {
        os << u << ", ";
    }
    os << "]\n";
    return os;
}
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size(), N = 1 << n, INF = 1e7;
        vector<vector<int>> dist(N, vector<int>(n, INF));
        queue<pair<int, int>> q;
        for(int u = 0; u < n; ++u) {
            q.push({1<<u, u});
            dist[1<<u][u] = 0;
        }
        while(!q.empty()) {
            pair<int, int> u = q.front(); 
            q.pop();
            if(u.first == N-1) return dist[u.first][u.second];
            for(int v : g[u.second]) { 
                int mask = u.first | (1<<v);
                if(dist[mask][v] == INF) {
                    dist[mask][v] = dist[u.first][u.second] + 1;
                    q.push({mask, v});
                }
            }
        }
        return INF;
    }
};
