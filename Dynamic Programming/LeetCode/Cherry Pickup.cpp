class Solution {
public:
    const int INF = 1e7;
    vector<vector< vector<int>>> dp;
    vector<vector< vector<bool>>> f;
    int rec(int r1, int c1, int r2, vector<vector<int>>&a) {
        int c2 = r1 + c1 - r2;
        if(r1 >= a.size() || c1 >= a.size() || r2>=a.size() || c2>=a.size() )
            return -INF;
        if(a[r1][c1] == -1 || a[r2][c2] == -1)
            return -INF;
        int &ret = dp[r1][c1][r2];
        if(f[r1][c1][r2]) 
            return ret;
        
        int cur = 0;
        if(a[r1][c1] == 1) ++cur;
        if(a[r2][c2] == 1) ++cur;
        if(r1 == r2 && c1 == c2 && a[r1][c1] == 1) --cur;  //same cherry counted twice
        
        
        ret = max(ret , cur + rec(r1 + 1 , c1 , r2, a));
        ret = max(ret , cur + rec(r1 + 1 , c1 , r2+1, a));
        ret = max(ret , cur + rec(r1, c1+1 , r2, a));
        ret = max(ret , cur + rec(r1, c1+1 , r2+1, a));
        
        f[r1][c1][r2] = 1;
        return ret;
    }
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();    
        dp.resize(n , vector<vector<int>> (n , vector<int> (n, -INF)));
        f.resize(n , vector<vector<bool>> (n , vector<bool> (n, 0)));
        dp[n-1][n-1][n-1] = a[n-1][n-1];
        f[n-1][n-1][n-1] = 1;
        int ans = rec(0, 0, 0, a);
        ans = max(ans, 0);
        return ans;
    }
};
