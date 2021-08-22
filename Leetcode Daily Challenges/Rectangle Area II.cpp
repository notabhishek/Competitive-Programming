class Solution {
public:
    int coordinateCompression(vector<vector<int>> &r) {
        set<int> sx, sy;
        vector<int> vx, vy;
        for(auto &j : r) {
            sx.insert(j[0]);
            sx.insert(j[2]);
            sy.insert(j[1]);
            sy.insert(j[3]);
        }
        for(auto &i : sx) vx.push_back(i);
        for(auto &i : sy) vy.push_back(i);
        
        vector<vector<int>> mat(vx.size() + 1, vector<int>(vy.size() + 1, 0));
        long long ans = 0;
        const int MOD = 1e9 + 7;
        int x1, x2, y1, y2;
        for(auto &i : r) {
            x1 = lower_bound(vx.begin(), vx.end(),i[0])-vx.begin();
            x2 = lower_bound(vx.begin(), vx.end(),i[2])-vx.begin();
            y1 = lower_bound(vy.begin(), vy.end(),i[1])-vy.begin();
            y2 = lower_bound(vy.begin(), vy.end(),i[3])-vy.begin();
            for(int x = x1; x < x2; ++x){
                for(int y = y1; y < y2; ++y) {
                    if(mat[x][y] == 0) {
                        long long cur = (vx[x+1]-vx[x]);
                        cur = (cur * (vy[y+1] - vy[y]))%MOD;
                        ans = (ans + cur)%MOD;
                    }
                    mat[x][y] = 1;
                }
            }
        }
        return ans;
    }
    
    int rectangleArea(vector<vector<int>>& r) {
        return coordinateCompression(r);
    }
};
