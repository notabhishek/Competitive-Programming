class Solution {
public:
    vector<vector<int>> g;
    vector<int> down;
    vector<int> up;
    vector<int> subsz;
    
    // calculate sum of distances in subtree
    void dfs(int u, int p) {
        down[u] = 0;
        subsz[u] = 1; 
        
        // calc down for u
        for(auto &i : g[u]) 
            if(i!=p) {
                dfs(i, u);
                subsz[u] += subsz[i];
                down[u] += down[i];
            }
        down[u] += subsz[u] - 1; 
    }
    
    // calculate sum of distances not in subtree
    void dfs2(int u, int p) {
        up[u] = 0;
        if(p == -1) up[u] = 0; // root 0
        else {
            up[u] = up[p] + (down[p] - down[u] - subsz[u]) + subsz[0] - subsz[u];
        }
        for(auto &i : g[u])
            if(i!=p) dfs2(i, u);
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        down.resize(n);
        up.resize(n);
        subsz.resize(n);
        
        for(auto &i : edges) 
            g[i[0]].push_back(i[1]), g[i[1]].push_back(i[0]); 
        
        dfs(0, -1);
        dfs2(0, -1);
        
        vector<int> res(n);
        for(int i  = 0; i < n; ++i) res[i] = up[i] + down[i];
        return res;
    }
};
