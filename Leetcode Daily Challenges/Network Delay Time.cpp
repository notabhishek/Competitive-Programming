class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto &t: times) {
            g[t[0]].push_back({t[1], t[2]});
            // g[t[1]].push_back({t[0], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            auto u = pq.top(); pq.pop();
            for(auto v : g[u.second]) {
                int nd = u.first + v.second;
                if(nd < dist[v.first]) {
                    dist[v.first] = nd;
                    pq.push({nd, v.first});
                }
            }
        }
        int ans = *max_element(dist.begin()+1, dist.end());
        if(ans >= INF)
            ans = -1;
        return ans;
    }
};
