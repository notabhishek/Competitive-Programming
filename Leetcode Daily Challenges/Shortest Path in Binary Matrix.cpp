class Solution {
    const int r8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int c8[8] = {0, 0, 1, -1, 1, -1, 1, -1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if(g[0][0] != 0)
            return -1;
        int n = g.size();
        queue<pair<int,int>> q;
        q.push({0, 0});
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            ++steps;
            while(sz--) {
                auto u = q.front(); q.pop();
                if(u.first == n-1 && u.second == n-1) 
                    return steps;
                for(int i = 0; i < 8; ++i) {
                    int tr = u.first + r8[i], tc = u.second + c8[i];
                    if(tr>=0 && tr < n && tc >=0 && tc<n && g[tr][tc] == 0) {
                        g[tr][tc] = 1;
                        q.push({tr, tc});
                    }
                }
            }
        }
        return -1;
    }
};
