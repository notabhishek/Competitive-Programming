class TreeAncestor {
public:
    vector<vector<int>> up;
    int L;
    TreeAncestor(int n, vector<int>& parent) {
        L = 1 + ceil(log2(n));
        up = vector<vector<int>>(L, vector<int>(n));
        up[0] = parent;
        for(int u = 0; u < n; ++u)
            for(int i = 1; i < L; ++i)
                if(up[i-1][u] == -1) up[i][u] = -1;
                else up[i][u] = up[i-1][up[i-1][u]];
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = L-1; i >= 0 && node != -1; --i) {
            if((1<<i) <= k) {
                k -= 1<<i;
                node = up[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
