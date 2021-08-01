class Solution {
public:
    vector<vector<int>> col;
    map<int, int> sz;
    int x[4] = {1, -1, 0 , 0};
    int y[4] = {0, 0 , 1, -1};
    int color , n;
    void dfs(int r, int c, vector<vector<int>> &a) {
        col[r][c] = color;
        sz[color]++;
        
        for(int i = 0 ; i < 4; ++i) {
            int tr = r + x[i];
            int tc = c + y[i];
            if(tr>=0 && tr<n && tc>=0 && tc<n && a[tr][tc]==1 && col[tr][tc]==-1) {
                dfs(tr, tc, a);
            }
        }
    }
    int largestIsland(vector<vector<int>>& a) {
        n = a.size();
        col.resize(n, vector<int>(n, -1));
        int ans = 0;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(a[r][c] == 1 && col[r][c] == -1) {
                    dfs(r,c, a);
                    ans = max(ans, sz[color]);
                    ++color;
                }
            }
        }
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(a[r][c] == 0) {
                    int sum = 0;
                    set<int> cols;
                    for(int i = 0 ; i < 4; ++i) {
                        int tr = r + x[i];
                        int tc = c + y[i];
                        if(tr>=0 && tr<n && tc>=0 && tc<n && a[tr][tc]==1) {
                            cols.insert(col[tr][tc]);
                        }
                    }
                    for(auto &i : cols) sum+= sz[i];
                    ans = max(ans, sum + 1);
                }
            }
        }
        return ans;
    }
};
