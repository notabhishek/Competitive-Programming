class Solution {
public:
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& b) {
        vector<vector<int>> l(n, vector<int>(n,0));
        vector<vector<int>> r = l  , u = l , d = l;
        vector< vector<int>> a(n , vector<int>(n , 1));
        for(auto &i : b) a[i[0]][i[1]] = 0;
        // left
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == 0) l[i][j] = a[i][j];
                else 
                l[i][j] = a[i][j] * (l[i][j-1]  + 1);
            }
        }
        // right 
        for(int i = 0; i < n; ++i ) {
            for(int j = n-1; j >= 0; --j) {
                if(j == n-1) r[i][j] = a[i][j];
                else 
                r[i][j] = a[i][j] * (r[i][j+1] + 1);
            }
        }
        // up
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < n; ++i) {
                if(i == 0) u[i][j] = a[i][j];
                else 
                u[i][j] = a[i][j] * (u[i-1][j] + 1);
            }
        }
        //down
        for(int j = 0; j < n; ++j) {
            for(int i = n-1; i>= 0; --i) {
                if(i == n-1) d[i][j] = a[i][j];
                else 
                d[i][j] = a[i][j] * (d[i+1][j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans= max(ans ,min( min(l[i][j] , r[i][j]) ,min(u[i][j] , d[i][j]) ));
                // cout << min( min(l[i][j] , r[i][j]) ,min(u[i][j] , d[i][j]) ) << " ";
            }
            // cout << "\n";
        }
        return ans;
    }
};
