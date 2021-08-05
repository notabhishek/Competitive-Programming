class Solution {
public:
    inline bool ok(int mask1, int mask2, int m, vector<char> &row) {
        //cheating across diagonals
        for(int i = 0; i < m; ++i) {
            if(mask2 & (1<<i) && i>0 && (mask1 & (1<<(i-1)))) return 0;
            if(mask2 & (1<<i) && i<m-1 && (mask1 & (1<<(i+1)))) return 0;
        }
        return 1;
    }
    int maxStudents(vector<vector<char>>& s) {
        // store each row as bitmask 
        int n = s.size();
        int m = s[0].size();
        s.insert(s.begin(), vector<char>(m, '.'));
        vector<int> pre(1<<m , 0); // dp[mask] = max students, no cheating, i rows
        for(int j = 1; j <= n; ++j) {
            vector<int> cur(1<<m, 0);
            for(int mask2 = 0; mask2 < (1<<m); ++mask2) {
                bool f = 1;
                //check for student in # cell 
                for(int i = 0; i < m; ++i) {
                    if((mask2 & (1<<i)) && s[j][i] == '#') {f = 0; break; }
                }
                //cheating in same row
                for(int i = 1; i < m; ++i) {
                    if((mask2 & (1<<i)) && (mask2 & (1<<(i-1)))) {f = 0; break; }
                }
                if(f)
                for(int mask1 = 0; mask1 < (1<<m); ++mask1) {
                    // check if mask1, mask2 are compatible
                    if(ok(mask1, mask2, m, s[j])) {
                        cur[mask2] = max(cur[mask2], __builtin_popcount(mask2) + pre[mask1]);
                    }
                }
            }
            pre = cur;
        }
        int fans = *max_element(pre.begin(), pre.end());
        return fans;
    }
};
