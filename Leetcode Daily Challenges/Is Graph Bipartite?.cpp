class Solution {
public:
    bool bipartite(int u, vector<int> &col, vector<vector<int>> &g) {
        for(int v : g[u]) {
            if(col[v] == -1) {
                col[v] = 1 - col[u];
                if(!bipartite(v, col, g)) 
                    return false;
            } else if(col[u] == col[v]) 
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; ++i)
            if(col[i] == -1) {
                col[i] = 0;
                if(!bipartite(i, col, graph))
                    return false;
            }
        return true;
    }
};
