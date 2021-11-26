template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {
    for(auto &i : v) os << i << ", "; os << endl;
    return os;
}
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<vector<int>> g(n);
        for(auto &e : relations) {
            g[e[1]-1].push_back(e[0]-1);
        }
        
        int N = 1<<n, INF = n;
        vector<int> dp(N, INF);
        dp[0] = 0;
        
        vector<int> req(N, 0);
        for(int m = 1; m < N; ++m) {
            for(int i = 0; i < n; ++i) {
                if((m>>i)&1) {
                    for(int v : g[i]) 
                        req[m] |= 1<<v;
                }
            }
        }
        // cout << g;
        for(int m = 1; m < N; ++m) {
            // to calculate dp[mask]
            for(int s = m; s; s = (s-1) & m) {
                if(__builtin_popcount(s) > k) continue;
                // submask is constructed this time and others were there previously
                int p = m ^ s;
                if((req[s]&s) > 0 || ((req[s]&p)!=req[s])) continue;
                dp[m] = min(dp[m], 1 + dp[p]);
            }
        }
        return dp[N-1];
    }
};
