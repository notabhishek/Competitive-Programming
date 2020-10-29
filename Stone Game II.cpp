class Solution {
public:
    int take(int i ,int m,vector< int > &a, vector<vector<int>> &dp) {
        if(i >= a.size())
            return 0;
        int &ret = dp[i][m];
        if(ret != -1)
            return ret;
        ret = INT_MIN;
        int sum = 0;
        for(int x = 1; x<= 2*m; ++x) {
            if(i+x-1 >= a.size())
                break;
            sum += a[i + x - 1];
            ret = max(ret ,sum-take(i+x,max(m , x),a,dp) );
        }
        return ret;
    }
    int stoneGameII(vector<int>& piles) {
        vector< vector<int >> dp(piles.size() ,vector<int> (piles.size()* 3 ,-1) );
        int d =  take(0 , 1, piles, dp);
        int s = accumulate(piles.begin(), piles.end() , 0);
        return (d + s)/2;
    }
};