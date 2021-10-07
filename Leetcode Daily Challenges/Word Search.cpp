class Solution {
public:
    int r4[4] = {1, -1, 0, 0};
    int c4[4] = {0, 0, 1, -1};
    vector<vector<bool>> vis;
    int n, m;
    bool dfs(int i, int j, int k, string &s, vector<vector<char>> &b) {
        if(b[i][j] != s[k]) return false;
        ++k;
        if(k == s.length()) return true;
        for(int u = 0; u < 4; ++u) {
            
            int ti = i + r4[u];
            int tj = j + c4[u];
            if(ti >= 0 && ti < n && tj >= 0 && tj<m && vis[ti][tj] == 0) { 
                vis[ti][tj] = 1;
                if(dfs(ti, tj, k, s, b)) 
                    return true;
                vis[ti][tj] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& b, string s) {
        n = b.size(); 
        m = b[0].size();
        vis.assign(n, vector<bool>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(b[i][j] != s[0]) continue;
                vis[i][j] = 1;
                if(dfs(i, j, 0, s, b)) return true;
                vis[i][j] = 0;
            }
        }
        return false;
    }
};
