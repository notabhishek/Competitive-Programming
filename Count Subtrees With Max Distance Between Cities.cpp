class Solution {
public:
    vector<vector<int>> g;
    
    int depth, farEnd;
    void dfs(int u, int p, int d, int mask) {
        if(d > depth) {
            farEnd = u;
            depth = d;
        }
        for(auto &i :  g[u]) {
            if(i != p && (mask & (1 << i))) {
                dfs(i , u , d+1, mask);
            }
        }
    }
    // diameter of the subtree in mask
    int diam(int mask) {
        int src = log2(mask & -mask);
        
        depth = 0;
        farEnd = 0;
        dfs(src , -1, 0, mask);
        depth = 0;
        dfs(farEnd, -1, 0 , mask);
        return depth;
    }
    //res array
    vector<int> D;
    void dfs2(int u, int p, int &mask) {
        if(mask & (1<<u)) 
            mask -= 1<<u;
        else return;
        for(auto &i : g[u]) 
            if(i != p) 
                dfs2(i , u , mask);
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        g.clear();
        D.clear();
        g.resize(n+1);
        for(auto &i : edges) {
            g[ i[0] ].push_back( i[1]);
            g[ i[1] ].push_back( i[0]);
        }
        
        D.resize(n-1, 0);
        for(int i = 2; i < (1 << (n+1)); ++i) {
            int mask = i;
            if( !(mask & (mask-1))) continue;
            dfs2( log2(i & -i), -1, mask);
            if(mask == 0) {
                 D[ diam(i) - 1]++;
            }
        }
        return D;
    }
};
