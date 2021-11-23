class Solution {
public:
    vector<int> spf, par, siz;
    int ans;
    void sieve(int M) {
        spf.resize(M);
        for(int i = 1; i < M; ++i) spf[i] = i;
        for(int i = 2; i*i < M; ++i) {
            if(spf[i] != i) continue;
            for(int j = i*i; j < M; j+=i) 
                if(spf[j] > i) spf[j] = i;
        }
    }
    
    int getp(int u) {
        if(par[u] == u) return u;
        return par[u] = getp(par[u]);
    }
    void uni(int u, int v) {
        int x = getp(u);
        int y = getp(v);
        if(x==y) return;
        if(siz[x] > siz[y]) swap(x, y);
        siz[y] += siz[x];
        par[x] = y;
        ans = max(ans, siz[y]);
    } 
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int M = *max_element(nums.begin(), nums.end());
        sieve(M + 1);
        ans = 1;
        siz.assign(n, 1);
        par.resize(n);
        for(int i = 0; i < n; ++i)
            par[i] = i;
        vector<vector<int>> div(M+1);
        for(int i = 0; i < n; ++i) {
            int &t = nums[i]; 
            while(t > 1) {
                int p = spf[t];
                while(t%p == 0) t/=p;
                div[p].push_back(i);
            }
        } 
        for(int i = 2; i <= M; ++i) {
            for(int j = 1; j < div[i].size(); ++j) 
                uni(div[i][j], div[i][j-1]);
        }
        return ans;
    }
};
