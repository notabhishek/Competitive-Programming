class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size() , mx = INT_MIN , mn = INT_MAX;
        int mprofit[n];
        mprofit[n-1] = 0;
        for(int i = n-2;i>=0;--i) {
            mx = max(mx , prices[i+1]);
            mprofit[i] = max(0 , mx - prices[i]);
        }
        int sell[n];
        sell[0] = 0;
        for(int i = 1;  i < n; ++i) {
            mn = min(mn  , prices[i-1]);
            sell[i] = max(0 , prices[i] - mn);
        }
        int lmax = sell[0];
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            lmax = max(lmax , sell[i-1]);
            ans = max(ans , lmax + mprofit[i]);
        }
        for(int i = 0 ; i < n;++i) ans = max(ans , max(sell[i] , mprofit[i]));
        return ans;
    }
};
