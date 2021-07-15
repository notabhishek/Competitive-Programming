class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> req(amount+1 , INT_MAX);
        req[0] = 0;
        for(auto &coin : coins) {
            for(int i = coin; i<=amount; ++i) 
                if(req[i-coin]!=INT_MAX)
                req[i] = min(req[i] , 1 + req[i-coin]);
        }
        if(req[amount] == INT_MAX) 
            return -1;
        return req[amount];
    }
};
