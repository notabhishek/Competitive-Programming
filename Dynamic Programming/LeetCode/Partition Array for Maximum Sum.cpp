class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        // DP[i] = maximum sum obtainable taking elements till A[i]
        vector<int> dp(n+1 , 0 );
        
        int mx = INT_MIN; 
        //For i = 1 to K DP[i] = i * maximum element in  A[0 to i]
        for(int i = 1; i <= K; ++i) {
        	mx = max( mx , A[i-1]);
        	dp[i] =  mx*i;
        }
        
    	
    	for(int i = K+1; i <= n;++i) {
    		int mx = INT_MIN;
    		for(int j = 1; j<=K;++j) {
    			mx  = max(mx , A[i - j]);
    			// Take solution for i-j , and make j elements equal to max of range [i-j to i ]
    			// j = 1 to K
    			dp[ i ] = max( dp[i] , dp[i-j] + mx * j );
    		}
    	}
   	return dp[n]; 	
    } 
};
