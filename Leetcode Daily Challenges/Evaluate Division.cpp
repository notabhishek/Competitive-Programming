class Solution {
public:
    map<string, int> idx;
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        int cnt = 0;
        map<pair<int, int>, double> val;
        for(auto &i : eq) {
            if(idx.count(i[0]) == 0) 
                idx[i[0]] = cnt++;
            if(idx.count(i[1]) == 0)
                idx[i[1]] = cnt++;
        }
        
        double INF = 1e18;
        vector<vector<double>> g(cnt, vector<double>(cnt, INF));
        for(int i = 0; i < v.size(); ++i) {
            int u = idx[eq[i][0]];
            int vv = idx[eq[i][1]];
            g[u][vv] = v[i];
            g[vv][u] = 1.0/v[i];
        }
        
        for(int k = 0; k < cnt; ++k) {
            for(int i = 0; i < cnt; ++i) 
                for(int j = 0; j < cnt; ++j) {
                    if(i == j) g[i][i] = 1;
                    if(g[i][k] < INF && g[k][j] < INF)
                        g[i][j] = g[i][k] * g[k][j]; 
                }
        }
        
        vector<double> res;
        for(auto &qu : q) {
            if(idx.count(qu[0]) == 0 || idx.count(qu[1]) == 0) {
                res.push_back(-1); continue;
            }
            int x = idx[qu[0]], y = idx[qu[1]];
            res.push_back(g[x][y] < INF ? g[x][y] : -1);
        } 
        
        return res;
    }
};
