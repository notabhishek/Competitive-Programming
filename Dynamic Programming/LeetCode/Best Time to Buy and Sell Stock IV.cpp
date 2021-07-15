class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 || prices.size()==0)
            return 0;
        int n = prices.size();
        if(k >= n/2) {
            int ans  = 0 ; 
            for(int i = 1 ; i < prices.size(); ++i) 
                ans+= max(0 , prices[i] - prices[i-1]);
            return ans;
        }
        //DP
        vector<int> cost(k+1 , prices[0]) , profit(k+1 , 0);
        for(int i  = 1;  i < n; ++i) {
            for(int j = 1; j<=k; ++j) {
                cost[j] = min(cost[j] , prices[i] - profit[j-1]);
                profit[j] = max(profit[j] , prices[i] - cost[j] );
            }
        }
        return profit[k];
    }
};
