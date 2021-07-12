class Solution {
public:
    const int INF = 1e8;
    vector< vector<int>> dp;
    int x[4] = {1, 0 , -1, 0};
    int y[4] = {0 , 1 , 0 , -1};
    int f(int r, int c){
        if(r >= dp.size() || r<0 || c >= dp[0].size() || c <0)
            return INF;
        int &ret = dp[r][c];
        if(ret != -1)
            return ret;
        
        ret = INF;
        int cur = INF;
        for(int i = 0; i < 4; ++i) {
            cur = min(cur, 1 + f(r + x[i] , c + y[i]));
        }
        return ret = cur;
    }
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
        
        int n = a.size();
        int m = a[0].size();
        dp.resize(n , vector<int> (m , INF));
        queue<pair<int, int>>q;
        for(int i =0 ; i < n; ++i)  {
            if(a[i][0] == '.' && (i != e[0] || 0 != e[1])) {
                dp[i][0] = 0;
                q.push({i,0});
            }
            if(a[i][m-1] == '.' && (i != e[0] || m-1 != e[1])) {
                dp[i][m-1] = 0;
                q.push({i,m-1});
            }
        }
        for(int j =0 ; j < m; ++j)  {
            if(a[0][j] == '.' && (0 != e[0] || j != e[1])) {
                dp[0][j] = 0;
                q.push({0,j});
            }
            if(a[n-1][j] == '.' && (n-1 != e[0] || j != e[1])) {
                dp[n-1][j] = 0;
                q.push({n-1,j});
            }
        }
        // print();
        while(!q.empty()) {
            pair<int,int> cur = q.front(); 
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int tr = cur.first + x[i];
                int tc = cur.second + y[i];
                if(tr>=0 && tr<n && tc>=0 && tc<m && a[tr][tc]=='.') {
                    int newd = dp[cur.first][cur.second] + 1;
                    if(dp[tr][tc] == INF) {
                        dp[tr][tc] = newd;
                        q.push({tr, tc});
                    }
                }
            }
        }
        // dp[ e[0]][e[1]] = -1;
        int ans = dp[e[0]][e[1]];
        if(ans >= INF) ans = -1;
        // // print();
        return ans;
    }
};
