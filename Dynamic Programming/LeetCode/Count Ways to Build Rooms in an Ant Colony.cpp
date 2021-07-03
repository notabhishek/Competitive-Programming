class Solution {
public:
    const int64_t mod = 1e9 + 7;
    vector<vector<int64_t>> g;
   
    vector<int64_t> f;
    vector<int64_t> finv;
    int64_t fpow(int64_t x, int64_t y , int64_t mod) {
        if(y==0) return 1;
        int64_t r = fpow(x, y/2, mod);
        r = (r * r) % mod;
        if(y&1) {
            r = (r * x) % mod;
        }
        return r;
    }
    int64_t ncr(int64_t n, int64_t r) {
        if(n < r) return 0;
        int64_t ans = (f[n] * finv[r])%mod;
        ans = (ans * finv[n-r])%mod;
        return ans;
    }
    vector<int64_t> dp;
    vector<int64_t> sz;
    int64_t dfs(int64_t u, int64_t p) {
        int64_t w = 1;
        dp[u] = 1;
        sz[u] = 1;
        int64_t tsz = 0;
        for(auto &v : g[u]) {
            if(v!=p) {
                dfs(v , u);
                sz[u] += sz[v];
            }
        }
        tsz = sz[u] - 1;
        for(auto &v : g[u]) {
            if(v!=p) {
                dp[u] = (dp[u] * (( ncr(tsz , sz[v]) * dp[v])%mod )) %mod;
                tsz -= sz[v];
            }
        }
        return dp[u];
    }
    int waysToBuildRooms(vector<int>& p) {
        int64_t n = p.size();
        g.resize(n);
        f.resize(n+1);
        finv = f;
        dp.resize(n+1);
        sz = dp;
        
        finv = f;
        f[0] = 1;
        finv[0] = fpow(1, mod-2, mod);
        for(int64_t i = 1; i <= n; ++i) {
            f[i] = (f[i-1] * i)%mod;
            finv[i] = fpow(f[i] , mod-2, mod);
        }
        
        for(int64_t i = 1; i < n; ++i){
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
        int64_t ans = dfs(0 , -1);
        return ans;
    }
};
