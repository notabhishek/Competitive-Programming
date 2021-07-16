class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        vector< int > dp(m);
        for(int col = 1; col < m; ++col ) {
            dp[col] = col;
            for(int prev = 0; prev < col; ++prev) {
                bool lexic = true;
                for(int i = 0 ; i < n; ++i) 
                    if(A[i][col] < A[i][prev]) {
                        lexic = false;
                        break;
                    }
                if(lexic) dp[col] = min(dp[col] , dp[prev] + (col - prev - 1));
            }
        } 
        int ans = INT_MAX;
        for(int i = 0; i < m; ++i)
            ans = min(ans , dp[i] + m - 1 - i);
        return ans;
    }
};
