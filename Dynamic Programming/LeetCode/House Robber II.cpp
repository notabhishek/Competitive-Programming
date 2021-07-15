class Solution {
public:
    int rob2(vector<int>& nums  , int n) {
        if(n==0)
            return 0;
        vector<int> dp(n+1 , 0);
        for(int i = 1; i <=n; ++i) {
            dp[i] = dp[i-1];
            if(i > 1)
                dp[i] = max(dp[i] ,nums[i-1] + dp[i-2]);
            else 
                dp[i] = max(dp[i] , nums[i-1]);
        }
        for(int i = 0 ; i <= n; ++i) cout << dp[i] <<" "; cout << endl;
        return dp[n];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0] , nums[1]);
        int n = nums.size();
        vector<int> t(nums.begin() + 2 ,nums.begin() + n-1 );
        vector<int> t2(nums.begin()+1, nums.end());
        return max(rob2(t2 , n-1) ,nums[0] + rob2(t , n-3));
    }
};
