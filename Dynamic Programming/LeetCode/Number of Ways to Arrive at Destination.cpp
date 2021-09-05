using ll = long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) {
        // floyd warshall
        const ll INF = 1e15;
        const int MOD = 1e9 + 7;
        vector<vector<ll>> d(n, vector<ll>(n, INF));
        vector<vector<ll>> w(n, vector<ll>(n, 0));
        for(auto &i : a) {
            if(i[2] < d[i[0]][i[1]]) {
                d[ i[0]][i[1]] = i[2];
                w[i[0]][i[1]] = 1;
            } else if(i[2] == d[i[0]][i[1]]) {
                w[i[0]][i[1]]++;
            }
            
            swap(i[0], i[1]);
            if(i[2] < d[i[0]][i[1]]) {
                d[ i[0]][i[1]] = i[2];
                w[i[0]][i[1]] = 1;
            } else if(i[2] == d[i[0]][i[1]]) {
                w[i[0]][i[1]]++;
            }
        }
        for(int i = 0; i < n; ++i) {
            d[i][i] = 0;
            w[i][i] = 1;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == j || i == k || j == k) continue;
                    ll newd = d[i][k] + d[k][j];
                    if(newd < d[i][j]) {
                        d[i][j] = newd;
                        w[i][j] = (w[i][k] * w[k][j]) % MOD;
                    } else if(newd == d[i][j]) {
                        w[i][j] = (w[i][j] + (w[i][k] * w[k][j]) % MOD) % MOD;
                    }
                }
            }
        }
        // cout << d << w;
        return w[0][n-1];
    }
};
