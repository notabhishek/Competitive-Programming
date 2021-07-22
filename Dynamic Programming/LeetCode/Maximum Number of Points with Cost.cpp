using ll = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<ll> dp( m+1 , 0);
        vector<ll> L(m+1, 0);
        vector<ll> R(m+1, 0);
        
        for(int i = 0; i  < n; ++i) {
            
            L[0] = 0;
            // Max points to the left when taking the ith element from current row
            for(int j = 1; j <= m; ++j) 
                L[j] = max(dp[j] , -1 + L[j-1]);
            
            R[m] = 0;
            // Max points to the right when taking j+1th element from current row
            for(int j = m-1; j >= 0; --j)
                R[j] = max(dp[j+1] , -1 + R[j+1]);
            
            // Max pts when taking jth element = a[i][j-1] + max(leftmax, rightmax) 
            for(int j = 1; j <= m; ++j) 
                dp[j] = a[i][j-1] + max(L[j], R[j-1]);
        }
        
        ll ans = INT_MIN;
        // ans is max points on any column
        for(int i = 1; i <= m; ++i) ans = max(ans, dp[i]);
        return ans;
    }
};
