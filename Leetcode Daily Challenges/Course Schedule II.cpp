class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> in(n, 0);
        for(auto e : pre) {
            g[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
        // kahns algo
        vector<int> tsort;
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(in[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            tsort.push_back(u);
            for(int v : g[u]) {
                if(--in[v] == 0)
                    q.push(v);
            }
        }
        
        if(tsort.size() != n) return {};
        return tsort;
    }
};
