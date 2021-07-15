using ld = double;

class Solution {
public:
    int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    double knightProbability(int n, int k, int row, int column) {
        vector< vector< ld >> prev(n , vector<ld> (n , 0));
        prev[row][column] = 1;
        
        while(k--) {
            vector<vector<ld>> cur(n , vector<ld>(n, 0));
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    for(int p = 0; p < 8; ++p) {
                        int ti = i + x[p];
                        int tj = j + y[p];
                        if(ti >= 0 && ti < n && tj>=0 && tj<n) {
                            cur[ti][tj] += (1.000/8.000) * prev[i][j];
                        }
                    }
                }
            }
            prev = cur;
        }
        
        ld ans = 0;
        for(auto &i : prev) 
            for(auto &j : i) ans += j;
        return ans;
    }
};
