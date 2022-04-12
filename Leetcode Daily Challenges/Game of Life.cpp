class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int r8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int c8[8] = {0, 1, -1, 1, -1, 1, 0, -1};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int alive = 0;
                for(int k = 0; k < 8; ++k) {
                    int tr = i + r8[k], tc = j + c8[k];
                    if(tr >= 0 && tr < n && tc >= 0 && tc < m && (a[tr][tc]&1)) ++alive;
                }
                
                if(a[i][j] && alive == 2) a[i][j] += 2;
                if(alive == 3) a[i][j] += 2;
            }
        }
        for(auto &i : a) 
            for(auto &j : i)
                j/=2;
    }
};
