class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));//dp[startId][endId]
        //base of dp
        for (int i=0; i<n-1; i++)
            dp[i][i+1]=0;
        //the rest of dp
        for (int i=3; i<=n; i++)
            for (int j=0; j<=n-i; j++){
                int L=j, R=j+i-1;
                for (int k=L+1; k<R; k++)
                    dp[L][R]=min(dp[L][R],dp[L][k]+dp[k][R]+A[L]*A[R]*A[k]);                
            }
        return dp[0][n-1];       
    }
};
