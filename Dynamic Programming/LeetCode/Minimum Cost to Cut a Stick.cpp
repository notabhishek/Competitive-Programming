class Solution {
public:
    int cut(int i , int j , vector<int> &a,vector<vector<int>> &dp){
        if(i > j || i < 0) 
            return 0;
        int &ret = dp[i][j];
        if(ret != -1) 
            return ret;
        
        ret = INT_MAX;
        int len = a[j + 1] - a[i-1];
        if(i == j) {
            return ret = len;
        }
        for(int k = i; k <= j; ++k) {
            ret = min(ret ,len + cut(i , k-1,a,dp) + cut(k + 1, j,a,dp) );
        }
        return ret;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int len = cuts.size() + 1;
        vector< vector< int >> dp(len , vector<int> (len , -1) );
        int ans = cut(1 , cuts.size()-2 , cuts, dp);
        return ans;
    }
};
    