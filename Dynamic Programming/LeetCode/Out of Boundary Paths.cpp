#define vt vector 
class Solution {
public:
    int d4i[4] = {1 , -1, 0 , 0};
    int d4j[4] = {0 , 0 , -1 , 1};
    const int MOD = 1e9 + 7;
    int move(int m, int n, int N, int i, int j,vt<vt<vt<int>>> &dp) {
       if(i < 0 || j < 0 || i >= m || j >= n) {
           return 1;
       }
        if(N == 0) {
            return 0;   
        }
        int &ret = dp[i][j][N];
        if(ret != -1) 
            return ret;
        long long int sum = 0;
        for(int k = 0; k < 4; ++k) {
            sum += move(m,n,N-1,i+d4i[k],j+d4j[k] , dp);
            sum %= MOD;
        }
        return ret = sum;
    }
    int findPaths(int m, int n, int N, int i, int j) {
       vt<vt<vt<int>>> dp(m , vt<vt<int>> (n , vt<int>(N+1, -1)));
        return move(m,n,N,i,j,dp);
    }
};