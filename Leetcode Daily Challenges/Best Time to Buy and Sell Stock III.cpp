class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int INF = 1e8;
        int n = prices.size();
        int maxProfitSelling1 = -INF;
        int minimumBuyingPrice1 = INF;
        int maxProfitBuying2 = -INF;
        int maxProfitSelling2 = 0;
        for(int i = 0; i < n; ++i) {
            maxProfitSelling2 = max(maxProfitSelling2, prices[i] + maxProfitBuying2);
            maxProfitBuying2 = max(maxProfitBuying2, maxProfitSelling1 - prices[i]);
            maxProfitSelling1 = max(maxProfitSelling1, prices[i]-minimumBuyingPrice1);
            minimumBuyingPrice1 = min(minimumBuyingPrice1, prices[i]);
        }
        int maxProfit = max(maxProfitSelling1, maxProfitSelling2);
        if(maxProfit < 0) maxProfit = 0;
        return maxProfit;
    }
};
