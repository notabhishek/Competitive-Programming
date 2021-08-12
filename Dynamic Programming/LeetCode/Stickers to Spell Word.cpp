class Solution {
public:
    const int INF = 1e7;
    unordered_map< string , int> dp;
    int dfs(string target, vector<vector<int>> &coins) {
        if(dp.count(target)) 
            return dp[target];
        
        int ret = INF;
        vector<int> f(26, 0);
        for(auto &i : target) f[i-'a']++;
        
        // try to take a coin
        for(int i = 0; i < coins.size(); ++i) {
            bool take = false;
            string newtarget = "";
            for(int j = 0; j < 26; ++j) {
                newtarget += string(f[j]-min(f[j], coins[i][j]), j+'a');
                if(f[j] > 0 && coins[i][j] > 0) 
                    take = true;
            }
            if(take) 
                ret = min(ret, 1 + dfs(newtarget, coins));
        }
        return dp[target] = ret;
    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> coins;
        for(auto &sticker : stickers) {
            vector<int> coin(26, 0);
            for(auto &i : sticker) coin[i-'a']++;
            coins.push_back(coin);
        }
        sort(target.begin(), target.end());
        dp[""] = 0;
        int ans = dfs(target, coins);
        if(ans >= INF) ans = -1;
        return ans;
    }
};
