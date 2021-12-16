class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> g(n);
        vector<int> in(n, 0);
        for(auto e : edges) {
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
            in[e[0]]++, in[e[1]]++;
        }
        
        // find centre/s
        queue<int> q;
        for(int i = 0; i < n; ++i) 
            if(in[i] == 1) {
                q.push(i);
            }
        
        vector<int> centres;
        while(!q.empty()) {
            centres.clear();
            int s = q.size();
            while(s--) {
                int u = q.front();
                q.pop();
                centres.push_back(u);
                for(int v : g[u]) {
                        if(--in[v] == 1) {
                            q.push(v);
                            in[v]--;
                        }   
                }
            }
        }
        return centres;
    }
};
