using pii = pair<int,int>;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pii>> g(n);
        for(auto &i : edges) {
            g[i[0]].push_back({i[1], i[2]});
            g[i[1]].push_back({i[0], i[2]});
        }
        
        // dijkstra 
        const int INF = 1e8;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> d(n, INF);
        pq.push({0, 0}); 
        d[0] = 0;
        
        while(!pq.empty()) {
            auto u = pq.top(); pq.pop();
            if(d[u.second] != u.first) continue;
            for(auto v : g[u.second]) {
                if(d[v.first] > u.first + v.second + 1) {
                    d[v.first] = u.first + v.second + 1;
                    pq.push({d[v.first], v.first});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) ans += d[i] <= maxMoves;
        
        for(auto &e : edges) {
            int x = max(0, (maxMoves - d[ e[0] ]));
            int y = max(0, (maxMoves - d[ e[1] ]));
            ans += min(e[2], x + y);
        }
        return ans;
    }
};
