class Solution {
public:
    set<int> s;
    vector<vector<int>> g;
    vector<bool> vis;
    void dfs(int u, int p, vector<int> &nums) {
        if(vis[u]) return;
        vis[u] = 1;
        s.insert(nums[u]);
        for(int v : g[u]) 
            if(v != p) 
                dfs(v, u, nums);
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        int idx = find(nums.begin(), nums.end(), 1) - nums.begin();
        vector<int> res(n, 1);
        if(idx == n) return res;
        g.resize(n);
        for(int i = 1; i < n; ++i) g[parents[i]].push_back(i);
        
        int cur = idx;
        vis.assign(n, 0);
        int mex = 1;
        while(cur != -1) {
            dfs(cur, parents[cur], nums);
            while(s.find(mex) != s.end()) ++mex;
            res[cur] = mex;
            cur = parents[cur];
        }
        return res;
    }
};
