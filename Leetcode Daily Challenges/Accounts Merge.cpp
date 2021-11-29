class Solution {
public:
    vector<int> par;
    vector<int> siz;
    void init(int n) {
        siz.assign(n, 1);
        par.resize(n);
        for(int i = 0; i < n; ++i) 
            par[i] = i;
    }
    int getp(int u) {
        if(par[u] == u) return u;
        return par[u] = getp(par[u]);
    }
    void uni(int u, int v) {
        int x = getp(u), y = getp(v);
        if(x == y) return;
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        init(n);
        unordered_map<string, int> m; // map[email] = person
        for(int p = 0; p < n; ++p) {
            for(int e = 1; e < accounts[p].size(); ++e) {
                if(m.count(accounts[p][e]) == 0)
                    m[accounts[p][e]] = p;
                else 
                    uni(m[accounts[p][e]], p);
            }
        }
        unordered_map<int, set<string> > res;
        for(int p = 0; p < n; ++p)
            for(int e = 1; e < accounts[p].size(); ++e) 
                res[getp(p)].insert(accounts[p][e]);
        vector<vector<string>> ans;
        for(auto &i : res) {
            ans.push_back({accounts[i.first][0]});
            for(auto &j : i.second) 
                ans[ans.size()-1].push_back(j);
        }
        return ans;
    }
};
