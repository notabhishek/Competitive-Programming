class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> wts;
        for(string s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            wts.push_back({zeros, s.length() - zeros});
        }
        vector<vector<int>> prev(m+1, vector<int> (n+1, 0)), cur(m+1, vector<int> (n+1));
        for(auto wt : wts) {
            for(int z = 0; z <= m; ++z)
                for(int o = 0; o <= n; ++o) {
                    cur[z][o] = prev[z][o];
                    if(z >= wt.first && o >= wt.second) 
                        cur[z][o] = max(cur[z][o], 1 + prev[z-wt.first][o-wt.second]);
                }
            swap(cur, prev);
        }
        return prev[m][n];
    }
};
