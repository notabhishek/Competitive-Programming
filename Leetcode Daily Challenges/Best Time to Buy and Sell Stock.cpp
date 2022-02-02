class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], maxProfit = 0;
        for(int p : prices) {
            mn = min(mn, p);
            maxProfit = max(maxProfit, p - mn);
        }
        return maxProfit;
    }
};
