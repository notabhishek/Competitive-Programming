class Solution {
public:
    const int MOD = 1e9 + 7;
    vector< vector<int>> col;
    void init(int i, vector<int> c) {
        if(i == 0) {
            col.push_back(c);
            return;
        }
        for(int u = 1; u < 4; ++u) 
            if(c.size() == 0 || c.back()!=u) {
                c.push_back(u);
                init(i-1, c);
                c.pop_back();
            }
    }
    int colorTheGrid(int m, int n) {
        map< vector<int> , int > prev;
        prev[vector<int> (m, 0)] = 1;
        
        init(m , vector<int>());
        
        for(int i = 0; i <n; ++i) {
            map< vector<int> , int> cur;
            for(auto &v : col) { // new col for this row
                for(auto &u : prev) { // prev row
                    bool f = 1;
                    for(int i = 0; i < m; ++i) 
                        if(v[i] == u.first[i])
                            f = 0;
                    if(f) {
                        cur[v] = (cur[v] + u.second) % MOD;
                    }
                }
            }
            // cout <<"prev i = " << i << prev;
            // cout <<"cur i = " << i << cur;
            prev = cur;
        }
        
        int ans =0;
        for(auto &u : prev) ans = (ans + u.second) % MOD;
        return ans;
    }
};
