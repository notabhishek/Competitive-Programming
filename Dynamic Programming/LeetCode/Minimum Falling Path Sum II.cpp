class Solution {
public:
    int fall(int r , int c,vector<vector<int>>&a, vector< vector< int >> &dp) {
        if(r > a.size()) 
            return 0;
        if(c == 0 || c > a.size() )
            return INT_MAX;
        int &ret = dp[r-1][c-1];
        if(ret != INT_MAX)
            return dp[r-1][c-1];
        for(int c1 = 1; c1 <= a.size(); ++c1 )
            if(c1 != c)
            ret = min(ret , a[r-1][c-1] + fall(r + 1 , c1, a, dp));
        return ret;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector < vector < int >> dp(n, vector< int > (n, INT_MAX) );
        int ans = INT_MAX;
        for(int c = 1; c <= n; ++c) 
            ans = min(ans , fall(1 , c ,arr, dp));
        return ans;    
    }
};