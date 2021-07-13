class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int hasStock = -a[0]; // max profit having 1 stock in hand
        int noStock = 0; // max profit having no stocks in hand
        for(int i = 0; i < a.size(); ++i) {
            noStock = max(noStock ,a[i] + hasStock-fee); //wait or sell the last stock in hand
            hasStock = max(hasStock, noStock - a[i]); // wait or sell and then buy new stock
        }
        return noStock;
    }
};
