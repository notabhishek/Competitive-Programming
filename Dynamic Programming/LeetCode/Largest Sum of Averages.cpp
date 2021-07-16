class Solution {
public:
    double mAvg(int i , vector<int>&A  ,int K , vector<vector<double>> &dp){
        if(dp[i][K])
            return dp[i][K];
        
        if(K == 1){
            double sum = 0;
            for(int j = i; j < A.size(); ++j) 
                sum += A[j];
            sum/= A.size() - i;
            dp[i][K] = sum;
            return sum;
        }
        //Make 1 part and recur for the remaining k-1 parts
        double sum = 0;
        double Avg = 0;
        for(int j = i; j < A.size() -( K - 1) ; ++j) {
            sum += A[j];
            Avg = max( Avg , sum/(j-i+1) + mAvg(j+1 , A , K-1 , dp));
        }
        dp[i][K] = Avg;
        return Avg;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        vector< vector<double>> dp(A.size()  , vector<double> (K+1 , 0));
        return mAvg(0 , A , K , dp);
    }
};
