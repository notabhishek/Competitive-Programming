#define vt vector
class Solution {
public:
    int mcm(int i , int j , vt<vt<int>>&dp , vt<int> &a) {
        if(j < i) 
            return 0;
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        ret = 0;
        int cost = 1;
        if(i>0)
            cost *= a[i-1];
        if(j < a.size()-1)
            cost *= a[j+1];
        
        if(i == j) {
            ret = a[i] * cost;
            return ret;
        }
        for(int k = i; k <=j; ++k) 
            ret = max(ret , a[k] * cost + mcm(i,k-1,dp,a) + mcm(k+1,j,dp,a) );
        return ret;
    }
    int maxCoins(vector<int>& a) {
        int n = a.size();
        vt<vt<int>> dp(n , vt<int>(n , -1));
        return mcm( 0 , n-1 , dp , a);
    }
};
