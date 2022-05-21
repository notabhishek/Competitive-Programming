class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> req(amount+1, amount+1);
        req[0] = 0;
        for(int a = 1; a <= amount; ++a) {
            for(int c : coins)
                if(c <= a)
                    req[a] = min(req[a], 1 + req[a-c]);
        }
        return req[amount] <= amount ? req[amount] : -1;
    }
};
