class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int prod = INT_MIN;
        long long int sofar = 1;
        vector<int> dp(nums.size() , 1);
        int prev = -1;
        for(int i = 0 ; i < nums.size(); ++i) {
            sofar*= nums[i];
            if(sofar < 0) {
                if(prev == -1) {
                    prev = i;
                }else {
                    prod = max(prod , sofar/dp[prev] );
                }
            }
            dp[i] = sofar;
            prod = max( prod , sofar);
            if(sofar == 0) {
                sofar = 1;
                prev = -1;
            }
        }
        return prod;
    }
};
